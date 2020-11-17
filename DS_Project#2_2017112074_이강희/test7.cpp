//--------------------------------------------------------------------
//
//Data Structure Project 2
//Micro facebook
//Made by 2017112074 Lee Kang Hee
//
//--------------------------------------------------------------------

#include <iostream>
#include <string>
#include "listlnk.cpp"

using namespace std;

void print_help()
{
    cout << endl << "Commands:" << endl;
    cout << "  P (name)           : Make new person's list" << endl;
    cout << "  F (name1)|(name2)  : Record that (name1) and (name2) is friend." << endl;
    cout << "  U (name1)|(name2)  : Record that (name1) and (name2) isn't friend." << endl;
    cout << "  L (name)           : Display (name)'s friends list." << endl;
    cout << "  Q (name1)|(name2)  : If (name1) and (name2) are friend, display 'Y' else display 'N'." << endl;
    cout << "  X                  : Quit the program" << endl;
    cout << endl;
}

void main()
{
    List<char> testList;   // Test list
    char cmd;              // Input comma
    string name1, name2;

    print_help();

    do
    {

        cout << endl << "Command: ";                          // Read command
        cin >> cmd;
        if (cmd == 'P' || cmd == 'p' || cmd == 'L' || cmd == 'l')
            cin >> name1;

        else if (cmd == 'F' || cmd == 'f' || cmd == 'U' || cmd == 'u' || cmd == 'Q' || cmd == 'q')
            cin >> name1 >> name2;

        switch (cmd)
        {

        case 'P': case 'p':                                  // make new person's list;
            cout << "Make " << name1 <<"'s ID." << endl;
            testList.Make(name1);
            name1 = "";
            break;

        case 'F': case 'f':                                  // Record that they are friend.
            testList.Record_friend(name1, name2);
            name1 = "";
            name2 = "";
            break;

        case 'U': case 'u':                                  // Record that they are not freind.
            testList.Record__N_friend(name1, name2);
            name1 = "";
            name2 = "";
            break;
        
        case 'L': case 'l':                                  // Display friends list
            cout << name1 << "'s friend list : ";
            testList.Display(name1);
            name1 = "";
            break;

        case 'Q': case 'q':                                  // Check that they are friend or not.
            testList.Check(name1, name2);
            name1 = "";
            name2 = "";
            break;

        case 'X': case 'x':                                  // Quit test program
            break;

        default:                                             // Invalid command
            cout << "Inactive or invalid command" << endl;
        }
    } while (cmd != 'X' && cmd != 'x');
}

