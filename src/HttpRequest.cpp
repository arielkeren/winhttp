#include "HttpRequest.h"

#include <string>

#include "Constants.h"

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
    std::string request = m_method + STATUS_LINE_SEPARATOR + m_uri +
                          STATUS_LINE_SEPARATOR + m_version;
    request += HEADER_SEPARATOR;

    for (const auto& header : m_headers) {
        request += header.first;
        request += HEADER_KEY_VALUE_SEPARATOR;
        request += header.second;
        request += HEADER_SEPARATOR;
    }

    request += HEADER_SEPARATOR;
    request += m_body;

    return request;
}
