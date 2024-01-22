#include "pch.h"
#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

using namespace std;

INPUT ip;

void generate_title_color() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
}

string title = R"(
                              |__/                                                            
 /$$$$$$$$  /$$$$$$  /$$$$$$$$ /$$       /$$$$$$/$$$$   /$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$ 
|____ /$$/ /$$__  $$|____ /$$/| $$      | $$_  $$_  $$ |____  $$ /$$_____/ /$$__  $$ /$$__  $$
   /$$$$/ | $$$$$$$$   /$$$$/ | $$      | $$ \ $$ \ $$  /$$$$$$$| $$      | $$  \__/| $$  \ $$
  /$$__/  | $$_____/  /$$__/  | $$      | $$ | $$ | $$ /$$__  $$| $$      | $$      | $$  | $$
 /$$$$$$$$|  $$$$$$$ /$$$$$$$$| $$      | $$ | $$ | $$|  $$$$$$$|  $$$$$$$| $$      |  $$$$$$/
|________/ \_______/|________/|__/      |__/ |__/ |__/ \_______/ \_______/|__/       \______/
)";

void clear_screen() {
    system("CLS");
}

void set_console_title() {
    SetConsoleTitle(L"zezi macro");
}

void print_status() {
    clear_screen();
    set_console_title();
    generate_title_color();
    cout << title << endl;
}

void run_macro(bool macro) {
    if (macro) {
        ip.type = INPUT_MOUSE;
        ip.mi.dwFlags = MOUSEEVENTF_WHEEL;
        ip.mi.mouseData = WHEEL_DELTA;
        SendInput(1, &ip, sizeof(INPUT));

        this_thread::sleep_for(chrono::milliseconds(1));

        ip.mi.mouseData = -WHEEL_DELTA;
        SendInput(1, &ip, sizeof(INPUT));

        this_thread::sleep_for(chrono::milliseconds(1));
    }
}

int main() {
    print_status();

    bool macro = false;
    while (true) {
        if (GetAsyncKeyState(VK_XBUTTON2)) {
            macro = !macro;
            while (GetAsyncKeyState(VK_XBUTTON2)) {}
        }
        run_macro(macro);
        this_thread::sleep_for(chrono::milliseconds(1));
    }

    cin.get();
    return 0;
}
