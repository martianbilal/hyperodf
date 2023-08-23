#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_PATH "/tmp/socket_example.sock"
#define CHILD_SOCKET_PATH "/tmp/socket_example_child.sock"
#define BUFFER_SIZE 256

// Function prototypes
int create_socket(const char *path);
void configure_server(struct sockaddr_un *server_addr, const char *path);
void start_server(const char *path);
int handle_client(int client_sock);  // Change return type to int

int main() {
    start_server(SOCKET_PATH);
    return 0;
}

int create_socket(const char *path) {
    int sock;
    if ((sock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    return sock;
}

void configure_server(struct sockaddr_un *server_addr, const char *path) {
    memset(server_addr, 0, sizeof(*server_addr));
    server_addr->sun_family = AF_UNIX;
    strncpy(server_addr->sun_path, path, sizeof(server_addr->sun_path) - 1);
    // Remove old socket file if it exists
    unlink(path);
}

void start_server(const char *path) {
    int server_sock = create_socket(path);

    struct sockaddr_un server_addr;
    configure_server(&server_addr, path);

    // Bind the socket to the server address
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on %s...\n", path);

    while (1) {
        struct sockaddr_un client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock;

        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len)) == -1) {
            perror("accept");
            continue;  // Continue to the next iteration
        }

        if (handle_client(client_sock)) {  // If handle_client returns 1, fork the server
            printf("handle_client returned 1, forking...\n");
            pid_t pid = fork();

            if (pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {  // Child process
                close(server_sock);  // Close the original socket in child
                start_server(CHILD_SOCKET_PATH);  // Start the child server
            }
        }

        close(client_sock);
    }
}

int handle_client(int client_sock) {  // Return type changed to int
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    while ((bytes_received = recv(client_sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';  // Null-terminate the received string
        printf("Received command: %s\n", buffer);

        // Respond to the client
        char response[BUFFER_SIZE];
        snprintf(response, sizeof(response), "Server received: %s", buffer);
        send(client_sock, response, strlen(response), 0);

        if (strcmp(buffer, "fork\n") == 0) {
            return 1;  // Signal to fork the server
        }
    }

    if (bytes_received == -1) {
        perror("recv");
    }

    return 0;  // Default return, no forking needed
}
