#include "Button.h"

long Button::bn_Clicked(lpWndEventArgs Wea){
    return 0;
}
long Button::bn_Paint(lpWndEventArgs Wea){
    return 0;
}
long Button::bn_Pushed(lpWndEventArgs Wea){
    return 0;
}
long Button::bn_Unpushed(lpWndEventArgs Wea){
    return 0;
}
long Button::bn_Disable(lpWndEventArgs Wea){
    return 0;
}
long Button::bn_Doubleclicked(lpWndEventArgs Wea){
    return 0;
}
long Button::bn_Setfocus(lpWndEventArgs Wea){
    return 0;
}
long Button::bn_Killfocus(lpWndEventArgs Wea){
    return 0;
}

Button::Button(HINSTANCE hi, int cs, HMENU ID): Control_Base(hi, cs, ID){
    m_classname = TEXT("BUTTON");
    m_type = WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON;
    AddInternalEventHandler(BN_CLICKED, &Button::bn_Clicked, m_bn_clicked);
    AddInternalEventHandler(BN_PAINT, &Button::bn_Paint, m_bn_paint);
    AddInternalEventHandler(BN_PUSHED, &Button::bn_Pushed, m_bn_pushed);
    AddInternalEventHandler(BN_UNPUSHED, &Button::bn_Unpushed, m_bn_unpushed);
    AddInternalEventHandler(BN_DISABLE, &Button::bn_Disable, m_bn_disable);
    AddInternalEventHandler(BN_DOUBLECLICKED, &Button::bn_Doubleclicked, m_bn_doubleclicked);
    AddInternalEventHandler(BN_SETFOCUS, &Button::bn_Setfocus, m_bn_setfocus);
    AddInternalEventHandler(BN_KILLFOCUS, &Button::bn_Killfocus, m_bn_killfocus);
}

WINUSERAPI LRESULT WINAPI Button::EventHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
    int wmEvent = HIWORD(wParam);
    lpWndEventArgs Wea = new WndEventArgs();
    Wea->hWnd=hWnd;
    Wea->lParam=lParam;
    Wea->wParam=wParam;
    Wea->message = message;
    switch (message)
    {
        case WM_COMMAND:
            // Parse the menu selections:
            switch(wmEvent){
                case BN_CLICKED: //0
                     return RunEventHandler(bn_clicked, m_bn_clicked, Wea);
                case BN_PAINT: //1
                     return RunEventHandler(bn_paint, m_bn_paint, Wea);
                case BN_PUSHED: //2
                     return RunEventHandler(bn_pushed, m_bn_pushed, Wea);
                case BN_UNPUSHED: //3
                     return RunEventHandler(bn_unpushed, m_bn_unpushed, Wea);
                case BN_DISABLE: //4
                     return RunEventHandler(bn_disable,  m_bn_disable, Wea);
                case BN_DOUBLECLICKED: //5
                     return RunEventHandler(bn_doubleclicked, m_bn_doubleclicked, Wea);
                case BN_SETFOCUS: //6
                     return RunEventHandler(bn_setfocus, m_bn_setfocus, Wea);
                case BN_KILLFOCUS: //7
                     return RunEventHandler(bn_killfocus, m_bn_killfocus, Wea);
            }
            break;
    default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

long Button::RunEventHandler(EVENTLIST &g_list, IEVENTLIST &list, lpWndEventArgs Wea){
    long ret = RunInternalEventHandler(list, Wea);
    ret = ret | RunExternalEventHandler(g_list, Wea);
    ret = ret | DefWindowProc(Wea->hWnd, Wea->message, Wea->wParam, Wea->lParam);
    return ret;
}
long Button::RunInternalEventHandler(IEVENTLIST &list, lpWndEventArgs Wea){
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

void Button::AddInternalEventHandler(unsigned int code, long (Button::*function)(lpWndEventArgs), IEVENTLIST &list){
    IEVENTHANDLER *temp = NULL;
    temp = new IEVENTHANDLER();
    temp->Code = code;
    temp->fnPtr = function;
    list.push_back(*temp);
    delete temp;
}