#include<iostream>
using namespace std;
bool checksort2(int a[],int n)
{
    if(n<=1)
    {
        return true;
    }
    if(a[0]>a[1])
    {
        return false;
    }
    return checksort2(a+1,n-1);



}
int checksort(int a[],int n)
{   if(n<=1)
   {
     return 1;
   }
    if(a[n-1]<a[n-2])
    {
        return 0;
    }

    return checksort(a,n-1);
}
int main()
{
    int n;
    cout<<"ENTER SIZE : ";
    cin>>n;
    int a[n];
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<endl<<endl;
    //int check=checksort(a,n);
    bool check=checksort2(a,n);
    if(check)
    {
        cout<<"sorted";
    }
    else{
        cout<<"unsorted";
    }
    //cout<<check;


}
