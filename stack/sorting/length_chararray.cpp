#include <iostream>
#include <cstring>
using namespace std;

void trimSpaces(char input[]) {
    // Write your code here
     int count=0;
     for(int i=0;input[i]!='\0';i++)
     {
         count++;
     }
     int i,j;
     bool found=false;
     for(i=(count-2);i>=0;i--)
     {

         //char last=input[]
         char temp=input[i];
         for(j=i+1;j<count;j++)
         {
             if(temp==' ')
             {
                 input[j-1]=input[j];
                 found=true;
             }
             else
             {
                 found=false;
             }

         }
         if(found)
         {
           input[j-1]='\0';
         }
     }
 }
 int main() {
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}





