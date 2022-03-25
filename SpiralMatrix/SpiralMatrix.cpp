/**
 * leetcode : 59
 * Bohn Chen 2022-03-25 22:25
 * |1|2|3|    |1 | 2| 3| 4|
 * |8|9|4|    |12|13|14| 5|
 * |7|6|5|    |11|16|15| 6|
 *						|10| 9| 8| 7|
 */
#include <iostream>
#include <vector>



class Solution {
	public:
		std::vector<std::vector<int>> generateMatrix (int n) {
			std::vector<std::vector<int>> res(n, std::vector<int>(n ,0));
			int startx = 0, starty = 0;					// (startx, starty) is the start coordinati
			int loop = n / 2;										// Find the unchanged value, then find circle times
			int mid = n / 2;										// (1, 1) is the middle coordinate in 3 * 3 matrix
			int count = 1;											// Using for assignning
			int offset = 1;											// Rule the range.
			int i = 0, j = 0;

			while (loop--) {
				i = startx;
				j = starty;

				// Right
				for(j = starty; j < starty + n - offset; ++j ) {
					res[i][j] = count++;
				}

				// Down
				for(i = startx; i < startx + n - offset; ++i) {
					res[i][j] = count++;
				}

				// Left
				for(; j > starty; --j) {
					res[i][j] = count++;
				}

				// Up
				for(; i > startx; --i) {
					res[i][j] = count++;
				}

				// Change coordinate in next circle
				startx++;
				starty++;

				// Control border condition
				offset += 2;
			}

			if(n % 2) {
				res[mid][mid] = count;
			}
			return res;
		}
};


int main(int argc, char *argv[])
{
	Solution s;
	std::vector<std::vector<int>> vec;
	vec = s.generateMatrix(4);
	for(auto v1 : vec) {
		for (auto v2: v1) {
			std::cout << v2 << " ";
		}
		std::cout <<  std::endl;
	}
	return 0;
}

