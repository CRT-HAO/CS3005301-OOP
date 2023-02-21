/**
 * @ Author: 張皓鈞 (B11030202@mail.ntust.edu.tw)
 * @ Create Time: 2023-02-21 19:52:33
 * @ Modified by: 張皓鈞 (B11030202@mail.ntust.edu.tw)
 * @ Modified time: 2023-02-21 21:02:44
 * @ Description: Output W,A,S,D after input, ESC to stop process.
 */

#include <conio.h> // For getch() function

#include <iostream> // For print out information

// Define inputs and its index
enum ValidInput
{
    EW = 0,
    ES = 1,
    EA = 2,
    ED = 3,
    ESPACE = 4,
    EESC = 5,
    INVALID,
};

// Detect state of input
void keyUpdate(bool key[]);

int main()
{
    // Initialize state of key
    bool gKeyState[ValidInput::INVALID];

    // Obtain and update the input using a loop
    /************************************************************************/
    /*Please implement your code here*/

    /************************************************************************/
}

//******************************************************************
//
// * 偵測輸入狀態
//==================================================================
void keyUpdate(bool key[])
//==================================================================
{
    for ( int i = 0; i < ValidInput::INVALID; i++ )
    {
        key[i] = false;
    }
    char input = _getch();

    // Implement a switch for output calls
    /************************************************************************/
    /*Please implement your code here*/

    /************************************************************************/
}
