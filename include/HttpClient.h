#pragma once

#include <ws2tcpip.h>

#include "HttpRequest.h"
#include "HttpResponse.h"

constexpr unsigned short TCP_PORT = 80;

class HttpClient {
   public:
    HttpClient();
    ~HttpClient();

    void connect(const std::string& host, unsigned short port = TCP_PORT);
    void send(const HttpRequest& request) const;
    HttpResponse receive() const;

   private:
    SOCKET sock;
};
