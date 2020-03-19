#ifndef MYFORM_H
#define	MYFORM_H

#include "Form_Base.h"
#include "Control_Base.h"

class MyForm : public Form_Base{
    private:
        struct IEVENTHANDLER{
            unsigned int Code;
            long (MyForm::*fnPtr)(lpWndEventArgs);
        };
        typedef list<IEVENTHANDLER> IEVENTLIST;
        IEVENTLIST m_wm_null;
        IEVENTLIST m_wm_move;
        IEVENTLIST m_wm_size;
        IEVENTLIST m_wm_setfocus;
        IEVENTLIST m_wm_enable;
        IEVENTLIST m_wm_close;
        IEVENTLIST m_wm_quit;
        IEVENTLIST m_wm_showwindow;
        IEVENTLIST m_wm_setcursor;
        IEVENTLIST m_wm_mouseactivate;
        IEVENTLIST m_wm_getminmaxinfo;
        IEVENTLIST m_wm_painticon;
        IEVENTLIST m_wm_chartoitem;
        IEVENTLIST m_wm_sethotkey;
        IEVENTLIST m_wm_gethotkey;
        IEVENTLIST m_wm_windowposchanging;
        IEVENTLIST m_wm_windowposchanged;
        IEVENTLIST m_wm_notify;
        IEVENTLIST m_wm_help;
        IEVENTLIST m_wm_notifyformat;
        IEVENTLIST m_wm_contextmenu;
        IEVENTLIST m_wm_displaychange;
        IEVENTLIST m_wm_geticon;
        IEVENTLIST m_wm_keydown;
        IEVENTLIST m_wm_keyup;
        IEVENTLIST m_wm_char;
        IEVENTLIST m_wm_syskeydown;
        IEVENTLIST m_wm_syskeyup;
        IEVENTLIST m_wm_syschar;
        IEVENTLIST m_wm_sysdeadchar;
        IEVENTLIST m_wm_command;
        IEVENTLIST m_wm_syscommand;
        IEVENTLIST m_wm_timer;
        IEVENTLIST m_wm_hscroll;
        IEVENTLIST m_wm_vscroll;
        IEVENTLIST m_wm_initmenu;
        IEVENTLIST m_wm_initmenupopup;
        IEVENTLIST m_wm_ctlcolormsgbox;
        IEVENTLIST m_wm_ctlcoloredit;
        IEVENTLIST m_wm_ctlcolorlistbox;
        IEVENTLIST m_wm_ctlcolorbtn;
        IEVENTLIST m_wm_ctlcolordlg;
        IEVENTLIST m_wm_ctlcolorscrollbar;
        IEVENTLIST m_wm_ctlcolorstatic;
        IEVENTLIST m_wm_mousemove;
        IEVENTLIST m_wm_lbuttondown;
        IEVENTLIST m_wm_lbuttonup;
        IEVENTLIST m_wm_lbuttondblclk;
        IEVENTLIST m_wm_rbuttondown;
        IEVENTLIST m_wm_rbuttonup;
        IEVENTLIST m_wm_rbuttondblclk;
        IEVENTLIST m_wm_mbuttondown;
        IEVENTLIST m_wm_mbuttonup;
        IEVENTLIST m_wm_mbuttondblclk;
        IEVENTLIST m_wm_sizing;
        IEVENTLIST m_wm_moving;
        IEVENTLIST m_wm_powerbroadcast;
        IEVENTLIST m_wm_dropfiles;
        IEVENTLIST m_wm_mousehover;
        IEVENTLIST m_wm_mouseleave;
        IEVENTLIST m_wm_clear;
        IEVENTLIST m_wm_hotkey;
        IEVENTLIST m_wm_print;
        IEVENTLIST m_wm_printclient;
        list<Control_Base*> m_controls;
        WINUSERAPI LRESULT WINAPI MyEventHandler(HWND, UINT, WPARAM, LPARAM);
        long RunEventHandler(EVENTLIST&, IEVENTLIST&, lpWndEventArgs);
        long RunInternalEventHandler(IEVENTLIST&, lpWndEventArgs);
        void AddInternalEventHandler(unsigned int, long (MyForm::*)(lpWndEventArgs), IEVENTLIST&);
    public:
        EVENTLIST wm_null;
        EVENTLIST wm_move;
        EVENTLIST wm_size;
        EVENTLIST wm_setfocus;
        EVENTLIST wm_enable;
        EVENTLIST wm_close;
        EVENTLIST wm_quit;
        EVENTLIST wm_showwindow;
        EVENTLIST wm_setcursor;
        EVENTLIST wm_mouseactivate;
        EVENTLIST wm_getminmaxinfo;
        EVENTLIST wm_painticon;
        EVENTLIST wm_chartoitem;
        EVENTLIST wm_sethotkey;
        EVENTLIST wm_gethotkey;
        EVENTLIST wm_windowposchanging;
        EVENTLIST wm_windowposchanged;
        EVENTLIST wm_notify;
        EVENTLIST wm_help;
        EVENTLIST wm_notifyformat;
        EVENTLIST wm_contextmenu;
        EVENTLIST wm_displaychange;
        EVENTLIST wm_geticon;
        EVENTLIST wm_keydown;
        EVENTLIST wm_keyup;
        EVENTLIST wm_char;
        EVENTLIST wm_syskeydown;
        EVENTLIST wm_syskeyup;
        EVENTLIST wm_syschar;
        EVENTLIST wm_sysdeadchar;
        EVENTLIST wm_command;
        EVENTLIST wm_syscommand;
        EVENTLIST wm_timer;
        EVENTLIST wm_hscroll;
        EVENTLIST wm_vscroll;
        EVENTLIST wm_initmenu;
        EVENTLIST wm_initmenupopup;
        EVENTLIST wm_ctlcolormsgbox;
        EVENTLIST wm_ctlcoloredit;
        EVENTLIST wm_ctlcolorlistbox;
        EVENTLIST wm_ctlcolorbtn;
        EVENTLIST wm_ctlcolordlg;
        EVENTLIST wm_ctlcolorscrollbar;
        EVENTLIST wm_ctlcolorstatic;
        EVENTLIST wm_mousemove;
        EVENTLIST wm_lbuttondown;
        EVENTLIST wm_lbuttonup;
        EVENTLIST wm_lbuttondblclk;
        EVENTLIST wm_rbuttondown;
        EVENTLIST wm_rbuttonup;
        EVENTLIST wm_rbuttondblclk;
        EVENTLIST wm_mbuttondown;
        EVENTLIST wm_mbuttonup;
        EVENTLIST wm_mbuttondblclk;
        EVENTLIST wm_sizing;
        EVENTLIST wm_moving;
        EVENTLIST wm_powerbroadcast;
        EVENTLIST wm_dropfiles;
        EVENTLIST wm_mousehover;
        EVENTLIST wm_mouseleave;
        EVENTLIST wm_clear;
        EVENTLIST wm_hotkey;
        EVENTLIST wm_print;
        EVENTLIST wm_printclient;
        void Height(int val){Form_Base::Height(val);}
        void Width(int val){Form_Base::Width(val);}
        HWND HWnd(void){return Form_Base::HWnd();}
        void Title(LPCSTR val){Form_Base::Title(val);}
        
        void AddControl(Control_Base*);
        MyForm(HINSTANCE, int);
        WINUSERAPI LRESULT WINAPI EventHandler(HWND, UINT, WPARAM, LPARAM);
};

#endif	/* MYFORM_H */