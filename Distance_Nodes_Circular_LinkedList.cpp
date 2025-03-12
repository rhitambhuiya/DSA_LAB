#include <iostream>
#include <algorithm>
using namespace std;

struct Node
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

class Circular_LL
{
    public:
        Node *head;
        int size;
        Circular_LL()
        {
            head = nullptr;
            size = 0;
        }
        void insertAtEnd(int data)
        {
            Node *newNode = new Node(data);
            if(!head)
            {
                head = newNode;
                head -> next = head;
                size = 1;
                return;
            }
            
            Node *curr = head;
            while (curr -> next != head)
            {
                if(curr -> data == data) // no duplicate nodes
                    return;
                curr = curr -> next;
            }
            if(curr -> data == data)
                return;
            curr -> next = newNode;
            newNode -> next = head;
            size += 1;
        }

        int distance(int val1, int val2)
        {
            if(head -> next == head)
                return -1;
            int dist[2] = {-1, -1};
            Node *temp = head;
            int i = 0;
            int d = 0;
            while(temp -> next != head)
            {
                if(temp -> data == val1 || temp -> data == val2)
                    dist[i++] = d;
                if(i == 2)
                    break;
                d += 1;
                temp = temp -> next;
            }
            if(i < 2 && (temp -> data == val1 or temp -> data == val2))
                dist[i] = d;
            if(dist[0] == -1 || dist[1] == -1)
                return -1;
            return min((dist[1] - dist[0]), (size - dist[1] + dist[0]));
        }

        void display()
        {
            Node *temp = head;
            if(!head)
            {
                cout << "\nLinked List is empty!\n";
                return;
            }
            cout << "\nDisplaying the Linked List: ";
            cout << temp -> data << "(HEAD) -> ";
            temp = temp -> next;
            while(temp != head)
            {
                cout << temp -> data << " -> ";
                temp = temp -> next;
            }
            cout << "HEAD\n\n";
        }
};

int main()
{
    Circular_LL cll;
    int ch;
    while(true)
    {
        cout << "\nEnter \n1. To insert node into the circular Linked List"
        << "\n2. To find the minimum distance between any two valid nodes"
        << "\n3. To display the circular Linked List: ";
        cin >> ch;
        int data, val;
        switch(ch)
        {
            case 1: cout << endl <<"Enter the data to insert: ";
            cin >> data;
            cll.insertAtEnd(data);
            break;

            case 2: cout << "\nEnter any two valid nodes: ";
            cin >> data >> val;
            val = cll.distance(data, val);
            if(val == -1)
                cout << "\nOne or both nodes not present\n";
            else
                cout << "\nMinimum Distance: " << val << endl;
            break;

            case 3: cll.display();
            break;

            default: cout << endl << "Wrong Choice" << endl;
            exit(0);
        }
    }
    return 0;
}