#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

// These typedefs let us write sockaddr_in and sockaddr
// without repeating the struct keyword.
typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;

int main(void) {
  int client_socket;

  sockaddr_in client_address;
  sockaddr_in server_address;

  char message[1024];
  char IPv4_address_string_buffer[1024];

  // 1. Ask for this computer's IPv4 address.
  //
  // We enter only the host number.
  // For example, entering 67 produces 192.168.10.67.
  //
  // fgets() reads from stdin until a newline, EOF, or the
  // buffer limit is reached. The newline is normally retained.

  printf("IPv4 address to use on this computer "
         "(192.168.10.xx/24, type host number; the xx): ");

  if (fgets(message, sizeof(message), stdin) == NULL) {
    printf("Failed to read input.\n");
    return 1;
  }

  // Remove the newline, if present.
  //
  // strcspn() returns the index of the first '\n'.
  // Replacing it with '\0' terminates the string there.
  //
  // If no newline exists, strcspn() returns the string length,
  // so we simply replace the existing '\0' with another '\0'.

  message[strcspn(message, "\n")] = '\0';

  // 2. Construct this computer's IPv4 address as a string.
  //
  // strcpy() copies the prefix, including its terminating '\0'.
  //
  // "192.168.10." contains 11 characters, so buffer + 11 points
  // to the position occupied by that terminating '\0'.
  //
  // The second strcpy() overwrites that '\0' with our host number
  // and copies the new terminating '\0' too.
  //
  // The destination buffer must be large enough for both strings.

  strcpy(IPv4_address_string_buffer, "192.168.10.");
  strcpy(IPv4_address_string_buffer + 11, message);

  printf("Using local IPv4 address: %s\n", IPv4_address_string_buffer);

  // 3. Ask for the Windows server's IPv4 host number.
  //
  // For example, if Windows uses 192.168.10.68, enter 68.
  //
  // We reuse message because we no longer need its previous contents.

  printf("IPv4 address of the Windows server "
         "(192.168.10.xx/24, type host number; the xx): ");

  if (fgets(message, sizeof(message), stdin) == NULL) {
    printf("Failed to read input.\n");
    return 1;
  }

  // Remove the newline before appending the host number.

  message[strcspn(message, "\n")] = '\0';

  // Construct the server's IPv4 address string.

  strcpy(IPv4_address_string_buffer, "192.168.10.");
  strcpy(IPv4_address_string_buffer + 11, message);

  printf("Connecting to server at %s:50001\n", IPv4_address_string_buffer);

  // 4. Create a TCP socket.
  //
  // AF_INET:
  //   Use IPv4 addressing.
  //
  // SOCK_STREAM:
  //   Use a reliable, ordered byte stream (TCP).
  //
  // 0:
  //   Select the default protocol for this combination, TCP.
  //
  // socket() returns a file descriptor identifying the socket.
  // It does not itself establish a connection.

  client_socket = socket(AF_INET, SOCK_STREAM, 0);

  if (client_socket == -1) {
    perror("socket");
    return 1;
  }

  // 5. Prepare the Windows server's socket address.
  //
  // This structure describes the REMOTE endpoint to which
  // connect() will attempt to establish a connection.
  //
  // sin_family specifies IPv4.
  // sin_port specifies the server's TCP port.
  // sin_addr contains the server's binary IPv4 address.

  memset(&server_address, 0, sizeof(server_address));

  server_address.sin_family = AF_INET;

  // htons() converts the port number to network byte order.
  // This must match the port on which the Windows server listens.

  server_address.sin_port = htons(50001);

  // inet_pton() converts the server's textual IPv4 address into
  // its four-byte binary representation.
  //
  // AF_INET specifies that the input is an IPv4 address.
  // The second argument is the address string.
  // The third argument points to the destination memory.
  //
  // Return value:
  //   1  Conversion succeeded.
  //   0  Invalid address string.
  //  -1  An error occurred.

  if (inet_pton(AF_INET, IPv4_address_string_buffer,
                &server_address.sin_addr) != 1) {
    printf("Invalid server IPv4 address.\n");
    close(client_socket);
    return 1;
  }

  // 6. Connect to the Windows server.
  //
  // connect() requests a TCP connection to the remote endpoint.
  //
  // client_socket:
  //   The socket we created in step 4.
  //
  // (sockaddr *)&server_address:
  //   Pointer to the remote IPv4 address structure, cast to the
  //   generic socket-address pointer type expected by connect().
  //
  // sizeof(server_address):
  //   Size of the address structure in bytes.
  //
  // Linux automatically chooses a local source port if we have
  // not explicitly bound the socket to a port.
  //
  // If the connection succeeds, the socket can be used for both
  // sending and receiving data.

  if (connect(client_socket, (sockaddr *)&server_address,
              sizeof(server_address)) == -1) {
    perror("connect");
    close(client_socket);
    return 1;
  }

  printf("Connected to Windows server!\n");

  // 7. Read a message from the terminal.
  //
  // fgets() waits for a line of input when used with an
  // interactive terminal.
  //
  // We reuse message as the outgoing message buffer.

  printf("Enter a message to send: ");

  if (fgets(message, sizeof(message), stdin) == NULL) {
    printf("Failed to read input.\n");
    close(client_socket);
    return 1;
  }

  // Remove the newline so it is not included in the message.

  message[strcspn(message, "\n")] = '\0';

  // 8. Send the message to the Windows server.
  //
  // send() writes bytes to the connected TCP socket.
  //
  // client_socket:
  //   The socket to send through.
  //
  // message:
  //   Pointer to the first byte of our message.
  //
  // strlen(message):
  //   Number of message bytes, excluding the C string's '\0'.
  //
  // 0:
  //   No special flags.
  //
  // TCP transports bytes, not C strings. The terminating '\0'
  // is not sent.
  //
  // NOTE: send() may send fewer bytes than requested. A robust
  // program must check the return value and handle partial sends.

  int bytes_sent = send(client_socket, message, strlen(message), 0);

  if (bytes_sent == -1) {
    perror("send");
    close(client_socket);
    return 1;
  }

  printf("Sent %d bytes.\n", bytes_sent);

  // 9. Receive the Windows server's reply.
  //
  // recv() reads bytes from the connected socket.
  //
  // client_socket:
  //   The socket to receive from.
  //
  // message:
  //   Memory where received bytes will be stored.
  //
  // sizeof(message) - 1:
  //   Maximum number of bytes to receive, leaving room for '\0'.
  //
  // 0:
  //   No special flags.
  //
  // Return value:
  //   Positive number: number of bytes received.
  //   0:               The peer has closed its sending direction.
  //   -1:              An error occurred.
  //
  // TCP is a byte stream. One recv() call does not guarantee that
  // it receives one complete application message.

  int bytes_received = recv(client_socket, message, sizeof(message) - 1, 0);

  if (bytes_received > 0) {

    // recv() gives us a byte count, not a C string.
    // Add '\0' so printf("%s", message) knows where it ends.

    message[bytes_received] = '\0';

    printf("Reply from Windows: %s\n", message);

  } else if (bytes_received == 0) {

    // The server closed its sending direction without sending
    // any more data.

    printf("Windows server closed the connection.\n");

  } else {

    // recv() returned -1, indicating an error.

    perror("recv");
  }

  // 10. Close the socket.
  //
  // close() releases the socket's file descriptor.
  // The operating system handles TCP connection cleanup.

  close(client_socket);

  return 0;
}
