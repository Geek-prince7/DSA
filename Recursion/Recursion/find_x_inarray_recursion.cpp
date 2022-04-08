#include<iostream>
using namespace std;
bool helper(int arr[],int si,int ei,int x)
{

    int half=(ei+si)/2;

if(arr[half]==x)
{
    return true;

}
helper(arr,si,half-1,x);
helper(arr,half+1,ei,x);
if(ei==si)
{
    return false;
}

}
bool checkNumber(int input[], int size, int x) {
  /*
    if(size<=0)
    {
        return false;
    }
    if(input[0]==x)
    {
        return true;
    }
    return checkNumber(input+1,size-1,x);
*/
bool res=helper(input,0,size-1,x);
return res;
}




int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int x;

    cin >> x;

    if(checkNumber(input, n, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}


