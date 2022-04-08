#include <iostream>
#include <string.h>
using namespace std;

int convertint(char c)
{
    int m=c-'0';
    return m;
}

char correspondingChar(int m)
{
    char c = 'a' + m - 1;
    return c;
}
void helper(string input,string output)
{
    if(input[0]=='\0')
    {

            cout<<output<<endl;
            return;
    }
    string out1,out2;
    int first=convertint(input[0]);
    char firstchar=correspondingChar(first);
    int second=0;
    char secondchar='\0';
    out1=output;
    helper(input.substr(1),out1+firstchar);
    if(input[1]!='\0')
    {
        second=first*10 + convertint(input[1]);
        if(second>=10 && second<=26)
        {
            secondchar=correspondingChar(second);

            out2=output;
            helper(input.substr(2),out2+secondchar);
        }
    }
    return;


}
void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output="";
    helper(input,output);
    return;
}


int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
