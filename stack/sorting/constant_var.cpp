#include<iostream>
using namespace std;
int main()
{
    const int j=9;
    const int &k=j;
//    k++; //not allowed
    cout<<j;

    return 0;
}
