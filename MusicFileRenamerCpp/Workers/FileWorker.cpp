#include "FileWorker.h"

using namespace std;

int FileWorker::CountChars(const string& value, char tocount){
    string temp = value;
    int ret = 0;
    int start = temp.find(tocount);
    while(start >= 0){
        ++ret;
       temp = temp.replace(start, 1, "");
       start = temp.find(tocount);
    }
    return ret;
}

FileWorker::FileWorker(const string& Folder) :  RenamerWorker_Base(Folder){
        RootSlashCount = CountChars(Folder, '\\');
}

bool FileWorker::CheckDirectory(const string& FolderName){
    bool ret = true;
    int FolderSlashCount = CountChars(FolderName, '\\');
    if (RootSlashCount >= FolderSlashCount)
            ret = false;
    return ret;
}

int FileWorker::CountFiles(const string& FolderName){
    int ret = 0;
    namespace f = boost::filesystem;
    f::path p (FolderName);
    try
    {
        if (f::exists(p))
        {
            if (f::is_regular_file(p)){
                ret = 1;
            }
            else if (f::is_directory(p))
            {
                typedef vector<f::path> vec;
                vec v;

                copy(f::recursive_directory_iterator(p), f::recursive_directory_iterator(), back_inserter(v));
                int i = 0;
                for (vec::const_iterator it (v.begin()); it != v.end(); ++it)
                {
                    if(f::is_regular_file(*it))
                        ret++;
                }
            }
        }
    }
    catch (const f::filesystem_error& ex){}
    return ret;
}

string FileWorker::GetParentFolder(const string& Folder){
    string val = Folder;
    val = val.substr(0, val.find_last_of('\\'));
    val = val.substr(0, val.find_last_of('\\') + 1);
    return val;
}

string FileWorker::CleanFolder(const string& FolderName){
    string fname = FolderName;
    string lhs = g_Stringcleaner.ToUpper(fname);
    string rhs = g_Stringcleaner.ToUpper(rootFolder);
    if (lhs == rhs || (CountFiles(FolderName) > 0))
            return "";
    string ret = CleanFolder(GetParentFolder(FolderName));
    if (ret == "")
        return FolderName;
    else
        return ret;
}

void FileWorker::CleanFolders(queue<string>* Folders){
    string current_dir;
    string ToDelete;
    while(!Folders->empty()){
        current_dir = Folders->front();
        if (boost::filesystem::exists(current_dir)){
            ToDelete = CleanFolder(current_dir);
            if (ToDelete != ""){
                if (boost::filesystem::exists(ToDelete) && CheckDirectory(ToDelete))
                    boost::filesystem::remove_all(ToDelete);
            }
        }
        Folders->pop();
    }
}

string* FileWorker::SetPreviewFiles(int PreviewSize){
    string* newFileNames = new string[(size < PreviewSize ? size : PreviewSize)];
    for (int i = 0; (i < size && i < PreviewSize); i++)
    {
        RenamerTag *NewTag = files[i].GetNewTag();
        newFileNames[i] = files[i].GetNewFileName(rootFolder, *NewTag);
        delete NewTag;
    }
    return newFileNames;
}

void FileWorker::CommitFileNameChanges(){
    if (size > 0){
        queue<string>* OldFolders = NULL;
        RenamerTag* NewTag = NULL;
        TagTree* Tree = this->BuildFileTree(true);
        
        if(Tree != NULL){
            string NewName;
            OldFolders = new queue<string>();
            RFile* currentFile = NULL;
            while(Tree->Size()> 0){
                currentFile = new RFile(Tree->Pop());
                string oldFile = currentFile->FileName();
                try{
                    OldFolders->push(oldFile.substr(0, oldFile.find_last_of('\\')));
                    
                    NewTag = currentFile->GetNewTag();
                    NewName = oldFile.substr(oldFile.find_last_of("."));
                    NewName = currentFile->GetNewFileName(rootFolder, *NewTag) + NewName;
                    g_Stringcleaner.ReplaceString(NewName, "?", "");
                    
                    bool tagSet = currentFile->Save(rootFolder + "\\DUPLICATES", NewName, NewTag);
                    
                    if(!tagSet){
                        delete NewTag;
                    }
                    NewTag = NULL;
                    delete currentFile;
                    currentFile = NULL;
                }
                catch (const char* e){}
            }
            if(OldFolders->size() > 0)
                CleanFolders(OldFolders);
            delete OldFolders;
            delete Tree;
        }
    }
}
