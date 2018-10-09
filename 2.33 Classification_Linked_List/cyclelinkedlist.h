#pragma once


template<typename T>
struct CycleNode
{
	T data;
	CycleNode *prenode;
	CycleNode *nextnode;
	CycleNode(const T &d) :data(d), prenode(NULL), nextnode(NULL);
};

template <class T>
 
class Cycle_Linked_List {
public:
	Cycle_Linked_List();
	Cycle_Linked_List(T firstelem);
	~Cycle_Linked_List();
	void InitCycleList(T headelem);
	bool isEmpty();
	int  CycleListLength();
	void CycleListInsert(int location, T elem);
	void CycleListDelete(int location);
	void CycleListDelete(int location, T &elem);
private:
	CycleNode *head;
};

template<class T>
inline Cycle_Linked_List<T>::Cycle_Linked_List()
{
	std::cout << "please init list use InitCycleList(data)!" << std::endl;
}

template<class T>
inline Cycle_Linked_List<T>::Cycle_Linked_List(T firstelem)
{
	InitCycleList(firstelem);
}

template<class T>
inline Cycle_Linked_List<T>::~Cycle_Linked_List()
{
	delete head;
}

template<class T>
inline void Cycle_Linked_List<T>::InitCycleList(T headelem)
{
	head = new CycleNode;
	head->data = headelem;
	head->prenode = head;
	head->nextnode = head;
}

template<class T>
inline bool Cycle_Linked_List<T>::isEmpty()
{
	if (head->nextnode==head)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

template<class T>
inline int Cycle_Linked_List<T>::CycleListLength()
{
	int length = 0;
	CycleNode *p = head;
	while (p->nextnode!=head)
	{
		length++;
		p = p->nextnode;
	}
	return length;
}

template<class T>
inline void Cycle_Linked_List<T>::CycleListInsert(int location, T elem)
{
	if (location<1||location>CycleListLength())
	{
		exit;
	}
	CycleNode *insertnode =new CycleNode(elem);
	CycleNode *temp = head;
	for (int i = 0; i < location; i++)
	{
		temp = temp->nextnode;
	}
	insertnode->nextnode = temp->nextnode;
	insertnode->nextnode->prenode = insertnode;
	insertnode->prenode = temp;
	temp->next = insertnode;
}
