/*
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks.
The objective of the puzzle is to move all disks from source rod to destination rod using third rod (say auxiliary).
The rules are :
1) Only one disk can be moved at a time.
2) A disk can be moved only if it is on the top of a rod.
3) No disk can be placed on the top of a smaller disk.
Print the steps required to move n disks from source rod to destination rod.
Source Rod is named as 'a', auxiliary rod as 'b' and destination rod as 'c'.

Sample Input 1 :
2
Sample Output 1 :
a b
a c
b c
Sample Input 2 :
3
Sample Output 2 :
a c
a b
c b
a c
b a
b c
a c

*/
#include<iostream>
using namespace std;
void TOH(int n,char source ,char aux,char des)
{
    if(n<=0)
    {
        return;
    }
    if(n==1)
    {
        cout<<"Move disk 1 from rod : "<<source<<" to rod : "<<des<<endl;
        return;
    }
    TOH(n-1,source,des,aux);
    cout<<"Move disk "<<n<<" from rod : "<<source<<" to rod : "<<des<<endl;
    TOH(n-1,aux,source,des);
    return;
}
int main()
{
    cout<<endl;
    cout<<"---------------TOWER OF HANOI -----------------"<<endl<<endl<<endl;
    int n;
    cout<<"Enter the no of disks : ";
    cin>>n;
    cout<<endl;
    TOH(n,'A','B','C');
    return 0;
}
