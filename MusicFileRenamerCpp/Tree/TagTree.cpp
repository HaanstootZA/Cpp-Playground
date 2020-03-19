#include "TagTree.h"
TagTree::TagTree(){
    RootNode = NULL;
    m_Size = 0;
}

int TagTree::Size() const { return m_Size; }

void TagTree::Push(const RFile &Value){
    TagNode* Node = new TagNode(Value);
    if (RootNode == NULL)
    {
        RootNode = Node;
        m_Size++;
    }
    else
        m_Size += RootNode->AddNode(Node);
    //delete Node;
}

RFile TagTree::Pop(){
    RFile ret;
    if (m_Size > 0)
    {
        TagNode* TempNode = RootNode;
        ret = RFile(TempNode->KeyValuePair().Value());
        if (RootNode->_CenterChild != NULL)
        {
            RootNode = TempNode->_CenterChild;
            TempNode->_CenterChild = NULL;
            
            RootNode->AddNode(TempNode->_LeftChild);
            TempNode->_LeftChild = NULL;
            
            RootNode->AddNode(TempNode->_RightChild);
            TempNode->_RightChild = NULL;
        }
        else if (RootNode->_LeftChild != NULL)
        {
            RootNode = TempNode->_LeftChild;
            TempNode->_LeftChild = NULL;
            
            RootNode->AddNode(TempNode->_RightChild);
            TempNode->_RightChild = NULL;
        }
        else if (RootNode->_RightChild != NULL)
        {
            RootNode = TempNode->_RightChild;
            TempNode->_RightChild = NULL;
        }
        else
            RootNode = NULL;
        m_Size--;
        
        delete TempNode;
    }
    return ret;
}

TagTree::~TagTree(){
    while(m_Size > 0){
        Pop();
    }
    if(RootNode != NULL)
    delete RootNode;
}