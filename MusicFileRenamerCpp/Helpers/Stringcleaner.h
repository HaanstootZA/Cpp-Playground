#include <string>
#include "boost/regex.hpp"
#include "../Helpers/Enums.h"
#include "../Helpers/MyStringConverter.h"

#ifndef STRINGCLEANER_H
#define STRINGCLEANER_H

class Stringcleaner {
    private:
        std::string IllegalChars[8];
        std::string ReplaceChars[8];
        std::string WordSearch;
        int a_Size;
    public:
        Stringcleaner(void);
    
        std::string ReplaceString(std::string&, const std::string&, const std::string&);
        std::string ReplaceString(std::string&, const std::string&, char);
        std::string RemoveChar(std::string&, char);
        
        std::string ToLower(const std::string&);
        std::string ToLower(const char*);
        std::string ToLower(char);
        
        std::string ToUpper(char);
        std::string ToUpper(const char*);
        std::string ToUpper(const std::string&);
        int ToInt(const std::string&);
        
        std::string CleanString(const std::string&);
        std::string InitialFirstLetter(const std::string&);
        std::string ToCamelCase(const std::string&);
        std::string ChangeCase(const std::string&, int);
};
#endif

