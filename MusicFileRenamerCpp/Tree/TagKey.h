#include <string>
#include "../File/RenamerTag.h"
#include "../Helpers/Enums.h"
#include "../Helpers/global.h"
#include "../Helpers/MyStringConverter.h"
using std::string;

#ifndef TAGKEY_H
#define TAGKEY_H

class TagKey{
    private:
        unsigned long _Artist;
        unsigned long _Album;
        unsigned long _Title;
        unsigned long _Track;
        unsigned long StringToInt(const string&);
    public:
        string Key() const ;
        unsigned long iKey() const;
        
        TagKey();
        TagKey(const RenamerTag&);
        
        bool Compare(const TagKey&, bool);
        bool operator==(const TagKey&);
        TagKey& operator=(const TagKey&);
};
#endif // TAGKEY_H
