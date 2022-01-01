#include <iostream>
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

void insertAtTail(node* &head,int val){
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

void print(node* &head){
    node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" "<<temp<<endl;;
        temp=temp->next;
    }
}

// node* merge(node* &head1,node* &head2){
//     node* temp1=head1;
//     node* temp2=head2;
//     node* Dummy=new node(-1);
//     node* temp3=Dummy;

//     while(temp1!=NULL && temp2!=NULL){
//         if(temp1->data<temp2->data){
//             temp3->next=temp1;
//             temp1=temp1->next;
//         }

//         else{
//             temp3->next=temp2;
//             temp2=temp2->next;
//         }
//         temp3=temp3->next;
//     }

//     while(temp1!=NULL){
//         temp3->next=temp1;
//         temp1=temp1->next;
//         temp3=temp3->next;
//     }

//     while(temp2!=NULL){
//         temp3->next=temp2;
//         temp2=temp2->next;
//         temp3=temp3->next;
//     }
    
//     return Dummy->next;
// }


node* mergeRec(node* &head1,node* &head2){

    if(head1==NULL){
        return head2;
    }

    if(head2==NULL){
        return head1;
    }

    node* result;

    if(head1->data<head2->data){
        result=head1;
        result->next=mergeRec(head1->next,head2);
    }


    if(head1->data>head2->data){
        result=head2;
        result->next=mergeRec(head1,head2->next);
    }
    return result;

}

int main() {
  
    node* head=NULL;
    node* head2=NULL;
    insertAtTail(head,1);
    insertAtTail(head,3);
    insertAtTail(head,7);
    insertAtTail(head,9);

    insertAtTail(head2,2);
    insertAtTail(head2,4);
    insertAtTail(head2,5);
    insertAtTail(head2,10);


    node* tem=mergeRec(head,head2);

    print(tem);
} 
