#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

using namespace std;

INPUT ip;

string title = R"(
                              |__/                                                            
 /$$$$$$$$  /$$$$$$  /$$$$$$$$ /$$       /$$$$$$/$$$$   /$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$ 
|____ /$$/ /$$__  $$|____ /$$/| $$      | $$_  $$_  $$ |____  $$ /$$_____/ /$$__  $$ /$$__  $$
   /$$$$/ | $$$$$$$$   /$$$$/ | $$      | $$ \ $$ \ $$  /$$$$$$$| $$      | $$  \__/| $$  \ $$
  /$$__/  | $$_____/  /$$__/  | $$      | $$ | $$ | $$ /$$__  $$| $$      | $$      | $$  | $$
 /$$$$$$$$|  $$$$$$$ /$$$$$$$$| $$      | $$ | $$ | $$|  $$$$$$$|  $$$$$$$| $$      |  $$$$$$/
|________/ \_______/|________/|__/      |__/ |__/ |__/ \_______/ \_______/|__/       \______/
)";

string additional_text = "By zezi";

void clear_screen() {
    system("CLS");
}

void set_console_title() {
    SetConsoleTitle(L"zezi macro");
}

void print_status() {
    clear_screen();
    set_console_title();

    cout << title << endl << additional_text << endl;
}

void run_macro(bool macro) {
    if (macro) {
        ip.type = INPUT_MOUSE;
        ip.mi.dwFlags = MOUSEEVENTF_WHEEL;
        ip.mi.mouseData = WHEEL_DELTA;
        SendInput(1, &ip, sizeof(INPUT));

        this_thread::sleep_for(chrono::microseconds(1));

        ip.mi.mouseData = -WHEEL_DELTA;
        SendInput(1, &ip, sizeof(INPUT));

        this_thread::sleep_for(chrono::microseconds(1));
    }
}

int main() {
    print_status();

    bool macro = false;
    while (true) {
        run_macro(macro);
        this_thread::sleep_for(chrono::microseconds(1));
    }

    cin.get();
    return 0;
}
