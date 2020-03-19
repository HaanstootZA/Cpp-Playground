#include <string>
#include <queue>
#include <boost/filesystem.hpp>
#include "../Tree/TagTree.h"

#ifndef RENAMERWORKER_BASE_H
#define RENAMERWORKER_BASE_H

class RenamerWorker_Base{
private:
    std::queue<string>* GetFileList(const string&);
    void AddFileRange(std::queue<string>*);

protected:
    RFile* files;
    string rootFolder;
    int size;
    
public:
    RFile* Files(void) const;
    string RootFolder(void) const;

    RenamerWorker_Base(const string& Folder);

    TagTree* BuildFileTree(bool CleanUp);
    void Clear();
    void Reset();
    ~RenamerWorker_Base();
};
#endif