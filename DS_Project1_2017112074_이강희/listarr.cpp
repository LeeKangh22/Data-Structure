//--------------------------------------------------------------------


//Data Structure project #1_made by_2017112074_�̰���


//--------------------------------------------------------------------

#include <string>
//���� ������� ���� �������
#include <fstream>
#include "listarr.h"
using namespace std;

//--------------------------------------------------------------------

List::List(int maxNumber)
//�̸�, ��ȭ��ȣ, ������ �����ϱ� ���� ������ ����Ʈ�� ������ش�.
//�� ����Ʈ���� �������� �ϳ��� �������� ������ �޴´�.
//�׷��� ������ ����� ������ �ָ� ������ ����Ʈ�� �ϳ��� ����Ʈó�� �����δ�.
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
//�Է� �ÿ� ���� ���� ���� �Ű������� �����͸� ���� �������ְ� ����� 1�÷� ���� �Է¿� ����Ѵ�.
throw (logic_error) {
	if (isFull() == false) {
		//�Է¹��� ���� Enter(\n)�� �����ֱ� ���� cin.ignore()���
		cin.ignore();
		cout << "Name :";
		getline(cin, name[size]);
		cout << "Phone :";
		getline(cin, phone[size]);
		cout << "Birthday :";
		getline(cin, birthday[size]);
		size++;
	}
	//����Ʈ�� �� �������� ����Ʈ�� �� ���� �� ���� �� ������ ����Ѵ�.
	else if (isFull())
		cout << "List is Full" << endl;
}

//--------------------------------------------------------------------

void List::remove() 
//�����͸� ������ �� ������ �������� �̸��� �ޱ� ������ �ش� �̸��� �˻��ϰ� �� �̸��� �ش��ϴ� 
//��ġ�� �ִ� ��ȭ��ȣ, ����, �̸��� ��� �����Ѵ�.
throw (logic_error) {
	string name_;
	//����Ʈ�� ��������� ������ �����Ͱ� ������ ����Ѵ�.
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
			//����Ʈ���� ������ ����� �̸��� �߸��Ǿ����� ���� �޽��� ���(����ó��)
			else {
				cout << name_ << " doesn't exist in the list!" << endl;
				cout << endl;
				return;
			}
			//��ĭ�� ����� ������ ��� �����͸� ��ĭ�� ������ ����ش�.
			name[i] = name[i + 1];
			phone[i] = phone[i + 1];
			birthday[i] = birthday[i + 1];
		}
		//�����͸� �����߱� ������ ����� �ٿ��ش�.
		size = size - 1;
	}
	
}

//--------------------------------------------------------------------

void List::Read(const DataType& filename)
//������ ���� ���� ���� �ִ� �����͸� �о�´�.
throw (logic_error) {
	ifstream fin;
	string File;
	File = filename;
	//�Է¹��� ���� �̸��� Ȯ���� .txt�� �ٿ� �ؽ�Ʈ ������ ������ �Ѵ�.
	File.append(".txt");
	fin.open(File);
	//������ ���� ���ڿ��� ���� �� ���� ���پ� �Է¹޾� �Ѹ� �����Ѵ�.
	if (fin.is_open()) {
		while (!fin.eof()) {
			getline(fin, name[size]);
			getline(fin, phone[size]);
			getline(fin, birthday[size]);
			//������ �����Ͱ� �þ���Ƿ� ����� �÷��ش�.
			size++;
		}
	}
	//������ �̸��� �߸��Ǿ��ų� ������ ������ ���� �޽����� ����Ѵ�(����ó��)
	else cout << "File opne failed!" << endl;
	fin.close();
}

void List::Write(const DataType& filename) 
//������ ���� ���±��� ����Ʈ�� ����� �����͸� �ؽ�Ʈ ���·� ���Ͽ� ����Ѵ�.
throw (logic_error) {
	ofstream fout;
	string File;
	File = filename;
	File.append(".txt");
	fout.open(File);
	//������ ���� �� �����͸��� �� ������ ���Ͽ� ����Ѵ�.
	if (fout.is_open()) {
		for (int i = 0; i < maxSize; i++) {
			fout << name[i] << endl;
			fout << phone[i] << endl;
			fout << birthday[i] << endl;
		}
	}
	//������ �̸��� �߸��Ǿ��ų� ������ ������ ������ �����޽����� ����Ѵ�(����ó��)
	else cout << "File open failed!" << endl;
	fout.close();

}

//--------------------------------------------------------------------
void List::month(const DataType& birthdayElement)
//�Է¹��� ���� �ش��ϴ� ������ ���� ����� ��������� �� ����� �����͸� ����Ѵ�.
throw (logic_error) {
	int count = 0;
	//string���·� 1������ 12������ �����ϱ� ���� �迭
	string birthday_temp[12];
	//string���·� �Է¹��� ������ ù��¥�� �ι�° ���ڸ� Ȯ���Ͽ� ���� �Ǻ��Ͽ� �Է�
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
	//���� �̸��� �߸��Ǿ��ų� �����ڰ� ������ ����Ѵ�(����ó��)
	if (count == 0) cout << "No birthday in " << birthdayElement << endl;
	else {
		cout << "Total number of birthdays in " << birthdayElement << ":" << count << endl;
		for (int i = 0; i < maxSize; i++) {
			//������ �Ǻ��Ͽ� �Է¹��� ���� ���� ����� ������ ���
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

//����Ʈ�� ����ִ����� Ȯ���ϴ� �Լ�
bool List::isEmpty() const {

	if (size == 0)
		return 1;
	else return 0;
}

//--------------------------------------------------------------------

//����Ʈ�� ���������� Ȯ���ϴ� �Լ�
bool List::isFull() const {
	
	if (size == maxSize)
		return 1;
	else return 0;
}

//--------------------------------------------------------------------

//����Ʈ ���� �����ϴ� �����Ϳ� �� ���� �ش��ϴ� �����ڰ� ��� �ִ��� ����Ѵ�.
void List::showStructure() const {
	int birthday_count[12];
	cout << "Total number of entries in the list:" << size << endl;
	for (int i = 0; i < 12; i++)
		birthday_count[i] = 0;
	if (isEmpty()) {
		cout << "Empty list" << endl;
		return;
	}

	//�� ���� �����ڸ� ǥ���ϱ� ���� ������ �����ڸ� ī��Ʈ�ϴ� �迭�� �ϳ� ����� 
	//�Էµ� ������ 1���ڿ�2��° ���ڸ� �Ǻ��Ͽ� ������ ������� ����ϰ� �����Ѵ�.
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
	}//�������� ���ڸ� ����Ѵ�.
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
//made by 2017112074�̰���