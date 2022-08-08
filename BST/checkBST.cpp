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

bool isBST(node* root,node* min=NULL,node* max=NULL){

    if(root==NULL){
        return true;
    }

    if(min!=NULL && root->data<=min->data){
        return false;
    }

    if(max!=NULL && root->data>=max->data){
        return false;
    }

    bool leftc=isBST(root->left,min,root);
    bool rightc=isBST(root->right,root,max);
    return leftc and rightc;

}

int main(){

    node* root=NULL;

    root=new node(4);
    root->left=new node(2);
    root->right=new node(5);

    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right->right=new node(6);
    // root->right->left=new node(7);



    cout<<isBST(root)<<endl;;
  

}
