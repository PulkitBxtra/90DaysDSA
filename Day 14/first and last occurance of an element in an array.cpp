#include<iostream>
using namespace std;

int first(int arr[],int n,int i,int k){
    if(n==0){
        return -1;
    }
    if(arr[0]==k){
        return i;
    }
    return first(arr+1,n-1,i+1,k);
}


int lastocc(int arr[],int n,int i,int k){
    if(i==n){
        return -1;
    }
    int restarr=lastocc(arr,n,i+1,k);
    if(restarr!=-1){
        return restarr;
    }
    if(arr[i]==k){
        return i;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int i=0;
    cout<<first(arr,n,i,k)<<endl; 
    cout<<lastocc(arr,n,i,k)<<endl;   
}
