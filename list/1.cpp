#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int my_val):val(my_val),next(nullptr) {};
};

void createList(Node* &list)
{
    int my_val;
    string line;
    getline(cin,line);
    stringstream ss(line);
    list=new Node(0);
    Node* p=list;
    while(ss >> my_val) {
        //cout << "1 " << my_val << endl;
        Node* curr_node =new Node(my_val);
        p->next=curr_node;
        p=p->next;
    }
    list=list->next;
    //cout << "end create" << endl;
}

void printList(Node* list)
{
    Node *p=list;
    while(p)
    {
        cout << p->val << ' ';
        p=p->next;
    }
    cout << endl;
}

void reverse(Node* &list)
{
    Node* pre=nullptr, *curr=list, *next=nullptr;
    while(curr)
    {
        next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
    }
    list=pre;
}

int main()
{
    Node * my_list;
    createList(my_list);
    cout << "print list" << endl;
    printList(my_list);
    cout << "reverse list" << endl;
    reverse(my_list);
    printList(my_list);
}