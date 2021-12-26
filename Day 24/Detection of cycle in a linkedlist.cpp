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

void print(node* &head){
    node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* reverse(node* &head,int k){
    node* prev=NULL;
    node* curr=head;
    node* nextptr;
    int count=0;

    while(curr!=NULL && count<k){
        nextptr=curr->next;
        curr->next=prev;

        prev=curr;
        curr=nextptr;
        count++;
    }    
    if(nextptr!=NULL){
        head->next=reverse(nextptr,k);
    }

    return prev;
}

void makecycle(node* &head,int pos){
    node* temp=head;
    node* startnode;
    int count=1;

    while(temp->next!=NULL){
        if(count==pos){
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}

bool ifcycle(node* &head){
    node* temp=head;
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    
        if(fast==slow){
            return true;
        }
    }
    return false;

}


int main(){

    node* head=NULL;
    
    AtTail(head,1);
    AtTail(head,2);
    AtTail(head,3);
    AtTail(head,4);
    AtTail(head,5);
    AtTail(head,6);
    AtTail(head,7);

    print(head);
    

    makecycle(head,4);
    cout<<ifcycle(head);

    //print(head);

    //node* newhead=reverse(head,2);
    //print(newhead);

 return 0;
}
