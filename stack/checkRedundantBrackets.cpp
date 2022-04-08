#include <iostream>
#include <string>
#include<stack>
using namespace std;
bool checkRedundantBrackets(string expression) {
	// Write your code here
	stack<int> s;
	int count=0;
	for(int i=0;expression[i]!='\0';i++)
    {
        if(expression[i]=='(')
        {
            for(i;expression[i]!=')';i++)
            {
                //cout<<expression[i]<<" pushed"<<endl;
                s.push(expression[i]);
            }
            i--;

        }
        else if(expression[i]==')')
        {
            if(s.empty())
            {
                //cout<<"empty stack"<<endl;
                return true;
            }
            while(s.top()!='(')
            {
                count++;
                s.pop();
            }
            s.pop();
            if(count<3)
            {
                //cout<<"count less than 3"<<endl;
                return true;
            }
            count=0;

        }

    }
    if(!s.empty())
    {
        cout<<"stack not empty after loop finish "<<endl;
        return true;
    }
    return false;


}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}
