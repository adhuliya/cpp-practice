#include <iostream>
#include <vector>
#include <string>

void print_vector (std::vector<int> & intvec);
void vec_try1();

int main (int argc, char **argv) {
    std::vector<int> intvec;

    intvec.push_back (10);
    intvec.push_back (11);
    intvec.push_back (13);

    print_vector (intvec);

    vec_try1();

    return 0;
}

void print_vector (std::vector<int> & intvec) {
    for (int i=0; i < intvec.size(); i++) {
        std::cout << intvec[i] << std::endl;
    }

    for (int i : intvec) {
        std::cout << i << std::endl;
    }
}

void vec_try1() {
    std::cout << "\n\nAdding C strings to std::vector<string>\n\n";
    std::vector<std::string> vecstr;
    std::string s;

    char c[] = "hello str";
    s = "my name is NEO";

    vecstr.push_back ("my name is neo");
    vecstr.push_back (s);
    s = "hello std::string";
    vecstr.push_back (s);
    vecstr.push_back (c);

    c[1] = 'H'; // when used, prints 'Command terminated'

    for (std::string str : vecstr) {
        std::cout << str << std::endl;
    }
}
