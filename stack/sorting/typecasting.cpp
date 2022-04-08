#include<iostream>
using namespace std;
int main()
{
    char a='A';
    char *pc=&a;
    int *p=(int*)pc;
    cout<<*p;
    return 0;

}
