#include <iostream>
#include <string>
using namespace std;
#include<stack>
bool isBalanced(string expression)
{
    // Write your code here
    stack<char> s;
    for(int i=0;expression[i]!='\0';i++)
    {
        if(expression[i]=='{' || expression[i]=='[' ||expression[i]=='(')
        {
            s.push(expression[i]);
        }
        else if(expression[i]=='}' ||expression[i]==')' ||expression[i]==']')
        {

            if(s.empty())
            {
                return false;
            }

            else if(expression[i]=='}')
              {
                  if(s.top()!='{')
                  {
                      return false;
                  }
                s.pop();
              }

             else if(expression[i]==']')
              {
                  if(s.top()!='[')
                  {
                      return false;
                  }
                s.pop();
              }
             else if(expression[i]==')')
              {
                  if(s.top()!='(')
                  {
                      return false;
                  }
                s.pop();
              }




        }


    }
    if(!s.empty())
    {
        return false;

    }
    return true;
}
int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}
