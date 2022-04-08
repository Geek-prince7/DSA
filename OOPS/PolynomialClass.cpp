#include<iostream>
using namespace std;
class Polynomial
{

public:
    int *cofficient;
    int capacity;
    Polynomial()
    {
        cofficient=new int[5];
        capacity=5;
        for(int i=0;i<capacity;i++)
        {
            cofficient[i]=0;
        }
    }
    Polynomial(Polynomial const &p)
    {
        capacity=p.capacity;
        cofficient=new int[p.capacity];
        for(int i=0;i<p.capacity;i++)
        {
            cofficient[i]=p.cofficient[i];
        }
    }
    void operator=(Polynomial const &p)
    {
         capacity=p.capacity;
        cofficient=new int[p.capacity];
        for(int i=0;i<p.capacity;i++)
        {
            cofficient[i]=p.cofficient[i];
        }

    }
    void setCofficient(int index,int val)
    {
        if(index>=capacity)
        {
            int *ptr=new int[index+10];
            for(int i=0;i<capacity;i++)
            {
                ptr[i]=cofficient[i];
            }
            for(int i=capacity;i<index+10;i++)
            {
                ptr[i]=0;
            }
            delete []cofficient;
            cofficient=ptr;
            capacity=index+10;
        }
        cofficient[index]=val;
    }
    Polynomial operator+(Polynomial const &p)
    {
        Polynomial pnew;
        int maxcap=max(capacity,p.capacity);
        delete []pnew.cofficient;
        pnew.cofficient=new int[maxcap];
        int i=0,j=0,k=0;
        while(i<capacity && j<p.capacity)
        {
            pnew.cofficient[k]=cofficient[i]+p.cofficient[j];
            i++;
            j++;
            k++;
        }
        while(i<capacity)
        {
            pnew.cofficient[k]=cofficient[i];
            k++;
            i++;
        }
        while(j<p.capacity)
        {
            pnew.cofficient[k]=p.cofficient[j];
            k++;
            j++;
        }
        return pnew;

    }
     Polynomial operator-(Polynomial const &p)
    {
        Polynomial pnew;
        int maxcap=std::max(capacity,p.capacity);
        delete []pnew.cofficient;
        pnew.cofficient=new int[maxcap];
        int i=0,j=0,k=0;
        while(i<capacity && j<p.capacity)
        {
            pnew.cofficient[k]=cofficient[i]-p.cofficient[j];
            i++;
            j++;
            k++;
        }
        while(i<capacity)
        {
            pnew.cofficient[k]=cofficient[i];
            k++;
            i++;
        }
        while(j<p.capacity)
        {
            pnew.cofficient[k]=(-1)*(p.cofficient[j]);
            k++;
            j++;
        }
        return pnew;

    }
    Polynomial operator*(Polynomial const &p)
    {
        Polynomial pnew;
        delete []pnew.cofficient;
        pnew.cofficient=new int[capacity*(p.capacity)];
        pnew.capacity=capacity*p.capacity;
        for(int i=0;i<pnew.capacity;i++)
        {
            pnew.cofficient[i]=0;
        }
        for(int i=0;i<capacity;i++)
        {
            for(int j=0;j<p.capacity;j++)
            {
                pnew.cofficient[i+j]+=cofficient[i]*p.cofficient[j];
            }
        }
        return pnew;

    }
    void print() const
    {
        for(int i=0;i<capacity;i++)
        {
            if(cofficient[i]==0)
            {
                continue;
            }
            else
            {
                cout<<cofficient[i]<<"x"<<i<<" ";
            }

        }
                //cout<<cofficient[capacity-1]<<"x"<<capacity-1;

    }
};
int main()
{
    int count1,count2,choice;
    cout<<"enter 1 st polynomial terms : ";
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for(int i=0;i < count1; i++) {
        cout<<"enter degree "<<i<<" : ";
        cin >> degree1[i];
    }

    for(int i=0;i < count1; i++) {
        cout<<"enter cofficient "<<i<<" : ";
        cin >> coeff1[i];
    }

    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCofficient(degree1[i],coeff1[i]);
    }
   // cout<<endl;
    //first.print();


    cout<<"enter 2nd polynomial terms : ";
    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for(int i=0;i < count2; i++) {
        cout<<"enter degree of poly 2 "<<i<<" : ";
        cin >> degree2[i];
    }

    for(int i=0;i < count2; i++) {
        cout<<"enter cofficient of poly 2 "<<i<<" : ";
        cin >> coeff2[i];
    }
     Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCofficient(degree2[i],coeff2[i]);
    }

    cout<<"1 for + 2 for - 3 for * 4 for copy const 5 for copy assign operator";
    cin >> choice;

    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;

        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.cofficient == first.cofficient) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.cofficient == first.cofficient) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

    }

     return 0;
}
