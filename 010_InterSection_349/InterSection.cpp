/**
 * Exercise set,multi_set,unordered_set in STL containers
 * Bohn Chen 2022-03-31 22:38
 */
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		// the flow 4 lines equals with 9th line.
		unordered_set<int> s;
		for (int i = 0; i < nums1.size(); ++i) {
			s.insert(nums1[i]);
		}
		// unordered_set<int> s(nums1.begin(), nums1.end());
		unordered_set<int> result_set;
		for(auto itemp : nums2) {
			if(s.find(itemp) != s.end())
				result_set.insert(itemp);
		}
		// It is better to use anonymous object Or comment lines blow
		return vector<int>(result_set.begin(), result_set.end());
		// vector<int> resVec;
		// for (auto itemp : result_set) {
		// 	resVec.push_back(itemp);
		// }
		// return resVec;
	}
};



int main(int argc, char *argv[])
{
	Solution s;
	vector<int> nums1{4,7,9,7,6,7};
	vector<int> nums2{5,0,0,6,1,6,2,2,4};
	std::cout << "The result is :" ;
	for( auto c :  s.intersection(nums1, nums2) ){
		std::cout <<  c << " ";
	}
	return 0;
}
