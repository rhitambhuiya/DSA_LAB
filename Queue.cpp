#include <iostream>
using namespace std;

class Queue
{
    public:
        int size;
        int front;
        int rear;
        int *queue;

        Queue(int size)
        {
            this -> size = size;
            this -> front = -1;
            this -> rear = -1;
            this -> queue = new int[size];
        }

        void enqueue(int data)
        {
            if(front > rear) // If Queue is empty, start over
                front = rear = -1;
            if (rear == size - 1)
            {
                cout << endl << "Queue is Full!" << endl;
                return;
            }
            rear += 1;
            queue[rear] = data;
            cout << endl << data << " successfully pushed into the Queue" << endl;
        }

        int dequeue()
        {
            if(front == -1)
                front = 0;
            int val = queue[front];
            if(front > rear) // If Queue is empty, start over
            {
                front = rear = -1;
                return -1;
            }
            front += 1;
            return val;
        }

        void display()
        {
            if((front > rear) || (front == -1 && rear == -1))
            {
                cout << endl << "Queue is Empty!" << endl;
                return;
            }
            cout << "Displaying Queue: " << endl << endl;
            int start = (front >= 0) ? front : 0;
            for(int i = start; i <= rear; i++)
                cout << queue[i] << "|";
                cout << endl;
        }
};

int main()
{
    int n;
    cout << "Enter the Queue size: ";
    cin >> n;
    Queue q(n);
    while(1)
    {
        cout << "\nEnter:-\n1. Enqueue Operation \n2. Dequeue Operation\n3. To display the Queue: ";
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

            case 3:
            q.display();
            break;

            default:
            exit(0);
        }
    }
}