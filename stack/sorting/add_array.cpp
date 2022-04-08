#include<iostream>
using namespace std;
int main()
{
    int a[6]={2,5,7,1,2,9};
    int b[5]={7,6,4,9,5};
    int lasta=5;
    int lastb=4;
    int carry=0;
    int g=2+max(lasta,lastb);
    int c[g];
    int i;
    for(i=6;i>=0;i--)
    {     if(lasta>=0 && lastb>=0)
         {


           carry=a[lasta]+b[lastb]+carry;
           lasta--;
           lastb--;
           c[i]=carry%10;
           carry=carry/10;
         }
         else{
            break;
         }

    }

    while(lasta>=0)
    {
        carry=carry+a[lasta];
        c[i]=carry%10;
        lasta--;
        carry=carry/10;
        i--;


    }
     while(lastb>=0)
    {
        carry=carry+b[lastb];
        c[i]=carry%10;
        lastb--;
        carry=carry/10;
        i--;


    }
    c[i]=carry;
    for(int i=0;i<g;i++)
    {

        cout<<c[i];
    }
}
