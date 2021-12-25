#include<iostream>
using namespace std;

class A{
    public:

    int a;
    void objA(){
        cout<<a<<endl;
    }

    private:
    int B;
    void objB(){
        cout<<B<<endl;
    }

    protected:
    int C;
    void objC(){
        cout<<C<<endl;
    }
};

int main(){
    A funk;

    funk.objA();
    funk.objB();
    funk.objC();

   

 return 0;
}
