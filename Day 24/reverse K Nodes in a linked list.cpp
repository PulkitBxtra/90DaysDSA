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

void InsertTail(node* &head,int val){
    node* n=new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node*temp= head;

    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=n;
}

void InsertHead(node* &head,int val){

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

void DeleteHead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}

void DeleteIt(node* &head,int target){
    node*temp=head;

    if(head==NULL){
        return;
    }

    if(head->next==NULL){
        DeleteHead(head);
        return;
    }
    while(temp->next->data!=target){
        temp=temp->next;
    }
    node* ToDelete=temp->next;
    temp->next=temp->next->next;
    delete(ToDelete);
}

node* reverse(node* &head,int k){

    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    int count=0;

    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }

    if(nextptr!=NULL){
    head->next=reverse(nextptr,k);
    }

    return prevptr;
}

int main(){

    node* head=NULL;
    InsertTail(head,1);
    InsertTail(head,2);
    InsertTail(head,3); 
    Print(head);
    InsertHead(head,0);
    Print(head);
    //DeleteHead(head);
    //Print(head);
    node* newhead=reverse(head,2);
    Print(newhead);
 return 0;
}
