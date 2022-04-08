#include <iostream>
#include <stack>
using namespace std;

//#include "solution.h"
void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    extra=input;

    while(!input.empty())
    {
        input.pop();
    }


    while(!extra.empty())
    {
        input.push(extra.top());
        extra.pop();
    }





}
int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}
