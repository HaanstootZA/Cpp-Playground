#include <string>
#include <fileref.h>
#include <tag.h>
#include <boost/filesystem.hpp>
#include "../Helpers/global.h"
#include "../Helpers/MyStringConverter.h"

using std::string;

#ifndef RENAMERTAG_H
#define RENAMERTAG_H

class RenamerTag
{
    private:
        string m_FileName;
        string m_Artist;
        string m_Album;
        string m_Title;
        int m_Track;
        int m_Year;
        string m_Comment;
        string m_Genre;
        long m_Bitrate;
        long m_Duration;
        void SetTag(TagLib::Tag*, TagLib::AudioProperties*);
        void SetTagLibTag(TagLib::Tag*) const;

    public:
        string FileName(void) const;
        string Artist(void) const;
        string Album(void) const;
        string Title(void) const;
        unsigned int Track(void) const;
        unsigned int Year(void) const;
        string Comment(void) const;
        string Genre(void) const;
        int Bitrate(void) const;
        unsigned int Duration(void) const;
        TagLib::FileRef File(void) const;
        
        RenamerTag(void);
        RenamerTag(const string&);
        RenamerTag* GetCleanTag();
        void Save();
        void Move(const string&);
        //overload the << operator
        string ToString();
        bool Compare(RenamerTag);
};
#endif
