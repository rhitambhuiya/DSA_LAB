#include <iostream>
using namespace std;

class Stack
{
    public:
        int size;
        int top;
        int *stack;
        Stack(int size)
        {
            this -> size = size;
            this -> top = -1;
            this -> stack = new int[size];
        }

        void push(int data)
        {
            if (top == size - 1)
            {
                cout << endl << "Stack is Full!" << endl;
                return;
            }
            top += 1;
            stack[top] = data;
            cout << endl << data << " successfully pushed into the stack" << endl;
        }

        int pop()
        {
            if(top == -1)
                return top;
            int val = stack[top];
            top -= 1;
            return val;
        }

        int peek()
        {
            return stack[top];
        }

        void display()
        {
            if(top == -1)
            {
                cout << endl << "Stack is Empty!" << endl;
                return;
            }

            int rear = top;
            cout << "Displaying Stack: " << endl << endl;
            while(rear >= 0)
            {
                cout << "|" << stack[rear] << "|" << endl;
                cout << "---" << endl;
                rear -= 1;
            }
        }
};

int main()
{
    int n;
    cout << "Enter the stack size: ";
    cin >> n;
    Stack st(n);
    while(1)
    {
        cout << "\nEnter:-\n1. To push into the stack \n2. To pop from the stack\n3. To peek into the stack \n4. To display the stack: ";
        int choice;
        int val;
        cin >> choice;
        switch(choice)
        {
            case 1: int data;
            cout << "Enter the value to push into the stack: ";
            cin >> data;
            st.push(data);
            
            break;

            case 2: val = st.pop();
            if(val == -1)
                cout << endl << "Stack is Empty!" << endl;
            else
                cout << endl << "Value popped: " << val;
            break;

            case 3:
            cout << endl << "Top Element in the Stack: " << st.peek() << endl;
            break;

            case 4:
            st.display();
            break;

            default:
            exit(0);
        }
    }
}