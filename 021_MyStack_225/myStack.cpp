/**
 * leetcode : 225
 * Construct a stack with two queues.
 * Bohn Chen 2022-04-11 17:33
 */
#include <queue>
#include <iostream>
using namespace std;
/*
// two queues
class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        queueIn.push(x);
    }
    
    int pop() {
        if(this->empty()){
            return -1;
        }
        if(!queueIn.empty()) {
            while(queueIn.size() > 1) {
                int temp = queueIn.front();
                queueOut.push(temp);
                queueIn.pop();
            }
            int temp = queueIn.front();
            queueIn.pop();
            return temp;
        } else {
            while(queueOut.size() > 1) {
                int temp = queueOut.front();
                queueIn.push(temp);
                queueOut.pop();
            }
            int temp = queueOut.front();
            queueOut.pop();
            return temp;
        }
        
    }
    
    int top() {
        if(!queueIn.empty()){
            return queueIn.back();
        }
        if(!queueOut.empty()) {
            return queueOut.back();
        }
        return -1;
    }
    
    bool empty() {
        return queueOut.empty() && queueIn.empty();
    }
private:
    queue<int> queueIn;
    queue<int> queueOut;
};
*/
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

class MyStack {
public:
    MyStack() 
    {

    }
    
    void push(int x) {
        queueIn.push(x);
    }
    
    int pop() {
        if(this->empty()){
            return -1;
        }
        int tempSize = queueIn.size();
        while(tempSize > 1) {
            queueIn.push(queueIn.front());
            queueIn.pop();
            --tempSize;
        }
        int temp = queueIn.front();
        queueIn.pop();
        return temp;    
    }
    
    int top() {
        if(!queueIn.empty()){
            return queueIn.back();
        }
        return -1;
    }
    
    bool empty() {
        return queueIn.empty();
    }
private:
    queue<int> queueIn;
};

int main(int argc, char *argv[])
{
  MyStack* obj = new MyStack();
  obj->push(1);
  obj->push(2);
  obj->push(3);
  obj->push(4);
  int param_2 = obj->pop();
  int param_3 = obj->top();
  bool param_4 = obj->empty();
	cout << "param_2 : " << param_2 << endl << "param_3 : " << param_3 << endl << "param_4 : " << param_4 << endl; 
	return 0;
}

