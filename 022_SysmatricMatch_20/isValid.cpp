/**
 * leetcode : 20
 * Use stack to slove sysmatic matching problems.
 * Bohn Chen 2022-04-11 18:57
 */
#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Sysmatric matching usually use stack.
        stack<int> st;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '{') 
                // for comparing 
                st.push('}');
            else if(s[i] == '(') 
                st.push(')');
            else if(s[i] == '[') 
                st.push(']');
            // st will be empty if there are extra right brackets
            // if st.top() != s[i] means error sequences
            else if(st.empty() || st.top() != s[i]) 
                return false;
            else 
                st.pop();
        }
        // st will not be empty if there are extra left brackets
        return st.empty();
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	string str {"{(})"};
	cout << s.isValid(str) << endl;
	return 0;
}
