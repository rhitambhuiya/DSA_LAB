#include <iostream>
using namespace std;

class Circular_Queue
{
    private:
        int *queue;
        int front, rear;
        int size;
        bool flag = false;

        bool isEmpty()
        {
            if(front == -1 && rear == -1)
                return true;
            return false;
        }

        bool isFull()
        {
            if(front == (rear + 1) % size)
                return true;
            return false;
        }

    public:
        Circular_Queue(int size)
        {
            this -> size = size;
            this -> queue = new int[this -> size];
            this -> front = this -> rear = -1;
        }

        void enqueue(int data)
        {
            if(isFull() == true)
            {
                cout << endl << "Queue is Full!" << endl;
                return;
            }
            if(front == -1)
                front = 0;
            rear = (rear + 1) % size;
            queue[rear] = data;
        }

        int dequeue()
        {
            if(isEmpty() == true)
                return -1;
            int val = queue[front];
            if(front == rear)
                front = rear = -1;
            else
                front = (front + 1) % size;
            return val;
        }
        
        void display()
        {
            if(isEmpty() == true)
            {
                cout << endl << "Queue is Empty!" << endl;
                return;
            }
            cout << endl << "Displaying Queue elements: ";
            for(int start = front; start != rear; start = (start + 1) % size)
                cout << queue[start] << " ";
            cout << queue[rear];
        }
        
};


int main()
{
    Circular_Queue q(5);
    int n;
    cout << "Enter the Queue size: ";
    cin >> n;
    while(1)
    {
        cout << "\nEnter:-\n1. Enqueue Operation \n2. Dequeue Operation: ";
        int choice;
        int val;
        cin >> choice;
        switch(choice)
        {
            case 1: int data;
            cout << "Enter the value to enter into the Queue: ";
            cin >> data;
            q.enqueue(data);
            
            break;

            case 2: val = q.dequeue();
            if(val == -1)
                cout << endl << "Queue is Empty!" << endl;
            else
                cout << endl << "Value removed from the Queue: " << val;
            break;

            default:
            exit(0);
        }
        q.display();
    }
}
