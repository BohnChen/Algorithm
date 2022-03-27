/**
 * Reverse List
 * nowcoder: BM1
 * leetcode: 206
 * Bohn Chen : 2022-03-27 22:25
 */

#include <cstdlib>
#include <iostream>
#include <time.h>
#define NUM 10

typedef struct LinkNode {
	int val;
	LinkNode* next;

	LinkNode(int x)
			: val(x)
			, next(nullptr)
	{
	}
} * LinkList;

class Solution {
	public:
	LinkNode* ReverseList(LinkNode* pHead);
};

// Solution 1:
/*LinkNode* Solution::ReverseList(LinkNode* pHead)
{
	LinkList pCur = pHead;
	LinkList pPre = nullptr;
	while (pCur) {
		LinkList pNext = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNext;
	}
	return pPre;
}
*/
// Solution 2:
LinkNode* Reverse(LinkNode* pre, LinkNode* pCur) {
	if (pCur == nullptr) return pre;
	LinkNode* temp = pCur->next;
	pCur->next = pre;
	return Reverse(pCur, temp);
}


LinkNode* Solution::ReverseList(LinkNode* pHead) {
	return Reverse(nullptr, pHead);
}

void MyPrint(LinkList L) {
	while(L) {
		std::cout << " " << L->val;
		L = L->next;
	}

}


int main(int argc, char* argv[])
{
	Solution solut;
	srand((int)time(NULL));
	struct LinkNode* pHead = (struct LinkNode*)malloc(sizeof(LinkNode));
	pHead->val = rand() % 10;
	pHead->next = nullptr;
	struct LinkNode* pCur = (struct LinkNode*)malloc(sizeof(LinkNode));
	pCur = pHead;
	struct LinkNode* pNew;
	for (int i = 0; i < NUM; ++i) {
		pNew = (struct LinkNode*)malloc(sizeof(LinkNode));
		pNew->val = rand() % 10;
		pCur->next = pNew;
		pCur = pNew;
	}
	struct LinkNode* pTemp = (struct LinkNode*)malloc(sizeof(LinkNode));
	pTemp = pHead;
	MyPrint(pTemp);
	std::cout << std::endl;
	
	pTemp = solut.ReverseList(pHead);
	// pTemp = pHead;
	MyPrint(pTemp);
	return 0;
}
