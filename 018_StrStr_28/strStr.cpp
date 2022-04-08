/**
 * leetcode : 28
 * KMP
 * Bohn Chen 2022-04-08 23:33
 */
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    // 前缀表统一减一的代码如下
    void getNext(int* next, const string& s) {
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.size(); ++i) {
            while( j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同
                j = next[j];    // 向前回退
            }
            if (s[i] == s[j + 1]) { // 找到相同的前后缀
                ++j;
            }
            next[i] = j;  // 将 j (前缀的长度)赋值给 next[i]
        }
    }
    // haystack 为文本串， needle 为模式串
    int strStr(string haystack, string& needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = -1; // next 数组中记录的起始位置为 -1
        for(int i = 0; i < haystack.size(); ++i) { // 注意 i 就从 0 开始
            while(j >= 0 && haystack[i] != needle[j + 1]) { // 不匹配
                j = next[j];
            }
            if(haystack[i] == needle[j + 1]) { // 匹配， j 和 i 同时向后移动
                ++j;    // i 的增加逻辑再 for 循环中
            }
            if(j == (needle.size() - 1)) { // 文本串 s 中出现了模式串 t
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};


int main(int argc, char *argv[])
{
	Solution s;
	string needle = "lo";
	cout << s.strStr("hello", needle) << endl;
	return 0;
}
