#include<iostream>
using namespace std;

int fibb(int n){

    if(n==1){
        return 0;
    }

    if(n==2){
        return 1;
    }

    int prev=fibb(n-1)+fibb(n-2);
    return prev;

}


int main(){
    int n;
    cin>>n;
    cout<<fibb(n)<<endl;

}
