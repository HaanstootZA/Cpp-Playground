#ifndef TEXTBOX_H
#define	TEXTBOX_H

#include "Control_Base.h"
#include <string>

class TextBox : public Control_Base{
    private:
        struct IEVENTHANDLER{
            unsigned int Code;
            long (TextBox::*fnPtr)(lpWndEventArgs);
        };
        typedef list<IEVENTHANDLER> IEVENTLIST;
        IEVENTLIST m_en_maxtext;
        bool m_canfocus;
        std::string m_text;
        int m_text_limit;
        long En_MaxText(lpWndEventArgs);
        long RunInternalEventHandler(IEVENTLIST&, lpWndEventArgs);
        void AddInternalEventHandler(unsigned int, long (TextBox::*)(lpWndEventArgs), IEVENTLIST&);
    public:
        //get
        int Width(void){return Control_Base::Width();}
        int Height(void){return Control_Base::Height();}
        int X_Position(void){return Control_Base::X_Position();}
        int Y_Position(void){return Control_Base::Y_Position();}
        HWND HWnd(void){return Control_Base::HWnd();}
        HMENU ID(void){return Control_Base::ID();}
        HWND Parent(){return Control_Base::Parent();}
        LPCSTR Text(void);
        bool ReadOnly(void);
        
        void Width(int val){Control_Base::Width(val);}
        void Height(int val){Control_Base::Height(val);}
        void X_Position(int val){Control_Base::X_Position(val);}
        void Y_Position(int val){Control_Base::Y_Position(val);}
        void Parent(HWND val){Control_Base::Parent(val);}
        void Text(LPCSTR);
        LPCSTR AppendText(LPCSTR);
        void ReadOnly(bool val);
        
        TextBox(HINSTANCE, int, HMENU);
        WINUSERAPI LRESULT WINAPI EventHandler(HWND, UINT, WPARAM, LPARAM);
        BOOL InitInstance();
};
#endif	/* TEXTBOX_H */

