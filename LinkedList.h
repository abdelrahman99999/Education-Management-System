#pragma once
#include "ListNode.h"

template<class T>
class LinkedList {
private:
	listNode<T> *head;
	int size;
public:
	LinkedList() {
		size = 0;
		head = NULL;
	}
	bool listEmpty() {
		return !size;
	}
	bool listFull() {
		return 0;
	}
	int listSize() {
		return size;
	}

	void clearList() {
		listNode<T> *pn = head;
		while (head) {
			pn = pn->next;
			free(head);
			head = pn;
		}
		size = 0;
	}
	int insertList(int pos, T e) {
		listNode<T> *pn;
		listNode<T> *temp = head;
		//if (pn = (listNode<T>*)malloc(sizeof(listNode<T>));
		if (pn = new listNode<T>) {
			pn->entry = e;
			if (pos == 0) {
				pn->next = head;
				head = pn;
			}
			else {
				for (int i = 0; i < pos - 1; i++) {
					temp = temp->next;
				}
				pn->next = temp->next;
				temp->next = pn;
			}
			size++;
			return 1;
		}
		else {
			return 0;
		}
	}

	T deleteList(int pos) {
		T pe;
		listNode<T> *pn, *temp;
		if (pos == 0) {
			pe = head->entry;
			temp = head->next;
			free(head);
			head = temp;
		}
		else {
			pn = head;
			for (int i = 0; i < pos - 1; i++) {
				pn = pn->next;
			}
			pe = pn->next->entry;
			temp = pn->next->next;
			free(pn->next);
			pn->next = temp;
		}
		size--;
		return pe;
	}

	T retrieveList(int pos) {
		T pe;
		listNode<T> *pn = head;
		for (int i = 0; i < pos; i++) {
			pn = pn->next;
		}
		pe = pn->entry;
		return pe;
	}

	void traverseList(void(*pf)(T)) {
		listNode<T> *pn = head;
		while (pn) {
			(*pf)(pn->entry);
			pn = pn->next;
		}
	}

	void replaceList(int pos, T e) {
		listNode<T> *pn = head;
		for (int i = 0; i < pos; i++) {
			pn = pn->next;
		}
		pn->entry = e;
	}

};

