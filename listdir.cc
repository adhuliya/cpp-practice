#include <iostream>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <dirent.h>

#define AD_ERROR -1

int listdir (std::string &fname, std::vector<std::string> &list);

int main (int argc, char **argv) {
    std::string name;
    std::vector<std::string> filelist;

    if (argc == 1) {
        // default value
        name = ".";
    } else {
        // takes the first file name
        name = argv[1];
    }

    if (listdir (name, filelist) == -1) {
        std::cerr << "\nCannot list directory due to the previous error.";
    }

    for (std::string str : filelist) {
        std::cout << "File: " << str << std::endl;
    }

    return 0;
}

int listdir (std::string &fname, std::vector<std::string> &list) {
    const char * name = fname.c_str();

    struct stat stbuf;
    if (stat(name, &stbuf) == -1) {
        std::cerr << "\nError stating file " << name;
        return AD_ERROR;
    }

    if ((stbuf.st_mode & S_IFMT) != S_IFDIR) {
        std::cerr << "\nNot a directroy " << name;
        return AD_ERROR;
    } else {
        std::cout << "\nA valid directory " << name;
    }

    dirent *dp;
    DIR *dfd;

    dfd = opendir (name);

    while ((dp = readdir (dfd)) != nullptr) {
        std::cout << dp << std::endl;
        list.push_back (dp->d_name); // implicitly creates a string object and inserts
    }
    closedir (dfd);

    return 1;
}
