#include <windows.h>
#include <list>
#include "MyForm.h"
#include "Button.h"
#include "TextBox.h"

using namespace std;

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_inst;
int g_cmdshow;
MyForm fb(g_inst, g_cmdshow);
Button* btnArtist;
Button* btnAlbum;
Button* btnTitle;
Button* btnTrack;
Button* btnFolder;
Button* btnDelim;
TextBox* txtTest;
TextBox* txtDelim;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow){
    g_inst = hInstance;
    g_cmdshow = nCmdShow;
    fb.Height(130);
    fb.Width(625);
    fb.Title("Windows Forms");
    
    MSG msg;
    
    fb.RegisterMyClass(WndProc);
    if (!fb.InitInstance())
    {
        return FALSE;
    }
    
    ShowWindow(fb.HWnd(), nCmdShow);
    UpdateWindow(fb.HWnd());
    
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

long btnArtist_OnClick(lpWndEventArgs Wea){
    txtTest->AppendText("[ARTIST]");
}
long btnAlbum_OnClick(lpWndEventArgs Wea){
    txtTest->AppendText("[ALBUM]");
}
long btnTitle_OnClick(lpWndEventArgs Wea){
    txtTest->AppendText("[TITLE]");
}
long btnTrack_OnClick(lpWndEventArgs Wea){
    txtTest->AppendText("[TRACK]");
}
long btnFolder_OnClick(lpWndEventArgs Wea){
    txtTest->AppendText("\\");
}
long btnDelim_OnClick(lpWndEventArgs Wea){
    LPCSTR temp = txtDelim->Text();
    txtTest->AppendText(temp);
}

static void CreateControls(HWND hWnd){
    txtTest = new TextBox(g_inst, g_cmdshow, fb.ID() + 1);
    txtDelim = new TextBox(g_inst, g_cmdshow, fb.ID() + 2);
    btnArtist = new Button(g_inst, g_cmdshow, fb.ID() + 3);
    btnAlbum = new Button(g_inst, g_cmdshow, fb.ID() + 4);
    btnTitle = new Button(g_inst, g_cmdshow, fb.ID() + 5);
    btnTrack = new Button(g_inst, g_cmdshow, fb.ID() + 6);
    btnFolder = new Button(g_inst, g_cmdshow, fb.ID() + 7);
    btnDelim = new Button(g_inst, g_cmdshow, fb.ID() + 8);
    
    txtTest->Height(20);
    txtTest->Width(600);
    txtTest->X_Position(5);
    txtTest->Y_Position(5);
    txtTest->Parent(hWnd);
    txtTest->InitInstance();
    txtTest->Text(TEXT("\\"));
    txtTest->ReadOnly(true);
    
    txtDelim->Height(20);
    txtDelim->Width(20);
    txtDelim->Y_Position(60);
    txtDelim->X_Position(5);
    txtDelim->Parent(hWnd);
    txtDelim->InitInstance();
    txtDelim->Text(TEXT(""));
    
    btnArtist->Height(22);
    btnArtist->Width(60);
    btnArtist->Y_Position(35);
    btnArtist->X_Position(5);
    btnArtist->Text("Artist");
    btnArtist->Parent(hWnd);
    btnArtist->AddEventHandler(BN_CLICKED, &btnArtist_OnClick, btnArtist->bn_clicked);
    
    btnAlbum->Height(22);
    btnAlbum->Width(60);
    btnAlbum->Y_Position(35);
    btnAlbum->X_Position(70);
    btnAlbum->Text("Album");
    btnAlbum->Parent(hWnd);
    btnAlbum->AddEventHandler(BN_CLICKED, &btnAlbum_OnClick, btnAlbum->bn_clicked);
    
    btnTitle->Height(22);
    btnTitle->Width(60);
    btnTitle->Y_Position(35);
    btnTitle->X_Position(135);
    btnTitle->Text("Title");
    btnTitle->Parent(hWnd);
    btnTitle->AddEventHandler(BN_CLICKED, &btnTitle_OnClick, btnTitle->bn_clicked);
    
    btnTrack->Height(22);
    btnTrack->Width(60);
    btnTrack->Y_Position(35);
    btnTrack->X_Position(210);
    btnTrack->Text("Track");
    btnTrack->Parent(hWnd);
    btnTrack->AddEventHandler(BN_CLICKED, &btnTrack_OnClick, btnTrack->bn_clicked);
    
    btnFolder->Height(22);
    btnFolder->Width(100);
    btnFolder->Y_Position(35);
    btnFolder->X_Position(285);
    btnFolder->Text("Folder Split (\\)");
    btnFolder->Parent(hWnd);
    btnFolder->AddEventHandler(BN_CLICKED, &btnFolder_OnClick, btnFolder->bn_clicked);
    
    btnDelim->Height(22);
    btnDelim->Width(100);
    btnDelim->Y_Position(60);
    btnDelim->X_Position(30);
    btnDelim->Text("Delimiter");
    btnDelim->Parent(hWnd);
    btnDelim->AddEventHandler(BN_CLICKED, &btnDelim_OnClick, btnDelim->bn_clicked);
    
    btnArtist->InitInstance();
    btnAlbum->InitInstance();
    btnTitle->InitInstance();
    btnTrack->InitInstance();
    btnFolder->InitInstance();
    btnDelim->InitInstance();
    //This is only nescary for the control to do
    //Event handling
    fb.AddControl(btnArtist);
    fb.AddControl(btnAlbum);
    fb.AddControl(btnTitle);
    fb.AddControl(btnTrack);
    fb.AddControl(btnFolder);
    fb.AddControl(btnDelim);
}

static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
    PAINTSTRUCT ps;
    HDC hdc;
        switch (message)
        {
            case WM_CREATE:
                CreateControls(hWnd);
                break;
            case WM_PAINT:
                hdc = BeginPaint(hWnd, &ps);
                // TODO: Add any drawing code here...
                EndPaint(hWnd, &ps);
                break;
            case WM_DESTROY:
                PostQuitMessage(0);
                break;
            default:
                return fb.EventHandler(hWnd, message, wParam, lParam);
        }
    return 0;
}