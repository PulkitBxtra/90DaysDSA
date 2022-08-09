#include<iostream>
using namespace std;

class queue{
    
    private:
    int arr[10];
    int front=-1;
    int back;

    public:
    bool empty(){

        if(front==-1){
            return true;
        }
        return false;
    }

    int peek(){
        if(front==-1){
            return -1;
        }

        return arr[front];
    }

    bool full(){
        if(front==10){
            return true;
        }

        return false;
    }



    void enque(int val){
        front++;
        arr[front]=val;
    }

    void deque(){
        front--;
    }
};

int main(){

    queue qu;

    qu.enque(1);   
    qu.enque(2);   
    qu.enque(3);   
    qu.enque(4);   
    // qu.enque(4);

    qu.deque();
    cout<<qu.peek()<<endl; 

}
