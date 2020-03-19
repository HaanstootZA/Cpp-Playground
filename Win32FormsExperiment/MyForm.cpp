#include "MyForm.h"

using namespace std;

MyForm::MyForm(HINSTANCE hi, int cs): Form_Base(hi, cs){}

void MyForm::AddControl(Control_Base* control){
    m_controls.push_back(control);
}

WINUSERAPI LRESULT WINAPI MyForm::MyEventHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
    lpWndEventArgs Wea = new WndEventArgs();
    Wea->hWnd=hWnd;
    Wea->lParam=lParam;
    Wea->wParam=wParam;
    Wea->message = message;
    if(message < 71){
        if(message < 10){
            switch(message)
            {
                case WM_NULL: //0
                    return RunEventHandler(wm_null, m_wm_null, Wea);
                case WM_MOVE: //3
                    return RunEventHandler(wm_move, m_wm_move, Wea);
                case WM_SIZE: //5
                    return RunEventHandler(wm_size, m_wm_size, Wea);
                case WM_SETFOCUS: //7
                    return RunEventHandler(wm_setfocus, m_wm_setfocus, Wea);
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }else if(message < 32){
            switch(message)
            {
                case WM_ENABLE: //10
                    return RunEventHandler(wm_enable, m_wm_enable, Wea);
                case WM_CLOSE: //16
                    return RunEventHandler(wm_close, m_wm_close, Wea);
                case WM_QUIT: //18
                    return RunEventHandler(wm_quit, m_wm_quit, Wea);
                case WM_SHOWWINDOW: //24
                    return RunEventHandler(wm_showwindow, m_wm_showwindow, Wea);
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
                }
        }else if(message < 47){
            switch(message)
            {
                case WM_SETCURSOR: //32
                    return RunEventHandler(wm_setcursor, m_wm_setcursor, Wea);
                case WM_MOUSEACTIVATE: //33
                    return RunEventHandler(wm_mouseactivate, m_wm_mouseactivate, Wea);
                case WM_GETMINMAXINFO: //36
                    return RunEventHandler(wm_getminmaxinfo, m_wm_getminmaxinfo, Wea);
                case WM_PAINTICON: //38
                    return RunEventHandler(wm_painticon, m_wm_painticon, Wea);
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }else{
            switch(message)
            {
                case WM_CHARTOITEM: //47
                    return RunEventHandler(wm_chartoitem, m_wm_chartoitem, Wea);
                case WM_SETHOTKEY: //50
                    return RunEventHandler(wm_sethotkey, m_wm_sethotkey, Wea);
                case WM_GETHOTKEY: //51
                    return RunEventHandler(wm_gethotkey, m_wm_gethotkey, Wea);
                case WM_WINDOWPOSCHANGING: //70
                    return RunEventHandler(wm_windowposchanging, m_wm_windowposchanging, Wea);
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
    }else if(message < 275){
        if(message < 123){
            switch(message)
            {
                case WM_WINDOWPOSCHANGED: //71
                    return RunEventHandler(wm_windowposchanged, m_wm_windowposchanged, Wea);
                case WM_NOTIFY: //78
                    return RunEventHandler(wm_notify, m_wm_notify, Wea);
                case WM_HELP: //83
                    return RunEventHandler(wm_help, m_wm_help, Wea);
                case WM_NOTIFYFORMAT: //85
                    return RunEventHandler(wm_notifyformat, m_wm_notifyformat, Wea);
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }else if(message < 257){
            switch(message)
            {
                case WM_CONTEXTMENU: //123
                    return RunEventHandler(wm_contextmenu, m_wm_contextmenu, Wea);
                case WM_DISPLAYCHANGE: //126
                    return RunEventHandler(wm_displaychange, m_wm_displaychange, Wea);
                case WM_GETICON: //127
                    return RunEventHandler(wm_geticon, m_wm_geticon, Wea);
                case WM_KEYDOWN: //256
                    return RunEventHandler(wm_keydown, m_wm_keydown, Wea);
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }else if(message < 262){
            switch(message)
            {
                case WM_KEYUP: //257
                    return RunEventHandler(wm_keyup, m_wm_keyup, Wea);
                case WM_CHAR: //258
                    return RunEventHandler(wm_char, m_wm_char, Wea);
                case WM_SYSKEYDOWN: //260
                    return RunEventHandler(wm_syskeydown, m_wm_syskeydown, Wea);
                case WM_SYSKEYUP: //261
                    return RunEventHandler(wm_syskeyup, m_wm_syskeyup, Wea);
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }else{
            switch(message)
            {
                case WM_SYSCHAR: //262
                    return RunEventHandler(wm_syschar, m_wm_syschar, Wea);
                case WM_SYSDEADCHAR: //263
                    return RunEventHandler(wm_sysdeadchar, m_wm_sysdeadchar, Wea);
                case WM_COMMAND:
                    return RunEventHandler(wm_command, m_wm_command, Wea);
                case WM_SYSCOMMAND: //274
                    return RunEventHandler(wm_syscommand, m_wm_syscommand, Wea);
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
    }else if(message < 516){
        if(message < 279){
            switch(message)
            {
                case WM_TIMER: //275
                    return RunEventHandler(wm_timer, m_wm_timer, Wea);
                case WM_HSCROLL: //276
                    return RunEventHandler(wm_hscroll, m_wm_hscroll, Wea);
                case WM_VSCROLL: //277
                    return RunEventHandler(wm_vscroll, m_wm_vscroll, Wea);
                case WM_INITMENU: //278
                    return RunEventHandler(wm_initmenu, m_wm_initmenu, Wea);
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }else if(message < 309){
            switch(message)
            {
                case WM_INITMENUPOPUP: //279
                    return RunEventHandler(wm_initmenupopup, m_wm_initmenupopup, Wea);
                case WM_CTLCOLORMSGBOX: //306
                    return RunEventHandler(wm_ctlcolormsgbox, m_wm_ctlcolormsgbox, Wea);
                case WM_CTLCOLOREDIT: //307
                    return RunEventHandler(wm_ctlcoloredit, m_wm_ctlcoloredit, Wea);
                case WM_CTLCOLORLISTBOX: //308
                    return RunEventHandler(wm_ctlcolorlistbox, m_wm_ctlcolorlistbox, Wea);
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }else if(message < 512){
            switch(message)
            {
                case WM_CTLCOLORBTN: //309
                    return RunEventHandler(wm_ctlcolorbtn, m_wm_ctlcolorbtn, Wea);
                case WM_CTLCOLORDLG: //310
                    return RunEventHandler(wm_ctlcolordlg, m_wm_ctlcolordlg, Wea);
                case WM_CTLCOLORSCROLLBAR: //311
                    return RunEventHandler(wm_ctlcolorscrollbar, m_wm_ctlcolorscrollbar, Wea);
                case WM_CTLCOLORSTATIC: //312
                    return RunEventHandler(wm_ctlcolorstatic, m_wm_ctlcolorstatic, Wea);
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }else{
            switch(message)
            {
                case WM_MOUSEMOVE: //512
                    return RunEventHandler(wm_mousemove, m_wm_mousemove, Wea);
                case WM_LBUTTONDOWN: //513
                    return RunEventHandler(wm_lbuttondown, m_wm_lbuttondown, Wea);
                case WM_LBUTTONUP: //514
                    return RunEventHandler(wm_lbuttonup, m_wm_lbuttonup, Wea);
                case WM_LBUTTONDBLCLK: //515
                    return RunEventHandler(wm_lbuttondblclk, m_wm_lbuttondblclk, Wea);
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
    }else if(message < 793){
        if(message < 520){
            switch(message)
            {
                case WM_RBUTTONDOWN: //516
                    return RunEventHandler(wm_rbuttondown, m_wm_rbuttondown, Wea);
                case WM_RBUTTONUP: //517
                    return RunEventHandler(wm_rbuttonup, m_wm_rbuttonup, Wea);
                case WM_RBUTTONDBLCLK: //518
                    return RunEventHandler(wm_rbuttondblclk, m_wm_rbuttondblclk, Wea);
                case WM_MBUTTONDOWN: //519
                    return RunEventHandler(wm_mbuttondown, m_wm_mbuttondown, Wea);
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }else if(message < 536){
            switch(message)
            {
                case WM_MBUTTONUP: //520
                    return RunEventHandler(wm_mbuttonup, m_wm_mbuttonup, Wea);
                case WM_MBUTTONDBLCLK: //521
                    return RunEventHandler(wm_mbuttondblclk, m_wm_mbuttondblclk, Wea);
                case WM_SIZING: //532
                    return RunEventHandler(wm_sizing, m_wm_sizing, Wea);
                case WM_MOVING: //534
                    return RunEventHandler(wm_moving, m_wm_moving, Wea);
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }else if(message < 771){
            switch(message)
            {
                case WM_POWERBROADCAST: //536
                    return RunEventHandler(wm_powerbroadcast, m_wm_powerbroadcast, Wea);
                case WM_DROPFILES: //563
                    return RunEventHandler(wm_dropfiles, m_wm_dropfiles, Wea);
                case WM_MOUSEHOVER: //673
                    return RunEventHandler(wm_mousehover, m_wm_mousehover, Wea);
                case WM_MOUSELEAVE: //675
                    return RunEventHandler(wm_mouseleave, m_wm_mouseleave, Wea);
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }else{
            switch(message)
            {
                case WM_CLEAR: //771
                    return RunEventHandler(wm_clear, m_wm_clear, Wea);
                case WM_HOTKEY: //786
                    return RunEventHandler(wm_hotkey, m_wm_hotkey, Wea);
                case WM_PRINT: //791
                    return RunEventHandler(wm_print, m_wm_print, Wea);
                case WM_PRINTCLIENT: //792
                    return RunEventHandler(wm_printclient, m_wm_printclient, Wea);
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
    }else{
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

WINUSERAPI LRESULT WINAPI MyForm::EventHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
    HMENU wmId = (HMENU)LOWORD(wParam);
    long ret =  MyEventHandler(hWnd, message, wParam, lParam);
    if(wmId != this->ID()){
        list<Control_Base*>::iterator iter = m_controls.begin();
        for(iter;iter != m_controls.end();++iter){
            Control_Base* temp = *iter;
            if((HMENU)wmId == temp->ID()){
                ret = ret | temp->EventHandler(hWnd, message, wParam, lParam);
            }
        }
    }
    return ret;
}

long MyForm::RunEventHandler(EVENTLIST &g_list, IEVENTLIST &list, lpWndEventArgs Wea){
    long ret = RunInternalEventHandler(list, Wea);
    ret = ret | RunExternalEventHandler(g_list, Wea);
    ret = ret | DefWindowProc(Wea->hWnd, Wea->message, Wea->wParam, Wea->lParam);
    return ret;
}
long MyForm::RunInternalEventHandler(IEVENTLIST &list, lpWndEventArgs Wea){
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
void MyForm::AddInternalEventHandler(unsigned int code, long (MyForm::*function)(lpWndEventArgs), IEVENTLIST &list){
    IEVENTHANDLER *temp = NULL;
    temp = new IEVENTHANDLER();
    temp->Code = code;
    temp->fnPtr = function;
    list.push_back(*temp);
    delete temp;
}