/**
 * ReverseString : A easy problem
 * leetcode : 344
 * Bohn Chen 2022-04-05 21:45
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	void reverseString (vector<char>& s){
		// reverse(s.begin(), s.end());
		for(int i = 0, j = s.size() - 1; i <= s.size() / 2 && j >= s.size() / 2; ++i, --j) {
			// swap(s[i], s[j]);
			char c = s[i];
			s[i] = s[j];
			s[j] = c;
		}
	}

	void print( const vector<char> s) {
		for (auto c: s) {
			cout << c << " " ;
		}
		std::cout << std::endl;
		
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<char> nums  = { 'A',' ','m','a','n',',',' ','a',' ','p','l','a','n',',',' ','a',' ','c','a','n','a','l',':',' ','P','a','n','a','m','a'};
	s.print(nums);
	s.reverseString(nums);
	s.print(nums);

	return 0;
}
