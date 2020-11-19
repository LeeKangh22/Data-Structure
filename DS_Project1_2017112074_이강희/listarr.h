#pragma once
//--------------------------------------------------------------------


//Data Structure project #1_made by_2017112074_�̰���


//--------------------------------------------------------------------

#include <stdexcept>
#include <iostream>
#include <string>


using namespace std;

const int defMaxListSize = 20;   // Default maximum list size

typedef string DataType;

class List
{
public:

	// Constructor
	List(int maxNumber = defMaxListSize);

	// Destructor
	~List();

	// List manipulation operations
	void insert()   
		throw (logic_error);
	void remove()                                 
		throw (logic_error);
	//���Ͽ��� ������ ����Ʈ�� �о���� ���� �Լ�
	void Read(const DataType& filename)
		throw (logic_error);
	//�ۼ��� ����Ʈ�� ���Ͽ� ���� ���� �Լ�
	void Write(const DataType& filename)
		throw (logic_error);
	//list ���� �Է¹��� ������ �����ڰ� �� ������� ����ϱ� ���� �Լ�
	void month(const DataType& birthdayElement)
		throw (logic_error);
	
	// List status operations
	//�� �Լ����� main�� �ƴ϶� �ٸ� ��� �Լ����� ����ϱ� ���� �ۼ��ߴ�.
	bool isEmpty() const;                    // List is empty
	bool isFull() const;                     // List is full

	//��� ���� �� ������ ���¸� ��Ÿ���ֱ� ���� �Լ�
	void showStructure() const;

private:
	// Data members
	int maxSize,
		size;        
	//�����͸� �̸�, ��ȭ��ȣ, ���� ���� �ޱ� ���� ����
	DataType* name;  
	DataType* phone;
	DataType* birthday;
};
//made by 2017112074�̰���
