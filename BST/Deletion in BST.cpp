#include<iostream>
using namespace std;

struct node{

    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

node* insert(node* root,int val){

    if(root==NULL){
        return new node(val);
    }

    if(root->data>val){
        root->left=insert(root->left,val);
    }

    else{
        root->right=insert(root->right,val);
    }

    return root;

}

void print(node* root){

    if(root==NULL){
        return;
    }

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

node* search(node* root,int key){

    if(root==NULL){
        return NULL;
    }

    if(root->data==key){
        return root;
    }

    if(root->data>key){
        search(root->left,key);
    }
    
    return search(root->right,key);
}

node* inorderSucc(node* root){
    node* temp=root;
    while(temp && temp->left!=NULL){
        temp=temp->left;
    }
    return temp;

}

node* del(node* root,int key){

    if(root->data>key){
        root->left=del(root->left,key);
    }

    else if(root->data<key){
        root->right=del(root->right,key);
    }


    else{

        if(root->right==NULL){
            node* temp=root->left;
            free(root);
            return temp;
        }

        else if(root->left==NULL){
            node* temp=root->right;
            free(root);
            return temp;
        }

        node* temp= inorderSucc(root->right);
        root->data=temp->data;
        root->right=del(root->right,temp->data);
    }

    return root;

}

int main(){

    node* root=NULL;

    root=new node(4);
    root->left=new node(3);
    root->right=new node(5);

    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right->right=new node(6);

    print(root);

    root=del(root,5);
    cout<<endl;

    print(root);
  

}
