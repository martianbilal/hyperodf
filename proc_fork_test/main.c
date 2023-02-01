#include <asm-generic/errno-base.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/sem.h>

#include <sys/mman.h> 	// for test_mlock
#include <signal.h>		// for testing sigpending set of pending signals
#include <fcntl.h>

#include <sys/time.h>	// for timers

#include <aio.h>		// for asynchronous IO
#include <libaio.h>		// for asynchronous IO

#include <errno.h>		// for errno


#define BUF_SIZE 100
#define FILE_NAME "test_file.txt"



pthread_t tid[2];
int counter;


union semun {
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};

void* trythis(void* arg)
{

	unsigned long i = 0;
	counter += 1;
	printf("\n Job %d has started\n", counter);

	for (i = 0; i < (0xFFFF); i++)
		;

	int pid = fork();
	
	
	if (pid == 0) {
		// recreate the locks 
		
		printf("Child process\n");

	}
	else {
		// wait for the child process 
		waitpid(pid, NULL, 0);
		printf("Parent process\n");
	}

	printf("[%d] Job %d has finished\n\n", pid, counter);


	return NULL;
}


void test_semop(){
	int pid = getpid();
	// Create a semaphore set with one semaphore
    // int semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    int semid = semget(IPC_PRIVATE, 1, 0 | 0600);

    // Initialize the value of the semaphore to 1
    union semun arg;
    arg.val = 2;
    semctl(semid, 0, SETVAL, arg);

    // Create a sembuf structure for the semop operation
    struct sembuf sop;
    sop.sem_num = 0; // operate on the first semaphore in the set
    sop.sem_op = -1; // decrement the semaphore value
    sop.sem_flg = 0;

    // Perform the semop operation
    semop(semid, &sop, 1);
    printf("[pid:%d]Semaphore value: %d\n", pid, semctl(semid, 0, GETVAL));
	pid = fork();
	if(pid == 0){

	}
	else{
		waitpid(pid, NULL, 0);
	}
    // Perform the semop operation again
    semop(semid, &sop, 1);
	
	int sem_val = semctl(semid, 0, GETVAL);
	if(sem_val == -1){
		perror("semctl");
		exit(1);
	}
    printf("[pid:%d]Semaphore value: %d\n", pid, sem_val);

    // Remove the semaphore set
    semctl(semid, 0, IPC_RMID);
	return;
}

void test_mlockall(){
	int pid = getpid();
	int ret = mlockall(MCL_CURRENT | MCL_FUTURE);
	if(ret == -1){
		perror("mlockall");
		exit(1);
	}
	printf("[pid:%d]mlockall success\n", pid);
	pid = fork();
	if(pid == 0){
		printf("[pid:%d]mlockall success\n", pid);
	}
	else{
		waitpid(pid, NULL, 0);
	}
	ret = munlockall();
	if(ret == -1){
		perror("munlockall");
		exit(1);
	}
	printf("[pid:%d]munlockall success\n", pid);
	return;
}


void print_pending_signals(sigset_t *s) {
    int i;
    for (i = 1; i < NSIG; i++) {
        if (sigismember(s, i)) {
            printf("%d is pending\n", i);
        }
    }
}


// test_sigpending tests if there are no pending signals in the set of the child process
int test_sigpending(){
	sigset_t set;
	sigset_t pending_set;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGUSR1);
    sigaddset(&set, SIGUSR2);
    sigprocmask(SIG_BLOCK, &set, NULL);
	int sig = SIGINT; // Signal to send (e.g., SIGINT, SIGKILL, etc.)
    raise(sig);

    pid_t pid = fork();
    if (pid == 0) {
        // child process
        sigpending(&pending_set);
        printf("Pending signals in child process:\n");
        print_pending_signals(&pending_set);
    } else {
        // parent process
		waitpid(pid, NULL, 0);
        printf("Pending signals in parent process:\n");
		sigset_t pending_set;
        sigpending(&pending_set);
        print_pending_signals(&pending_set);
    }

    return 0;
}

