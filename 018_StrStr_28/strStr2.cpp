/**
 * leetcode : 28
 * 直接将前缀表当作 next 数组使用
 *  Bohn Chen 2022-04-09 19:32
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	void getNext(int* next, const string& needle) {
		int j = 0;
		next[0] = 0;
		for (int i = 1; i < needle.size(); ++i) {
			while(j > 0 && needle[i] != needle[j]){
				j = next[j - 1];
			}
			if(needle[i] == needle[j]) {
				++j;
			}
			next[i] = j;
		}
	}

	int strStr(string haystack, string needle) {
		if(needle.size() < 1) {
			return 0;
		}
		int next[needle.size()];
		getNext(next, needle);
		int j = 0;
		for(int i = 0; i < haystack.size(); ++i) {
			while(j > 0 && haystack[i] != needle[j]){
				j = next[j - 1];
			}
			if(haystack[i] == needle[j]) {
				++j;
			}
			if(j == needle.size()) {
				return (i - needle.size() + 1);
			}
		}
		return -1;
	}
};


int main(int argc, char *argv[])
{
	Solution s;
	string haystack { "aabaabaaf" };
	string needle { "aabaaf" };
	cout << s.strStr(haystack, needle) << endl;
	return 0;
}
