#include "Control_Base.h"

//get
int Control_Base::Width(){return m_width;}
int Control_Base::Height(){return m_height;}
int Control_Base::X_Position(){return m_y;}
int Control_Base::Y_Position(){return m_x;}
LPCTSTR Control_Base::Title(){return m_title;}
HWND Control_Base::Parent(){return m_parent;}

//set
void Control_Base::Width(int val){m_width = val;}
void Control_Base::Height(int val){m_height = val;}
void Control_Base::X_Position(int val){m_x = val;}
void Control_Base::Y_Position(int val){m_y = val;}
void Control_Base::Title(LPCTSTR val){m_title = val;}
void Control_Base::Parent(HWND val){m_parent = val;}


Control_Base::Control_Base(HINSTANCE hInstance, int CmdShow, HMENU ID) : FormObject_Base(ID){
    m_ncmdshow = CmdShow;
    m_hIstance = hInstance;
}

BOOL Control_Base::InitInstance(){
    m_hwnd = CreateWindow(
           m_classname,
           m_title,
           m_type,
           m_x,
           m_y,
           m_width,
           m_height,
           m_parent,
           (HMENU)m_id,
           m_hIstance,
           NULL);
    
    if (!m_hwnd)
    {
      return FALSE;
    }
    return TRUE;
}