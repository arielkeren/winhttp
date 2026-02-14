/// @file HttpRequest.h
/// @brief Defines a simple HTTP request builder.

#pragma once

#include <string>
#include <unordered_map>

/// Builder for an HTTP request message.
class HttpRequest {
   public:
    /// Set the HTTP method (e.g. "GET", "POST").
    /// @param method HTTP method token.
    /// @return Reference to this request for chaining.
    HttpRequest& method(const std::string& method);

    /// Set the request URI (e.g. "/index.html").
    /// @param uri Request target.
    /// @return Reference to this request for chaining.
    HttpRequest& uri(const std::string& uri);

    /// Set the HTTP version (e.g. "HTTP/1.1").
    /// @param version HTTP version string.
    /// @return Reference to this request for chaining.
    HttpRequest& version(const std::string& version);

    /// Add or replace a header.
    /// @param key Header name.
    /// @param value Header value.
    /// @return Reference to this request for chaining.
    HttpRequest& header(const std::string& key, const std::string& value);

    /// Set the request body.
    /// @param body Body payload.
    /// @return Reference to this request for chaining.
    HttpRequest& body(const std::string& body);

    /// Serialize the request to a raw HTTP string.
    /// @return HTTP request string.
    std::string to_string() const;

   private:
    std::string m_method;
    std::string m_uri;
    std::string m_version;
    std::unordered_map<std::string, std::string> m_headers;
    std::string m_body;
};
