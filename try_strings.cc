#include <iostream>
#include <string>

int main () {
    char c[] = "hello world";
    std::string str (c);

    c[5] = 'H';

    std::cout << "String capacity = " << str.capacity() << std::endl;
    std::cout << str << std::endl;

    return 0;
}

