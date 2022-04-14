/**
* leetcode : 347
* Descrip	 : none  
* Paragra  : Bohn Chen 2022-04-14 20:01
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
class Solution {
public:
    // 小顶堆
    class mycomparison {
    public:
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计元素出现的次数
        unordered_map<int, int> map; // map<nums[i], 对应出现次数>
        for(int i = 0; i < nums.size(); ++i) {
            ++map[nums[i]];
        }

        // 对元素出现的次数进行排序
        // 定义一个小顶堆，大小为 k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // 用固定大小为 k 的小顶堆遍历所有元素出现次数的数值
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); ++it) {
            pri_que.push(*it);
            // 如果堆的大小k，则队列弹出，保证堆的大小一直为k
            if(pri_que.size() > k) {
                pri_que.pop();
            }
        }

        // 找出前 k 个高频元素，因为小顶堆先弹出的是最小的元素，所以倒序输出到 res 数组中
        vector<int> res(k);
        for(int i = k - 1; i >= 0; --i) {
            res[i] = pri_que.top().first;
            pri_que.pop();
        }
        return res;

    }
};


int main(int argc, char *argv[])
{
	Solution s;
	vector<int> nums { 2, 2, 2, 2, 3, 5,5,123, 23, 34, 4, 4 };
	int k = 2;
	for(auto c : s.topKFrequent(nums, k)) {
		std::cout << c << " ";
	}
	return 0;
}
