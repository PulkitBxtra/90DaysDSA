#include<iostream>
using namespace std;

class node{

    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }

};

//instert at tail
void Insert(node* &head,int val){
    node* n=new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void Inserthead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}

void print(node* head){
    node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){

    node* head=NULL;
    Insert(head,1);
    Insert(head,2);
    Insert(head,3);
    print(head);
    Inserthead(head,0);
    print(head);

}
