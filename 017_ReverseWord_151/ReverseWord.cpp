/**
 * leetcode : 151
 * Reverse the sequence of words.
 * Bohn Chen 2022-04-07 22:33
 * 1. remove usless blanks in given string
 * 2. reverse entire string
 * 3. reverse word
 */
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
	string reverseWords(string s)
	{
		RemoveExtraBlanks(s);
		reverse(s.begin(), s.end());
		int slow = 0, fast = 0;
		for (; fast < s.size(); ++fast) {
			if (fast != s.size() - 1) {
				if (s[fast] != ' ') {
					continue;
				} else {
					reverse(s.begin() + slow, s.begin() + fast);
					slow = fast;
					// skip the blank
					++slow;
				}
			} else {
				// end is the last one element's next position
				reverse(s.begin() + slow, s.begin() + fast + 1);
			}
		}
		return s;
	}

	void RemoveExtraBlanks(string& s)
	{
		int pSlow = 0, pFast = 0;
		// Handle the blanks in the begining.
		while (pFast > 0 && s[pFast] == ' ') {
			++pFast;
		}
		// Handle the blanks in the body.
		for (; pFast < s.size(); ++pFast) {
			if (pFast - 1 > 0 && s[pFast - 1] == s[pFast] && s[pFast] == ' ') {
				continue;
			} else {
				s[pSlow++] = s[pFast];
			}
		}
		// Handle the blanks at the end.
		if (pSlow - 1 > 0 && s[pSlow - 1] == ' ') {
			// because post ++
			s.resize(pSlow - 1);
		} else {
			s.resize(pSlow);
		}
	}
};


int main(int argc, char *argv[])
{
	Solution s;
	string str { "  hello world " };
	cout << s.reverseWords(str) <<  endl;
	return 0;
}
