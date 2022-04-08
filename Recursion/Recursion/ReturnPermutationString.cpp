#include <iostream>
#include <string>
using namespace std;
void swapstringplaces(string input)
{
    int f=input.length();

        char k=input[input.length()-1];
        int j;
        for(j=f-1;j>=1;j--)
        {
            input[j]=input[j-1];
        }
        input[0]=k;

}
int returnPermutations(string input, string output[],int m=0){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if(input.length()==0)
    {
        output[0]="";
        return 1;
    }
    int ans=0;
     //string out1[1000];
    for(int i=1;i<=input.length();i++)
    {

        ans=returnPermutations(input.substr(1),output,m);
        int j=0;
        for(int j=0;j<ans;j++)
        {
            output[j]=input[0]+output[j];
        }
            swapstringplaces(input);
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
