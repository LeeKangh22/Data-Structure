//--------------------------------------------------------------------


//Data Structure project #1_made by_2017112074_이강희


//--------------------------------------------------------------------
#include <iostream>
//입력받는 데이터의 자료형이 string이기 때문에 헤더파일 추가
#include <string>
//파일 입출력을 위한 헤더파일
#include <fstream>
#include "listarr.h"
using namespace std;

void main()
{
	List testList(8);		  //8크기의 List생성
	string birthdayElement;   //month함수에서 사용할 매개변수
	string filename;          //파일 이름을 입력받을, Read와Write함수에서 사용할 매개변수
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

		case 'R':                                 // 파일 읽어들이기
			cout << "Enter the name of the file:";
			cin >> filename;
			testList.Read(filename);
			filename = "";
			testList.showStructure();
			break;

		case 'W':                                 //파일 내보내기
			cout << "Enter the name of the file:";
			cin >> filename;
			testList.Write(filename);
			cout << "The list is written into " << filename << endl;
			filename = "";
			break;
			
		case 'M':                                //해당 월의 생일자 숫자 세기
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
//made by 2017112074이강희