// test_file_IO tests if the file descriptors are shared between the parent and child process
// and if the file offset is shared between the parent and child process
// if child write to the file after the parent, it inherits the file offset
int test_file_IO(){
	int fd = open("test.txt", O_RDWR | O_CREAT, 0666);
	
	// stdout fd
	// int fd = 1;

	if(fd == -1){
		perror("open");
		exit(1);
	}
	
	int ret = write(fd, "parent", 6);
	if(ret == -1){
		perror("write");
		exit(1);
	}
	int pid = fork();
	
	

	if(pid == 0){
		// child process
		int ret = write(fd, "child", 5);
		if(ret == -1){
			perror("write");
			exit(1);
		}
	}
	else{
		// parent process
		waitpid(pid, NULL, 0);
		
	}
	return 0;
}

int test_fcntl(){
	int fd;
	struct flock lock = {0};
	pid_t pid;

	fd = open(FILE_NAME, O_RDWR | O_CREAT, 0666);
	if (fd == -1) {
		perror("open");
		return 1;
	}

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 1000;
	lock.l_pid = getpid();

	if (fcntl(fd, F_SETLK, &lock) == -1) {
		perror("fcntl");
		return 1;
	}
	write(fd, "parent", sizeof("parent"));

	pid = fork();
	if (pid == -1) {
		perror("fork");
		return 1;
	} else if (pid == 0) {
		// child process
		printf("[%d]Child process: checking lock status...\n", getpid());
		if (fcntl(fd, F_GETLK, &lock) == -1) {
			perror("fcntl");
			return 1;
		}
		if (lock.l_type == F_UNLCK) {
			printf("Child process: lock is not held\n");
		} else {
			printf("[%d]Child process: lock is held by [%d]\n", getpid(), lock.l_pid);
			// printf("Child process: lock is held\n");
			write(fd, "child", sizeof("child"));
		}
		return 0;
	} else {
			// parent process
			waitpid(pid, NULL, 0);
			printf("Parent process: holding lock...\n");
			sleep(2);
			printf("Parent process: releasing lock...\n");
			lock.l_type = F_UNLCK;
			if (fcntl(fd, F_SETLK, &lock) == -1) {
				perror("fcntl");
				return 1;
			}
	}

	close(fd);
	return 0;
}

void timer_handler(int signum)
{
    printf("[%d]Timer expired!\n", getpid());
}

void print_itimer(struct itimerval *timer){
	getitimer(ITIMER_REAL, timer);
	printf("\n\n[%d]", getpid());
	printf("timer.it_value.tv_sec: %ld\n", (*timer).it_value.tv_sec);
	printf("timer.it_value.tv_usec: %ld\n", (*timer).it_value.tv_usec);
	printf("timer.it_interval.tv_sec: %ld\n", (*timer).it_interval.tv_sec);
	printf("timer.it_interval.tv_usec: %ld\n", (*timer).it_interval.tv_usec);
}


int test_itimer(){
	    struct itimerval timer;
    int pid;

    /* Install the signal handler */
    signal(SIGALRM, timer_handler);

    /* Set the timer to fire after 1 second */
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;

    /* Set the interval time to be the same as the value time */
    timer.it_interval.tv_sec = timer.it_value.tv_sec;
    timer.it_interval.tv_usec = timer.it_value.tv_usec;

    /* Start the timer */
    setitimer(ITIMER_REAL, &timer, NULL);

    /* Create a child process */
    pid = fork();
    if (pid == 0) {
        /* Child process */
        print_itimer(&timer);
	

		sleep(5);
        printf("Child process\n");

        exit(0);
    } else if (pid > 0) {
        /* Parent process */
        waitpid(pid, NULL, 0);
		print_itimer(&timer);
        sleep(5);
        printf("Parent process\n");
    } else {
        /* fork() failed */
        printf("Error: Failed to create child process!\n");
        exit(1);
    }

    return 0;
}

int test_alarm(){
	return 0;
}

int test_timer_create(){
	return 0;
}


