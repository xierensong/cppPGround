#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int my_val):val(my_val),next(nullptr) {};
};
    
void createList(Node * &head) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int a;
    head = new Node(0);
    Node * p= head;
    while(ss >> a) {
        Node *curr_node = new Node(a);
        p->next=curr_node;
        p=p->next;
    }
    head=head->next;
}

void printList(Node * head) {
    Node *p=head;
    while(p) {
        cout << p->val << ' ';
        p=p->next;
    }
    cout << endl;
}

int main()
{


    Node *head=nullptr;
    //创建链表
    createList(head);
    printList(head);
}