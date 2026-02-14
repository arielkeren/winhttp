#include "HttpResponse.h"

#include <string>
#include <unordered_map>

HttpResponse::HttpResponse(const std::string& response) : raw(response) {
    // Parse status line (HTTP/1.1 200 OK)
    size_t first_space = raw.find(' ');
    size_t second_space = raw.find(' ', first_space + 1);
    size_t line_end = raw.find("\r\n");

    version = raw.substr(0, first_space);
    status_code =
        std::stoi(raw.substr(first_space + 1, second_space - first_space - 1));
    status_message = raw.substr(second_space + 1, line_end - second_space - 1);

    // Parse headers
    size_t header_start = raw.find("\r\n") + 2;
    size_t header_end = raw.find("\r\n\r\n");
    std::string header_str =
        raw.substr(header_start, header_end - header_start);

    size_t pos = 0;
    while ((pos = header_str.find("\r\n")) != std::string::npos) {
        std::string line = header_str.substr(0, pos);
        size_t colon_pos = line.find(':');
        if (colon_pos != std::string::npos) {
            std::string key = line.substr(0, colon_pos);
            std::string value = line.substr(colon_pos + 1);
            headers[key] = value;
        }
        header_str.erase(0, pos + 2);
    }

    // Parse body
    if (header_end != std::string::npos) {
        body = raw.substr(header_end + 4);
    }
}
