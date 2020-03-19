#include "Stringcleaner.h"

using namespace std;

string Stringcleaner::ReplaceString(string& Source, const string& lhs, const string& rhs){
    if(lhs == rhs)
        return Source;
    int start = Source.find(lhs);
    while(start >= 0){
       Source = Source.replace(start, lhs.length(), rhs);
       start = Source.find(lhs);
    }
    return Source;
}
string Stringcleaner::ReplaceString(string& Source, const string& lhs, char rhs){
    string real_rhs(1, rhs);
    int start = Source.find(lhs);
    while(start >= 0){
       Source = Source.replace(start, lhs.length(), real_rhs);
       start = Source.find(lhs);
    }
    return Source;
}
string Stringcleaner::RemoveChar(string& Source, char lhs){
    int start = Source.find(lhs);
    while(start >= 0){
       Source = Source.replace(start, 1, "");
       start = Source.find(lhs);
    }
    return Source;
}

Stringcleaner::Stringcleaner(){
    IllegalChars[0] = "[:]";
    IllegalChars[1] = "[*]";
    IllegalChars[2] = "[/]";
    IllegalChars[3] = "[\\\\]";
    IllegalChars[4] = "[<>|\"]";
    IllegalChars[5] = "^[Aa][Cc].[Dd][Cc]|^[Aa][cc][Dd][Cc]";
    IllegalChars[6] = "^[Aa][Tt][Bb]";
    IllegalChars[7] = "^[Aa][Tt][Cc]";
    ReplaceChars[0] = "-";
    ReplaceChars[1] = "_";
    ReplaceChars[2] = "";
    ReplaceChars[3] = "";
    ReplaceChars[4] = "";
    ReplaceChars[5] = "ACDC";
    ReplaceChars[6] = "ATB";
    ReplaceChars[7] = "ATC";
    WordSearch = "\\b(\\w|['])+\\b";
    a_Size = 8;
}

string Stringcleaner::ToLower(char value){
    string ret(1, value);
    transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
    return ret;
}
string Stringcleaner::ToLower(const char* value){
    string ret(value);
    transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
    return ret;
}
string Stringcleaner::ToLower(const string& value){
    string ret = value;
    transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
    return ret;
}

string Stringcleaner::ToUpper(char value){
    string ret(1, value);
    transform(ret.begin(), ret.end(), ret.begin(), ::toupper);
    return ret;
}
string Stringcleaner::ToUpper(const char* value){
    string ret = value;
    transform(ret.begin(), ret.end(), ret.begin(), ::toupper);
    return ret;
}
string Stringcleaner::ToUpper(const string& value){
    string sValue = value;
    transform(sValue.begin(), sValue.end(), sValue.begin(), ::toupper);
    return sValue;
}

int Stringcleaner::ToInt(const string& value){
    int i;
    std::stringstream(value) >> i;
    return i;
}

string Stringcleaner::CleanString(const string& value){
    string ret = value;
    for (int i = 0; i < a_Size; i++)
    {
        string huh = IllegalChars[i];
        boost::regex Regex_Cleaner(huh);
        ret =  boost::regex_replace(ret, Regex_Cleaner, ReplaceChars[i], boost::match_default | boost::format_sed);
    }
    return ret;
}
string Stringcleaner::InitialFirstLetter(const string& input){
    boost::regex expression(WordSearch);
    std::string::const_iterator start, end;    
    boost::match_results<std::string::const_iterator> matches;
    boost::match_flag_type flags = boost::match_default;
    
    string val= input;
    start = val.begin();
    end = val.end();
    while(boost::regex_search(start, end, matches, expression, flags)){
        string curr = matches.str(0);
        if(curr.size() > 0){
            string substitute;
            if (ToUpper(curr) == "FT")
                substitute =  "ft";
            else{
                string upper = ToUpper(curr[0]);
                substitute = curr.replace(0, 1, upper);
            }
            val = ReplaceString(val, curr, substitute);
        }
        start = matches[0].second;
        flags |= boost::match_prev_avail;
        flags |= boost::match_not_bob;
    }
    return val;
}
string Stringcleaner::ToCamelCase(const string& value){
    string val = ToLower(value);
    return InitialFirstLetter(val);
}

string Stringcleaner::ChangeCase(const string& value, int namingCase){
    Case currCase;
    if(namingCase == currCase.ALLCAPS)
        return ToUpper(value);
    else if(namingCase == currCase.nocaps)
        return ToLower(value);
    else if(namingCase == currCase.CamelCase)
        return ToCamelCase(value);
    else if(namingCase == currCase.FirstLetterInitial)
        return InitialFirstLetter(value);
    else if(namingCase == currCase.None)
        return value;
    else
        return value;
}
string Stringcleaner::ChangeCase(const string& value){
    return ChangeCase(value, 3);
}
