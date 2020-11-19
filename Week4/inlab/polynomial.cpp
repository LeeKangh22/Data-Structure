#include <iostream>
#include <cmath>
#include "listlnk.cpp"

using namespace std;

class PolyNode {
private:
    // Data members
    int coefficient; //계수
    int degree;       //차수
   
public:
    
    PolyNode() {
        coefficient = 0;
        degree = 0;
    }
  
    PolyNode(int c, int d) {
        coefficient = c;
        degree = d;
    }

    //계수 반환   
    int getCoef() {
        return coefficient;
    }
    
    //차수 반환
    int getDegree() {
        return degree;
    }

    //계수 변환
    void addCoef(int added) {
        coefficient += added;
    }
};

//c: coefficient, d: degree
void addTerm(List<PolyNode>* list, int c, int d) {
    PolyNode temp(c, d);
    if (list->isEmpty() == 1) {
        list->insertBefore(temp);
        return;
    }
    
    PolyNode cmp;
    list->gotoBeginning();
    cmp = list->getCursor();

    while (list->isEnd()!=1) {
        if (temp.getDegree() == cmp.getDegree()) {
            cmp.addCoef(temp.getCoef());
            list->replace(cmp);
            return;
        }
        
        if (temp.getDegree() > cmp.getDegree()) {
            list->insertBefore(temp);
            return;
        }list->gotoNext();
        cmp = list->getCursor();
    } list->gotoEnd();
   
    if (temp.getDegree() > cmp.getDegree()) {
        list->insertBefore(temp);
        return;
    }
    if (temp.getDegree() == cmp.getDegree()) {
        cmp.addCoef(temp.getCoef());
        list->replace(cmp);
        return;
    } list->insert(temp);
}

//다항식 출력 함수
void showPolynomial(List<PolyNode>& list) {
    list.gotoBeginning();
    if (list.isEmpty()==1) return;
    
    PolyNode temp1 = list.getCursor();
    if (temp1.getCoef() < 0) {
        if (temp1.getCoef() == -1) {
            cout << '-';
            if (temp1.getDegree() == 0)
                cout << -1 * temp1.getCoef() << ' ';
            else
                cout << "x^" << temp1.getDegree() << ' ';
        }
        else {
            cout << '-';
            if (temp1.getCoef() == 0)
                cout << -1 * temp1.getCoef() << ' ';
            else
                cout << -1 * temp1.getCoef() << "x^" << temp1.getDegree() << ' ';
        }
    }
    else {
        if (temp1.getCoef() == 1) {
            if (temp1.getDegree() == 0)
                cout << temp1.getCoef() << ' ';
            else
                cout << "x^" << temp1.getDegree() << ' ';
        }
        else {
            if (temp1.getCoef() == 0)
                cout << temp1.getCoef() << ' ';
            else
                cout << temp1.getCoef() << "x^" << temp1.getDegree() << ' ';
        }
    }
    
    while (list.isEnd() != 1) {
        list.gotoNext();
        PolyNode temp2 = list.getCursor();
        if (temp2.getCoef() < 0) {
            if (temp2.getCoef() == -1) {
                cout << '-';
                if (temp2.getDegree() == 0)
                    cout << ' ' << -1 * temp2.getCoef() << ' ';
                else
                    cout << "x^" << temp2.getDegree() << ' ';
            }
            else {
                cout << '-';
                if (temp2.getDegree() == 0)
                    cout << ' ' << -1 * temp2.getCoef() << ' ';
                else
                    cout << ' ' << -1 * temp2.getCoef() << "x^" << temp2.getDegree() << ' ';
            }
        }
        else {
            if (temp2.getCoef() == 1) {
                cout << '+';
                if (temp2.getDegree() == 0)
                    cout << ' ' << temp2.getCoef() << ' ';
                else
                    cout << "x^" << temp2.getDegree() << ' ';
            }
            else {
                cout << '+';
                if (temp2.getDegree() == 0)
                    cout << ' ' << temp2.getCoef() << ' ';
                else
                    cout << ' ' << temp2.getCoef() << "x^" << temp2.getDegree() << ' ';
            }
        }
    }
    cout << endl;
}//made by 2017112074이강희

void main()
{
    List<PolyNode> testList;   // Test list
    int coef, degree;          // List data item
    char cmd;                  // Input command
    
    do
    {        
        showPolynomial(testList);                     // Output list

        cout << endl << "Command: ";                  // Read command
        cin >> cmd;
        if ( cmd == '+'  ||  cmd == '-')
           cin >> degree >> coef;

        switch ( cmd )
        {
          case '+' :                                  // insert
              addTerm(&testList, coef, degree);
               break;

          case '-' :                                  // remove
              coef *= -1;
              addTerm(&testList, coef, degree);
               break;

          case 'C' : case 'c' :                       // clear
               testList.clear();
               break;

          case 'Q' : case 'q' :                   // Quit test program
               break;

          default :                               // Invalid command
               cout << "Inactive or invalid command" << endl;
        }
    }
    while ( cmd != 'Q'  &&  cmd != 'q' );
}

