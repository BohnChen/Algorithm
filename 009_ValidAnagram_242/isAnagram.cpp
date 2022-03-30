/**
 * leetcode : 242
 * IsAnagram?
 * Bohn Chen 2022-03-30 17:57
 */
#include <iostream>
#include <string.h>
using namespace std;
class Solution {
public:
	bool IsAnagram(string s, string t) {
		if(s.size() != t.size())
			return false;
		// bitmap
		int arr1[26] { 0 };
		int arr2[26] { 0 };
		for (int i = 0; i < s.size(); ++i) {
			++arr1[s[i] - 'a'];
		}
		for (int i = 0; i < t.size(); ++i) {
			++arr2[t[i] - 'a'];
		}
		for (int i = 0; i < 26; ++i) {
			if(arr1[i] != arr2[i])
				return false;
		}
		return true;
	}
};


int main(int argc, char *argv[])
{
	Solution solu;
	string s = "arst";
	string t = "rsta";
	if(solu.IsAnagram(s, t))
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	return 0;
}

