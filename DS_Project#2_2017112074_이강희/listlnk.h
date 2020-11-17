//--------------------------------------------------------------------
//
//Data Structure Project 2
//Micro facebook
//Made by 2017112074 Lee Kang Hee
//
//--------------------------------------------------------------------

#include <new>
#include <stdexcept>
#include <unordered_map>
using namespace std;

template < class DT >         // Forward declaration of the List class
class List;

template < class DT >
class Person                // Facilitator class for the List class
{
private:

	// Constructor
	Person(string name, Person* nextPtr);

	// Data members

	string name;                       // ������ ����� �̸�
	Person* next;                      // ������ ������� ��ũ�� ����Ʈ�� �����ϱ� ���� ���
	int order = 1;                     // ���� �����͸� �˻��ϱ� ���� Key
	unordered_map<int, string>f_list;  // ����� ģ�� ����� �����ϱ� ���� map
	
	friend class List<DT>;
};

template < class DT >
class List
{
public:

	// ������
	List(int ignored = 0);

	// �Ҹ���
	~List();

	// Micro Facebook�� �����ϱ� ���� �Լ��� 
	void Make(string name)                               // �Է¹��� �̸��� �ش��ϴ� ID ����
		throw (bad_alloc);
	void Record_friend(string name1, string name2)       // �Է¹��� �� ����� ģ������ ���
		throw (logic_error);
	void Record__N_friend(string name1, string name2)    // �Է¹��� �� ����� ģ���� �ƴ��� ���
		throw (logic_error);
	void Display(string name)                            // �Է¹��� ����� ģ�� ����� ���
		throw (logic_error);
	void Check(string name1, string name2)               // �Է¹��� �� ����� ģ������ �ƴ��� ���
		throw (logic_error);

    void clear()                                         // �Ҹ��ڸ� ����ϱ� ���� ����
		throw (logic_error);
	bool isEmpty() const
		throw (logic_error);                             // Make���� ����Ʈ�� ������� ��츦 ����ϱ� ���� ����
private:
	Person<DT>* head,   // Pointer to the beginning of the list
		* cursor;  // ����Ʈ�� ����ų Ŀ��
		
};

