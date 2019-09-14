#include<bits/stdc++.h>

using namespace std;

struct Node {
    char val;
    Node* left, *right;
    Node(char my_val) : val(my_val), left(nullptr), right(nullptr) {}; 
};

void PreOrder(Node* root) //入栈前打印
{
    stack<Node*> my_stack;
    //cout << "0" << endl;
    if(root) cout << root -> val << ' ';
    my_stack.push(root);
    while(!my_stack.empty()) {
        Node * curr= my_stack.top();
        while(curr) {
            //cout << "1" << endl;
            if(curr->left) cout << curr -> left -> val << ' ';
            my_stack.push(curr->left);
            curr=my_stack.top();
        }
        my_stack.pop();
        if(!my_stack.empty()) {
            curr=my_stack.top();
            my_stack.pop();
            //cout << "2" << endl;
            if(curr->right) cout << curr -> right -> val << ' ';
            my_stack.push(curr->right);
        }
    }
    cout << endl;
}

void InOrder(Node *Tree)
{
    stack<Node*> my_stack;
    my_stack.push(Tree);
    while(!my_stack.empty()) {
        Node* curr=my_stack.top();
        while(curr) {
            my_stack.push(curr->left);
            curr=my_stack.top();
        }
        my_stack.pop();
        if(!my_stack.empty()) {
            curr=my_stack.top();
            cout << curr->val << ' ';
            my_stack.pop();
            my_stack.push(curr->right);
        }    
    }
    cout << endl;
}

void PostOrder(Node* root) //根右左先序遍历反过来
{
    vector<char> results;
    stack<Node*> my_stack;
    if(root) results.push_back(root->val);
    my_stack.push(root);
    while(!my_stack.empty()) {
        Node* curr=my_stack.top();
        while(curr) {
            //cout << "1" << endl;
            if(curr->right) results.push_back(curr->right->val);
            //cout << "1" << results.size() << endl;
            my_stack.push(curr->right);
            curr=my_stack.top();
        }
        my_stack.pop();
        if(!my_stack.empty()) {
            curr=my_stack.top();
            my_stack.pop();
            //cout << "2" << endl;
            if(curr->left) results.push_back(curr->left->val);
            //cout << "2" << results.size() << endl;
            my_stack.push(curr->left);
        }
    }
    reverse(results.begin(),results.end());
    for(auto result:results) {
        cout << result << ' ';
    }
    cout << endl;
}

void createTree(Node* &root) 
{
    char ch;
    scanf("%c", &ch);
    if(ch==' ') {
        root=nullptr;
    }
    else {
        root=new Node(ch);
        createTree(root->left);
        createTree(root->right);
    }
}

int main()
{
    Node * root; //ABC  DE G  F   
    createTree(root);
    PreOrder(root);
    InOrder(root);
    PostOrder(root);
}