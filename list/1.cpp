#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int my_val):val(my_val),next(nullptr) {};
};

void createList(Node* list)
{
    int my_val;
    string line;
    getline(cin,line);
    stringstream ss(line);
    Node* p=list;
    while(ss >> my_val) {
        cout << "1" << endl;
        Node* curr_node =new Node(my_val);
        list->next=curr_node;
        list=list->next;
    }
    list=p->next;
    cout << "end create" << endl;
}

void printList(Node* list)
{
    Node *p=list;
    while(p)
    {
        cout << p->val << endl;
        p=p->next;
    }
}

int main()
{
    Node * my_list;
    createList(my_list);
    cout << "print list" << endl;
    printList(my_list);
}