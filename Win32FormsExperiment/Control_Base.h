#ifndef CONTROL_BASE_H
#define	CONTROL_BASE_H

#include "FormObject_Base.h"
#include "commctrl.h"

class Control_Base : public FormObject_Base{ 
    protected:
        DWORD m_type;
        //get
        int Width(void);
        int Height(void);
        int X_Position(void);
        int Y_Position(void);
        LPCTSTR Title(void);
        HWND HWnd(void){return FormObject_Base::HWnd();}
        HWND Parent(void);
        
        //set
        void Width(int);
        void Height(int);
        void X_Position(int);
        void Y_Position(int);
        void Title(LPCTSTR);
        void Parent(HWND);
        
        Control_Base(HINSTANCE, int, HMENU);
    public:
        HMENU ID(void){return FormObject_Base::ID();}
        BOOL InitInstance();
        virtual WINUSERAPI LRESULT WINAPI EventHandler(HWND, UINT, WPARAM, LPARAM){return(0);}
};

#endif	/* CONTROL_BASE_H */

