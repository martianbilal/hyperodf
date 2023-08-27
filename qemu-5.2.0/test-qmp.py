import socket
import json
import sys

class QemuQmpTest:
    def __init__(self, socket_path):
        self.socket_path = socket_path
        self.sock = None

    def connect(self):
        self.sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        self.sock.connect(self.socket_path)
        # Read the greeting message
        greeting = self._recv()
        # stringify the greeting for printing
        greeting = json.dumps(greeting, indent=4)
        print(greeting)
        assert 'QMP' in greeting and 'version' in greeting, "Invalid QMP greeting"

    def close(self):
        if self.sock:
            self.sock.close()

    def _send(self, cmd):
        self.sock.sendall(json.dumps(cmd).encode())

    def _recv(self):
        response = self.sock.recv(4096).decode()
        return json.loads(response)

    def set_qmp_capabilities(self):
        self._send({"execute": "qmp_capabilities"})
        response = self._recv()
        assert 'return' in response, "Failed to set QMP capabilities"

    def do_query_version(self):
        self._send({"execute": "query-version"})
        version_info = self._recv()
        print(version_info)
        assert 'return' in version_info, "Failed to get QEMU version"
        assert 'qemu' in version_info['return'], "Version info does not contain QEMU details"

    def do_get_hello(self):
        self._send({"execute": "get_hello"})
        result = self._recv()
        result = json.dumps(result, indent=4)
        print(result)
        assert 'Hello' in result, "Did not get hello"

    def do_vm_fork(self):
        self._send({"execute": "vm_fork"})
        result = self._recv()
        result = json.dumps(result, indent=4)
        print(result)

    def do_query_iothreads(self):
        self._send({"execute": "query-iothreads"})
        result = self._recv()
        result = json.dumps(result, indent=4)
        print(result)

def run_cmd(sock_con, cmd):
    if cmd == "quit" or cmd == "q":
        exit(0)
    elif cmd == "query_version":
        sock_con.do_query_version()
    elif cmd == "get_hello":
        sock_con.do_get_hello()
    elif cmd == "query_iothreads":
        sock_con.do_query_iothreads()
    elif cmd == "vm_fork":    
        sock_con.do_vm_fork()
    else:
        print(f"Unknown command: {cmd}")

if __name__ == "__main__":
    # take the arg from cmdline to pass the socket path
    sock_path = sys.argv[1]
    try:
        cmd = sys.argv[2]
    except:
        cmd = None
        
    
    sock_con = QemuQmpTest(sock_path)
    sock_con.connect()
    sock_con.set_qmp_capabilities()
    if cmd :
        run_cmd(sock_con, cmd)
        exit(0)
    
    try:
        while True:
            cmd = input("Enter command (or 'quit' to exit): ")
            run_cmd(sock_con, cmd)
    finally:
        sock_con.close()