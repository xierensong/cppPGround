#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int my_val):val(my_val), next(nullptr) {};
};

void print(Node* linkList)
{
    while(linkList)
    {
        cout << linkList -> val << ' ';

        linkList=linkList->next;
    }
    cout << endl;
}

void reverseList(Node* &linkList)
{
    Node* pre=nullptr, *curr=linkList, *post=nullptr;
    while(curr) {
        post= curr->next;
        curr->next=pre;
        pre=curr;
        curr=post;
    }
    linkList=pre;
}

void createLinkList(Node* &linkList) 
{
    string my_line;
    getline(cin, my_line);
    stringstream ss(my_line);
    int my_val;
    linkList = new Node(0);
    Node* p=linkList;
    while(ss >> my_val) {
        Node* curr= new Node(my_val);
        p->next=curr;
        p=p->next;
    }
    linkList=linkList->next;
}

int main()
{
    Node * LinkList;
    createLinkList(LinkList);
    print(LinkList);
    reverseList(LinkList);
    print(LinkList);
}