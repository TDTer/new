#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *pointer;
};

struct LinkedList{
    Node *head;
    Node *tail;
};

// ham khoi tao
void initList(LinkedList& L){
    L.head=L.tail=NULL;
}
// ham tao thanh phan
Node* CreateNode(int data){
    Node *e=new Node;
    e->data=data;
    e->pointer=e;
    return e;
}
// ham chen dau
void InsertFirst(Node *e, LinkedList &L){
   if(L.head==NULL)
    L.head=L.tail=e;
   else{
    e->pointer=L.head;
    L.head=e;
    L.tail->pointer = e;
   }
}

void InsertTail(Node *e, LinkedList &L){
   if(L.tail==NULL)
    L.head=L.tail=e;
    else{
        L.tail->pointer=e;
        e->pointer=L.head;
        L.tail=e;
    }
}

void InsertAfterP(Node *e, Node *p,LinkedList &L){
   if(p!=NULL){
    e->pointer=p->pointer;
    p->pointer=e;
    if(L.tail==p)
    {
            L.tail = e;
            e->pointer=L.head;
    }
   }
}

void DeleteFirst(LinkedList &L){
    if(L.head!=NULL){
    Node *p=L.head;
    L.head=L.head->pointer;
    L.tail->pointer=L.head;
    delete p;
    }
}

void DeleteTail(LinkedList &L){
    if(L.tail!=NULL){
     Node *p=L.head;

     while(p->pointer!=L.tail)
        p=p->pointer;

     Node *tmp=L.tail;
     L.tail=p;
     p->pointer=L.head;
     delete tmp;

     }
}
void DeleteP(Node *q,LinkedList &L){
    if(L.tail!=NULL){
     Node *p=L.head;

     while(p->pointer!=q)
        p=p->pointer;
    if (L.tail==q) L.tail = p;
    if (L.head==q) L.head = p;
    p->pointer=q->pointer;

     delete q;

     }
}

void TravleList(LinkedList L){
     Node *p=L.head;
     while(p!=L.tail){
        cout<<p->data<<'\t';
        p=p->pointer;
     }
     cout<<p->data<<'\t';
     cout<< "\n";
}

int main()
{
    LinkedList L;
    initList(L);

    Node *e=CreateNode(7);
    InsertFirst(e,L);
    e=CreateNode(9);
    InsertFirst(e,L);
    e=CreateNode(88);
    InsertFirst(e,L);
    e=CreateNode(20);
    InsertTail(e,L);

    TravleList(L);
    cout<<'\n';
    e=CreateNode(100);
    Node *p=CreateNode(101);
    InsertTail(p,L);
    InsertAfterP(e,p,L);
//    TravleList(L);
//    cout<<'\n';
    TravleList(L);
    DeleteP(p,L);
    TravleList(L);
}
