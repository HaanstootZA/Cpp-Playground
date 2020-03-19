#include "RenamerWorker_Base.h"

#ifndef FILEWORKER_H
#define FILEWORKER_H

class FileWorker : public RenamerWorker_Base{
    private:
        int RootSlashCount;
        bool CheckDirectory(const string&);
        int CountFiles(const string&);
        string CleanFolder(const string&);
        void CleanFolders(std::queue<string>*);
        string GetParentFolder(const string&);
        int CountChars(const string&, char);

    public:
        FileWorker(const string&);
        string* SetPreviewFiles(int);
        void CommitFileNameChanges(void);
};
#endif