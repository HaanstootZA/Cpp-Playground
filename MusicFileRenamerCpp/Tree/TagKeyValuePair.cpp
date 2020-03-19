#include "TagKeyValuePair.h"

unsigned long TagKeyValuePair::iKey() const { return _Key.iKey(); }
RFile TagKeyValuePair::Value() const { return _Value; }

void TagKeyValuePair::Swop(TagKeyValuePair& Right){
    RFile ret = _Value;
    _Value = Right._Value;
    Right._Value = ret;
}

TagKeyValuePair::TagKeyValuePair(){}
TagKeyValuePair::TagKeyValuePair(const RFile &Value){
    RFile temp = Value;
    bool corrupt = temp.Corrupt();
    if (!corrupt)
        _Key = temp.Tag();
    _Value = temp;
}

void TagKeyValuePair::GetFileToDelete(TagKeyValuePair& KeyValuePair){
    if (!_Value.isDuplicate)
    {
        if (!_Value.isOriginal)
        {
            RFile temp = KeyValuePair.Value();
            if (!temp.Corrupt() && _Value.Corrupt())
                Swop(KeyValuePair);
            else if (!temp.Corrupt())
            {
                if (temp.Tag().Bitrate() < _Value.Tag().Bitrate())
                    Swop(KeyValuePair);
                else if (temp.Tag().Duration() < _Value.Tag().Duration())
                    Swop(KeyValuePair);
                else if (temp.isOriginal)
                    Swop(KeyValuePair);
            }
        }
        KeyValuePair._Value.isDuplicate = true;
    }
    if(KeyValuePair._Value.isDuplicate)
        KeyValuePair._Value.DuplicateCount = _Value.DuplicateCount + 1;
}

bool TagKeyValuePair::operator ==(const TagKeyValuePair& rhs){
    return _Key == rhs._Key;
}
TagKeyValuePair& TagKeyValuePair::operator=(const TagKeyValuePair &rhs) {
    if (this != &rhs) {
        _Key = rhs._Key;
        _Value = rhs._Value;
    }
    return *this;
}