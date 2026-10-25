

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;

int main(void) {
  int server_socket;
  int client_socket;

  sockaddr_in server_address; // contains Port number e.g. 50001, and IPv4
                              // address e.g. 192.168.10.67
  sockaddr_in client_address;

  socklen_t client_address_length = sizeof(client_address);

  char buffer[1024];

  // 1. Create a TCP socket.
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  if (server_socket == -1) {
    perror("socket");
    return 1;
  }

  // 2. Describe the local IPv4 address and port.
  memset(&server_address, 0, sizeof(server_address));

  server_address.sin_family = AF_INET; // Address Family INET. INET is for IPv4

  /*
   * Port range    |   Purpose
   *               |
   *               |
   * 0–1023        |   Well-known ports,
   *               |   generally reserved
   *               |   for established services
   *               |
   *               |
   * 1024–49151    |  Registered ports
   *               |
   *               |
   * 49152–65535   |  Dynamic/private ports,
   *               |  commonly used for
   *               |  temporary client ports
   */

  // The htons() function converts the unsigned short integer hostshort from
  // host byte order to network byte order.
  server_address.sin_port = htons(50001);
  // convert IPv4 and IPv6 addresses from text to binary form

  printf("IPv4 address to use on this computer (192.168.10.xx/24, type host "
         "number; the xx): ");
  char message[1024];
  if (fgets(message, sizeof(message), stdin) == NULL) {
    printf("Failed to read input.\n");
    return 1;
  }
  // end string at first '\n'
  message[strcspn(message, "\n")] = '\0';

  printf("You inputted: %s\n", message);

  char IPv4_address_string_buffer[1024];

  strcpy(IPv4_address_string_buffer, "192.168.10.");
  strcpy(IPv4_address_string_buffer + 11,
         message); // replaces \0 after '.' in "192.168.10."
  printf("Using IPv4 address: %s\n", IPv4_address_string_buffer);

  inet_pton(AF_INET, IPv4_address_string_buffer, &server_address.sin_addr);

  // 3. Bind the socket to the local IPv4 address and port.
  //
  // The bind() function associates a socket with a local address.
  //
  // Parameters:
  //   server_socket                  The socket we want to bind.
  //   (struct sockaddr *)&server_address
  //                                  Pointer to the address structure.
  //                                  Cast to sockaddr because bind()
  //                                  accepts the generic sockaddr type.
  //   sizeof(server_address)         Size of the address structure in bytes.
  //
  // This does NOT establish a connection to another computer.
  // It associates this socket with 192.168.10.67:50001.

  if (bind(server_socket, (sockaddr *)&server_address,
           sizeof(server_address)) == -1) {
    perror("bind");
    close(server_socket);
    return 1;
  }

  // 4. Mark the socket as a listening socket.
  //
  // The listen() function prepares a TCP socket to accept incoming
  // connection requests.
  //
  // Parameters:
  //   server_socket   The socket that should listen for connections.
  //   5               Requested backlog for pending connections.
  //
  // The number 5 does NOT limit the total number of clients.
  // The operating system determines the effective queue size.
  //
  // listen() does not accept a connection itself.
  // That is the job of accept().

  if (listen(server_socket, 5) == -1) {
    perror("listen");
    close(server_socket);
    return 1;
  }

  printf("Waiting for a connection on port 50001...\n");

  // 5. Accept one incoming TCP connection.
  //
  // The accept() function waits for a connection request.
  // By default, it blocks until a connection arrives.
  //
  // Parameters:
  //   server_socket                  The listening socket.
  //   (struct sockaddr *)&client_address
  //                                  Where the OS writes the remote
  //                                  computer's address information.
  //   &client_address_length         Pointer to the size of that structure.
  //                                  The OS updates this value.
  //
  // Return value:
  //   A NEW socket for communication with this particular client.
  //   -1 if an error occurs.
  //
  // server_socket remains the listening socket.
  // client_socket will be used to send and receive data.

  client_socket = accept(server_socket, (sockaddr *)&client_address,
                         &client_address_length);

  if (client_socket == -1) {
    perror("accept");
    close(server_socket);
    return 1;
  }

  printf("Client connected!\n");

  // 6. Receive bytes from the connected client.
  //
  // The recv() function reads bytes from a connected socket.
  //
  // Parameters:
  //   client_socket         The connected socket to read from.
  //   buffer                Memory where received bytes will be stored.
  //   sizeof(buffer) - 1    Maximum number of bytes to receive.
  //                         We leave one byte for the '\0' terminator.
  //   0                     No special flags.
  //
  // Return value:
  //   Positive number: number of bytes received.
  //   0:               The peer has closed its sending direction.
  //   -1:              An error occurred.
  //
  // IMPORTANT:
  // TCP is a byte stream. recv() does not guarantee that it receives
  // one complete application message. It may return fewer bytes than
  // requested, even when the connection remains open.

  int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);

  if (bytes_received > 0) {

    // recv() gives us a byte count, not a C string.
    // Add '\0' after the received bytes so printf("%s", buffer)
    // knows where the string ends.
    //
    // This is safe because we requested at most sizeof(buffer) - 1 bytes.

    buffer[bytes_received] = '\0';

    printf("Received: %s\n", buffer);

    // 7. Send a reply to the connected client.
    //
    // The send() function writes bytes to the TCP connection.
    //
    // Parameters:
    //   client_socket    The connected socket to write to.
    //   reply            Pointer to the bytes we want to send.
    //   strlen(reply)    Number of bytes to send, excluding '\0'.
    //   0                No special flags.
    //
    // TCP sends bytes, not C string terminators.
    // The '\0' at the end of reply is not sent.
    //
    // IMPORTANT:
    // send() may send fewer bytes than requested. A robust program
    // must check its return value and send any remaining bytes.

    const char *reply = "Hello from Linux!";

    if (send(client_socket, reply, strlen(reply), 0) == -1) {
      perror("send");
    }

  } else if (bytes_received == 0) {

    // recv() returned 0: the peer has closed its sending direction.
    // There are no more bytes to receive from that direction.

    printf("Client disconnected.\n");

  } else {

    // recv() returned -1: a socket error occurred.

    perror("recv");
  }

  // 8. Close the connected socket.
  //
  // close() releases this process's file descriptor for the socket.
  // The operating system handles the TCP connection's closure.
  //
  // Closing client_socket does not close server_socket.

  close(client_socket);

  // 9. Close the listening socket.
  //
  // We are finished accepting connections, so release this socket too.
  //
  // This server handles only ONE client in this example.
  // The program will exit after this connection is finished.

  close(server_socket);

  return 0;
}
