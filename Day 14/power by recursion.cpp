#include<iostream>
using namespace std;

int power(int n,int p){

    if(p==0){
        return 1;
    }

    int prevpower=power(n,p-1);
    return prevpower*n;
}


int main(){
    int n;
    cin>>n;
    cout<<power(n,p)<<endl;

}
