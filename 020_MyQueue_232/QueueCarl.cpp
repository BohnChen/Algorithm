/**
 * leetcode : 232
 * two stack. Proficient in using the interface.
 * Bohn Chen 2022-04-10 22:14
 */
#include <stack>
#include <iostream>
using namespace std;
class MyQueue {
public:
	stack<int> stIn;
	stack<int> stOut;

	void push(int x) {
		stIn.push(x);
	}

	int pop() {
		// Input data to stOut only when stOut is empty.
		if(stOut.empty()) {
			// Transfer the data in stIn to stOut
			while(!stIn.empty()) {
				stOut.push(stIn.top());
				stIn.pop();
			}
		}
		int res = stOut.top();
		stOut.pop();
		return res;
	}

	// get the head of queue
	int peek() {
		int res = this->pop(); // Use our own pop function.
		stOut.push(res); // Use pop-function will pop the head in queue, so push it again.
		return res;
	}

	bool empty() {
		// MyQueue it empty when both stOut and stIn are empty.
		return stOut.empty() && stIn.empty();
	}
};

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
	return 0;
}
