/**
 * Remove element in linklist
 * Bohn Chen 2022-03-26
 */
#include <iostream>

// destination
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
	ListNode(int x, ListNode* next)
			: val(x)
			, next(next)
	{
	}
};

class Solution {
	public:
	// remove element that val == val
	ListNode* removeElements(ListNode** head, int val)
	{
		// delete head
		while((*head) != NULL && (*head)->val == val) {
			ListNode* tmp = *head;
			(*head) = (*head)->next;
			delete tmp;
		}

		// delete element is not head
		ListNode* pCur = *head;
		while (pCur != NULL && pCur->next != NULL) {
			if (pCur->next->val == val) {
				ListNode* tmp = pCur->next;
				pCur->next = pCur->next->next;
				delete tmp;
			} else {
				pCur = pCur->next;
			}
		}
		return *head;
	}
};

int main(int argc, char* argv[])
{
	Solution s;
	ListNode* head = new ListNode(3);
	ListNode* pCur = head;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 4; ++i) {
		ListNode* pNew = new ListNode(rand() % 4);
		pCur->next = pNew;
		pCur = pNew;
	}
	pCur = head;
	while (pCur) {
		std::cout << pCur->val << " ";
		pCur = pCur->next;
	}
	std::cout << std::endl;
	s.removeElements(&head, 3);
	pCur = head;
	while (pCur) {
		std::cout << pCur->val << " ";
		pCur = pCur->next;
	}

	return 0;
}
