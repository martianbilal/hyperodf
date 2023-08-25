import socket
import json

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

    def test_query_version(self):
        self._send({"execute": "qmp_capabilities"})
        response = self._recv()
        assert 'return' in response, "Failed to set QMP capabilities"

        self._send({"execute": "query-version"})
        version_info = self._recv()
        print(version_info)
        assert 'return' in version_info, "Failed to get QEMU version"
        assert 'qemu' in version_info['return'], "Version info does not contain QEMU details"

        print(f"QEMU Version: {version_info['return']['qemu']}")

        return True
    def test_get_hello(self):
        self._send({"execute": "qmp_capabilities"})
        response = self._recv()
        assert 'return' in response, "Failed to set QMP capabilities"

        self._send({"execute": "get_hello"})
        result = self._recv()
        result = json.dumps(result, indent=4)
        print(result)
        assert 'Hello' in result, "Did not get hello"

        return True


if __name__ == "__main__":
    test = QemuQmpTest("./qmp.sock")
    test.connect()

    try:
        # if test.test_query_version():
        if test.test_get_hello():
            print("Test passed!")
        else:
            print("Test failed!")
    finally:
        test.close()
