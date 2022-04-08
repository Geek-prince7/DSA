#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<input.size();i++)
    {
        for(int j=0;j<input[i]->size();j++)
        {
            pq.push(input.at(i)->at(j));
        }
    }
    vector<int> out;
    while(!pq.empty())
    {
        out.push_back(pq.top());
        pq.pop();
    }
    return out;


}
*/


class triplet
{
public:
    int element;
    int arrayIndex;
    int elemenrIndex;

};

    bool operator<(const triplet &t1,const triplet &t2)
    {
        return t1.element > t2.element;
    }
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    priority_queue<triplet> pq;
    int k=input.size(); //no of arrays
    int i=0;
    while(i<k)
    {
        triplet t;
        t.arrayIndex=i;
        t.elemenrIndex=0;
        t.element=input[i]->at(0);
        cout<<t.element<<" pushed in pq "<<endl;
        pq.push(t);
        i++;
    }
    vector<int> out;
    while(!pq.empty())
    {
        triplet t=pq.top();
        out.push_back(t.element);
        cout<<t.element<<" popped from pq and pushed in vector out"<<endl;

        pq.pop();
        if(t.elemenrIndex+1<input[t.arrayIndex]->size())
        {
            t.elemenrIndex+=1;
            t.element=input[t.arrayIndex]->at(t.elemenrIndex);
            pq.push(t);
            cout<<t.element<<" pushed in pq "<<endl;

        }
    }




    return out;


}


int main() {
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}
