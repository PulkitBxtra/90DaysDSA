#include<iostream>
#include<string>
using namespace std;

void rev(string s){
    

    if(s.length()==0){
        return;
    }

    string ans=s.substr(1); 
    rev(ans);
    cout<<s[0];
}

int main(){
    string s="binod";
    rev(s);


}
