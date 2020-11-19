//--------------------------------------------------------------------


//Data Structure project #1_made by_2017112074_이강희


//--------------------------------------------------------------------

#include <string>
//파일 입출력을 위한 헤더파일
#include <fstream>
#include "listarr.h"
using namespace std;

//--------------------------------------------------------------------

List::List(int maxNumber)
//이름, 전화번호, 생일을 저장하기 위해 각각의 리스트를 만들어준다.
//이 리스트들은 사이즈라는 하나의 변수에만 영향을 받는다.
//그렇기 때문에 사이즈만 조절해 주면 세개의 리스트는 하나의 리스트처럼 움직인다.
	: maxSize(maxNumber),
	size(0)
{
	name=new DataType[maxNumber];
	phone=new DataType[maxNumber];
	birthday=new DataType[maxNumber];
}

//--------------------------------------------------------------------

List:: ~List() {
	delete[]name;
	delete[]phone;
	delete[]birthday;
}

//--------------------------------------------------------------------

void List::insert()
//입력 시에 각각 전달 받은 매개변수의 데이터를 각각 저장해주고 사이즈를 1늘려 다음 입력에 대비한다.
throw (logic_error) {
	if (isFull() == false) {
		//입력받을 때의 Enter(\n)을 없애주기 위해 cin.ignore()사용
		cin.ignore();
		cout << "Name :";
		getline(cin, name[size]);
		cout << "Phone :";
		getline(cin, phone[size]);
		cout << "Birthday :";
		getline(cin, birthday[size]);
		size++;
	}
	//리스트가 꽉 차있으면 리스트가 꽉 차서 더 넣을 수 없음을 출력한다.
	else if (isFull())
		cout << "List is Full" << endl;
}

//--------------------------------------------------------------------

void List::remove() 
//데이터를 제거할 때 제거할 데이터의 이름을 받기 때문에 해당 이름을 검색하고 그 이름에 해당하는 
//위치에 있는 전화번호, 생일, 이름을 모두 제거한다.
throw (logic_error) {
	string name_;
	//리스트가 비어있으면 제거할 데이터가 없음을 출력한다.
	if (isEmpty())
		cout << "List is Empty" << endl;
	else if (isEmpty() == false) {
		cout << "Name :";
		cin.ignore();
		getline(cin, name_);
		for (int i = 0; i < size; i++) {
			if (name[i] == name_) {
				name[i] = name[i+1];
				phone[i] = phone[i+1];
				birthday[i] = birthday[i+1];
			}
			//리스트에서 제거할 목록의 이름이 잘못되었으면 오류 메시지 출력(예외처리)
			else {
				cout << name_ << " doesn't exist in the list!" << endl;
				cout << endl;
				return;
			}
			//빈칸이 생겼기 때문에 모든 데이터를 한칸씩 앞으로 당겨준다.
			name[i] = name[i + 1];
			phone[i] = phone[i + 1];
			birthday[i] = birthday[i + 1];
		}
		//데이터를 제거했기 때문에 사이즈를 줄여준다.
		size = size - 1;
	}
	
}

//--------------------------------------------------------------------

void List::Read(const DataType& filename)
//파일을 열어 파일 내에 있는 데이터를 읽어온다.
throw (logic_error) {
	ifstream fin;
	string File;
	File = filename;
	//입력받은 파일 이름에 확장자 .txt를 붙여 텍스트 파일을 열도록 한다.
	File.append(".txt");
	fin.open(File);
	//파일을 열어 문자열이 끝날 때 까지 한줄씩 입력받아 한명씩 저장한다.
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, name[size]);
			getline(fin, phone[size]);
			getline(fin, birthday[size]);
			//저장한 데이터가 늘어났으므로 사이즈를 늘려준다.
			size++;
		}
	}
	//파일의 이름이 잘못되었거나 열리지 않으면 오류 메시지를 출력한다(예외처리)
	else cout << "File opne failed!" << endl;
	fin.close();
}

void List::Write(const DataType& filename) 
//파일을 열어 여태까지 리스트에 저장된 데이터를 텍스트 형태로 파일에 출력한다.
throw (logic_error) {
	ofstream fout;
	string File;
	File = filename;
	File.append(".txt");
	fout.open(File);
	//파일을 열어 각 데이터마다 줄 단위로 파일에 출력한다.
	if (fout.is_open()) {
		for (int i = 0; i < maxSize; i++) {
			fout << name[i] << endl;
			fout << phone[i] << endl;
			fout << birthday[i] << endl;
		}
	}
	//파일의 이름이 잘못되었거나 파일이 열리지 않으면 오류메시지를 출력한다(예외처리)
	else cout << "File open failed!" << endl;
	fout.close();

}

