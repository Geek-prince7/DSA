#include<iostream>
using namespace std;
template <typename T>

class QueueUsingArray {
	T *data;
	int nextIndex;
	int firstIndex;
	int size;
	int capacity;

	public :
	QueueUsingArray(int s) {
		data = new T[s];
		nextIndex = 0;
		firstIndex = -1;
		size = 0;
		capacity = s;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	// insert element
	void enqueue(T element) {
		if(size == capacity) {
			cout << "Queue Full ! " << endl;
			return;
		}
		data[nextIndex] = element;
		nextIndex = (nextIndex + 1) % capacity ;
		if(firstIndex == -1) {
			firstIndex = 0;
		}
		size++;
	}

	T front() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		return data[firstIndex];
	}

	T dequeue() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		T ans = data[firstIndex];
		firstIndex = (firstIndex + 1) % capacity;
		size--;
		if(size == 0) {
			firstIndex = -1;
			nextIndex = 0;
		}
		return ans;
	}

};
int main()
{
    QueueUsingArray<int> q1(4);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    cout<<q1.getSize()<<endl;
    q1.enqueue(40);
    q1.enqueue(50);
    cout<<"\n"<<q1.getSize()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.front()<<endl;
    cout<<q1.dequeue()<<endl;

    q1.enqueue(60);
    q1.enqueue(70);
    q1.enqueue(80);
    cout<<q1.dequeue()<<endl;
    cout<<q1.getSize();
}
