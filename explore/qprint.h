#include <iostream>

void print(const std::string& title, const auto& output, const std::string& type) {
    std::cout << title << ": " << output << type <<std::endl;
}

// type num to MB
auto convMB(const auto& value) {
    return value/(1024*1024);
}