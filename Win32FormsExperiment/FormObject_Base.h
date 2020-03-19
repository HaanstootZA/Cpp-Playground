#ifndef FORMOBJECT_BASE_H
#define	FORMOBJECT_BASE_H

#include <windowsx.h>
#include <windows.h>
#include <list>

using std::list;

typedef struct WindowsEventArguments{
    HWND hWnd;
    WPARAM wParam;
    LPARAM lParam;
    UINT message;
} WndEventArgs, *lpWndEventArgs;
struct EVENTHANDLER{
    unsigned int Code;
    long (*fnPtr)(lpWndEventArgs);
};
typedef list<EVENTHANDLER> EVENTLIST;

class FormObject_Base{
    protected:
        int m_ncmdshow;
        HWND m_hwnd;
        HMENU m_id;
        
        int m_width;
        int m_height;
        int m_x;
        int m_y;
        LPCTSTR m_title;
        LPCTSTR m_name;
        LPCTSTR m_classname;
        HINSTANCE m_hIstance;
        HWND m_parent;
    public:
        HWND HWnd(void);
        HMENU ID(void);
        
        FormObject_Base(HMENU);
        
        void AddEventHandler(unsigned int, long (*)(lpWndEventArgs), EVENTLIST&);
        long RunExternalEventHandler(EVENTLIST&, lpWndEventArgs);
        /**
         *@Description
         * In this function, we save the instance handle in a global variable and
         * create and display the main program window.
         *@CreateWindow() Function Paramaters
         * HWND WINAPI CreateWindow(
         * LPCTSTR lpClassName,LPCTSTR lpWindowName,
         * DWORD dwStyle,int x_position,
         * int y_position,
         * int nWidth, int nHeight,
         * HWND hWndParent, HMENU hMenu,
         * HINSTANCE hInstance, LPVOID lpParam)
         *@Return 
         * BOOL - Successful
         */
        virtual BOOL InitInstance(){ return (0);}
        virtual WINUSERAPI LRESULT WINAPI EventHandler(HWND hWnd, UINT message,
                                          WPARAM wParam,LPARAM lParam){
            return DefWindowProc(hWnd, message, wParam, lParam);}
};

#endif	/* FORMOBJECT_BASE_H */

