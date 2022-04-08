#include<iostream>
using namespace std;
 class DynamicArray
 {
     int *data;
     int nextIndex;
     int capacity;
 public:

     DynamicArray()
     {

         data=new int[5];
         nextIndex=0;
         capacity=5;
     }
     DynamicArray(DynamicArray const &d)
     {
         //deep copy
         data=new int[d.capacity];
         for(int i=0;i<d.nextIndex;i++)
         {
             data[i]=d.data[i];
         }
         //
         nextIndex=d.nextIndex;
         capacity=d.capacity;

     }
     void operator= (DynamicArray const &d)
     {

         //deep copy
         data=new int[d.capacity];
         for(int i=0;i<d.nextIndex;i++)
         {
             data[i]=d.data[i];
         }
         //
         nextIndex=d.nextIndex;
         capacity=d.capacity;


     }
     void add(int element)
     {
         if(nextIndex==capacity)
         {
             capacity*=2;
             int *d=new int[capacity];
             for(int i=0;i<capacity/2;i++)
             {
                 d[i]=data[i];
             }
             delete []data;
             data=d;
         }
         data[nextIndex]=element;
         nextIndex++;
     }
     void addAtIndex(int index,int element)
     {
         if(index<nextIndex)
         {
             data[index]=element;
         }
         else if(index==nextIndex)
         {
             add(element);
         }
         else{
            return;
         }
     }
     int getDataAtIndex(int index)
     {
         if(index>=nextIndex)
         {
             return -1;
         }
         return data[index];
     }
     void printdata()
     {
         for(int i=0;i<nextIndex;i++)
         {
             cout<<"Element "<<i+1<<" is : "<<data[i]<<endl;
         }
     }
 };

 int main()
 {
     DynamicArray d1;

     d1.add(3);
     d1.add(4);
     d1.add(5);
     d1.add(7);
     DynamicArray d2(d1);//calling copy const and shallow copy ..now in d2 cap=5,nextIndex=4 and array is same and now i we add in d2 it will overwrite the 4th and 5th index....to overcome we create our own copy constructor

     d2.add(27);
     d2.add(77);
     d1.add(9);
     DynamicArray d3;
     d3=d1;//copy assignment operator it also acts like copy constructor and can disturb data to over come this we create our own copy assignment operator with deep copy
     d3.add(100);
     d3.add(200);
     d1.add(11);
     int k;
     cout<<"enter an index i will fetch the data : ";
     cin>>k;
     cout<<d1.getDataAtIndex(k)<<endl;
     cout<<"now printing all data of d1"<<endl;
     d1.printdata();
     cout<<"now printing all data of d2"<<endl;
     d2.printdata();
     cout<<"now printing all data of d3"<<endl;
     d3.printdata();
 }
