/// @file HttpClient.h
/// @brief Declares the HttpClient interface for basic HTTP requests.

#pragma once

#include <ws2tcpip.h>

#include "HttpRequest.h"
#include "HttpResponse.h"

constexpr unsigned short TCP_PORT = 80;

/// Simple HTTP client using a blocking TCP socket.
class HttpClient {
   public:
    /// Initialize Winsock and create the socket.
    HttpClient();

    /// Close the socket and clean up Winsock.
    ~HttpClient();

    /// Connect to the remote host and port.
    /// @param host Remote IPv4 address (e.g. "93.184.216.34").
    /// @param port TCP port to connect to.
    void connect(const std::string& host, unsigned short port = TCP_PORT);

    /// Send a serialized HTTP request over the socket.
    /// @param request HTTP request to serialize and send.
    void send(const HttpRequest& request) const;

    /// Receive the HTTP response from the socket.
    /// @return Parsed HTTP response.
    HttpResponse receive() const;

   private:
    SOCKET m_socket;
};
