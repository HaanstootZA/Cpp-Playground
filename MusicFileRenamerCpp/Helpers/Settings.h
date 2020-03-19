#include <string>
#include <cstring>
#include "Enums.h"

using std::string;

#ifndef SETTINGS_H
#define SETTINGS_H

class Settings
{

    private:
        int m_TreeOrder;
        bool m_UseAlbumInKey;
        bool m_UseTrackInKey;
        int m_UknownCounter;
        string _FileNamingConvention;
        struct Setting_Inst
        {
            int s_StringCase;
            bool s_RemoveComments;
            string s_FileNamingConvention;

            int s_TreeOrder;
            bool s_UseAlbumInKey;
            bool s_UseTrackInKey;
        } TempSettings;

    public:
        int StringCase;
        bool RemoveComments;

        string Artist(void);
        string Title(void);
        string Album(void);
        string Track(void);

        Settings(void);
        
        //get
        bool UseAlbumInKey(void) const;
        bool UseTrackInKey(void) const;
        int TreeOrder(void) const;
        int UnknownCounter(void); 
        string FileNamingConvention(void) const;
        
        //set
        void UseAlbumInKey(bool);
        void UseTrackInKey(bool);
        void TreeOrder(int);
        void UnknownCounter(int);
        void FileNamingConvention(const string&);

        void Abort(void);
        void Confirm(void);
        void Backup(void);
};
#endif
