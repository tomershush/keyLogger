#include "registryHandler.h"

/*
* A function that checks whether or not the auto start registry entry is present on the machine.
* Input: None.
* Output: True if exists, false if it does not.
*/
bool registryHandler::checkRegistry()
{
    bool stat = false;
    PHKEY regKey = (PHKEY) malloc(sizeof(HKEY));

    if (regKey) // Making sure regKey is not null.
    {
        stat = !(RegOpenKeyExA(HKEY_CURRENT_USER, REG_PATH, NULL, KEY_SET_VALUE, regKey));

        RegCloseKey(*regKey);
    }

    return stat;
}

/*
* A function that adds the program to the auto run registry key.
* Input: None.
* Output: 0 on success, other value otherwise.
*/
int registryHandler::addToRegistry()
{
    PHKEY regKey = (PHKEY)malloc(sizeof(HKEY));
    char dataStr[1024] = {0};
    int dataSize = 0;
    int stat = 0;


    dataSize = GetModuleFileNameA(NULL, dataStr, 1024) + 1; // Getting the file's name.

    if (regKey)
    {
        stat = RegOpenKeyExA(HKEY_CURRENT_USER, REG_PATH, NULL, KEY_SET_VALUE, regKey); // Opening the key.
        
        if (!stat)
        {
            // Setting the auto run value.
            RegSetValueExA(*regKey, "test", NULL, REG_SZ, (BYTE *) dataStr, dataSize);
        }
    }

    return stat;
}
