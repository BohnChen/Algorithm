/**
 * leetcode : 19
 * Remove nth element from end.
 * Bohn Chen 2022-03-28 17:02
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
	ListNode* RemoveNthFromEnd(ListNode* head, int n)
	{
		// Nth element from end is (length - N + 1)th element
		/*
		 * 1: get length
		 * 2: find pre-Node of target
		 * 3: delete
		 */

		/*
		 * 1: Move fast pointer n times.
		 * 2: Move both pointers until pFast is nullptr.
		 * 3: return dummyHead->next but not head, because head may be freed.
		 */
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* pSlow = dummyHead;
		ListNode* pFast = dummyHead;
		while(n-- && pFast != nullptr) {
			pFast = pFast->next;
		}
		// We should get the Pre-Node
		pFast = pFast->next;
		while(pFast) {
			pFast = pFast->next;
			pSlow =pSlow->next;
		}
		// Now pSlow point to prev Node of target.
		ListNode* tmp = pSlow->next;
		pSlow->next = pSlow->next->next;
		delete tmp;
		return dummyHead->next;
	}

	// Insert a element at tail
	void addAtTail(ListNode* head, int val)
	{
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* pNew = new ListNode(val);
		ListNode* pCur = dummyHead;
		while (pCur->next != nullptr) {
			pCur = pCur->next;
		}
		pCur->next = pNew;
	}

	void printLinkList(ListNode* head){
		if(head == NULL) {
			std::cout << "List is NULL." << std::endl;
			return;
		}
		ListNode* pCur = head;
		while(pCur != nullptr) {
			std::cout << pCur->val << " ";
			pCur = pCur->next;
		}
	}
	ListNode* head = new ListNode(1);
};



int main(int argc, char *argv[])
{
	Solution s;
	// s.addAtTail(s.head, 2);
	// s.addAtTail(s.head, 3);
	// s.addAtTail(s.head, 4);
	// s.addAtTail(s.head, 5);
	s.printLinkList(s.head);
	std::cout << std::endl;
	s.printLinkList(s.RemoveNthFromEnd(s.head, 1));
	return 0;
}
