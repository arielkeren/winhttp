#pragma once

#include <string>
#include <unordered_map>

class HttpRequest {
   public:
    HttpRequest& method(const std::string& method);

    HttpRequest& uri(const std::string& uri);

    HttpRequest& version(const std::string& version);

    HttpRequest& header(const std::string& key, const std::string& value);

    HttpRequest& body(const std::string& body);

    std::string to_string() const;

   private:
    std::string m_method;
    std::string m_uri;
    std::string m_version;
    std::unordered_map<std::string, std::string> m_headers;
    std::string m_body;
};
