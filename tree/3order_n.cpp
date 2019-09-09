#include <bits/stdc++.h>

using namespace std;

struct Node {
    char val;
    Node *left,*right;
    Node(char my_val):val(my_val),left(nullptr),right(nullptr) {};
};

void createTree(Node* &Tree)
{
    char ch;
    scanf("%c", &ch);   //ABC  DE G  F   
    if (ch==' ') {
        Tree = nullptr;
    }
    else {
        Tree = new Node(ch);
        createTree(Tree->left);
        createTree(Tree->right);
    }
}
void PreOrder(Node* Tree) {
    stack<Node*> my_stack;
    if (Tree) {
        cout << Tree -> val << ' ';
    }
    my_stack.push(Tree);
    while(!my_stack.empty()) {
        Node* curr = my_stack.top();
        while(curr) {
            if (curr->left) {
                cout << curr->left->val << ' ';
            }
            my_stack.push(curr->left);
            curr=my_stack.top();
        }
        my_stack.pop();
        if(!my_stack.empty()) {
            curr=my_stack.top();
            my_stack.pop();
            if(curr->right) {
                cout << curr->right->val << ' ';
            }
            my_stack.push(curr->right);
        }
    }
    cout << endl;
}
void InOrder(Node* Tree)
{
    stack<Node*> my_stack;
    my_stack.push(Tree);    //根入栈
    while(!my_stack.empty()) {  //每次从栈取
        Node *curr=my_stack.top();  //接着判断
        while(curr) {
            my_stack.push(curr->left);
            curr=my_stack.top();
        }
        my_stack.pop();
        if(!my_stack.empty()) {
            curr=my_stack.top();
            my_stack.pop();
            cout << curr -> val << ' ';
            my_stack.push(curr->right); //入栈不判断
        }
    }
    cout << endl;
}

void postOrder(Node * Tree)
{
        
}
int main()
{
    Node * Tree;
    createTree(Tree);
    PreOrder(Tree);
    InOrder(Tree);
}