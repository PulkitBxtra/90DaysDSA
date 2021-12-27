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

// node* rev(node* &head,int k){
//     int count=0;
//     node* prev=NULL;
//     node* curr=head;
//     node* nextptr;

//     while(curr!=0 && count<k){
//         nextptr=curr->next;
//         curr->next=prev;

//         prev=curr;
//         curr=nextptr;
//         count++;
//     }

//     if(nextptr!=NULL){
//         head->next=rev(nextptr,k);
//     }

//     return prev;
// }

void makecycle(node* &head,int pos){
    node* temp=head;
    node* startnode;
    int count=0;
    
    while(temp->next!=NULL){
        if(count==pos){
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;

}

bool detectcylce(node* &head){
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;

        if(fast==slow){
            return true;
        }

    }
    return false;

}

void removecycle(node* &head){
    node* slow=head;
    node* fast=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow->next!=fast->next);

    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=NULL;
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
    AtTail(head,8);
    AtTail(head,9);
 
    Print(head);
    cout<<endl;
    //AtHead(head,0);
    //Print(head);

    makecycle(head,2);
    cout<<detectcylce(head);
    cout<<endl;
    if(detectcylce(head)==true){
        removecycle(head);
    } 
    Print(head);

 return 0;
}

