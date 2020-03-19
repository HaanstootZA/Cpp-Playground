#include <cstdlib>
#include <iostream>
#include <string.h>
#include <windows.h>
#include <windowsx.h>
#include <winuser.h>
#include <list>
#include <algorithm>

using namespace std;

class kv_pair{
    public:
        string command;
        int value;
        kv_pair(string s, int val){
            command = s;
            value = val;
        }
        bool operator <(const kv_pair &rhs){
            return value < rhs.value;
        }
        bool operator >(const kv_pair &rhs){
            return value > rhs.value;
        }
        bool operator ==(const kv_pair &rhs){
            return value == rhs.value;
        }
};

string ToLower(const string& value){
    string ret = value;
    transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
    return ret;
}

string ToUpper(const string& value){
    string ret = value;
    transform(ret.begin(), ret.end(), ret.begin(), ::toupper);
    return ret;
}

int main(int argc, char** argv) {
    kv_pair *pair;
    list<kv_pair> kv_list;
    pair = new kv_pair("EN_ALIGN_LTR_EC", 0x0700);
    kv_list.push_back(*pair);
    pair = new kv_pair("EN_ALIGN_RTL_EC",0x0701);
    kv_list.push_back(*pair);
    pair = new kv_pair("EN_CHANGE",EN_CHANGE);
    kv_list.push_back(*pair);
    pair = new kv_pair("EN_ERRSPACE",EN_ERRSPACE);
    kv_list.push_back(*pair);
    pair = new kv_pair("EN_HSCROLL",EN_HSCROLL);
    kv_list.push_back(*pair);
    pair = new kv_pair("EN_KILLFOCUS",EN_KILLFOCUS);
    kv_list.push_back(*pair);
    pair = new kv_pair("EN_MAXTEXT",EN_MAXTEXT);
    kv_list.push_back(*pair);
    pair = new kv_pair("EN_SETFOCUS",EN_SETFOCUS);
    kv_list.push_back(*pair);
    pair = new kv_pair("EN_UPDATE",EN_UPDATE);
    kv_list.push_back(*pair);
    pair = new kv_pair("EN_VSCROLL",EN_VSCROLL);
    kv_list.push_back(*pair);    
    kv_list.sort();
    
    for(list<kv_pair>::iterator iter = kv_list.begin(); iter != kv_list.end(); ++iter){
        string temp2 = iter->command;
        temp2 = ToLower(temp2);
        cout << "case " << iter->command << ": //" << iter->value << endl;
        cout << "\t return RunEventHandler(" << temp2 << ", Wea);" << endl;
    }
    
    
//    for(list<kv_pair>::iterator iter = kv_list.begin(); iter != kv_list.end(); ++iter){
//        string temp2 = iter->command;
//        temp2 = ToLower(temp2);
//        cout << "EVENTLIST " << temp2 << ";" << endl;
//    }
    
//    for(list<kv_pair>::iterator iter = kv_list.begin(); iter != kv_list.end(); ++iter){
//        string temp = iter->command;
//        temp = ToLower(temp);
//        string temp2 = temp;
//        temp2.replace(3, 1, ToUpper(temp.substr(3, 1)));
//        cout << "AddEventHandler(" << iter->command << ", &Button::" << temp2 << ", " << temp << ");" << endl;
//    }
    
//    for(list<kv_pair>::iterator iter = kv_list.begin(); iter != kv_list.end(); ++iter){
//        string temp = iter->command;
//        temp = ToLower(temp);
//        string temp2 = temp;
//        temp2.replace(3, 1, ToUpper(temp.substr(3, 1)));
//        cout << "long " << temp2 << "(lpWndEventArgs);" << endl;
//    }
   
//    for(list<kv_pair>::iterator iter = kv_list.begin(); iter != kv_list.end(); ++iter){
//        string temp = iter->command;
//        temp = ToLower(temp);
//        string temp2 = temp;
//        temp2.replace(3, 1, ToUpper(temp.substr(3, 1)));
//        cout << "long Button::" << temp2 << "(lpWndEventArgs Wea){" << endl;
//        cout << "    return DefWindowProc(Wea->hWnd, Wea->message, Wea->wParam, Wea->lParam);" << endl;
//        cout << "}" << endl;
//    }
    
    system("pause");
    return 0;
}

