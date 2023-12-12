#include <iostream>
#include<algorithm>
#include<cassert>
using namespace std;
template <class any>
class linkedList
{
private:
	struct node
	{
		any item;
		node* next;
	};
	node* head;
	node* tail;
	int length;

public:
	linkedList() {
		length = 0;
		head = tail = NULL;
	}

	bool isEmpty()
	{
		return length == 0;
	}

	int getSize()
	{
		return length;
	}

	void insertAtBegin(any elem)
	{
		node* newNode = new node;
		newNode->next = NULL;
		newNode->item = elem;

		if (isEmpty())
		{

			head = tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		length++;
	}

	void insertAtEnd(any element)
	{
		node* newNode = new node;
		newNode->item = element;
		newNode->next = NULL;

		if (isEmpty())
			head = tail = newNode;
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		length++;
	}//insert at end Method

	void insertAt(int pos, any elem)
	{
		if (pos == 0)
		{
			insertAtBegin(elem);
			return;
		}
		if (pos == length)
		{
			insertAtEnd(elem);
			return;
		}
		else if (pos<0 || pos>length)
		{
			cout << "Out of Range !!!\n";
			return;
		}

		node* newNode = new node;
		newNode->item = elem;
		node* cur = head;

		for (int i = 1; i < pos; i++)
		{
			cur = cur->next;
		}
		newNode->next = cur->next;
		cur->next = newNode;

		length++;
	}

	void removeFirstItem()
	{
		assert(!isEmpty());

		if (head == tail)
		{
			delete tail;
			delete head;
			length = 0;

			return;
		}

		node* temp = head;

		head = head->next;

		temp->next = NULL;
		delete temp;

		length--;
	}
	void popBack()
	{
		assert(!isEmpty());

		if (length == 1)
		{
			removeFirstItem();
			return;
		}

		node* trailCurr, * curr;

		trailCurr = head;
		curr = head->next;

		while (curr->next != NULL)
		{
			trailCurr = trailCurr->next;
			curr = curr->next;
		}

		tail = trailCurr;
		tail->next = NULL;
		delete curr;

		length--;
	}
	int seqSearch(any element)
	{
		assert(!isEmpty());


		node* curr = head;
		int loc = 0;

		while (curr != NULL)
		{
			if (curr->item == element)
				return loc;

			curr = curr->next;
			loc++;
		}

		return -1;
	}

	void removeAt(int location)
	{
		assert(!isEmpty());

		if (location<0 || location>=length)
		{
			cout << "Out Of Range ...!!!" << endl;
			return;
		}
		else if (location == 0)
		{
			removeFirstItem();
			return;
		}

		node* curr = head->next;
		node* trailcurr = head;

		for (int i = 1; i < location; i++)
		{
			curr = curr->next;
			trailcurr = trailcurr->next;
		}

		trailcurr->next = curr->next;

		if (tail == curr) // last item
		{
			tail = trailcurr;
		}

		delete curr;
		length--;

	}

	void print()
	{
		assert(!isEmpty());

		node* curr = head;

		while (curr != NULL)
		{
			cout << curr->item << " ";
			curr = curr->next;
		}
		cout << "\n";
	}

	void remove(any element)
	{
		int location = seqSearch(element);
		removeAt(location);
	}
	void reverse()
	{
		node* prev = NULL;
		node* curr = head;
		node* nex=new node;

		while (nex != NULL && curr != NULL)
		{
			nex = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nex;
		}
		head = prev;
	}
};
int main()
{
	linkedList<int> list;

	list.insertAtEnd(10);
	list.insertAtEnd(20);
	list.insertAtEnd(30);
	list.insertAtEnd(40);
	list.insertAtEnd(50);
	list.insertAtEnd(60);

	list.insertAtBegin(5);

	list.reverse();


	list.print();


	system("pause");

	return 0;
}
