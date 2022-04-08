#include<stdio.h>
#include<conio.h>
struct student
{
    int roll;
    char name[10];
    float marks;
};
int main(int argc, char const *argv[])
{
    
    struct student s1[3];
    struct student *ptr=s1;
    //int i;
    //for(i=0;i<3;i++)
    //{
        scanf("%d",ptr->roll);

    //}
    //for(i=0;i<3;i++)
    //{
        printf("You have entered roll no : %d",*(int*)ptr->roll);
        
    //}

    return 0;
    
}

