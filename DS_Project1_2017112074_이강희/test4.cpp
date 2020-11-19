//--------------------------------------------------------------------


//Data Structure project #1_made by_2017112074_�̰���


//--------------------------------------------------------------------
#include <iostream>
//�Է¹޴� �������� �ڷ����� string�̱� ������ ������� �߰�
#include <string>
//���� ������� ���� �������
#include <fstream>
#include "listarr.h"
using namespace std;

void main()
{
	List testList(8);		  //8ũ���� List����
	string birthdayElement;   //month�Լ����� ����� �Ű�����
	string filename;          //���� �̸��� �Է¹���, Read��Write�Լ����� ����� �Ű�����
	char cmd;                 // Input command

	do
	{
		cout << endl << "Commands:" << endl;
		cout << "  R   : Read from a file" << endl;
		cout << "  +   : Add a new entry" << endl;
		cout << "  -   : Remove an entry" << endl;
		cout << "  Q   : Quit the program" << endl;
		cout << "  W   : Write to a file" << endl;
		cout << "  M   : Select a month" << endl;
		
		cout << endl;
		cout << endl << "Command: ";                  // Read command
		cin >> cmd;

		switch (cmd)
		{
		case '+':                                  // insert
			cout << "Add an entry" <<  endl;
			testList.insert();
			testList.showStructure();
			break;

		case '-':                                  // remove
			cout << "Remove an entry" << endl;
			testList.remove();
			testList.showStructure();
			break;

		case 'R':                                 // ���� �о���̱�
			cout << "Enter the name of the file:";
			cin >> filename;
			testList.Read(filename);
			filename = "";
			testList.showStructure();
			break;

		case 'W':                                 //���� ��������
			cout << "Enter the name of the file:";
			cin >> filename;
			testList.Write(filename);
			cout << "The list is written into " << filename << endl;
			filename = "";
			break;
			
		case 'M':                                //�ش� ���� ������ ���� ����
			cout << "Enter the selected month: ";
			cin >> birthdayElement;
			testList.month(birthdayElement);
			birthdayElement = "";
			break;

		case 'Q': case 'q':                   // Quit test program
			break;

		default:                               // Invalid command
			cout << "Inactive or invalid command" << endl;
		}
	} while (cmd != 'Q' && cmd != 'q');
}
//made by 2017112074�̰���