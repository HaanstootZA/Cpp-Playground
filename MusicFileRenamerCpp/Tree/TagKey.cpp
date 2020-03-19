#include "TagKey.h"

using namespace std;

unsigned long TagKey::StringToInt(const string& Value){
    unsigned long ret = 0;
    string val = Value;
    g_Stringcleaner.RemoveChar(val, ' ');
    for(unsigned int i = 0; i < val.length(); i++)
    {
        char c = Value[i];
        int temp = c;
        while (temp > 0)
        {
            ret = ret * 10;
            temp = temp / 10;
        }
        ret += c;
    }
    return ret;
}

string TagKey::Key() const {
    string ret = ::ToCharP<int>(_Artist);
    if(g_SettingsValue.UseAlbumInKey()){
        ret += "-" + ::ToString<int>(_Album);
    }
    ret += "-" + ::ToString<int>(_Title);
    if(g_SettingsValue.UseTrackInKey()){
        ret += "-" + ::ToString<int>(_Track);
    }
    return ret;
}

unsigned long TagKey::iKey() const{
    OrderBy g_OrderBy;
    int CurrentOrder = g_SettingsValue.TreeOrder();
    if( CurrentOrder == g_OrderBy.Artist)
        return _Artist;
    else if(CurrentOrder == g_OrderBy.Title)
        return _Title;
    else if(CurrentOrder == g_OrderBy.Album)
        return _Album;
    else if(CurrentOrder == g_OrderBy.Track)
        return _Track;
    else
        return _Artist;
}

TagKey::TagKey(){
    string Unknown = "Unknown";
    _Artist = StringToInt(Unknown);
    _Album = StringToInt(Unknown);
    _Title = StringToInt(Unknown);
    _Track = 0;
}

TagKey::TagKey(const RenamerTag &Tag){
    string Unknown = "Unknown";
    RenamerTag temp = Tag;
    if (temp.Artist() == "")
        _Artist = StringToInt(Unknown);
    else
        _Artist = StringToInt(temp.Artist());
    if (temp.Album() == "")
        _Album = StringToInt(Unknown);
    else
        _Album = StringToInt(temp.Album());
    if (temp.Title() == "")
        _Title = StringToInt(Unknown);
    else
        _Title = StringToInt(temp.Title());

    _Track = temp.Track();
}

bool TagKey::operator == (const TagKey& rhs){
    bool ret = (_Artist == rhs._Artist && _Title == rhs._Title);
    if(g_SettingsValue.UseAlbumInKey())
        ret = ret && _Album == rhs._Album;
    if(g_SettingsValue.UseTrackInKey())
        ret = ret && _Track == rhs._Track;
    return ret;
}
TagKey& TagKey::operator=(const TagKey &rhs) {
    if (this != &rhs) {
        _Artist = rhs._Artist;
        _Album = rhs._Album;
        _Title = rhs._Title;
        _Track = rhs._Track;
    }
    return *this;
}