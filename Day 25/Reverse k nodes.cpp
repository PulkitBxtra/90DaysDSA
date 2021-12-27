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

void AtTail(node* &head,int val){
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

void AtHead(node* &head,int val){
    
    node* temp=new node(val);
    temp->next=head;
    head=temp;

}

void Print(node* &head){
    node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* rev(node* &head,int k){
    int count=0;
    node* prev=NULL;
    node* curr=head;
    node* nextptr;

    while(curr!=0 && count<k){
        nextptr=curr->next;
        curr->next=prev;

        prev=curr;
        curr=nextptr;
        count++;
    }

    if(nextptr!=NULL){
        head->next=rev(nextptr,k);
    }

    return prev;
}

int main(){
    node* head=NULL;
    
    AtTail(head,1);
    AtTail(head,2);
    AtTail(head,3);
    AtTail(head,4);
    AtTail(head,5);
    AtTail(head,6);
    Print(head);
    //AtHead(head,0);
    //Print(head);

    node* newhead= rev(head,2);
    Print(newhead);
     

 return 0;
}
