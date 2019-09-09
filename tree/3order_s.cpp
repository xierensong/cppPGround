#include<bits/stdc++.h>

using namespace std;

struct Node {
    char val;
    Node *left, *right;
    Node(char val):val(val),left(nullptr),right(nullptr) {}
};

void createTree(Node *&Tree) {
    char ch;
    scanf("%c",&ch);
    //cout << ch << endl;
    if (ch == ' ') {
        Tree = nullptr;
    }
    else {
        Tree = new Node(ch);
        createTree(Tree->left);
        createTree(Tree->right);
    }
}

bool firstOrder(Node* Tree) 
{
    if (Tree) {
        cout << Tree->val << ' ';
        if (firstOrder(Tree->left)) {
            if (firstOrder(Tree->right)) {
                return true;
            }            
        }
    }
    else {
        return true;
    }
    return false;
}

bool inOrder(Node* Tree) {
    if (Tree) {
        if (inOrder(Tree->left)) {
            cout << Tree -> val << ' ';
            if (inOrder(Tree->right)) {
                return true;
            }
        }
    }
    else {
        return true;
    }
    return false;
}

bool postOrder(Node* Tree) {
    if (Tree) {
        if (postOrder(Tree->left)) {
            if (postOrder(Tree->right)) {
                cout << Tree -> val << ' ';
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
    vector<char> input{'A','B','C',' ', ' ', 'D','E',' ','G', ' ', ' ', 'F', ' ', ' ', ' '}; //ABC  DE G  F   
    Node *Tree;
    createTree(Tree);
    firstOrder(Tree);
    cout << endl;
    inOrder(Tree);
    cout << endl;
    postOrder(Tree);
    cout << endl;
    return 0;
}