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

node* insertBST(node* root,int val){
    
    if(root==NULL){
        return new node(val);
    }
    
    if(val<root->data){
        root->left=insertBST(root->left,val);
    }

    else{
        root->right=insertBST(root->right,val);
    }
    return root;
}

void inorder(node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

node* search(node* root,int val){
    
    if(root==NULL){
        return NULL;
    }

    if(root->data==val){
        return root;
    }

    if(root->data>val){
        return search(root->left,val);
    }

    return search(root->right,val);
  

}

int main(){
    node* root=NULL;

    root=new node(4);
    root->left=new node(3);
    root->right=new node(5);

    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right->right=new node(6);

    

    node* ans=search(root,5);

    if(ans!=NULL){
        cout<<"key exist"<<endl;
    }

    else{
        cout<<"key doesn't exist"<<endl;
    }

}
