#include "HttpResponse.h"

#include <string>
#include <unordered_map>

#include "Constants.h"

HttpResponse::HttpResponse(const std::string& response) : raw(response) {
    size_t first_space = raw.find(STATUS_LINE_SEPARATOR);
    size_t second_space = raw.find(STATUS_LINE_SEPARATOR, first_space + 1);
    size_t line_end = raw.find(HEADER_SEPARATOR);

    version = raw.substr(0, first_space);
    status_code =
        std::stoi(raw.substr(first_space + 1, second_space - first_space - 1));
    status_message = raw.substr(second_space + 1, line_end - second_space - 1);

    size_t header_start = raw.find(HEADER_SEPARATOR) + HEADER_SEPARATOR.size();
    size_t header_end = raw.find(HEADER_BODY_SEPARATOR);
    std::string header_str =
        raw.substr(header_start, header_end - header_start);

    size_t pos = 0;
    while ((pos = header_str.find(HEADER_SEPARATOR)) != std::string::npos) {
        std::string line = header_str.substr(0, pos);
        size_t colon_pos = line.find(HEADER_KEY_VALUE_SEPARATOR);
        if (colon_pos != std::string::npos) {
            std::string key = line.substr(0, colon_pos);
            std::string value =
                line.substr(colon_pos + HEADER_KEY_VALUE_SEPARATOR.size());
            headers[key] = value;
        }
        header_str.erase(0, pos + HEADER_SEPARATOR.size());
    }

    if (header_end != std::string::npos) {
        body = raw.substr(header_end + HEADER_BODY_SEPARATOR.size());
    }
}
