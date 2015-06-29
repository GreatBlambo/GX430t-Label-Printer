#include "winsock_wrapper.h"
#include <qDebug>

int setup_connection_TCP(Connection& connection, const char* ip_address, int port)
{
    qDebug("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&connection.wsa) != 0)
    {
        qDebug("\nFailed. Error Code : %d",WSAGetLastError());
        return INITIALIZATION_FAILED;
    }

    qDebug("\nInitialised.");

    if((connection.s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        qDebug("\nCould not create socket : %d" , WSAGetLastError());
        return SOCKET_CREATION_FAILED;
    }

    qDebug("\nSocket created.");

    connection.server.sin_addr.s_addr = inet_addr(ip_address);
    connection.server.sin_family = AF_INET;
    connection.server.sin_port = htons( port );

    if (connect(connection.s, (struct sockaddr *)&connection.server, sizeof(connection.server)) < 0)
    {
        qDebug("\nconnect error");
        qDebug("\nFailed. Error Code : %d", WSAGetLastError());
        return CONNECTION_FAILED;
    }
    qDebug("\nConnected");

    return CONNECTION_SUCEESS;
}

int send_data(Connection& connection, const char* message)
{
    if( send(connection.s , message , strlen(message) , 0) < 0)
    {
        qDebug("Send failed");
        return MESSAGE_SEND_FAILED;
    }
    qDebug("\nData Sent\n");
    return MESSAGE_SEND_SUCCESS;
}

int close_connection(Connection &connection)
{
    int error_code;
    error_code = closesocket(connection.s);
    if (error_code == 0)
    {
        qDebug("Connection closed successfully");
    }
    return error_code;
}
