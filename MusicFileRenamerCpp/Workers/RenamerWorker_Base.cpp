#include "RenamerWorker_Base.h"
using namespace std;

//private
queue<string>* RenamerWorker_Base::GetFileList(const string& FolderName){
    queue<string>* ret = NULL;
    namespace f = boost::filesystem;
    f::path p (FolderName);
    try
    {
        if (f::exists(p))
        {
            if (f::is_regular_file(p)){
                ret = new queue<string>();
                size = 1;
                string t = ::ToString<f::path>(p);
                if(t.find(".mp3") > 0 || t.find(".m4a") > 0 || t.find("wma") > 0){
                    if(t.substr(0, 1) == "\"")
                        t = t.substr(1, t.size() - 2);
                    if(t.find("&&") > 0)
                        g_Stringcleaner.ReplaceString(t, "&&", '&');
                    ret->push(t);
                }
            }
            else if (f::is_directory(p)){
                typedef vector<f::path> vec;
                vec v;

                copy(f::recursive_directory_iterator(p), f::recursive_directory_iterator(), back_inserter(v));
                size = 0;
                for (vec::const_iterator it (v.begin()); it != v.end(); ++it)
                {
                    if(f::is_regular_file(*it)){
                        if(ret == NULL)
                            ret = new queue<string>();
                        string t = ::ToString<boost::filesystem::path>(*it);
                        if(t.find(".mp3") > 0 || t.find(".m4a") > 0 || t.find("wma") > 0){
                            if(t.substr(0, 1) == "\"")
                                t = t.substr(1, t.size() - 2);
                            if(t.find("&&") > 0)
                                g_Stringcleaner.ReplaceString(t, "&&", '&');
                            ret->push(t);
                            size++;
                        }
                    }
                }
            }
        }
    }
    catch (const f::filesystem_error& ex){}
    return ret;
}
void RenamerWorker_Base::AddFileRange(queue<string>* FilesToAdd){
    files = new RFile[size]; 
    string file;
    int i = 0;
    while(!FilesToAdd->empty())
    {
        try{
            file = FilesToAdd->front();
            FilesToAdd->pop();
            RFile newFile(rootFolder, file);
            files[i++] = newFile;
        }catch(exception& e){
        }
    }
}

//public
RFile* RenamerWorker_Base::Files(void) const { return files; }
string RenamerWorker_Base::RootFolder(void) const { return rootFolder; }

RenamerWorker_Base::RenamerWorker_Base(const string& Folder){
    rootFolder = Folder;
    queue<string>* fileNames = GetFileList(Folder);
    if(fileNames != NULL)
        AddFileRange(fileNames);
}

TagTree* RenamerWorker_Base::BuildFileTree(bool CleanUp){
    TagTree* Tree = NULL;
    if(size > 0)
        Tree = new TagTree();
    for (int i = 0; i < size; i++)
    {
        Tree->Push(files[i]);
    }
    if (CleanUp){
        delete[] files;
        files = NULL;
    }
    return Tree;
}

void RenamerWorker_Base::Clear(){
    if(files != NULL){
        delete[] files;
        files = NULL;
    }
}
void RenamerWorker_Base::Reset(){
    if(files != NULL){
        delete[] files;
        files = NULL;
    }
    g_SettingsValue.UnknownCounter(0);
}
RenamerWorker_Base::~RenamerWorker_Base(){
    if(files != NULL){
        delete[] files;
        files = NULL;
    }
}