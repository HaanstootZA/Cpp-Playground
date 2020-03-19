#include "RFile.h"

bool RFile::Corrupt() const { return _Corrupt; }
string RFile::FileName() const { return tag->FileName();}
RenamerTag RFile::Tag() const { RenamerTag ret = *tag; return ret; }

RFile::RFile(){
        isDuplicate = false;
        isOriginal = false;
        DuplicateCount = 0;
        _Corrupt = false;
        tag = NULL;
}
RFile::RFile(const string& RootFolder, const string& Filename){
    isDuplicate = false;
    DuplicateCount = 0;
    try
    {
        tag = new RenamerTag(Filename);
        string f(Filename);
        if (f.substr(0, f.find_last_of(".")) == RFile::GetNewFileName(RootFolder, *tag))
            isOriginal = true;
        else
            isOriginal = false;
        _Corrupt = false;
    }
    catch(const char* e)
    {
        _Corrupt = true;
    }
}
RFile::RFile(const RFile& rhs){
    isDuplicate = rhs.isDuplicate;
    isOriginal = rhs.isOriginal;
    DuplicateCount = rhs.DuplicateCount;
    _Corrupt = rhs._Corrupt;
    tag = new RenamerTag();
    *tag = *(rhs.tag);
}

//Private
bool RFile::FileNotExists(const string& filename ) {
    bool ret = !(boost::filesystem::exists((filename)) && boost::filesystem::is_regular_file(filename));
    return ret;
}
void RFile::CheckDirectoryForFile(const string& FileName){
    string sName(FileName);
    int last = sName.find_last_of("\\");
    int len = sName.length();
    sName = sName.substr(0, last);
    try
    {
        if (!boost::filesystem::exists(sName)){
            boost::filesystem::create_directory(sName);
        }
    }
    catch (const char* e){}
}
int RFile::CheckFile(const string& NewName){
    int ret = 1;
    string t_new = NewName;
    string t_old = FileName();
    
    int nd_index = t_new.find_last_of("\\");
    string newDirectory = t_new.substr(0, nd_index);
    newDirectory = g_Stringcleaner.ToUpper(newDirectory);
    
    int od_index = t_old.find_last_of("\\");
    string oldDirectory = t_old.substr(0, od_index);
    oldDirectory = g_Stringcleaner.ToUpper(oldDirectory);
    
    string newFile = t_new.substr(nd_index + 1);
    string oldFile = t_old.substr(od_index + 1);
    
    if (newDirectory == oldDirectory && newFile == oldFile)
        return 2;
    
    t_new = "\"" + t_new + "\"";
    if (FileNotExists(t_new))
        return 0;

    return ret;
}
string RFile::SetErrorName(const string& RemoveFolder, const string& NewName, int Counter){
    string sName = NewName;
    int startIndex = sName.find_last_of("\\");
    int endIndex = sName.find_last_of(".") - startIndex;
    int offset = 0;
    
    if (Counter > 1)
    {
        string t = ::ToString<int>(Counter - 1);
        offset = 1 + t.length();
    }
    
    string ret = RemoveFolder + sName.substr(startIndex, endIndex - offset);
    
    if (Counter > 0){
        ret += "_";
        ret += ::ToString<int>(Counter);
    }
    ret += sName.substr(endIndex + startIndex);

    return ret;
}
void RFile::SaveFile(const string& NewName, const string& RemoveFolder){
    try
    {
        int counter = 0;
        bool busy = true;
        bool error = false;
        string ncpy = NewName;
        while (busy)
        {
            if (ncpy != "")
            {
                CheckDirectoryForFile(ncpy);
                int check = CheckFile(ncpy);
                if (check == 2)
                   busy = false;
                else if (check == 0)
                {
                    try
                    {
                        tag->Move(ncpy);
                        busy = false;
                    }
                    catch (const char* ioex)
                    {
                        error = true;
                    }
                }
                if (check == 1 || error)
                {
                    ncpy = SetErrorName(RemoveFolder, ncpy, counter);
                    counter++;
                }
            }
        }
    }
    catch (const char* e)
    {
    }
}
string RFile::SetName(const string& NamingConvention){
    string nnc = NamingConvention;
    g_Stringcleaner.ReplaceString(nnc, g_SettingsValue.Artist(), tag->Artist());
    g_Stringcleaner.ReplaceString(nnc, g_SettingsValue.Title(), tag->Title());
    g_Stringcleaner.ReplaceString(nnc, g_SettingsValue.Album(), tag->Album());
    g_Stringcleaner.ReplaceString(nnc, g_SettingsValue.Track(), ::ToString<unsigned int>(tag->Track()));
    return nnc;
}

//Public
RenamerTag* RFile::GetNewTag(){
    if (tag == NULL || tag->FileName() == "")
        return NULL;
    return tag->GetCleanTag();
}
string RFile::GetNewFileName(const string& RootFolder, RenamerTag Tag){
    string newName;
    try
    {
        if (tag != NULL)
        {
            if (isDuplicate)
            {
                string fnameconv = g_SettingsValue.FileNamingConvention();
                int startIndex = fnameconv.find_last_of("\\");
                int endIndex = fnameconv.size() - startIndex;
                string t = fnameconv.substr(startIndex, endIndex);
                
                newName = RootFolder + "\\DUPLICATES" 
                        + SetName(t) + "_" + ::ToString<int>(DuplicateCount);
            }
            else
            {
                newName = RootFolder
                        + SetName(g_SettingsValue.FileNamingConvention());
            }
        }
    }
    catch (const char* e)
    {
        string sfname = FileName();
        int ErrorStartIndex = sfname.find_last_of("\\") + 1;
        int ErrorEndIndex = sfname.find_last_of(".") - ErrorStartIndex;
        newName = RootFolder + "\\0_FAILED\\"
                + sfname.substr(ErrorStartIndex, ErrorEndIndex);
    }
    return newName;
}
bool RFile::SaveTag(RenamerTag *NewTag){
    if (NewTag != NULL && !tag->Compare(*NewTag))
    {
        NewTag->Save();
        tag = NewTag;
        return true;
    }
    return false;
}
bool RFile::Save(const string& RemoveFolder, const string& NewName, RenamerTag* NewTag){
    bool ret = false;
    ret = SaveTag(NewTag);
    SaveFile(NewName, RemoveFolder);
    return ret;
}

bool RFile::CompareTags(RenamerTag NewTag){
    return tag->Compare(NewTag);
}
RFile& RFile::operator=(const RFile &rhs) {
    if(this != &rhs) {
        isDuplicate = rhs.isDuplicate;
        isOriginal = rhs.isOriginal;
        DuplicateCount = rhs.DuplicateCount;
        _Corrupt = rhs._Corrupt;
        if(tag != NULL){
            delete tag;
        }
        tag = new RenamerTag();
        *tag = *(rhs.tag);
    }
    return *this;
}
RFile::~RFile(){
    if(tag != NULL){
        delete tag;
    }
    tag = NULL;
}