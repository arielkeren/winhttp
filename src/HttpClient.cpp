#include "HttpClient.h"

#include <winsock2.h>
#include <ws2tcpip.h>

#include <stdexcept>

#include "HttpRequest.h"
#include "HttpResponse.h"

constexpr size_t BUFFER_SIZE = 4096;
constexpr unsigned char WINSOCK_MAJOR = 2;
constexpr unsigned char WINSOCK_MINOR = 2;

HttpClient::HttpClient() : sock(INVALID_SOCKET) {
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(WINSOCK_MAJOR, WINSOCK_MINOR), &wsa)) {
        throw std::runtime_error("WSAStartup failed");
    }

    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        throw std::runtime_error("Failed to create socket");
    }
}

HttpClient::~HttpClient() {
    if (sock != INVALID_SOCKET) {
        closesocket(sock);
        WSACleanup();
    }
}

void HttpClient::connect(const std::string& host, unsigned short port) {
    if (sock == INVALID_SOCKET) {
        throw std::runtime_error("Socket is not initialized");
    }

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if (inet_pton(AF_INET, host.c_str(), &server.sin_addr) <= 0) {
        throw std::runtime_error("Invalid address");
    }

    if (::connect(sock, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        throw std::runtime_error("Failed to connect to server");
    }
}

void HttpClient::send(const HttpRequest& request) const {
    std::string raw_request = request.to_string();
    ::send(sock, raw_request.c_str(), raw_request.size(), 0);
}

HttpResponse HttpClient::receive() const {
    std::string response;
    char buffer[BUFFER_SIZE];

    while (true) {
        int bytes = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes < 0) {
            throw std::runtime_error("Failed to receive response");
        }
        if (bytes == 0) {
            break;
        }

        response.append(buffer, bytes);

        if (bytes < static_cast<int>(sizeof(buffer))) {
            break;
        }
    }

    if (response.empty()) {
        throw std::runtime_error("Failed to receive response");
    }

    return HttpResponse(response);
}
