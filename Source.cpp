#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Tree
{
private:
    Node* root;

public:
    Tree()
    {
        root = NULL;
    }

    Node* getRoot()
    {
        return this->root;
    }

    // A utility function to do inorder traversal of BST
    void inorder(Node* r)
    {
        if (r != NULL)
        {
            inorder(r->left);
            cout << r->data << " ";
            inorder(r->right);
        }
    }

    // A utility function to do preorer traversal of BST
    void preorder(Node* r)
    {
        if (r != NULL)
        {
            cout << r->data << " ";
            preorder(r->left);
            preorder(r->right);
        }
    }

    // A utility function to do postorder traversal of BST
    void postorder(Node* r)
    {
        if (r != NULL)
        {
            postorder(r->left);
            postorder(r->right);
            cout << r->data << " ";
        }
    }
    /* A utility function to insert a new node with given key in BST */
    Node* insert(Node* node, int key)
    {

        Node* newNode = new Node;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->data = key;
        if (this->root == NULL)
        {
            this->root = newNode;
        }
        /* If the tree is empty, return a new node */
        if (node == NULL)
        {
            node = newNode;
        }
        /* Otherwise, recur down the tree */
        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);

        return node;
    }


    // C function to search a given key in a given BST
    bool Search(Node* node, int key)
    {
        static int count = 0;
        if (node != NULL)
        {
            // Base Cases: root is null or key is present at root
            if (node->data == key)
            {
                count++;
                cout << "Found in " << count << " iterations." << endl;
                return true;
            }
            // Key is greater than root's key
            if (node->data < key)
            {
                count++;
                return Search(node->right, key);
            }
            // Key is smaller than root's key
            count++;
            return Search(root->left, key);
        }
        cout << "Not found after " << count << " iterations." << endl;
        return false;
    }

    Node* Min(Node* root)
    {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    // Function to search a delete a value from tree.
    Node* Delete(Node* root, int data) {
        if (root == NULL) {
            return root; 
        }
        else if (data < root->data) {
            root->left = Delete(root->left, data);
        }
        else if (data > root->data) {
            root->right = Delete(root->right, data);
        }	
        else {
            // case 1: One child
            if (root->left == NULL) {
                Node* temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == NULL) {
                Node* temp = root;
                root = root->left;
                delete temp;
            }
            // case 2: 2 children
            else {
                Node* temp = Min(root->right);
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
        }
        return root;
    }
    void display() {
        char ch;
        int choice, key;
        do {
            cout << "Enter 1 if you want to insert value in the tree " << endl;
            cout << "Enter 2 if you want to delete value from the tree " << endl;
            cout << "Enter 3 if you want to search any value from the tree " << endl;
            cout << "Enter 4 if you want to print the tree in in-order " << endl;
            cout << "Enter 5 if you want to print the tree in post-order " << endl;
            cout << "Enter 6 if you want to prnt the tree in pre-order " << endl;
            cout << "Enter your choice "; cin >> choice;
            switch (choice) {
            case 1: {
                cout << "Enter Number you want to insert "; cin >> key;
                insert(getRoot(), key);
                break;
            }
            case 2: {
                cout << "Enter Number you want to delete "; cin >> key;
                Delete(getRoot(), key);
                break;
            }
            case 3: {
                cout << "Enter Number you want to search "; cin >> key;
                if (Search(getRoot(), key)) {
                    cout << "Number found " << endl;
                }
                else {
                    cout << "Number not found " << endl;
                }
                break;
            }
            case 4: {
                cout << "In-order tree is " << endl;
                inorder(getRoot());
                cout << endl;
                break;
            }
            case 5: {
                cout << "Pre-order tree is " << endl;
                preorder(getRoot());
                cout << endl;
                break;
            }
            case 6: {
                cout << "Post-order tree is " << endl;
                postorder(getRoot());
                cout << endl;
                break;
            }
            default: {
                cout << "Invalid Input " << endl; }
            }
            system("pause");
            system("cls");
            cout << "Enter \'Y\' or  \'y\' if you want to continue "; cin >> ch;

        } while (ch == 'Y' || ch == 'y');
    }
};

int main()
{
    Tree T;
    T.display();
    cout << endl;
    return 0;
}
