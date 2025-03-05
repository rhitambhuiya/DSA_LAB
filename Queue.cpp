#include <iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
	Node(int data)
	{
		this -> data = data;
		this -> next = nullptr;
	}
};

class Queue
{
	public:
		Node* front, *rear;
		int size, val;
		Queue()
		{	
			front = rear = nullptr;
			size = 0;
		}
		
		void enqueue(int data)
		{
			Node* newNode = new Node(data);
			if(!rear)
			{
				rear = newNode;
				front = newNode;
				size = 1;
				return;
			}
			rear -> next = newNode;
			rear = newNode;
			size += 1;
		}
		
		int dequeue()
		{
			if(!front)
				return -1;
			val = front -> data;
			if(front == rear){
				front = rear = nullptr;
				size = 0;
				}
			else{
				front = front -> next;
				size -= 1;
				}
			return val;
		}
		
		bool isEmpty()
		{
			return rear == nullptr;
		}
		
		void display()
		{
			if(!rear){
				cout << "Queue is empty!\n";
				return;
				}
			Node *temp = front;
			cout << "\nDisplaying Queue: ";
			while(temp)
			{
				cout << temp -> data << " -> ";
				temp = temp -> next;
			}	
			cout << "NULL\n";
		}
		
};

int main()
{
	Queue q;
	while(true)
	{
		int ch;
		cout << "\nEnter \n1. Enqueue operation \n2. Dequeue operation \n3. To check if the queue is empty: ";
		int data, val;
		cin >> ch;
		switch(ch)
		{
			case 1: cout << "\nEnter the data to enter: ";
			cin >> data;
			q.enqueue(data);
			q.display();
			break;
			
			case 2: val = q.dequeue();
			if(val == -1)
				cout << "\nCan't remove, queue is  empty!\n";
			else
				cout << "\nValue removed: " << val << "\n";
				q.display();
			break;
			
			case 3: val = q.isEmpty();
			if(val == true)
				cout << "Queue is  empty!\n";
			else
				cout << "\nSize of the Queue: " << q.size << "\n";
			break;
			
			default: cout << "\nWrong Choice\n";
			exit(0); 
			
		}
	}
	
}
