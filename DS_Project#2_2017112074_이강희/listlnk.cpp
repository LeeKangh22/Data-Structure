
#include "listlnk.h"
#include <iostream>
#include<unordered_map>

using namespace std;

//------------------------------------------------

template<class DT>
Person<DT>::Person(string name, Person* nextPtr)
{
    this->name = name;
    next = nextPtr;
}

//------------------------------------------------

template<class DT>
List<DT>::List(int ignored)
{
    head = NULL;
    cursor = NULL;
}

//------------------------------------------------


template<class DT>
List<DT>::~List()
{
    clear();
}

//------------------------------------------------

template<class DT>
bool List<DT>::isEmpty() const
{
    if (head == NULL) return true;
    else return false;
}

//------------------------------------------------

/*리스트가 비어있을 경우 생성된 새로운 ID를 head로 두기 위해 isEmpty()이용*/
template<class DT>
void List<DT>::Make(string name)
{
   Person<DT>* newPerson;
   if (isEmpty()) {
       newPerson = new Person<DT>(name, cursor);
       cursor = newPerson;
       head = cursor;
   }
   else {
       newPerson = new Person<DT>(name, cursor->next);
       cursor->next = newPerson;
       cursor = cursor->next;
   }
   
}

//------------------------------------------------

/*두 파라미터를 받고 그에 각각 대응하는 flag1, flag2를 생성한다.
리스트에 각각의 파라미터에 해당하는 사람이 있다면 flag를 1로 마킹한다
이 때 만약 해당하는 사람이 없다면 flag는 0으로 유지되고
해당하는 flag가 0이라면 그 사람이 존재하지 않음을 출력한다.
그리고 temp를 만들어 이를 head로 두고 연결된 다음리스트로 전진하면서
name1에 해당하는 사람이 존재하면 그 객체가 가지고 있는 map에 name2를 친구로 생성한다.
name2도 위와 같은 알고리즘으로 구현한다.*/
template<class DT>
void List<DT>::Record_friend(string name1, string name2)
{
    int flag1 = 0, flag2 = 0;
    Person<DT>* stranger = head;

    while (stranger != NULL) {
        if ((stranger->name) == name1) flag1 = 1;
        else if ((stranger->name) == name2) flag2 = 1;
        stranger = stranger->next;
    }
    if (flag1 == 0) cout << name1 << "isn't exist in facebook." << endl;
    else if (flag2 == 0)cout << name2 << "isn't exist in facebook." << endl;
    else {
        Person<DT>* temp = head;
        while (temp != NULL) {
            if (temp->name == name1) {
                temp->f_list.insert(unordered_map<int, string>::value_type(temp->order, name2)); 
                temp->order = temp->order + 1;
            }
            else if (temp->name == name2) {
                temp->f_list.insert(unordered_map<int, string>::value_type(temp->order, name1));
                temp->order = temp->order + 1;
            }
            temp = temp->next;
        }
        cout << "Record that " << name1 << " and " << name2 << " are freind." << endl;
    }

}

//------------------------------------------------

/*파라미터로 받은 두 이름 name1과 name2에 대해 다음으로 연결된 리스트로
한칸 씩 전진하며 name1에 해당하는 노드에 도달했을 경우
그 객체가 가지고 있는 map에서 친구 목록을 제거할 name2를 찾는다.
만약 name2가 존재한다면 name2를 그 map에서 제거하고
이는 name2에서도 동일하게 수행되어야 하므로 name2에 대해서도
동일하게 name1을 제거하는 작업을 해준다.*/
template<class DT>
void List<DT>::Record__N_friend(string name1, string name2)
{
    
    Person<DT>* temp = head;
    while (temp != NULL) {
        if (temp->name == name1) {
            for (int i = 1; i < temp->order; i++) {
                if (temp->f_list[i] == name2) temp->f_list.erase(temp->f_list.find(i));
            }
        }
        else if (temp->name == name2) {
            for (int i = 1; i < temp->order; i++) {
                if (temp->f_list[i] == name1) temp->f_list.erase(temp->f_list.find(i));
            }
        }
        temp = temp->next;
    }
    cout << "Record that " << name1 << " and " << name2 << " are not freind." << endl;
}

//------------------------------------------------

/*파라미터로 받은 name에 대해 그 name이 가지고 있는 map의 모든 정보를 출력해준다.*/
template<class DT>
void List<DT>::Display(string name1)
{
    Person<DT>* find = head;
    while (find != NULL) {
        if (find->name == name1) {
            for (int i = 0; i < find->order; i++) {
                cout << (find->f_list)[i] << " ";
            }
        }
        find = find->next;
    }
    delete find;
}

//------------------------------------------------

/*name1과 name2가 친구라면 name2에 대한 작업은 진행해 주지 않아도 되기 때문에
name1에 대한 작업만 진행해 준다. 이때, name1에 해당하는 노드, 즉 그 객체가 갖고있는
map에 name2가 존재한다면 flag를 1로 수정하여 둘이 친구임을 나타낸다.
만약 존재하지 않는다면 flag는 0으로 유지되어 친구가 아님을 나타낸다.*/
template<class DT>
void List<DT>::Check(string name1, string name2) {
    int flag = 0;
    Person<DT>* temp = head;
    while (temp != NULL) {
        for (int i = 1; i < temp->order; i++) {
            if (temp->name == name1 && temp->f_list[i] == name2) {
                cout << "Yes" << endl;
                flag = 1;
            }
        }temp = temp->next;
    }
    if (flag == 0) cout << "NO" << endl;
}

//------------------------------------------------

template<class DT>
void List<DT>::clear()
{
    
    cursor = head;
    while (head != NULL) {
        Person<DT>* temp;
        temp = head;
        head=head->next;
        delete temp;
    }
    cursor = NULL;
    
}

//------------------------------------------------
//
//mady by 2017112074이강희
//
//------------------------------------------------

