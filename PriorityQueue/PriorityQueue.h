#include<iostream>
#include <vector>
using namespace std;
class PriorityQueue {
public:

    std::vector<int> pq;
    bool isEmpty() {
        return pq.size() == 0;
    }

    int getSize() {
        return pq.size();
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        // Write your code here
        int lastIndex=pq.size()-1;
        int temp=pq[lastIndex];
        pq[lastIndex]=pq[0];

        pq[0]=temp;
        int val=pq[lastIndex];
        pq.pop_back();
        int currentIndex=0;
        while(currentIndex<pq.size()-1)
        {
            int ci1=(2*currentIndex)+1;
            int ci2=(2*currentIndex)+2;
            if(ci2<pq.size())
            {
                if(pq[ci1]<pq[ci2])
                {
                    if(pq[currentIndex]>pq[ci1])
                    {
                        int temp=pq[currentIndex];
                        pq[currentIndex]=pq[ci1];
                        pq[ci1]=temp;
                        currentIndex=(2*currentIndex)+1;
                    }
                    else
                    {
                        break;
                    }
                }
                else if(pq[ci1]>pq[ci2])
                {
                    if(pq[currentIndex]>pq[ci2])
                    {
                        int temp=pq[currentIndex];
                        pq[currentIndex]=pq[ci2];
                        pq[ci2]=temp;
                        currentIndex=(2*currentIndex)+2;
                    }
                    else
                    {
                        break;
                    }

                }
            }
            else if(ci1<pq.size())
            {
                    if(pq[currentIndex]>pq[ci1])
                    {
                        int temp=pq[currentIndex];
                        pq[currentIndex]=pq[ci1];
                        pq[ci1]=temp;
                        currentIndex=(2*currentIndex)+1;
                    }
                    else
                    {
                        break;
                    }
            }
            else
            {
                break;
            }



        }
        return val;
    }
    void print()
    {
        for(int i=0;i<pq.size();i++)
        {
            cout<<pq[i]<<" ";
        }
        cout<<endl;
    }
};
