#ifndef MYSTRINGCONVERTER_H
#define MYSTRINGCONVERTER_H

#include <string>
#include <stdlib.h>
#include <sstream>

template<typename T> char* ToCharP(T value){
    std::stringstream ss;
    ss << value;
    std::string t = ss.str();
    char *ret = new char[t.size() + 1];
    std::strcpy(ret, t.c_str());
    return ret;
}

template<typename T> std::string ToString(T value){
    std::stringstream ss;
    ss << value;
    return ss.str();
}
#endif