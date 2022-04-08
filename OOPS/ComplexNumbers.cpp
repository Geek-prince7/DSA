#include<iostream>
using namespace std;
class ComplexNumbers {
    // Complete this class
    public:
        int real;
        int imaginary;
       ComplexNumbers(int re,int im)
       {
           real=re;
           imaginary=im;
       }
       void plus(ComplexNumbers c)
       {
           real=real+c.real;
           imaginary=imaginary+c.imaginary;
       }
       void multiply(ComplexNumbers c)
       {
           int r,i;
           r=real;
           i=imaginary;
           real=(real*c.real)-(imaginary*c.imaginary);
           imaginary=(r*c.imaginary)+(c.real*i);
       }
       void print()
       {
           if(imaginary>=0)
           {
               cout<<real<<" + i"<<imaginary;
           }
           else
           {
               int pos=imaginary*(-1);
               cout<<real<<" - i"<<pos;
           }
       }


};
int main()
{
    cout<<"You have to enter two complex no :"<<endl;

    int real1, imaginary1, real2, imaginary2;

    cout<<"enter first complex no "<<endl;
    cout<<"Real part : ";
    cin >> real1;
    cout<<"Imaginary part : ";
    cin>> imaginary1;
    cout<<"enter second complex no "<<endl;
    cout<<"Real part : ";
    cin >> real2;
    cout<<"Imaginary part : ";
    cin>> imaginary2;
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;

    cout<<"press 1 for + and 2 for * : ";
    cin >> choice;

    if(choice == 1) {
        c1.plus(c2);
        cout<<endl<<"Addition is  :  ";
        c1.print();
        cout<<endl;
    }
    else if(choice == 2) {
        c1.multiply(c2);
        cout<<endl<<"Multiplication is  :  ";
        c1.print();
        cout<<endl;
    }
    else {
        return 0;
    }
}
