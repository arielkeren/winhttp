#pragma once

#include <ws2tcpip.h>

#include "HttpRequest.h"
#include "HttpResponse.h"

class HttpClient {
   public:
    HttpClient();
    ~HttpClient();

    void connect(const std::string& host, int port = 80);
    void send(const HttpRequest& request) const;
    HttpResponse receive() const;

   private:
    SOCKET sock;
};
