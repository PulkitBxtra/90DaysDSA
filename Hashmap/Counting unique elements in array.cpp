#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

    int arr[10]={1,2,3,1,2,3,1,1,2,3}; 

    unordered_map<int,int> m;

    for(int i=0;i<10;i++){
        m[arr[i]]++;
    }

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

}
