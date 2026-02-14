#include <winsock2.h>
#include <ws2tcpip.h>

#include <iostream>

#include "HttpClient.h"
#include "HttpRequest.h"
#include "HttpResponse.h"

int main() {
    HttpClient client;
    HttpRequest request;

    request.method("GET").uri("/").version("HTTP/1.1");
    request.header("Host", "example.com");
    request.header("Connection", "close");

    std::cout << "-----Raw request-----" << std::endl;
    std::cout << request.to_string() << std::endl;

    client.connect("104.18.27.120");
    client.send(request);

    HttpResponse response = client.receive();

    std::cout << "-----Version-----" << std::endl;
    std::cout << response.version << std::endl;

    std::cout << "-----Status Code-----" << std::endl;
    std::cout << response.status_code << std::endl;

    std::cout << "-----Status Message-----" << std::endl;
    std::cout << response.status_message << std::endl;

    std::cout << "-----Headers-----" << std::endl;
    for (const auto& header : response.headers) {
        std::cout << header.first << ": " << header.second << std::endl;
    }

    std::cout << "-----Body-----" << std::endl;
    std::cout << response.body << std::endl;
}
