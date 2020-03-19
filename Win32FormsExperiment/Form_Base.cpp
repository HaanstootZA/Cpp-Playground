#include "Form_Base.h"
using namespace std;
//get
int Form_Base::Width(){return m_width;}
int Form_Base::Height(){return m_height;}
int Form_Base::X_Position(){return m_y;}
int Form_Base::Y_Position(){return m_x;}
LPCTSTR Form_Base::Title(){return m_title;}
HWND Form_Base::Parent(){return m_parent;}
HMENU Form_Base::Menu(){return m_menu;}
LPCTSTR Form_Base::MenuName(){return m_menuname;}

//set
void Form_Base::Width(int val){m_width = val;}
void Form_Base::Height(int val){m_height = val;}
void Form_Base::X_Position(int val){m_x = val;}
void Form_Base::Y_Position(int val){m_y = val;}
void Form_Base::Title(LPCTSTR val){m_title = val;}
void Form_Base::Menu(HMENU val){m_menu = val;}
void Form_Base::MenuName(LPCTSTR val){m_menuname = val;}

Form_Base::Form_Base(HINSTANCE hInstance, int CmdShow) : FormObject_Base(NULL){
    m_ncmdshow = CmdShow;
    m_hIstance = hInstance;
    m_hwnd = NULL;
    
    m_parent = NULL;
    m_menu = NULL;
    m_menuname = 0;
    m_title = "Window";
}
Form_Base::Form_Base(HINSTANCE hInstance, int CmdShow, HWND Parent) : FormObject_Base(NULL){
    m_ncmdshow = CmdShow;
    m_hIstance = hInstance;
    m_hwnd = NULL;
    
    m_parent = Parent;
    m_menu = NULL;
    m_menuname = 0;
    m_title = "Window";
}
Form_Base::Form_Base(HINSTANCE hInstance, int CmdShow, HWND Parent, HMENU Menu, LPCTSTR MenuName) : FormObject_Base(NULL){
    m_ncmdshow = CmdShow;
    m_hIstance = hInstance;
    m_hwnd = NULL;
    
    m_parent = Parent;
    m_menu = Menu;
    m_menuname = MenuName;
    m_title = "Window";
}

ATOM Form_Base::RegisterMyClass(WNDPROC WndProc){
    WNDCLASSEX wcex;
    //Window structures   
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS; //Catch redraw, and double clicks
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = m_hIstance;
    wcex.hbrBackground = CreateSolidBrush(RGB(228, 248, 239));
    wcex.lpszMenuName = m_menuname;
    wcex.lpszClassName = m_classname;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION); //Default Icon
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION); //Default Icon
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);

    return RegisterClassEx(&wcex);
}
   
BOOL Form_Base::InitInstance(){
    m_hwnd = CreateWindow(
           m_classname,
           m_title,
           WS_OVERLAPPEDWINDOW,
           m_x,
           m_y,
           m_width,
           m_height,
           m_parent,
           m_menu,
           m_hIstance,
           NULL);
    
    if (!m_hwnd)
    {
      return FALSE;
    }
    return TRUE;
}