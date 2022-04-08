#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[],int m=0)
{
    if(input.length()==0)
    {
        output[0]="";
        return 1;
    }
    int ans=returnPermutations(input.substr(1),output);
    for(int i=0;i<ans;i++)
    {
        output[i]=input[0]+output[i];
    }
    return ans;
}
int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
