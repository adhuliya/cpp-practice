#include<iostream>
#include<string>

using namespace std;

int main() {
    string str = "Hello, how are you?";

    cout << str << endl;

    str = R"abc(This is \n which is not interpreted " ' hello)abc";

    cout << str << endl;
}

