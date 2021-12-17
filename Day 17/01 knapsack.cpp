#include<iostream>
using namespace std;

int tiling(int value[],int wt[],int n,int W){

    if(n==0 || W==0){
        return 0;
    }
    
    int a=tiling(value,wt,n-1,W-wt[n-1]+value[n-1]);
    int b=tiling(value,wt,n-1,W);
    
    
    return max(a,b);

    
    
}

int main(){
    int wt[]={10,20,30};
    int value[]={100,50,150};
    int w=50;
    cout<<tiling(value,wt,3,w)<<endl;


return 0;
}
