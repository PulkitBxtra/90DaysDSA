#include<iostream>
#include<stack>
using namespace std;

void make(string s){
    stack<string> st;
    int n=s.length();

    for(int i=0;i<n;i++){
       string word=""; 
        while(s[i]!=' ' && i<n){
            word+=s[i];
            i++;
        }
        st.push(word);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    string s="hey, kaisa hai chomu";
    make(s);
 return 0;
}
