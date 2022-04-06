/**
 * reverse string
 * leetcode : 541
 * Bohn Chen 2022-04-06 21:27
 */
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
	string reverseStr(string& s, int k){
		for (int i = 0; i < s.size(); i += (2 * k)) {
			if(i + k < s.size()) {
				reverse(s.begin() + i, s.begin() + i + k);
				continue;
			}
			// if less than k
			reverse(s.begin() + i, s.begin() + s.size());
		}
		return s;
	}
	void print (string s) {
		for (auto c: s) {
			std::cout << c << " ";
		}
	}
};


int main(int argc, char *argv[])
{
	Solution s;
	string str {"arstdhneio"};
	s.print(str);
	int k = 2;
	std::cout << std::endl;
	s.reverseStr(str, k);
	s.print(str);
	return 0;
}
