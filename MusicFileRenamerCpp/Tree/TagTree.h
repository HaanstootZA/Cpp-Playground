#include "TagNode.h"

#ifndef TAGTREE_H
#define TAGTREE_H

class TagTree{
    private:
        TagNode* RootNode;
        int m_Size;

    public:
        TagTree(void);
        int Size(void) const;
        void Push(const RFile&);
        RFile Pop(void);
        ~TagTree(void);
};
#endif