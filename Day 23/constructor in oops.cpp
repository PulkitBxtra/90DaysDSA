#include<iostream>
using namespace std;

class student{
    public:

    string name;
    int age;
    bool gender;

    //constructor
    student(string s,int a,bool g){
        name=s;
        age=a;
        gender=g;
    }

    void print(){
        cout<<"NAME -> "<<name<<endl;
        cout<<"AGE -> "<<age<<endl;
        cout<<"GENDER -> "<<gender<<endl;
    }
};


int main(){

    student a("int",20,1);
    a.print();

 return 0;
}