//--------------------------------------------------------------------
void List::month(const DataType& birthdayElement)
//입력받은 월에 해당하는 생일을 가진 사람이 몇명인지와 그 사람의 데이터를 출력한다.
throw (logic_error) {
	int count = 0;
	//string형태로 1월부터 12월까지 저장하기 위한 배열
	string birthday_temp[12];
	//string형태로 입력받은 생일의 첫글짜와 두번째 글자를 확인하여 생일 판별하여 입력
	for (int i = 0; i < size; i++) {
		if (birthday[i][0] == '0' && birthday[i][1] == '1')
			birthday_temp[i]="January";
		else if (birthday[i][0] == '0' && birthday[i][1] == '2')
			birthday_temp[i] = "February";
		else if (birthday[i][0] == '0' && birthday[i][1] == '3')
			birthday_temp[i] = "March";
		else if (birthday[i][0] == '0' && birthday[i][1] == '4')
			birthday_temp[i] = "April";
		else if (birthday[i][0] == '0' && birthday[i][1] == '5')
			birthday_temp[i] = "May";
		else if (birthday[i][0] == '0' && birthday[i][1] == '6')
			birthday_temp[i] = "June";
		else if (birthday[i][0] == '0' && birthday[i][1] == '8')
			birthday_temp[i] = "July";
		else if (birthday[i][0] == '0' && birthday[i][1] == '8')
			birthday_temp[i] = "August";
		else if (birthday[i][0] == '0' && birthday[i][1] == '9')
			birthday_temp[i] = "September";
		else if (birthday[i][0] == '1' && birthday[i][1] == '0')
			birthday_temp[i] = "October";
		else if (birthday[i][0] == '1' && birthday[i][1] == '1')
			birthday_temp[i] = "November";
		else if (birthday[i][0] == '1' && birthday[i][1] == '2')
			birthday[i] = "December";
		if (birthday_temp[i] == birthdayElement) {
			count++;
		}
	}
	//월의 이름이 잘못되었거나 생일자가 없으면 출력한다(예외처리)
	if (count == 0) cout << "No birthday in " << birthdayElement << endl;
	else {
		cout << "Total number of birthdays in " << birthdayElement << ":" << count << endl;
		for (int i = 0; i < maxSize; i++) {
			//생일을 판별하여 입력받은 월과 같은 사람의 정보를 출력
			if (birthday_temp[i] == birthdayElement) {
				cout << "Name : " << name[i] << endl;
				cout << "Phone : " << phone[i] << endl;
				cout << "Birthday : " << birthday[i] << endl;
				cout << endl;
				cout << endl;
			}
		}
	}
}

//--------------------------------------------------------------------

//리스트가 비어있는지를 확인하는 함수
bool List::isEmpty() const {

	if (size == 0)
		return 1;
	else return 0;
}

//--------------------------------------------------------------------

//리스트가 가득한지를 확인하는 함수
bool List::isFull() const {
	
	if (size == maxSize)
		return 1;
	else return 0;
}

//--------------------------------------------------------------------

//리스트 내에 존재하는 데이터와 월 마다 해당하는 생일자가 몇명 있는지 출력한다.
void List::showStructure() const {
	int birthday_count[12];
	cout << "Total number of entries in the list:" << size << endl;
	for (int i = 0; i < 12; i++)
		birthday_count[i] = 0;
	if (isEmpty()) {
		cout << "Empty list" << endl;
		return;
	}

	//각 월의 생일자를 표시하기 위해 월마다 생일자를 카운트하는 배열을 하나 만들어 
	//입력된 생일의 1글자와2번째 글자를 판별하여 생일이 몇월인지 계산하고 저장한다.
	for (int i = 0; i < maxSize; i++) {
		if (birthday[i][0] == '0'&& birthday[i][1]=='1')
			birthday_count[0]++;
		else if (birthday[i][0] == '0' && birthday[i][1] == '2')
			birthday_count[1]++;
		else if (birthday[i][0] == '0' && birthday[i][1] == '3')
			birthday_count[2]++;
		else if (birthday[i][0] == '0' && birthday[i][1] == '4')
			birthday_count[3]++;
		else if (birthday[i][0] == '0' && birthday[i][1] == '5')
			birthday_count[4]++;
		else if (birthday[i][0] == '0' && birthday[i][1] == '6')
			birthday_count[5]++;
		else if (birthday[i][0] == '0' && birthday[i][1] == '8')
			birthday_count[6]++;
		else if (birthday[i][0] == '0' && birthday[i][1] == '8')
			birthday_count[7]++;
		else if (birthday[i][0] == '0' && birthday[i][1] == '9')
			birthday_count[8]++;
		else if (birthday[i][0] == '1' && birthday[i][1] == '0')
			birthday_count[9]++;
		else if (birthday[i][0] == '1' && birthday[i][1] == '1')
			birthday_count[10]++;
		else if (birthday[i][0] == '1' && birthday[i][1] == '2')
			birthday_count[11]++;
	}//생일자의 숫자를 출력한다.
	if(isEmpty()==false)
		cout << "Number of birthdays in" << endl;
	if (birthday_count[0] != 0)
		cout << "     January: " << birthday_count[0] << endl;
	if (birthday_count[1] != 0)
		cout << "     February: " << birthday_count[1] << endl;
	if (birthday_count[2] != 0)
		cout << "     March: " << birthday_count[2] << endl;
	if (birthday_count[3] != 0)
		cout << "     April: " << birthday_count[3] << endl;
	if (birthday_count[4] != 0)
		cout << "     March: " << birthday_count[4] << endl;
	if (birthday_count[5] != 0)
		cout << "     June: " << birthday_count[5] << endl;
	if (birthday_count[6] != 0)
		cout << "     July: " << birthday_count[6] << endl;
	if (birthday_count[7] != 0)
		cout << "     August: " << birthday_count[7] << endl;
	if (birthday_count[8] != 0)
		cout << "     September: " << birthday_count[8] << endl;
	if (birthday_count[9] != 0)
		cout << "     October: " << birthday_count[9] << endl;
	if (birthday_count[10] != 0)
		cout << "     November: " << birthday_count[10] << endl;
	if (birthday_count[11] != 0)
		cout << "     December: " << birthday_count[11] << endl;
}
//made by 2017112074이강희