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

	string name;                       // 생성된 사람의 이름
	Person* next;                      // 생성된 사람들을 링크드 리스트로 구현하기 위한 노드
	int order = 1;                     // 맵의 데이터를 검색하기 위한 Key
	unordered_map<int, string>f_list;  // 사람의 친구 목록을 저장하기 위한 map
	
	friend class List<DT>;
};

template < class DT >
class List
{
public:

	// 생성자
	List(int ignored = 0);

	// 소멸자
	~List();

	// Micro Facebook을 구현하기 위한 함수들 
	void Make(string name)                               // 입력받은 이름에 해당하는 ID 생성
		throw (bad_alloc);
	void Record_friend(string name1, string name2)       // 입력받은 두 사람이 친구임을 기록
		throw (logic_error);
	void Record__N_friend(string name1, string name2)    // 입력받은 두 사람이 친구가 아님을 기록
		throw (logic_error);
	void Display(string name)                            // 입력받은 사람의 친구 목록을 출력
		throw (logic_error);
	void Check(string name1, string name2)               // 입력받은 두 사람이 친구인지 아닌지 출력
		throw (logic_error);

    void clear()                                         // 소멸자를 사용하기 위해 구현
		throw (logic_error);
	bool isEmpty() const
		throw (logic_error);                             // Make에서 리스트가 비어있을 경우를 고려하기 위해 구현
private:
	Person<DT>* head,   // Pointer to the beginning of the list
		* cursor;  // 리스트를 가리킬 커서
		
};

