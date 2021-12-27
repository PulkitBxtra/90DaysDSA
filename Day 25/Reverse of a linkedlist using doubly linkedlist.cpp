#include<iostream>
using namespace std;

class node{

    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void Insertathead(node* &head,int val){
    node* n=new node(val);
    n->next=head;

    if(head!=NULL){
        head->prev=n;
    }

    head=n;
}

void InsertTail(node* &head,int val){

    if(head==NULL){
        Insertathead(head,val);
        return;
    }

    node* n=new node(val);
    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=n;
    n->prev=temp;

}

void print(node* &head){

    node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}

node* last(node* &head){
    node* emp=head;
    while(emp->next!=NULL){
        emp=emp->next;
    }
    return emp;
}

void printRev(node* &head){

    node* temp=last(head);

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }  
    cout<<endl;  

}

int main(){

    node* head=NULL;
    InsertTail(head,1);
    InsertTail(head,2);
    InsertTail(head,3);
    InsertTail(head,4);
    InsertTail(head,5);
    InsertTail(head,6);
    print(head);
    printRev(head);





 return 0;    
}
