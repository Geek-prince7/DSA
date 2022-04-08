#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a,b,choice;
    float c;
    printf("ENTER A NO : ");
    scanf("%d",&a);
     printf("ENTER SECOND NO : ");
    scanf("%d",&b);
    printf("press 1 for +");
    printf("press 2 for -");
    printf("press 3 for *");
    printf("press 4 for /");
    printf("press 5 for %");
    scanf("%d",&choice);
    if (choice==1)
    {
        c=a+b;
        
    }
    if (choice==2)
    {
        c=a-b;
    }
    if (choice==3)
    {
        c=a*b;
    }
    if (choice==4)
    {
        c=a/b;
    }
    if (choice==5)
    {
        c=a%b;
    }
    printf("ANS IS : %f",c);
    return 0;
}
