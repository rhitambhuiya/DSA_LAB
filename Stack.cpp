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

class Stack
{
	public:
		Node* top;
		int size, val;
		Stack()
		{	
			top = nullptr;
			size = 0;
		}
		
		void push(int data)
		{
			Node* newNode = new Node(data);
			newNode -> next = top;
			top = newNode;
			size += 1;
		}
		
		int pop()
		{
			if(!top)
				return -1;
			val = top -> data;
			top = top -> next;
			if (size > 0)
				size -= 1;
			return val;
		}
		
		int peek()
		{
			if(!top)
				return -1;
			return top -> data;
		}
		
		bool isEmpty()
		{
			return top == nullptr;
		}
		
		void display()
		{
			if(!top)
				cout << "Stack is empty!\n";
			Node *temp = top;
			cout << "\nDisplaying Stack: ";
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
	Stack st;
	while(true)
	{
		int ch;
		cout << "\nEnter 1. To push into the stack \n2. To pop from the stack \n3. To peek into the stack \n4. To check if the stack is empty: ";
		int data, val;
		cin >> ch;
		switch(ch)
		{
			case 1: cout << "\nEnter the data to push: ";
			cin >> data;
			st.push(data);
			st.display();
			break;
			
			case 2: val = st.pop();
			if(val == -1)
				cout << "\nCan't pop, stack is  empty!\n";
			else
				cout << "\nValue popped: " << val << "\n";
				st.display();
			break;
			
			case 3: val = st.peek();
			if(val == -1)
				cout << "\nCan't peek, stack is  empty!\n";
			else
				cout << "\nValue at the top of the stack: " << val << "\n";
			break;
			
			case 4: val = st.isEmpty();
			if(val == true)
				cout << "Stack is  empty!\n";
			else
				cout << "\nSize of the stack: " << st.size << "\n";
			break;
			
			default: cout << "\nWrong Choice\n";
			exit(0); 
			
		}
	}
	
}
