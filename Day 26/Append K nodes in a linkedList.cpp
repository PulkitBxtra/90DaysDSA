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


void InsertHead(node* &head,int val){

    node* n=new node(val);
    n->next=head;
    
    if(head!=NULL){
        head->prev=n;
    }
    
    head=n;


}


void insertTail(node* &head,int val){

    if(head==NULL){
        InsertHead(head,val);
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


void Print(node* head){
    
    node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}

node* last(node* &head){
    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp;
}

int length(node* &head){
    node* temp=head;
    int count=0;

    while(temp->next!=NULL){
        temp=temp->next;
        count++;
    }

    return count;
}

node* kAppend(node* &head,int k){

    node* newhead;
    node* newtail;
    node* temp=head;
    int count=1;
    int l=length(head);

    while(temp->next!=NULL){
        if(count==l-k){
            newtail=temp;
        }

        if(count==l-k+1){
            newhead=temp;
        }

        temp=temp->next;
        count++;
    }

    temp->next=head;
    newtail->next=NULL;

    return newhead;
}


void revese(node* &head){
    node* temp=last(head);

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<endl;

}

void deletion(node* &head,int pos){
    node* temp=head;
    int count=1;

    while(temp->next!=NULL && count<pos){
        temp=temp->next;
        count++;
    }
 
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;

}

int main(){
    
    node* head=NULL;
    
    insertTail(head,1);
    insertTail(head,2);
    insertTail(head,3);
    insertTail(head,4);
    insertTail(head,5);
    insertTail(head,6);
    Print(head);

    InsertHead(head,0);
    Print(head);

    revese(head);

    cout<<length(head)<<endl;
    
    //deletion(head,2);
    //Print(head);

    node* newhead=kAppend(head,2);
    Print(newhead);


 return 0;
}
