/// @file HttpResponse.h
/// @brief Defines a parsed HTTP response.

#pragma once

#include <string>
#include <unordered_map>

/// Parsed HTTP response fields.
class HttpResponse {
   public:
    /// Parse a raw HTTP response string.
    /// @param response Raw response payload.
    HttpResponse(const std::string& response);

    /// Raw response string as received from the socket.
    std::string raw;
    /// HTTP version (e.g. "HTTP/1.1").
    std::string version;
    /// Numeric status code (e.g. 200).
    unsigned short status_code;
    /// Reason phrase (e.g. "OK").
    std::string status_message;
    /// Response headers keyed by header name.
    std::unordered_map<std::string, std::string> headers;
    /// Response body payload.
    std::string body;
};
