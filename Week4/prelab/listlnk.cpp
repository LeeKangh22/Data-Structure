
#include "listlnk.h"
#include <iostream>

using namespace std;

template<class DT>
ListNode<DT>::ListNode(const DT& nodeData, ListNode* nextPtr)
{
    dataItem = nodeData;
    next = nextPtr;
}


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
void List<DT>::insert(const DT& newData)
{
    
    if (isFull()) return;
    else {
        ListNode<DT>* newNode;
        if (isEmpty()) {
            newNode = new ListNode<DT>(newData, cursor);
            cursor = newNode;
            head = cursor;
        }
        else {
            newNode = new ListNode<DT>(newData, cursor->next);
            cursor->next = newNode;
            cursor = cursor->next;
        }
    }
}

//------------------------------------------------


template<class DT>
void List<DT>::remove()
{
    if (isEmpty()==1) cout<<"Empty List"<<endl ;
    else {
        ListNode<DT>* temp;
        temp = cursor;
        cursor = cursor->next;
        if (cursor != head->next) {
            ListNode<DT>* before;
            before = head;
            while (before->next->next != cursor)
                before = before->next;
            before->next = cursor;
        }
        else head = cursor;
        delete temp;
        if (cursor == NULL)
            gotoBeginning();
    }
}

//------------------------------------------------


template<class DT>
void List<DT>::replace(const DT& newData)
{
    if (isEmpty()==1) cout<<"Empty List!"<<endl;
    else cursor->dataItem = newData;
}

//------------------------------------------------


template<class DT>
void List<DT>::clear()
{
    if (isEmpty()==1) cout<<"Empty List!"<<endl;
    else {
        cursor = head;
        while (head != NULL) {
            ListNode<DT>* temp;
            temp = head;
            head=head->next;
            delete temp;
        }
        cursor = NULL;
    }
}

//------------------------------------------------


template<class DT>
bool List<DT>::isEmpty() const
{
    if (head == NULL) return true;
    else return false;
}

//------------------------------------------------


template<class DT>
bool List<DT>::isFull() const
{
    ListNode<DT>*newNode;
    newNode = new ListNode<DT>(NULL,NULL);
    if (newNode == NULL) return true;
    else return false;
}

//------------------------------------------------


template<class DT>
void List<DT>::gotoBeginning()
{
    if (isEmpty()==1) cout<<"Empty List!"<<endl;
    else cursor = head;
}

//------------------------------------------------


template<class DT>
void List<DT>::gotoEnd()
{
    if (isEmpty()==1) cout<<"Empty List!"<<endl;
    else {
        while (cursor->next != NULL)
            cursor = cursor->next;
    }
}

//------------------------------------------------


template<class DT>
bool List<DT>::gotoNext()
{
    if (isEmpty()==1)return false;
    else if (cursor->next == NULL) return false;
    else cursor = cursor->next;
}

//------------------------------------------------


template<class DT>
bool List<DT>::gotoPrior()
{
    if (isEmpty()==1) return false;
    else if (cursor == head) return false;
    else {
        ListNode<DT>* before = head;
        while (before->next != cursor)
            before = before->next;
        cursor = before;
    }
}

//------------------------------------------------


template<class DT>
DT& List<DT>::getCursor() const
{
    DT item;
    item = cursor->dataItem;
    if (isEmpty()) cout<<"List is Empty"<<endl;
    else return item;
}

template<class DT>
void List<DT>::showStructure() const
{
    if (isEmpty()==1)cout << "Empty List" << endl;
    else {
        ListNode<DT>* cur;
        cur = head;
        while (cur != NULL) {
            cout << "|" << cur->dataItem;
            cur = cur->next;
        }
        cout << "|" << endl;
        cur = head;
        while (cur != cursor->next) {
            cout << " ";
            if (cur == cursor)
                cout << "^";
            else cout << " ";
            cur = cur->next;
        }
    }
}//mady by 2017112074¿Ã∞≠»Ò

//------------------------------------------------

//use in-lab
template<class DT>
void List<DT>::insertBefore(const DT& newElement) {
    if (cursor == head) {
        ListNode<DT>* node = new ListNode<DT>(newElement, head);
        head = node; cursor = node;
    }
    else {
        gotoPrior();
        insert(newElement);
    }
}
