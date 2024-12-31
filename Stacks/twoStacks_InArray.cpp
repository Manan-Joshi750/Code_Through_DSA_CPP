#include<iostream>
#include<stack>
using namespace std;
//This code is basically showing two stack implementation using array. 

class TwoStack {
    //properties
    public:
    int *arr;
    int top1;
    int top2;
    int size;

    //behaviour
    TwoStack (int size){
        this -> size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int element){
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = element;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    void push2(int element){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = element;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    int pop1(){
        if(top1 >=0){
            int ans = arr[top1];
            top1--;
            return ans;
        } else {
            cout << "Stack underflow" << endl;
            return -1;
        }
    }

    int pop2(){
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            cout << "Stack underflow" << endl;
            return -1;
        }
    }
};

int main(){
    TwoStack st(5);
    st.push1(22);
    st.push1(44);
    st.push2(88);
    st.push2(176);
    cout << "Current popped element is " << st.pop1() << endl;
    cout << "Current popped element is " << st.pop2() << endl;

    return 0;
}