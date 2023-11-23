#ifndef _FORMAT_H_
#define _FORMAT_H_

#include <iostream>

template<typename T>
void format_helper(std::string& str, const T& value) {
    std::size_t openBracket = str.find('{');
    if (openBracket == std::string::npos) { return; }
    std::size_t closeBracket = str.find('}', openBracket + 1);
    if (closeBracket == std::string::npos) { return; }
    std::cout << str.substr(0, openBracket) << value;
    str = str.substr(closeBracket + 1);
}

template<typename... Targs>
std::string format(const std::string& str, Targs...args) {
    (format_helper(str, args),...);
    return str;
};

#endif