int test_aio(){
	pid_t child_pid;
    struct aiocb aio_cb;
    char buf[BUF_SIZE];

	printf("test aio\n");
    // Open the file for writing
    int fd = open(FILE_NAME, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }


	// changing buffer
	memset(buf, 'a', BUF_SIZE);

    // Create the AIO context
    memset(&aio_cb, 0, sizeof(struct aiocb));
    aio_cb.aio_fildes = fd;
    aio_cb.aio_buf = buf;
    aio_cb.aio_nbytes = BUF_SIZE;
    aio_cb.aio_offset = 0;

    // Start the AIO operation
    if (aio_write(&aio_cb) == -1) {
        perror("Error starting AIO write");
        exit(1);
    }

    child_pid = fork();
    if (child_pid == 0) {
        // This is the child process
        // Check if the AIO context and operation are shared
        if (aio_error(&aio_cb) == EINPROGRESS) {
            printf("AIO context and operation are shared in the child process\n");
        } else {
            printf("AIO context and operation are not shared in the child process\n");
        }
    } else if (child_pid > 0) {
        // This is the parent process
        int status;
        waitpid(child_pid, &status, 0);
        printf("Child process finished\n");
    } else {
        // fork() failed
        perror("fork error");
        exit(1);
    }

    close(fd);
    return 0;

}
#define BUFSIZE 100

int test_io_setup(){
	int fd, ret;
    io_context_t ctx;
    struct iocb *iocb = NULL;
    struct io_event event;
    char buf[BUFSIZE];

	iocb = (struct iocb *)malloc(sizeof(struct iocb));


	// following two lines of code would be used for setting up the io context in the child process 
    memset(&ctx, 0, sizeof(io_context_t));
    ret = io_setup(10, &ctx);
    if (ret < 0) {
        perror("io_setup");
        return 1;
    }

    fd = open("test.txt", O_RDONLY | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    io_prep_pread(iocb, fd, buf, BUFSIZE, 0);
    ret = io_submit(ctx, 1, &iocb);
    if (ret != 1) {
        perror("io_submit");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        /* child process */
        // sleep(1);
        ret = io_getevents(ctx, 0, 1, &event, NULL);
		printf("ret: %d\n", ret);
        if (ret == 0) {
            printf("In the child process, there are no pending I/O events\n");
        } else if (ret == -EAGAIN) {
            printf("In the child process, there are still pending I/O events\n");
        } else if (ret == -EINVAL) {
			printf("In the child process, the context ID is invalid\n");
		} else {
			printf("pid : %d\n", getpid());
			printf("buf: %s\n", buf);
            perror("io_getevents");
        }
        exit(0);
    } else {
        /* parent process */
        int status;
        waitpid(pid, &status, 0);
        ret = io_getevents(ctx, 0, 1, &event, NULL);
		printf("ret: %d\n", ret);
        if (ret == 0) {
            printf("In the parent process, there are no pending I/O events\n");
        } else if (ret == -EAGAIN) {
            printf("In the parent process, there are still pending I/O events\n");
        } else {
			printf("pid : %d\n", getpid());
			printf("buf: %s\n", buf);
            perror("io_getevents");
        }
    }

    io_destroy(ctx);
    close(fd);
	return 0;
}

int main(void)
{
	int i = 0;
	int error;
	
    // test_semop();
	// test_mlockall();
	// test_sigpending();
	// test_file_IO();
	// test_fcntl();
	// test_itimer();
	// test_aio();
	// test_io_setup();



	// while (i < 1) {
	// 	error = pthread_create(&(tid[i]),
	// 						NULL,
	// 						&trythis, NULL);
	// 	if (error != 0)
	// 		printf("\nThread can't be created :[%s]",
	// 			strerror(error));
	// 	i++;
	// }

	// pthread_join(tid[0], NULL);
	// pthread_join(tid[1], NULL);
	

	return 0;
}

/**

+---------+--------+
| Resouce | Shared |
+---------+--------+
| semop   | shared |
| sigpend | not    |
| mlock   | n/a    |
| mlock   | n/a    |
| mlock   | n/a    |
| mlock   | n/a    |
| mlock   | n/a    |
| mlock   | n/a    |
| mlock   | n/a    |
+---------+--------+



*/