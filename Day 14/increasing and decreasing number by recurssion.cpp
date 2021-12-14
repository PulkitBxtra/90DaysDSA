#include<iostream>
using namespace std;
//decreasing

void print(int n){

    if(n==1){
        cout<<1<<" ";
        return;
    }

    cout<<n<<" ";
    print(n-1);
} 

//increasing

void printinc(int n){

    if(n==0){
        return;
    }

    print(n-1);
    cout<<n<<" ";
} 



int main(){
    int n;
    cin>>n;
    print(n);
    cout<<endl;
    printinc(n);
}
