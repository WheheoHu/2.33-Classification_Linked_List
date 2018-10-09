#pragma once
#include <iostream>

template<typename T>
struct Node {
	T data;
	Node * next;
	Node(const T &d) :data(d), next(NULL) {}
};

template<class T>
class Linear_Linked_List
{
public:

	Linear_Linked_List();
	Linear_Linked_List(T elem);
	~Linear_Linked_List();
	void InitList(T firstelem);
	void DestoryList();
	bool ListEmpty();
	int ListLength();
	T GetElem(int location);
	int locateElem(T elem);
	int ListInsert(int location, T elem);
	int ListDelete(int location, T& elem);
	int ListDelete(int location);
	Node<T> *HeadPoint;
	Node<T> *EndPoint;
	Node<T> * getEndPoint();
private:

	Node<T> * head;
	//寻找第location个Node前一个Node的位置！！！！
	Node<T> * find(const int &location) {
		Node<T> *locateNode = head;
		if (location == 1)
		{
			return locateNode;
		}
		for (int i = 0; i < location - 2; i++)
		{
			locateNode = locateNode->next;
		}
		return locateNode;
	}
};

template<class T>
inline Linear_Linked_List<T>::Linear_Linked_List()
{
	std::cout << "Please initalize list manually!(Use InitList)" << std::endl;
}

template<class T>
inline Linear_Linked_List<T>::Linear_Linked_List(T elem)
{
	InitList(elem);
}

template<class T>
inline Linear_Linked_List<T>::~Linear_Linked_List()
{
	DestoryList();
}

template<class T>
inline void Linear_Linked_List<T>::InitList(T firstelem)
{
	head = new Node<T>(firstelem);
	HeadPoint = head;
}

template<class T>
inline void Linear_Linked_List<T>::DestoryList()
{
	Node<T> *p = head;

	while (p)
	{
		Node<T> *q = p->next;
		delete p;
		p = q;
	}
}

template<class T>
inline bool Linear_Linked_List<T>::ListEmpty()
{
	return(head == NULL);
}

template<class T>
inline int Linear_Linked_List<T>::ListLength()
{
	int listlenght = 0;
	Node<T> *p = head;
	while (p != NULL)
	{
		p = p->next;
		listlenght++;
	}
	return listlenght;
}

template<class T>
inline T Linear_Linked_List<T>::GetElem(int location)
{
	/*Node *p = head;
	for (int i = 0; i < (location-1); i++)
	{
		p = p->next;
	}*/
	Node<T> *p = find(location);
	if (location == 1)
	{
		return p->data;
	}
	return p->next->data;
}

template<class T>
inline int Linear_Linked_List<T>::locateElem(T elem)
{
	Node *targetNode = head;
	int location = 1;
	while (targetNode->data != elem && targetNode->next != NULL)
	{
		targetNode = targetNode->next;
		location++;

	}
	if (targetNode->next == NULL)
	{
		return 0;
	}
	return location;
}

template<class T>
inline int Linear_Linked_List<T>::ListInsert(int location, T elem)
{
	Node<T> *InsertNode = new Node<T>(elem);
	if (location == 1)
	{
		InsertNode->next = head;

		head = InsertNode;
		return 1;
	}
	if (location > ListLength())
	{
		Node<T> *lastNode = head;
		for (int i = 0; i < ListLength() - 1; i++)
		{
			lastNode = lastNode->next;
		}
		lastNode->next = InsertNode;
		return 1;
	}
	Node<T> *PreNode = head;
	for (int i = 0; i < location - 2; i++)
	{
		PreNode = PreNode->next;
	}
	InsertNode->next = PreNode->next;
	PreNode->next = InsertNode;
	return 1;
}

template<class T>
inline int Linear_Linked_List<T>::ListDelete(int location, T & elem)
{
	Node *deleteNode = head;
	if (location == 1)
	{
		elem = deleteNode->data;
		free(head);
		head = deleteNode->next;
		return 1;
	}
	for (int i = 0; i < location - 1; i++)
	{
		deleteNode = deleteNode->next;
	}
	Node *tempNode = deleteNode;

	elem = deleteNode->next->data;
	free(tempNode);
	deleteNode->next == deleteNode->next->next;
	return 1;
}

template<class T>
inline int Linear_Linked_List<T>::ListDelete(int location)
{
	if (ListLength() == 0 || location<1 || location>ListLength())
	{
		return 0;
	}
	if (location == 1)
	{
		head = head->next;
		return 1;
	}
	Node *deleteNode = head;
	for (int i = 0; i < location - 2; i++)
	{
		deleteNode = deleteNode->next;
	}
	Node *tempNode = deleteNode->next;
	deleteNode->next = deleteNode->next->next;
	free(tempNode);
	tempNode = NULL;
	return 1;
}

template<class T>
inline Node<T> * Linear_Linked_List<T>::getEndPoint()
{
	EndPoint = head;
	for (size_t i = 0; i < ListLength() - 1; i++)
	{
		EndPoint = EndPoint->next;
	}
	return EndPoint;
}


