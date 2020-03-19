#include "Workers/FileWorker.h"

using namespace std;

int main(int argc, char** argv) {
    string FolderName = "C:\\Users\\hendrikj\\Documents\\Renamer Files";
    FileWorker worker1(FolderName);
    g_SettingsValue.FileNamingConvention("\\[TITLE]\\[ALBUM]\\[ARTIST] - [TITLE]");
    system("pause");
    worker1.CommitFileNameChanges();
    system("pause");
    return 0;
}