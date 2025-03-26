#include <iostream>

using namespace std;

class TreeNode
{
    public:
        int data;
        TreeNode *left, *right, *parent;
        TreeNode(int data)
        {
            this -> data = data;
            left = right = parent = nullptr;
        }
};

class BST
{
    public:
        TreeNode *root;

        BST()
        {
            root = nullptr;
        }

        bool searchNode(int data)
        {
            TreeNode *temp = root;
            while(temp)
            {
                if(data == temp -> data)
                    return true;
                else if(data < temp -> data)
                    temp = temp -> left;
                else
                    temp = temp -> right;
            }
            return false;
        }

        TreeNode* insert(TreeNode *root, int data)
        {
            if(!root)
                return new TreeNode(data);
            if(root -> data == data)
                return root;
            if(data < root -> data)
                root -> left = insert(root -> left, data);
            else
                root -> right = insert(root -> right, data);
            return root;
        }

        void preorder(TreeNode *rootNode)
        {
            if(!rootNode)
                return;
            cout << rootNode -> data << " ";
            preorder(rootNode -> left);
            preorder(rootNode -> right);
        }

        void inorder(TreeNode *rootNode)
        {
            if(!rootNode)
                return;
            inorder(rootNode -> left);
            cout << rootNode -> data << " ";
            inorder(rootNode -> right);
        }

        void postorder(TreeNode *rootNode)
        {
            if(!rootNode)
                return;
            postorder(rootNode -> left);
            postorder(rootNode -> right);
            cout << rootNode -> data << " ";
        }
};

int main()
{
    BST b;
    int ch;
    while(true)
    {
        cout << "\nEnter \n1. To insert node into the BST"
        << "\n2. Preorder Traversal"
        << "\n3. Inorder Traversal"
        << "\n4. Postorder Traversal: ";
        cin >> ch;
        int data;
        switch(ch)
        {
            case 1: cout << "Enter the value of the node: ";
            cin >> data;
            b.root = b.insert(b.root, data);
            cout << endl;
            break;
            case 2: if(!b.root) {
                cout << "\nEmpty BST\n";
                break;
            }
            cout << "\nPreorder Traversal: ";
            b.preorder(b.root);
            break;
            case 3: if(!b.root) {
                cout << "\nEmpty BST\n";
                break;
            }
            cout << "\nInorder Traversal: ";
            b.inorder(b.root);
            break;
            case 4: if(!b.root) {
                cout << "\nEmpty BST\n";
                break;
            }
            cout << "\nPostorder Traversal: ";
            b.postorder(b.root);
            break;
            default: cout << endl << "Wrong Choice" << endl;
            exit(0);
        }
    }
}