#include<bits/stdc++.h>

using namespace std;

struct Node {
    char val;
    Node* left, *right;
    Node(char my_val) : val(my_val), left(nullptr), right(nullptr) {};
};

bool preOrder(Node* tree) 
{
    if(tree) {
        cout << tree->val << ' ';
        if (preOrder(tree->left)) {
            if(preOrder(tree->right)) {
                return true;
            }
        }
    }
    return true;
}

bool InOrder(Node* tree)
{
    if(tree) {
        if(InOrder(tree->left)) {
            cout << tree->val << ' ';
            if(InOrder(tree->right)) {
                return true;
            }
        }
    }
    return true;
}

bool PostOrder(Node* tree) {
    if(tree) {
        if(PostOrder(tree->left)) {
            if (PostOrder(tree->right)) {
                cout << tree->val << " ";
                return true;
            }
        }
    }
    return true;
}

void createTree(Node* &tree)
{
    char ch;
    scanf("%c", &ch);
    //cout << "curr " << ch << endl;
    if(ch==' ') {
        tree=nullptr;
    }
    else {
        tree=new Node(ch);
        createTree(tree->left);
        createTree(tree->right);
    }
}

int main()
{
    Node* tree;  //ABC  DE G  F   
    createTree(tree);
    preOrder(tree);
    cout << endl;
    InOrder(tree);
    cout << endl;
    PostOrder(tree);
    cout << endl;
}