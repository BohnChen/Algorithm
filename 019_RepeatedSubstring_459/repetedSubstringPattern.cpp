/**
 * leetcode : 459
 * kmp
 * Bohn Chen 2022-04-09 22:35
 */
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); ++i) {
            while(j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if(s[i] == s[j]) {
                ++j;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if(next[len - 1] != 0 && len % (len - next[len - 1]) == 0){
            return true;
        }
        
        return false;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.repeatedSubstringPattern("abab") << endl;
	return 0;
}
