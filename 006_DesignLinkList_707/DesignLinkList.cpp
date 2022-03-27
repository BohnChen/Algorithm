/**
 * Design my own linklist and implement six interface
 * leetcode : 707
 * Bohn Chen 2022-03-27
 */

/*
 *
 * MyLinkedList() :
 * Initializes the MyLinkedList object.
 *
 * int get(int index) :
 * Get the value of the indexth node in the linked list. If the index is invalid, return -1.
 *
 * void addAtHead(int val) :
 * Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
 *
 * void addAtTail(int val) :
 * Append a node of value val as the last element of the linked list.
 *
 * void addAtIndex(int index, int val) :
 * Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
 *
 * void deleteAtIndex(int index)  :
 * Delete the indexth node in the linked list, if the index is valid.
 */
#include <iostream>

class MyLinkedList {
	public:
	struct LinkNode {
		int val;
		LinkNode* next;
		LinkNode()
				: val(0)
				, next(nullptr)
		{
		}
		LinkNode(int x)
				: val(x)
				, next(nullptr)
		{
		}
	};

	// Initializes LinkList
	MyLinkedList()
	{
		// Virtual head
		dummyHead = new LinkNode(0);
		size = 0;
	}

	// get the val of Linklist[index]
	int get(int index)
	{
		// For robast
		if (index > size - 1 || index < 0)
			return -1;
		LinkNode* pCur = dummyHead->next;
		// This a fabulas handle method
		while (index--) { // It must be "a--"
			pCur = pCur->next;
		}
		return pCur->val;
	}

	// Insert a element at LinkList Head
	void addAtHead(int val)
	{
		LinkNode* pNew = new LinkNode(val);
		pNew->next = dummyHead->next;
		dummyHead->next = pNew;
		++size;
	}

	// Insert a element at tail
	void addAtTail(int val)
	{
		LinkNode* pNew = new LinkNode(val);
		LinkNode* pCur = dummyHead;
		while (pCur->next != nullptr) {
			pCur = pCur->next;
		}
		pCur->next = pNew;
		++size;
	}

	// Insert a element before indexth element
	// index == 0 : addAtHead
	// index == size : addAtTail
	// else : execute nothing
	void addAtIndex(int index, int val)
	{ // ps: You only need to find pre-position of insert position
		if (index > size)
			return;
		LinkNode* pNew = new LinkNode(val);
		LinkNode* pCur = dummyHead;
		while (index--) {
			pCur = pCur->next;
		}
		pNew->next = pCur->next;
		pCur->next = pNew;
		++size;
	}

	// delete indexth element
	// return if index >= size
	void deleteAtIndex(int index) {
		if(index > size || index < 0) 
			return;
		LinkNode* pCur = dummyHead;
		while(index--) {
			pCur = pCur->next;
		}
		LinkNode* tmp = pCur->next;
		pCur->next = pCur->next->next;
		delete tmp;
		--size;
	}

	void printLinkList() {
		LinkNode* pCur = dummyHead->next;
		while(pCur) {
			std::cout << pCur->val << " ";
			pCur = pCur->next;
		}
		std::cout << std::endl;
		
	}

	private:
	LinkNode* dummyHead;
	int size;
};



int main(int argc, char *argv[])
{
	MyLinkedList linklist;
	linklist.addAtHead(1);
	linklist.addAtTail(3);
	linklist.addAtIndex(1, 2);
	linklist.printLinkList();
	std::cout << "get(1) : " << linklist.get(1) << std::endl;
	linklist.deleteAtIndex(1);
	std::cout << "After deleteAtIndex(1) : " << std::endl;
	linklist.printLinkList();
	std::cout << "get(1) : " << linklist.get(1) << std::endl;
	linklist.printLinkList();
	return 0;
}
