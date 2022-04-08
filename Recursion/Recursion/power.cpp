#include<iostream>
using namespace std;
unsigned int pow(int x,int n)
{
    if(n==0)
    {
        return 1;
    }
    return x*pow(x,n-1);

}
int main()
{
    int x;
    cout<<"Enter NO : ";
    cin>>x;
    int n;
    cout<<"\n Enter exponential : ";
    cin>>n;
    int power=pow(x,n);
    cout<<power;
    return 0;
}
