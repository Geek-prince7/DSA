/*
question .
given array a and size-n ...thier is a new array b of size k*n and we need to find the maximum sum of subarray by concat k copies of a
input - int n,int k ,n elemtnts of array a
out - max sum
*/
/*
#include<iostream>
using namespace std;
typedef long long ll;
ll kadanes(int *arr,int n)
{
    int maxi=0;
    int maxSum=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            maxi=0;
            continue;
        }
        maxi+=arr[i];
        if(maxSum<maxi)
        {
            maxSum=maxi;
        }
    }
    return maxSum;

}
ll maxsum(int *a,int n,int k)
{
    ll maxi=0,cb=0;
    int positive=0;
    if(k==1)
    {
        return kadanes(a,n);
    }
    for(int i=0;i<(n*2);i++)
    {
        if(a[i%n]<0)
        {
            cb=0;
            continue;
        }
        cb+=a[i%n];
        positive++;
        //cout<<cb<<endl;
        if(maxi<cb)
        {
            maxi=cb;
        }
    }
    if(positive==2*n)
    {
        maxi=maxi/2;
        maxi*=k;
    }

    return maxi;
}

int main()
{
    int n,k;
    cin>>n>>k;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<maxsum(a,n,k);
    return 0;
}
*/
#include<iostream>
using namespace std;
typedef long long ll;
ll kadanes(int *arr,int n)
{
    int maxi=0;
    int maxSum=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            maxi=0;
            continue;
        }
        maxi+=arr[i];
        if(maxSum<maxi)
        {
            maxSum=maxi;
        }
    }
    return maxSum;

}
ll maxsum(int *a,int n,int k)
{
    ll maxi=0,cb=0;
    int positive=0;
    if(k==1)
    {
        return kadanes(a,n);
    }
    for(int i=0;i<(n);i++)
    {
        if(a[i]<0)
        {
            cb=0;
            continue;
        }
        cb+=a[i];
        positive++;
        //cout<<cb<<endl;
        if(maxi<cb)
        {
            maxi=cb;
        }
    }
    if(positive==n)
    {
        //maxi=maxi/2;
        maxi*=k;
        return maxi;
    }
    //find suffix and prefix
    ll ss=0,ps=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            break;
        }
        ps+=a[i];
    }

    for(int i=n-1;i>=0;i--)
    {
        if(a[i]<0)
        {
            break;
        }
        ss+=a[i];
    }
    if(ps+ss>maxi)
    {
        maxi=ps+ss;
    }

    return maxi;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(k<=0)
        {
            cout<<0<<endl;
        }
        int *a=new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<maxsum(a,n,k)<<endl;
    }
    return 0;
}
