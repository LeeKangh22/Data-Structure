//--------------------------------------------------------------------
//
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------

#include "listarr.h"

using namespace std;

//--------------------------------------------------------------------

List::List(int maxNumber)

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).

	: maxSize(maxNumber),
	size(0),
	cursor(-1)
{
	dataItems = new DataType[maxNumber];
}

//--------------------------------------------------------------------

List:: ~List()
// Frees the memory used by a list.

{
	// pre-lab
	delete[]dataItems;

}

//--------------------------------------------------------------------

void List::insert(const DataType& newDataItem)
throw (logic_error)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{
	// pre-lab
	if (isFull()==false) 
	{
		dataItems[size] = newDataItem;
		size++;
		//커서를 가장 끝으로 옮겨줌으로써 커서가 사이즈를 벗어나는 일이 없도록 한다.
		cursor = size - 1;
	}
	else if (isFull())
		cout << "List is Full" << endl;
	
	

}

//--------------------------------------------------------------------

void List::remove() throw (logic_error)

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.
{
	// pre-lab
	if (isEmpty())
		cout << "List is Empty" << endl;
	else if (isEmpty()==false) {
		//커서 자리에 있는 요소를 삭제하고 마지막에 있는 원소를 그 자리에 대신 넣는다.
		dataItems[cursor] = dataItems[size - 1];
		size--;
		//커서가 그자리에 그대로 있다가 insert로 인하여 커서가 값을 넘어서는 일을 방지하도록 커서가 사이즈보다 커지면 커서의 크기를 조정한다.
		if (cursor > size)
			cursor = size - 1;
	}
}

//--------------------------------------------------------------------

void List::replace(const DataType& newDataItem)
throw (logic_error)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.
{
	// Requires that the list is not empty
	// pre-lab
	if (isEmpty()) 
		cout << "List is Empty" << endl;
	
	else 
		dataItems[cursor] = newDataItem;
	

}
//--------------------------------------------------------------------

void List::clear()
// Removes all the data items from a list.
{
	// pre-lab
	//전부 초기화
	dataItems = NULL;
	//커서 및 크기 초기값 설정
	size = 0;
	cursor = -1;
}

//--------------------------------------------------------------------

bool List::isEmpty() const
// Returns 1 if a list is empty. Otherwise, returns 0.
{
	// pre-lab
	if (size == 0)
		return 1;
	else return 0;

}

//--------------------------------------------------------------------

bool List::isFull() const
// Returns 1 if a list is full. Otherwise, returns 0.
{
	// pre-lab
	if (size == maxSize)
		return 1;
	else return 0;
}

//--------------------------------------------------------------------

int List::gotoBeginning() throw (logic_error)
// Moves the cursor to the beginning of the list.
{
	// pre-lab
	//배열이 비어있으면 움직이지 않도록 한다.
	if (isEmpty())
		return 0;
	else {
		cursor = 0;
		return 1;
	}

}

//--------------------------------------------------------------------

int List::gotoEnd() throw (logic_error)

// Moves the cursor to the end of the list.

{
	// pre-lab
	//배열이 비어있으면 움직이지 않도록 한다.
	if (isEmpty())
		return 0;
	else {
		cursor = size - 1;
		return 1;
	}
}

//--------------------------------------------------------------------

bool List::gotoNext() throw (logic_error)

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.
{
	// pre-lab
	//커서가 가장 마지막에 있으면 더 옮기지 못하게 한다.
	if (cursor == size - 1) {
		cout << "Cursor is at the End" << endl;
		return 0;
	}
	else {
		cursor++;
		return 1;
	}
	
}

//--------------------------------------------------------------------

bool List::gotoPrior() throw (logic_error)

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
	// pre-lab
	//커서가 제일 앞부분에 있으면 더이상 옮기지 못하게 한다.
	if (cursor == 0)
		return 0;
	else {
		cursor--;
		return 1;
	}

}

//--------------------------------------------------------------------

DataType List::getCursor() const throw (logic_error)
// Returns the item marked by the cursor.

{
	// pre-lab
	return dataItems[cursor];
}

//--------------------------------------------------------------------

void List::showStructure() const
// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{

	// pre-lab
	if (isEmpty()) {
		cout << "Empty list" << endl;
		return;
	}
	//리스트의 각 부분에 무엇이 들어가 있는지 알기 위해 출력한다.
	else {
		cout << "size =" << size << "  cursor = " << cursor << endl;
		for (int i = 0; i < maxSize; i++) {
			cout << "[ " << i << " ]";
		}
		cout << endl;
		for (int i = 0; i < size; i++) {
			cout << "  " << dataItems[i] << "  ";
		}
	}
}

//--------------------------------------------------------------------

//in-lab

void List::countBases(List& dnaSequence, int& aCount, int& cCount, int& tCount, int& gCount) {
	//실행 이후 값이 중첩되는 것을 막기 위해 모두 0으로 초기화
	aCount = 0;
	cCount = 0;
	tCount = 0;
	gCount = 0;
	//이후 각 원소들의 갯수를 셈
	for (int i = 0; i < size; i++) {
		if (dataItems[i] == 'A') 
			aCount++;
		else if (dataItems[i] == 'C')
			cCount++;
		else if (dataItems[i] == 'T')
			tCount++;
		else if (dataItems[i] == 'G')
			gCount++;
	}
}
//made by 2017112074이강희