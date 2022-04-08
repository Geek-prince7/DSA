#include<string>
using namespace std;

template<typename V>
class mapNode
{
public:
    string key;
    V value;
    mapNode *next;
    mapNode(string key,V value)
    {
        this->key=key;
        this->value=value;
        this->next=NULL;
    }
    ~mapNode()
    {
        delete next;
    }
};

template<typename V>
class ourmap
{
    mapNode<V>** buckets;
    int count;
    int numBuckets;
public:
    ourmap()
    {
        count=0;
        numBuckets=5;
        buckets=new mapNode<V>*[numBuckets];
        for(int i=0;i<numBuckets;i++)
        {
            buckets[i]=NULL;
        }

    }
    ~ourmap()
    {
        for(int i=0;i<numBuckets;i++)
        {
            delete buckets[i];
        }
        delete [] buckets;

    }


    int size()
    {
        return count;
    }

    double getLoadFactor()
    {
        return (1.0*count)/numBuckets;
    }


    void insert(string key,V value)
    {
        int bucketIndex=getBucketIndex(key);
        mapNode<V> *head=buckets[bucketIndex];
        //now find if already exist
        mapNode<V> *temp=head;

        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                temp->value=value;
                return;
            }
            temp=temp->next;
        }
        mapNode<V> *newnode=new mapNode<V>(key,value);
        newnode->next=head;
        buckets[bucketIndex]=newnode;
        count++;
        double loadfactor=(1.0*count)/numBuckets;
        if(loadfactor>0.7)
        {
            rehashing();
        }
        return;


    }


    V remove(string key)
    {
        int bucketIndex=getBucketIndex(key);
        mapNode<V> *head=buckets[bucketIndex];
        mapNode<V> *prev=NULL;
        V val=0;
        while(head!=NULL)
        {
            if(head->key==key)
            {
                if(prev==NULL)
                {
                    buckets[bucketIndex]=head->next;
                    //val=head->value;
                    //head->next=NULL;
                    //count--;
                    //delete head;
                    //break;
                }
                else
                {
                    //val=head->value;
                    prev->next=head->next;

                    //break;
                }
                val=head->value;
                head->next=NULL;
                count--;
                delete head;
                break;

            }
            prev=head;
            head=head->next;
        }

        return val;

    }

    V getValue(string key)
    {
        V val=0;
        int bucketIndex=getBucketIndex(key);
        mapNode<V> *head=buckets[bucketIndex];
        while(head!=NULL)
        {
            if(head->key==key)
            {
                val=head->value;
                break;
            }
            head=head->next;
        }
        return val;


    }
private:
    int getBucketIndex(string key)
    {
        int hashcode=0;
        //lets assume string is a no with base p
        //prime no is lets suppose 37
        int cofficient=1;
        for(int i=key.size()-1;i>=0;i--)
        {
            hashcode+=cofficient*key[i];
            cofficient*=37;
            //thier is a problem this goes out of range of int very fast in 5 6 iteration max
            //to overcome we use %
            //if (a*b*c)%r is same as ((a%r)*(b%r)*(c%r))%r  //both have same ans
            //so reduce the problem of going out of range we use this..
            hashcode%=numBuckets;

            cofficient%=numBuckets;

        }


        return hashcode %numBuckets;  //compression
    }
    void rehashing()
    {
        mapNode<V>** temp=buckets;
        buckets=new mapNode<V>*[2*numBuckets];
        for(int i=0;i<2*numBuckets;i++)
        {
            buckets[i]=NULL;
        }
        count=0;
        int oldnumBucket=numBuckets;
        numBuckets*=2;
        for(int i=0;i<oldnumBucket;i++)
        {
            mapNode<V>* head=temp[i];
            while(head!=NULL)
            {
                string key=head->key;
                V value=head->value;
                insert(key,value);
                head=head->next;
            }

        }
        for(int i=0;i<oldnumBucket;i++)
        {
            delete temp[i];
        }
        delete [] temp;
    }

};


