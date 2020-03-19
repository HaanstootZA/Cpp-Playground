#include "TagNode.h"

TagKeyValuePair TagNode::KeyValuePair(void) const { return _KeyValuePair; }
unsigned long TagNode::Key() const { return _KeyValuePair.iKey(); }
RFile TagNode::Value() const { return _KeyValuePair.Value(); }

int TagNode::AddLeft(TagNode* Node){
    if (_LeftChild == NULL)
    {
        _LeftChild = Node;
        return 1;
    }
    else
        return _LeftChild->AddNode(Node);
}
int TagNode::AddCenter(TagNode* Node){
    if (_KeyValuePair == Node->KeyValuePair())
    {
        _KeyValuePair.GetFileToDelete(Node->_KeyValuePair);
    }
    if (_CenterChild == NULL)
    {
        _CenterChild = Node;
        return 1;
    }
    else
        return _CenterChild->AddNode(Node);
}
int TagNode::AddRight(TagNode* Node){
    if (_RightChild == NULL)
    {
        _RightChild = Node;
        return 1;
    }
    else
        return _RightChild->AddNode(Node);
}
void TagNode::BaseInit(){
    _LeftChild = NULL;
    _CenterChild = NULL;
    _RightChild = NULL;
}

TagNode::TagNode(){
    BaseInit();
}
TagNode::TagNode(TagKeyValuePair KeyValuePair){
    BaseInit();
    _KeyValuePair = KeyValuePair;
}
TagNode::TagNode(const RFile& Value){
    BaseInit();
    _KeyValuePair = TagKeyValuePair(Value);
}

int TagNode::AddNode(TagNode* Node){
    if(Node != NULL){
        if(Key() == Node->Key()){ return AddCenter(Node); }
        else{
            unsigned long val1 = Node->Key();
            unsigned long val2 = Key();
            unsigned long diff = ((val1 - val2)/2);
            if (diff > val1)
                return AddRight(Node);
            else if (diff <= val1)
                return AddLeft(Node);
        }
    }
    return 0;
}
TagNode::~TagNode(){
    if(_LeftChild != NULL)
        delete _LeftChild;
    if(_CenterChild != NULL)
        delete _CenterChild;
    if(_RightChild != NULL)
        delete _RightChild;
}