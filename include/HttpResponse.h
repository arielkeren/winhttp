#pragma once

#include <string>
#include <unordered_map>

class HttpResponse {
   public:
    HttpResponse(const std::string& response);

    std::string raw;
    std::string version;
    unsigned short status_code;
    std::string status_message;
    std::unordered_map<std::string, std::string> headers;
    std::string body;
};
