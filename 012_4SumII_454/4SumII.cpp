/**
 * We can get the importance of selecting datastructures.
 * leetcode : 454
 * Bohn Chen 2022-04-02 22:05
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
	public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
	{
		/*
		// time complexity : O(n^4)
		int cnt = 0;
		for (int i = 0; i < nums1.size(); ++i) {
			for (int j = 0; j < nums2.size(); ++j) {
				for (int k = 0; k < nums3.size(); ++k) {
					for (int t = 0; t < nums4.size(); ++t) {
						if(num1[i] + nums2[j] + nums3[k] + nums4[t] == 0)
							++cnt;
					}
				}
			}
		}
		return cnt;
		*/
		// we can use map here, and you can compare RB-tree and hash here
		unordered_map<int, int> myUnorderedMap;
		for (auto i1 : nums1) {
			for (auto i2 : nums2) {
				++myUnorderedMap[i1 + i2];
			}
		}

		int cnt = 0;
		for (auto i3 : nums3) {
			for (auto i4 : nums4) {
				if (myUnorderedMap.find(0 - i3 - i4) != myUnorderedMap.end()) {
					cnt += myUnorderedMap[0 - i3 - i4];
				}
			}
		}
		return cnt;
	}
};

int main(int argc, char* argv[])
{
	Solution s;
	vector<int> nums1 {
		-4, -12, 3, -7, 6, -27, 4, -5, -23, -19, -10, -12, -17, -30, -24, -6, -15, -7, -11, -11, 0, -32, -2, -14, 5, -28, -2, -22, -29, -30, 7, -22, 4, -14, -17, 2, -12, 2, -13, -18, -4, -6, -27, -23, -1, -31, -23, -14, 5, 7, 10, 9, -5, -7, -14, -13, -16, 8, -28, -7, 5, -9, -16, -12, -8, -14, -6, -20, -22, -8, -4, -9, -16, -3, 9, 1, -25, -6, -10, 6, -6, -5, -29, -27, 2, -12, -20, 10, -22, -9, -32, -8, -16, -6, -16, 9, -4, -18, -11, -4
	};
	vector<int>
			nums2 {
				3, -30, -17, -20, -20, -21, -29, 5, -13, -31, -11, 4, -2, -27, -2, -15, -26, -3, 0, 5, -2, -15, 7, -18, 9, -19, -4, -15, -6, -30, 1, -21, 10, -28, -11, -11, -25, 1, -7, -17, -6, -9, -26, -28, 8, -12, 0, -7, 1, -9, 9, 10, -12, -15, -15, -6, -27, -17, -24, 2, -30, 10, -17, 0, -12, -24, -13, -25, -10, -29, 5, -10, -28, -9, -3, -32, -12, -9, 3, -8, -24, -1, -6, 8, 4, -10, -15, -4, 1, -11, -15, -11, -32, 1, -32, -1, 7, -27, 0, 2
			};
	vector<int>
			nums3 {
				-23, -20, -11, -10, -19, -26, -14, -9, -21, -24, -10, -13, 3, -5, -26, 8, 5, -15, 2, -26, -5, 10, -16, -14, -5, 5, -16, -12, 6, -26, -16, 2, -8, 10, -29, -6, -14, -22, -4, -29, 3, -1, 9, 0, -21, -1, -22, 4, 6, -32, -26, -18, -24, -19, -9, -5, -20, -20, 4, 1, 9, -7, -26, -12, -9, 6, -20, -19, -18, -29, -11, -8, -29, 1, 3, -1, -29, -19, -3, -24, -23, -6, 10, 9, 6, -24, -25, 4, -25, -14, -32, -32, -25, -4, 4, -24, -24, 7, -5, -1
			};

	vector<int>
			nums4 {
				-24, -3, -26, 9, -5, -3, -24, 6, 7, -9, 8, -16, 4, -14, -30, -9, 4, -29, -24, -20, -6, -22, -20, 7, 5, -14, -9, 0, 5, -15, 1, -12, 2, 3, 7, 3, -24, 7, -18, -27, -19, 5, -13, -14, 1, -26, -6, 8, -11, -27, -3, -27, -18, -4, 8, 4, -25, 1, -15, -22, -6, 4, 10, 1, -16, -10, -6, -5, -5, -23, -9, 2, 0, 9, -14, -25, -20, -25, 7, -31, -6, -18, -22, -19, -32, -16, -32, 1, -22, -26, 8, 5, -28, 3, -26, 0, 4, -7, -32, -27
			};
	std::cout << "the correct result is 407524." << endl;;
	std::cout << "result : " << s.fourSumCount(nums1, nums2, nums3, nums4) << std::endl;
	return 0;
}
