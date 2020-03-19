#ifndef FORM_BASE_H
#define	FORM_BASE_H

#include "Control_Base.h"

class Form_Base : public FormObject_Base{ 
    private:
        HMENU m_menu;
        LPCTSTR m_menuname;
    protected:
        //get
        int Width(void);
        int Height(void);
        int X_Position(void);
        int Y_Position(void);
        LPCTSTR Title(void);
        HWND HWnd(void){return FormObject_Base::HWnd();}
        HWND Parent(void);
        HMENU Menu(void);
        LPCTSTR MenuName(void);
        
        //set
        void Width(int);
        void Height(int);
        void X_Position(int);
        void Y_Position(int);
        void Title(LPCTSTR);
        void Menu(HMENU);
        void MenuName(LPCTSTR);
        
        Form_Base(HINSTANCE, int);
        Form_Base(HINSTANCE, int, HWND);
        Form_Base(HINSTANCE, int, HWND, HMENU, LPCTSTR);
        
    public:
        /**
         *@Desciprtion
         * Registers the window class within windows
         */
        ATOM RegisterMyClass(WNDPROC);
        BOOL InitInstance();
        virtual WINUSERAPI LRESULT WINAPI EventHandler(HWND, UINT, WPARAM, LPARAM){return(0);}
};
#endif	/* FORM_H */