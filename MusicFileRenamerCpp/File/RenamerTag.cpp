#include "RenamerTag.h"

void RenamerTag::SetTag(TagLib::Tag *Tag, TagLib::AudioProperties *Properties){
    if (Tag != NULL)
    {
        m_Artist = Tag->artist().toCString(true);
        m_Album = Tag->album().toCString(true);
        m_Title = Tag->title().toCString(true);
        m_Track = Tag->track();
        m_Year = Tag->year();
        m_Comment = Tag->comment().toCString(true);
        m_Genre = Tag->genre().toCString(true);
    }
    if(Properties != NULL){
        m_Bitrate = Properties->bitrate();
        m_Duration = Properties->length();
    }
}
void RenamerTag::SetTagLibTag(TagLib::Tag* tag) const{
    if(tag != NULL) {
        tag->setArtist(m_Artist);
        tag->setAlbum(m_Album);
        tag->setTitle(m_Title);
        tag->setTrack(m_Track);
        tag->setYear(m_Year);
        tag->setComment(m_Comment);
        tag->setGenre(m_Genre);
    }
}


string RenamerTag::FileName() const {return m_FileName;}
string RenamerTag::Artist() const { return m_Artist; }
string RenamerTag::Album() const { return m_Album; }
string RenamerTag::Title() const { return m_Title; }
unsigned int RenamerTag::Track() const { return m_Track; }
unsigned int RenamerTag::Year() const { return m_Year; }
string RenamerTag::Comment() const { return m_Comment; }
string RenamerTag::Genre() const { return m_Genre; }
int RenamerTag::Bitrate() const { return m_Bitrate; }
unsigned int RenamerTag::Duration() const { return m_Duration; }

TagLib::FileRef RenamerTag::File() const{
    TagLib::FileName fName(m_FileName.c_str());
    TagLib::FileRef ret(fName, true, TagLib::AudioProperties::Accurate);
    SetTagLibTag(ret.tag());
    return ret;
}

RenamerTag::RenamerTag(){
    m_FileName = "";
    m_Artist = "";
    m_Album = "";
    m_Title = "";
    m_Track = 0;
    m_Year = 0;
    m_Comment = "";
    m_Genre = "";
    m_Bitrate = 0;
    m_Duration = 0;
}
RenamerTag::RenamerTag(const string& FileName){
    m_FileName = FileName;
    TagLib::FileName fName(m_FileName.c_str());
    TagLib::FileRef temp(fName, true, TagLib::AudioProperties::Accurate);
    SetTag(temp.tag(), temp.audioProperties());
}

RenamerTag* RenamerTag::GetCleanTag(){
    string Unknown = "Unknown";
    string UnknownTrack = "Unknown_Track_";
    RenamerTag *NewTag = new RenamerTag(m_FileName);
    if (m_Artist == "")
    {
        NewTag->m_Artist = Unknown;
    }
    if (m_Title == "")
    {
        NewTag->m_Title =UnknownTrack + ::ToString<int>(g_SettingsValue.UnknownCounter());
    }
    if (m_Album == "")
    {
        NewTag->m_Album = Unknown;
    }

    NewTag->m_Artist = g_Stringcleaner.CleanString(
            g_Stringcleaner.ChangeCase(NewTag->m_Artist, g_SettingsValue.StringCase));
    NewTag->m_Album = g_Stringcleaner.CleanString(
            g_Stringcleaner.ChangeCase(NewTag->m_Album, g_SettingsValue.StringCase));
    NewTag->m_Title = g_Stringcleaner.CleanString(
            g_Stringcleaner.ChangeCase(NewTag->m_Title, g_SettingsValue.StringCase));
    if (g_SettingsValue.RemoveComments)
        NewTag->m_Comment = '\0';
    return NewTag;
}

void RenamerTag::Save(){
    TagLib::FileRef save = File();
    save.save();
}

void RenamerTag::Move(const string& NewFile){
    boost::filesystem::rename(m_FileName, NewFile);
    m_FileName = NewFile;
}

//Transform into stream operator
string RenamerTag::ToString(){
    return m_FileName;
}

//transform into == operator
bool RenamerTag::Compare(RenamerTag NewTag){
    if (m_Title != NewTag.m_Title)
        return false;
    if (m_Album != NewTag.m_Album)
        return false;
    if (m_Track != NewTag.m_Track)
        return false;
    if (m_Year != NewTag.m_Year)
        return false;
    if (m_Comment != NewTag.m_Comment)
        return false;
    if (m_Artist != NewTag.m_Artist)
        return false;
    if (m_Genre != NewTag.m_Genre)
        return false;
    return true;
}