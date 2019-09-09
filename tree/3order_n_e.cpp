#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left,*right;
    Node(char my_val):val(my_val),left(nullptr),right(nullptr) {};
};

void createTree(Node *&root) {
    char ch;
    scanf("%c",&ch);
    cout << ch << endl;
    if(ch==' ') {
        root=nullptr;
    }
    else {
        root=new Node(ch);
        createTree(root->left);
        createTree(root->right);
    }
}

void preOrder(Node *root) {
    stack<Node*> my_stack;
    my_stack.push(root);
    while(!my_stack.empty()) {
        cout << "we" << endl;
        Node* curr=my_stack.top();
        while(!curr) {
            cout << "wewe" << endl;
            my_stack.push(curr->left);
            cout << my_stack.size() << endl;
            curr=my_stack.top();
        }    
        my_stack.pop();
        if (!my_stack.empty()) {
            curr=my_stack.top();
            cout << curr->val << '-';
            my_stack.pop();
            my_stack.push(curr->right);
        }
    }
    cout << endl;
}
int main()
{
    Node *root;  //ABC  DE G  F   
    createTree(root);
    if (!root) cout << "wer" << endl;
    preOrder(root);
}