#include<stdio.h>
#define N 5
int stack[N];
unsigned capacity;
int top=-1;
bool Isfull()
{
    if (top==capacity-1)
    {
        return true;
    }
}
bool IsEmpty()
{
    if (top==-1)
    {
        return true;
    }
}
void CreateStack(int data)
{
    bool a=Isfull();
    if(a==true)
    {
        printf("stack overflow");
    }
    else{
        top++;
        stack[top]=data;
    }

}
void display()
{

    for(int i=0;i<capacity;i++)
    {

        printf("%d \n",stack[i]);
    }
}
int main()
{CreateStack(5);
CreateStack(4);
CreateStack(3);
CreateStack(2);
CreateStack(1);
CreateStack(77);


}
