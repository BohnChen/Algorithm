/**
 * leedcode : 232
 * make a queue with two stack.
 * Bohn Chen 2022-04-10 22:02
 */
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
public:
    MyQueue() 
    : size(0)
    // , top(-1)
    {

    }
    
    void push(int x) {
        if(size < 1) {
            queue.push(x);
            ++size;
        }
        else {
            for(int i = 0; i < size; ++i){
                int temp = queue.top();
                queue.pop();
                stackTemp.push(temp);
            }
            queue.push(x);
            for(int i = 0; i < size; ++i){
                int temp = stackTemp.top();
                stackTemp.pop();
                queue.push(temp);
            }
            ++size;
        }
    }
    
    int pop() {
        
        if(size < 1) {
            return -1;
        } else {
            int temp = queue.top();
            queue.pop();
            --size;
            return temp;
        }
    }
    
    int peek() {
        if(size < 1)
            return -1;
        else
            return queue.top();
    }
    
    bool empty() {
        if(size == 0)
            return true;
        else
            return false;
    }
private:
    int size;
    // int top;
    stack<int, vector<int>> stackTemp;
    stack<int, vector<int>> queue;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(int argc, char *argv[])
{
	MyQueue queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.pop();
	queue.push(5);
	cout << "peek is : " << queue.peek() << endl;
	std::cout << "empty :" << queue.empty()  << std::endl;
	std::cout << "pop1  : " << queue.pop() << std::endl;
	std::cout << "pop2  : " << queue.pop() << std::endl;
	std::cout << "pop3  : " << queue.pop() << std::endl;
	std::cout << "pop4  : " << queue.pop() << std::endl;
	std::cout << "empty :" << queue.empty()  << std::endl;
	return 0;
}
