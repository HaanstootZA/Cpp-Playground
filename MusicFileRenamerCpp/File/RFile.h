#include <string>
#include <boost/filesystem.hpp>
#include "RenamerTag.h"
#include "../Helpers/MyStringConverter.h"
using std::string;

#ifndef RFILE_H
#define RFILE_H

class RFile
{
    private:
        bool _Corrupt;
        RenamerTag* tag;
        void CheckDirectoryForFile(const string&);
        int CheckFile(const string&);
        string SetErrorName(const string&, const string&, int);
        void SaveFile(const string&, const string&);
        string SetName(const string&);
        bool FileNotExists(const string&);
    public:
        bool isDuplicate;
        bool isOriginal;
        int DuplicateCount;
        
        //Accessor Methods
        bool Corrupt(void) const;
        string FileName(void) const;
        RenamerTag Tag(void) const;
        
        //Constructors
        RFile(void);
        RFile(const string&, const string&);
        RFile(const RFile&);
        
        RenamerTag* GetNewTag();
        string GetNewFileName(const string&, RenamerTag);
        bool SaveTag(RenamerTag*);
        bool Save(const string&, const string&, RenamerTag*);
        
        //Basics
        bool CompareTags(RenamerTag);
        RFile& operator=(const RFile&);
        ~RFile();
};
#endif
