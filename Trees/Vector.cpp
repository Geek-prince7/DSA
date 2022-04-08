#include<iostream>
#include<vector>
using namespace std;
// basically vector are same as dynamic array !

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);

    v[2]=30;//this is not a standard way because pushback check size and double size but if we do explicitly then array size wont change to double maybe it adds maybe it wont
    //so its good to use v[index] only on those element which is already intialized by pushback...it ll be overridden by pushback
    v[0]=100;
    v.push_back(40);
    v.push_back(50);
    cout<<v.size()<<endl; //print total no of elements inserted usin pushback
    cout<<v.capacity(); //print the capacity of array
    cout<<v.at(2);  //print at index 2

    cout<<v[2]<<endl;
}
