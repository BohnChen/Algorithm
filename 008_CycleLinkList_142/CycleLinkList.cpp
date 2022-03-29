/**
 * leetcode : 142
 * Find Cycle in LinkList
 * Bohn Chen 2022-03-29
 */
#include <iostream>
class Solution {
	public:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode()
				: val(0)
				, next(nullptr)
		{
		}
		ListNode(int x)
				: val(x)
				, next(nullptr)
		{
		}
	};
	
	Solution() 
	{
		ListNode* dummyHead = new ListNode(0);
		size = 0;
	}

	ListNode* detectCycle(ListNode* head)
	{
		// Using slow and fast pointers to find cycle
		ListNode* pSlow = head;
		ListNode* pFast = head;
		// in a NO cycle LinkList,if we judge pSlow first and then judge pFast->next, and it may cause ERROR because *NULL!!!
		// Using short circuit to avoid error.
		// pSlow is slower than pFast
		while(pFast != nullptr && pFast->next != nullptr) {
			pSlow = pSlow->next;
			pFast = pFast->next->next;
			if (pSlow == pFast) {
				ListNode* Index1 = head;
				ListNode* Index2 = pFast;
				while(Index1 != Index2) {
					Index1 = Index1->next;
					Index2 = Index2->next;
				}
				return Index1;
			}
		}
		return nullptr;
	}

	void addAtHead(int val) {
		ListNode* pNew = new ListNode(val);
		ListNode* pCur = dummyHead;
		while(pCur->next) {
			pCur = pCur->next;
		}
		pCur->next = pNew;
	}

	void makeCycle(int pos) {
		ListNode* pCur = dummyHead;
		ListNode* pEntry = dummyHead;

		if(pos < size && pos > 0) {
			while(pos--) {
				pEntry = pEntry->next;
			}

			while(pCur->next) {
				pCur = pCur->next;
			}
			pCur->next = pEntry;
			std::cout << "make cycle success! " << std::endl;
		}else {
			std::cout << "ERROR pos." << std::endl;
		}
	}


	ListNode* dummyHead;
	int size;
};


int main(int argc, char *argv[])
{
	Solution s;
	s.addAtHead(1);
	s.addAtHead(2);
	s.addAtHead(3);
	s.addAtHead(4);
	s.addAtHead(5);
	s.addAtHead(6);
	if(s.detectCycle(s.dummyHead) == nullptr)
		std::cout << "No cycle. " << std::endl;
	s.makeCycle(3);
	if(s.detectCycle(s.dummyHead) != nullptr)
		std::cout << "The entry is :  " <<  s.detectCycle(s.dummyHead) << std::endl;
	return 0;
}


