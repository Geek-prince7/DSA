#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
void hussainset(int *arr,int n)
{
    queue<int> q1;
    sort(arr,arr+n);
    int last=n-1;
    while(last>=0 || !q1.empty())
    {
        if(q1.empty())
        {
            int l=arr[last];
            cout<<arr[last]<<endl;
            last--;
            l=l/2;
            if(l>0)
            {
                q1.push(l);
            }

        }
        else
        {
            //check if queue front >last element
            if(last<0 ||q1.front()>arr[last] )
            {
                int l=q1.front();
                cout<<l<<endl;
                q1.pop();
                l=l/2;
                if(l>0)
                {
                    q1.push(l);
                }
            }
            else{
                int l=arr[last];
                last--;
                cout<<l<<endl;
                l=l/2;
                if(l>0)
                {
                    q1.push(l);
                }
            }
        }

    }

}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    //int question[k];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    /*
    for(int i=0;i,k;i++)
    {
        cin>>question[k];
    }
    */
    hussainset(arr,n);

}
