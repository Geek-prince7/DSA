// C++ implementation of De-queue using circular
// array
#include<iostream>
using namespace std;
class Deque{
int *data;
int fi;
int ni;
int cap;
int size;
public:
    Deque(int c)
    {
        data=new int[c];
        cap=c;
        ni=0;
        fi=-1;
        size=0;
    }
    bool isFull()
    {
        return size==cap;
    }
    bool isEmpty()
    {
        return size==0;
    }
    void insertFront(int element)
    {
        if(isFull())
        {
            cout<<-1<<endl;
            return;
        }
        if(fi==-1)
        {
            data[fi+1]=element;
            fi++;
            ni++;
        }
        else{
            for(int i=ni-1;i>=fi;i--)
            {
                data[i+1]=data[i];
            }
            data[fi]=element;
            ni++;
        }
        size++;
    }
    void insertRear(int element)
    {
        if(isFull())
        {
            cout<<-1<<endl;
            return;
        }
        data[ni]=element;
        ni++;
        if(fi==-1)
        {
            fi++;
        }
        size++;

    }
    void deleteFront()
    {
        if(isEmpty())
        {
            cout<<-1<<endl;
            return;
        }
        fi++;
        size--;
    }
    void deleteRear()
    {
        if(isEmpty())
        {
            cout<<-1<<endl;
            return;
        }
        if(ni==fi+1)
        {
            fi--;
        }
        ni--;
        size--;

    }
    int getFront()
    {
        if(isEmpty())
        {
            //cout<<-1<<endl;
            return -1;
        }
        return data[fi];
    }
    int getRear()
    {
        if(isEmpty())
        {
            //cout<<-1<<endl;
            return -1;
        }
        return data[ni-1];
    }

};

//#include "Solution.h"

// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cout<<"choice 1.addF 2.addR 3.delF 4.delR 5.getF 6.getR : ";
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }

    return 0;
}
