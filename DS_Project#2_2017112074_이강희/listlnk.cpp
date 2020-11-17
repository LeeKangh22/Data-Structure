
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

/*����Ʈ�� ������� ��� ������ ���ο� ID�� head�� �α� ���� isEmpty()�̿�*/
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

/*�� �Ķ���͸� �ް� �׿� ���� �����ϴ� flag1, flag2�� �����Ѵ�.
����Ʈ�� ������ �Ķ���Ϳ� �ش��ϴ� ����� �ִٸ� flag�� 1�� ��ŷ�Ѵ�
�� �� ���� �ش��ϴ� ����� ���ٸ� flag�� 0���� �����ǰ�
�ش��ϴ� flag�� 0�̶�� �� ����� �������� ������ ����Ѵ�.
�׸��� temp�� ����� �̸� head�� �ΰ� ����� ��������Ʈ�� �����ϸ鼭
name1�� �ش��ϴ� ����� �����ϸ� �� ��ü�� ������ �ִ� map�� name2�� ģ���� �����Ѵ�.
name2�� ���� ���� �˰������� �����Ѵ�.*/
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

/*�Ķ���ͷ� ���� �� �̸� name1�� name2�� ���� �������� ����� ����Ʈ��
��ĭ �� �����ϸ� name1�� �ش��ϴ� ��忡 �������� ���
�� ��ü�� ������ �ִ� map���� ģ�� ����� ������ name2�� ã�´�.
���� name2�� �����Ѵٸ� name2�� �� map���� �����ϰ�
�̴� name2������ �����ϰ� ����Ǿ�� �ϹǷ� name2�� ���ؼ���
�����ϰ� name1�� �����ϴ� �۾��� ���ش�.*/
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

/*�Ķ���ͷ� ���� name�� ���� �� name�� ������ �ִ� map�� ��� ������ ������ش�.*/
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

/*name1�� name2�� ģ����� name2�� ���� �۾��� ������ ���� �ʾƵ� �Ǳ� ������
name1�� ���� �۾��� ������ �ش�. �̶�, name1�� �ش��ϴ� ���, �� �� ��ü�� �����ִ�
map�� name2�� �����Ѵٸ� flag�� 1�� �����Ͽ� ���� ģ������ ��Ÿ����.
���� �������� �ʴ´ٸ� flag�� 0���� �����Ǿ� ģ���� �ƴ��� ��Ÿ����.*/
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
//mady by 2017112074�̰���
//
//------------------------------------------------

