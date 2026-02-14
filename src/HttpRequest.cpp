#include "HttpRequest.h"

#include <string>

HttpRequest& HttpRequest::method(const std::string& method) {
    m_method = method;
    return *this;
}

HttpRequest& HttpRequest::uri(const std::string& uri) {
    m_uri = uri;
    return *this;
}

HttpRequest& HttpRequest::version(const std::string& version) {
    m_version = version;
    return *this;
}

HttpRequest& HttpRequest::header(const std::string& key,
                                 const std::string& value) {
    m_headers[key] = value;
    return *this;
}

HttpRequest& HttpRequest::body(const std::string& body) {
    m_body = body;
    return *this;
}

std::string HttpRequest::to_string() const {
    std::string request = m_method + " " + m_uri + " " + m_version + "\r\n";

    for (const auto& header : m_headers) {
        request += header.first + ": " + header.second + "\r\n";
    }

    request += "\r\n" + m_body;

    return request;
}
