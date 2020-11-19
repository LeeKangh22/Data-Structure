#pragma once
//--------------------------------------------------------------------


//Data Structure project #1_made by_2017112074_이강희


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
	//파일에서 기존의 리스트를 읽어오기 위한 함수
	void Read(const DataType& filename)
		throw (logic_error);
	//작성한 리스트를 파일에 쓰기 위한 함수
	void Write(const DataType& filename)
		throw (logic_error);
	//list 내의 입력받은 생일의 생일자가 총 몇명인지 계산하기 위한 함수
	void month(const DataType& birthdayElement)
		throw (logic_error);
	
	// List status operations
	//이 함수들은 main이 아니라 다른 멤버 함수에서 사용하기 위해 작성했다.
	bool isEmpty() const;                    // List is empty
	bool isFull() const;                     // List is full

	//명령 수행 시 데이터 상태를 나타내주기 위한 함수
	void showStructure() const;

private:
	// Data members
	int maxSize,
		size;        
	//데이터를 이름, 전화번호, 생일 나눠 받기 위해 생성
	DataType* name;  
	DataType* phone;
	DataType* birthday;
};
//made by 2017112074이강희
