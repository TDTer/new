#include <bits/stdc++.h>
using namespace std;

struct Node  {
    int data;
    Node* next;
    Node* prev;
};

struct LinkedList{
    Node *head;
    Node *tail;
};

void initList(LinkedList& L){
    L.head=L.tail=NULL;
}

Node* CreateNode(int data){
    Node *e=new Node;
    e->data=data;
    e->next=NULL;
    e->prev=NULL;
    return e;
}

void InsertAtHead(Node *e, LinkedList &L) {
    if(L.head == NULL) {
        L.head = e;
        L.tail = e;
    }
    else
    {
        L.head->prev = e;
        e->next = L.head;
        L.head = e;
    }
}

void InsertAtTail(Node *e, LinkedList &L) {
    if(L.head == NULL) {
        L.head = e;
        L.tail = e;
    }
    else
    {
        L.tail->next = e;
        e->prev = L.tail;
        L.tail = e;
    }
}

void InsertAfterP(Node *e, Node *p){
   if(p!=NULL){
        e->next=p->next;
        e->prev=p;
        p->next->prev=e;
        p->next=e;
   }
}

void DeleteAtHead(LinkedList &L) {
    if(L.head == NULL) {
        return;
    }
    L.head = L.head->next;
    L.head->prev = NULL;
}


void DeleteAtTail(LinkedList &L) {
    if(L.head == NULL) {
        return;
    }
    L.tail = L.tail->prev;
    L.tail->next = NULL;
}


void Print(LinkedList L) {
    Node* temp = L.head;
    while(temp != NULL) {
        cout<<temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}


int main() {

    LinkedList L;
    initList(L);

    Node *e=CreateNode(7);
    InsertAtHead(e, L);
    e=CreateNode(9);
    InsertAtHead(e, L);
    e=CreateNode(10);
    InsertAtTail(e, L);
    Print(L);

//    DeleteAtHead(L);
//    DeleteAtTail(L);
//    Print(L);
    Node *c=CreateNode(100);
    InsertAtHead(c, L);
    e=CreateNode(99);
    InsertAfterP(e,c);
    Print(L);

}
