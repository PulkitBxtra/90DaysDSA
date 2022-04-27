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
// code to check height of the tree
int height(Node* root){

    if(root==NULL){
        return 0;
    }

    int lh=height(root->left);
    int rh=height(root->right);

    int high=max(lh,rh)+1;

    return high;
}


bool isBalanced(Node* root){
    //recursion end call
    if(root==NULL){
        return true;
    }
    //to check if the tree is balaced by recursion
    if(isBalanced(root->left)==false){
        return false;
    }

    if(isBalanced(root->right)==true){
        return true;
    }


    //checking conditions
    int lh=height(root->left);
    int rh=height(root->right);

    if(abs(lh-rh)<=1){
        return true;
    }

    else{
        return false;
    }


}



int main(){

    Node* root=new Node(1);
    
    root->left=new Node(2);
    root->right=new Node(3);
    
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<isBalanced(root)<<endl;
    // cout<<endl;
    cout<<height(root)<<endl;

}
