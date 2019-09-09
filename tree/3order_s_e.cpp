#include <bits/stdc++.h>

using namespace std;

struct Node {
    char val;
    Node *left,*right;
    Node(char my_val):val(my_val),left(nullptr),right(nullptr) {}
};

void createTree(Node * &root) {
    char ch;
    scanf("%c", &ch);
    //cout << ch << endl;
    if (ch==' ') {
        root=nullptr;
    }
    else {
        root = new Node(ch);
        createTree(root->left);
        createTree(root->right);
    }
    return;
}

bool preOrder(Node * root) {
    if(root) {
        cout << root -> val << '-';
        if (preOrder(root->left)) {
            if (preOrder(root->right)) {
                return true;
            }
        }
    }
    else {
        return true;
    }
    return false;
}

bool inOrder(Node *root) 
{
    if (root) {
        if(inOrder(root->left)) {
            cout << root->val << '-';
            if(inOrder(root->right)) {
                return true;
            }
        }
    }
    else {
        return true;
    }
    return false;
}

bool postOrder(Node *root) 
{
    if (root) {
        if(postOrder(root->left)) {
            if(postOrder(root->right)) {
                cout << root->val << '-';
                return true;
            }
        }
    }
    else {
        return true;
    }
    return false;
}

int main()
{
    Node *root;
    createTree(root);  //ABC  DE G  F   
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    return 0;
}