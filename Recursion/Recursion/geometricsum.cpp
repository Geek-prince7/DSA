#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
double gs(int k)
{
    if(k==0)
    {
        return 1;

    }
    double ans=gs(k-1);
    return 1+((0.5)*ans);   ///cant use 1/2 instead of 0.5 as it treats 1/2 as interger so 1/2=0
}
int main()
{
    int n;
    cout<<"Enter value of n : ";
    cin>>n;
    double sol=gs(n);
    cout<<fixed<<setprecision(5);
    cout<<sol;
    return 0;

}
