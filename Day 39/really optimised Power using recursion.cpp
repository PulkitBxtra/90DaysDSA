#include<iostream>
using namespace std;
int rec(int n,int p){
	if(p==0){
		return 1;
	}

	if(p==1){
		return n;
	}

	int ans=rec(n,p/2);

	if(p%2==0){
		return ans*ans;
	}

	else{
		return n*ans*ans;
	}

}

 
int main(){
	int n,p;
	cin>>n>>p;

	cout<<rec(n,p)<<endl;

}
