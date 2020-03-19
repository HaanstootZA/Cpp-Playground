#ifndef BUTTON_H
#define	BUTTON_H

#include "Control_Base.h"

class Button : public Control_Base{
    private:
        bool m_fittotext;
        struct IEVENTHANDLER{
            unsigned int Code;
            long (Button::*fnPtr)(lpWndEventArgs);
        };
        typedef list<IEVENTHANDLER> IEVENTLIST;
        IEVENTLIST m_bn_clicked;
        IEVENTLIST m_bn_paint;
        IEVENTLIST m_bn_pushed;
        IEVENTLIST m_bn_unpushed;
        IEVENTLIST m_bn_disable;
        IEVENTLIST m_bn_doubleclicked;
        IEVENTLIST m_bn_setfocus;
        IEVENTLIST m_bn_killfocus;
        long bn_Clicked(lpWndEventArgs);
        long bn_Paint(lpWndEventArgs);
        long bn_Pushed(lpWndEventArgs);
        long bn_Unpushed(lpWndEventArgs);
        long bn_Disable(lpWndEventArgs);
        long bn_Doubleclicked(lpWndEventArgs);
        long bn_Setfocus(lpWndEventArgs);
        long bn_Killfocus(lpWndEventArgs);
        long RunInternalEventHandler(IEVENTLIST&, lpWndEventArgs);
        void AddInternalEventHandler(unsigned int, long (Button::*)(lpWndEventArgs), IEVENTLIST&);
        long RunEventHandler(EVENTLIST&, IEVENTLIST&, lpWndEventArgs);
    public:
        EVENTLIST bn_clicked;
        EVENTLIST bn_paint;
        EVENTLIST bn_pushed;
        EVENTLIST bn_unpushed;
        EVENTLIST bn_disable;
        EVENTLIST bn_doubleclicked;
        EVENTLIST bn_setfocus;
        EVENTLIST bn_killfocus;
        //get
        int Width(void){return Control_Base::Width();}
        int Height(void){return Control_Base::Height();}
        int X_Position(void){return Control_Base::X_Position();}
        int Y_Position(void){return Control_Base::Y_Position();}
        LPCTSTR Text(void){return Control_Base::Title();}
        HWND HWnd(void){return Control_Base::HWnd();}
        HMENU ID(void){return Control_Base::ID();}
        HWND Parent(){return Control_Base::Parent();}
        
        void Width(int val){Control_Base::Width(val);}
        void Height(int val){Control_Base::Height(val);}
        void X_Position(int val){Control_Base::X_Position(val);}
        void Y_Position(int val){Control_Base::Y_Position(val);}
        void Parent(HWND val){Control_Base::Parent(val);}
        void Text(LPCSTR val){Control_Base::Title(val);}
        
        Button(HINSTANCE, int, HMENU);        
        WINUSERAPI LRESULT WINAPI EventHandler(HWND, UINT, WPARAM, LPARAM);
};

#endif	/* BUTTON_H */