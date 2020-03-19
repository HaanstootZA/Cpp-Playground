#include "FormObject_Base.h"

HWND FormObject_Base::HWnd(){return m_hwnd;}
HMENU FormObject_Base::ID(){return m_id;}

FormObject_Base::FormObject_Base(HMENU ID){
    m_width = 10;
    m_height = 10;
    m_x = 0;
    m_y = 0;
    m_id = ID;
    m_title = TEXT("FormObject_Base");
    m_classname = TEXT("FormObject_Base");
    m_hIstance = NULL;
    m_hwnd = NULL;
}

void FormObject_Base::AddEventHandler(unsigned int code, long (*function)(lpWndEventArgs), EVENTLIST& list){
    EVENTHANDLER *temp = NULL;
    temp = new EVENTHANDLER();
    temp->Code = code;
    temp->fnPtr = function;
    list.push_back(*temp);
    delete temp;
}

long FormObject_Base::RunExternalEventHandler(EVENTLIST &list, lpWndEventArgs Wea){
    long result = 0;
    EVENTHANDLER *temp = NULL;
    for(EVENTLIST::iterator iter = list.begin(); iter != list.end(); ++iter){
        temp = &(*iter);
        result = result | (temp->fnPtr)(Wea);
        delete temp;
        temp = NULL;
    }
    return result;
}