#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};

int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}


Node* BuildTree(int preorder[],int inorder[],int start,int end){
    static int i=0;

    if(start>end){
        return NULL;
    }

    int curr=preorder[i];
    i++;

    Node* node=new Node(curr);
    int pos=search(inorder,start,end,curr);
    node->left=BuildTree(preorder,inorder,start,pos-1);
    node->right=BuildTree(preorder,inorder,pos+1,end);

    return node;
}

void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){

    int preorder[5]={1,2,4,3,5};
    int inorder[5]={4,2,1,5,3};

    Node* root=BuildTree(preorder,inorder,0,4);
    inorderPrint(root);

 return 0;
}
