#include<iostream>
#include<string>
using namespace std;

void move(string s,string ans){

    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
 
 
    char ch=s[0];
    int code=ch;
    string ros=s.substr(1);

    move(ros,ans);
    move(ros,ans+ch);
    move(ros,ans+ to_string(code));
    //to stirng is an stl function
}

int main(){
    move("ABC","");
}
