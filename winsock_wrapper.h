#ifndef WINSOCK_WRAPPER
#define WINSOCK_WRAPPER

#endif // WINSOCK_WRAPPER

#include <stdio.h>
#include <winsock2.h>

#define INITIALIZATION_FAILED 0
#define SOCKET_CREATION_FAILED -1
#define CONNECTION_FAILED -2
#define MESSAGE_SEND_FAILED -3

#define CONNECTION_SUCEESS 1
#define MESSAGE_SEND_SUCCESS 1

struct Connection
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
};

int setup_connection_TCP(Connection& connection, const char* ip_address, int port);

int send_data(Connection& connection, const char* message);

int close_connection(Connection& connection);
