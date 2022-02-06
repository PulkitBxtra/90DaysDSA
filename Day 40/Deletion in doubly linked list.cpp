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

void InsertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}

void InsertAtTail(node* &head,int val){

    if(head==NULL){
        InsertAtHead(head,val);
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

void delHead(node* &head){

    node* temp=head;

    head=head->next;
    head->prev=NULL;

    delete temp;

}

void del(node* &head,int val){
    node* temp=head;
//head deltetion
    if(val==head->data){
        delHead(head);
        return;
    }

    while(temp!=NULL){
        temp=temp->next;
        
        if(temp->data==val){
            temp->prev->next=temp->next;
            //for last node deltetion
            if(temp->next!=NULL){
                temp->next->prev=temp->prev;
            }
            
            delete temp;
            return;
        }
    }

}

int main(){

    node* head=NULL;

    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);


    del(head,1);


    print(head);

        

}
