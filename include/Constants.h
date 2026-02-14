#pragma once

#include <string_view>

inline constexpr char STATUS_LINE_SEPARATOR = ' ';
inline constexpr std::string_view HEADER_SEPARATOR = "\r\n";
inline constexpr std::string_view HEADER_KEY_VALUE_SEPARATOR = ": ";
inline constexpr std::string_view HEADER_BODY_SEPARATOR = "\r\n\r\n";
