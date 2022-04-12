/**
* leetcode : 150
* Descrip	 : none  
* Paragra  : Bohn Chen 2022-04-12 21:53
*/
#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> numSt;
		for (auto c: tokens) {
			if(c == "-" || c == "+" || c == "*" || c == "/") {
				int num1 = numSt.top();
				numSt.pop();
				int num2 = numSt.top();
				numSt.pop();

				if(c == "+") numSt.push(num2 + num1);
				if(c == "-") numSt.push(num2 - num1);
				if(c == "*") numSt.push(num2 * num1);
				if(c == "/") numSt.push(num2 / num1);
			} else {
				// string to int 
				numSt.push(stoi(c));
			}
		}
		int res = numSt.top();
		numSt.pop();
		return res;
	}
};

int main(int argc, char *argv[])
{
	vector<string> tokens { "4", "12", "5", "/", "+" };
	for (auto c: tokens) {
		std::cout << c << " ";
	}
	std::cout << std::endl;
	Solution s;
	cout << "The restult is " << s.evalRPN(tokens) << endl;
	return 0;
}
