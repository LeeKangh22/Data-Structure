#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

class bank
{
    char name[20];
    int acno;
    char actype[4];
    float balance;

public:
    void init();
    void deposit();
    void withdraw();
    void disp_det();
};
//member functions of bank class
void bank::init()
{
    cout << "New Account" << endl;
    cout << "Enter the Name of the deposit :";
    cin >> name;
    cout << "Enter the Accoutn number : ";
    cin >> acno;
    cout << "Enter the Account type (CURR/SAVG/FD/RD/DMAT) : ";
    cin >> actype;
    cout << "Enter the Amount to deposit : ";
    cin >> balance;
    cout << endl;
}
void bank::deposit()
{
    float deposit;
    cout << "Enter th Amount to deposit : ";
    cin >> deposit;
    balance += deposit;
    cout << endl;

}
void bank::withdraw()
{
    float draw;
    cout << "Enter th Amount to deposit : ";
    cin >> draw;
    balance -= draw;
    cout << endl;
}
void bank::disp_det()
{
    cout << "Name of the depositor   :" << name << endl;
    cout << "Account Number   :" << acno << endl;
    cout << "Account Type    :" << actype << endl;
    cout << "Balance     :$" << balance << endl;
    cout << endl;
}
// main function , exectution starts here
void main(void)
{
    // clrscr();
    bank obj;
    int choice = 1;
    while (choice != 0)
    {
        cout << "Enter 0 to exit\n1. Initialize a new acc.\n2. Deposit\n3. Withdraw\n4. See A / c Status\n";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 0:
            obj.disp_det();
            cout << "EXITING PROGRAM.";
            break;
        case 1:
            obj.init();
            break;
        case 2:
            obj.deposit();
            break;
        case 3:
            obj.withdraw();
            break;
        case 4:
            obj.disp_det();
            break;
        default:
            cout << "Illegal Option" << endl;
        }
    }
    _getch();
}//made by 2017112074 ÀÌ°­Èñ