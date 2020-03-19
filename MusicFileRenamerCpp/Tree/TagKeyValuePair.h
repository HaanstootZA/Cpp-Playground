#include "TagKey.h"
#include "../File/RFile.h"

#ifndef TAGKEYVALUEPAIR_H
#define TAGKEYVALUEPAIR_H

class TagKeyValuePair
{
    private:
        TagKey _Key;
        RFile _Value;
        void Swop(TagKeyValuePair&);
    public:
        unsigned long iKey(void) const;
        RFile Value(void) const;
        
        TagKeyValuePair(void);
        TagKeyValuePair(const RFile&);
        void GetFileToDelete(TagKeyValuePair&);
        
        bool operator==(const TagKeyValuePair&);
        TagKeyValuePair& operator=(const TagKeyValuePair &rhs);
};
#endif