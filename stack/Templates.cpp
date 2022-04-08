//using pair class we want to create a triplet
#include<iostream>
using namespace std;
template<typename T,typename V>
class pairs
{
    T x;
    V y;
public:
    void setX(T x)
    {
        this->x=x;
    }
    void setY(V y)
    {
        this->y=y;
    }
    T getX()
    {
         return x;
    }
    V getY()
    {
        return y;
    }

};
int main()
{
    pairs<pairs<int,double>,char> p1;
    p1.setY('a');
    pairs<int,double> p2;
    p2.setX(10);
    p2.setY(30.4);
    p1.setX(p2);
    cout<<p1.getX().getX()<<" "<<p1.getX().getY()<<" "<<p1.getY();
    return 0;
}
