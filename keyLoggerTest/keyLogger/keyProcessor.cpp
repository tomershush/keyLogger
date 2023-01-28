#include "keyProcessor.h"

/*
* A function to filter a printable character.
* Input: Any ASCII character.
* Output: The ASCII character if printable, 0 if not printable.
*/
char keyProcessor::filterPrintableChar(char keyChar)
{
    if (keyChar >= LOWEST_PRINTABLE && keyChar <= HIGHEST_PRINTABLE)
        return keyChar;

    return 0;
}

/*
* A function to format shifted keys. Switches the original key with it's Shift counterpart.
* Input: ASCII character from the keyboard.
* Output: The original character if it does not have a shifted form, or the shifted form if one exists.
*/
char keyProcessor::formatShiftedKeys(char keyChar)
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
    case '\\':
        shiftedChar = '|';
        break;


    default:
        break;

    }

    return shiftedChar;
}

/*
* A function that converts capital ASCII letters to lower case.
* Input: Capital ASCII letter.
* Output: Lower case ASCII letter.
*/
char keyProcessor::convertToLowerCase(char letter)
{
    return letter + 32;
}

std::string keyProcessor::convertSpecialChar(int virtualCode)
{
    std::string keyName = "";

    switch (virtualCode)
    {
        case VK_SHIFT:
            keyName = "Shift";
            break;

        case VK_RETURN:
            keyName = "Enter";
            break;

        case VK_MENU:
            keyName = "Alt";
            break;

        default:
            break;
    }
    
    return keyName;
}
