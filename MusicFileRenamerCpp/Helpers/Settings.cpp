#include "Settings.h"

string Settings::Artist() {
    return "[ARTIST]";
}
string  Settings::Title() { 
    return "[TITLE]";
}
string  Settings::Album() {
    return "[ALBUM]";
}
string  Settings::Track() {
    return "[TRACK]";
}

string Settings::FileNamingConvention() const {return _FileNamingConvention;}
bool Settings::UseAlbumInKey() const { return m_UseAlbumInKey; }
bool Settings::UseTrackInKey() const { return m_UseTrackInKey; }
int Settings::TreeOrder() const { return m_TreeOrder; }
int Settings::UnknownCounter() { return m_UknownCounter++; }

void Settings::UnknownCounter(int value){
    if (value >= 0)
        m_UknownCounter = value;
    else
        m_UknownCounter = 0;
}
void Settings::FileNamingConvention(const string& value){
    string temp = value;
    if (temp.find(Artist()) >= 0
     || temp.find(Track()) >= 0
     || temp.find(Title()) >= 0
     || temp.find(Album()) >= 0)
        _FileNamingConvention = value;
    else{
        _FileNamingConvention = "\\" + Artist() 
                              + "\\" + Album()
                              + "\\" + Artist()
                              + " - " + Title();
    }
}
void Settings::UseAlbumInKey(bool value){
    OrderBy g_OrderBy;
    if (value)
        m_UseAlbumInKey = value;
    else if (m_TreeOrder == g_OrderBy.Album)
        m_UseAlbumInKey = true;
}
void Settings::UseTrackInKey(bool value){
    OrderBy g_OrderBy;
    if (value)
        m_UseTrackInKey = value;
    else if (m_TreeOrder == g_OrderBy.Track)
        m_UseTrackInKey = true;
}
void Settings::TreeOrder(int value) {
    OrderBy g_OrderBy;
    if ((value == g_OrderBy.Album && !UseAlbumInKey())
     || (value == g_OrderBy.Track && !UseTrackInKey()))
        m_TreeOrder = m_TreeOrder;
    else
        m_TreeOrder = value;
}

Settings::Settings(){
    OrderBy g_OrderBy;
    Case g_Case;
    m_TreeOrder = g_OrderBy.Artist;
    m_UseAlbumInKey = false;
    m_UseTrackInKey = false;
    m_UknownCounter = 0;
    _FileNamingConvention  = "\\" + Artist() + "\\" + Album()
                           + "\\" + Artist() + " - " + Title();
    StringCase = g_Case.CamelCase;
    RemoveComments = false;
}

void Settings::Abort(){
    RemoveComments = TempSettings.s_RemoveComments;
    UseAlbumInKey(TempSettings.s_UseAlbumInKey);
    UseTrackInKey(TempSettings.s_UseTrackInKey);
    StringCase = TempSettings.s_StringCase;
    m_TreeOrder = TempSettings.s_TreeOrder;
}
void Settings::Backup(){
    TempSettings.s_RemoveComments = RemoveComments;
    TempSettings.s_UseAlbumInKey = UseAlbumInKey();
    TempSettings.s_UseTrackInKey = UseTrackInKey();
    TempSettings.s_StringCase = StringCase;
    TempSettings.s_TreeOrder = m_TreeOrder;
}
