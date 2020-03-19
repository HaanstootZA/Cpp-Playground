#include "TagKeyValuePair.h" 

#ifndef TAGNODE_H
#define TAGNODE_H

class TagNode
{
    private:
        TagKeyValuePair _KeyValuePair;
        int AddLeft(TagNode* Node);
        int AddCenter(TagNode* Node);
        int AddRight(TagNode* Node);
        void BaseInit(void);
    public:
        TagNode* _LeftChild;
        TagNode* _CenterChild;
        TagNode* _RightChild;
        
        //Accessor Methods - Get
        TagKeyValuePair KeyValuePair(void) const;
        unsigned long Key(void) const;
        RFile Value(void) const;
        
        //Constructors
        TagNode(void);
        TagNode(const RFile&);
        TagNode(TagKeyValuePair);
        
        int AddNode(TagNode*);
        ~TagNode(void);
};
#endif