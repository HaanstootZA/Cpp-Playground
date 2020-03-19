#include "TextBox.h"

LPCSTR TextBox::Text(){
    LPSTR temp = new char[Edit_GetTextLength(m_hwnd) + 1];
    Edit_GetText(m_hwnd, temp, Edit_GetTextLength(m_hwnd) + 1);
    return temp;
}
void TextBox::Text(LPCSTR val){
    m_text = val;
    if(m_hwnd == NULL)
        Title(m_text.c_str());
    else
        Edit_SetText(m_hwnd, const_cast<char*>(m_text.c_str()));
}
LPCSTR TextBox::AppendText(LPCSTR val){
    m_text += val;
    Edit_SetText(m_hwnd, const_cast<char*>(m_text.c_str()));
    return m_text.c_str();
}

bool TextBox::ReadOnly(){
    return m_canfocus;
}
void TextBox::ReadOnly(bool val){
    m_canfocus = val;
    Edit_SetReadOnly(m_hwnd, val);
}

long TextBox::En_MaxText(lpWndEventArgs Wea){
     m_text_limit += 1000;
     Edit_LimitText(m_hwnd, m_text_limit);
}
TextBox::TextBox(HINSTANCE hi, int cs, HMENU ID): Control_Base(hi, cs, ID){
    m_classname = TEXT("Edit");
    m_type = WS_CHILD|WS_VISIBLE|WS_BORDER;
    AddInternalEventHandler(EN_MAXTEXT, &TextBox::En_MaxText, m_en_maxtext);
}

long TextBox::RunInternalEventHandler(IEVENTLIST &list, lpWndEventArgs Wea){
    long result = 0;
    IEVENTHANDLER *temp = NULL;
    for(IEVENTLIST::iterator iter = list.begin(); iter != list.end(); ++iter){
        temp = &(*iter);
        result = result | (this->*temp->fnPtr)(Wea);
        delete temp;
        temp = NULL;
    }
    return result;
}
void TextBox::AddInternalEventHandler(unsigned int code, long (TextBox::*function)(lpWndEventArgs), IEVENTLIST &list){
    IEVENTHANDLER *temp = NULL;
    temp = new IEVENTHANDLER();
    temp->Code = code;
    temp->fnPtr = function;
    list.push_back(*temp);
    delete temp;
}

WINUSERAPI LRESULT WINAPI TextBox::EventHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
    lpWndEventArgs Wea = new WndEventArgs();
    Wea->hWnd=hWnd;
    Wea->lParam=lParam;
    Wea->wParam=wParam;
    Wea->message = message;
    switch(message){
        case EN_MAXTEXT:
            RunInternalEventHandler(m_en_maxtext, Wea);
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
BOOL TextBox::InitInstance(){
     Control_Base::InitInstance();
     m_text_limit = 1000;
     Edit_LimitText(m_hwnd, m_text_limit);
     
}