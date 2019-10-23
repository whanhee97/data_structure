#pragma once
#include<iostream>
using namespace std;


/**
*@brief ���Ÿ�� ����ü
*@details �������� ���� ���� ��������Ͱ� ����
*@author ��ȯ��
*@date 2019-09-24

*/
template<class T>
struct NodeType
{
	T info;
	NodeType<T>* next;
};

/**
*@brief ������ ��ũ�帮��Ʈ Ŭ����
*@details ������ �߰��� �Ҷ� �����ؼ� �߰�
*@author ��ȯ��
*@date 2019-09-24

*/
template<class T>
class SortedLinkedList
{
public:

	/**
	*@brief ������
	*@pre
	*@post
	*/
	SortedLinkedList();
	/**
	*@brief �Ҹ���
	*@pre
	*@post MakeEmpty() ������ ��� ����
	*/
	~SortedLinkedList();

	/**
	*@brief ���� �ϳ��� �����ϸ� delete��
	*@pre 
	*@post ����Ʈ�����Ͱ� NULL�� ����Ŵ
	*/
	void MakeEmpty();

	/**
	*	@brief	Add item into appropriate spot of this list.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int AddItem(T& item); //singerŸ�԰� ������Ÿ�� �Ѵ� ������ �����ε� ���ֱ�!
	
	/**
	*	@brief	Delete item from this list.
	*	@pre	List is not empty. the item exists in list.
	*	@post	Item is deleted from this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int DeleteItem(T item);
	
	/**
	*	@brief	Initialize current pointer for an iteration through the list.
	*	@pre	None.
	*	@post	current pointer is prior to list. current pointer has been initialized.
	*/
	int Retrieve(T& item);
	
	/**
	*	@brief	Change value of item which is in this list.
	*	@pre	List is not empty. the item exists in list.
	*	@post	Item's value is changed.
	*	@return	1 if this function works well, otherwise 0.
	*/
	void Replace(T& item);

	/**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength() const;
	
	/**
	*@brief ������� Ȯ��
	*/
	bool IsEmpty();

private:
	NodeType<T>* m_pList;
	NodeType<T>* m_pCurPointer;
	int m_Length;

};


template<class T>
SortedLinkedList<T>::SortedLinkedList()
{
	m_pList = NULL;
	m_pCurPointer = NULL;
	m_Length = 0;
}

template<class T>
SortedLinkedList<T>::~SortedLinkedList()
{
	MakeEmpty();
}

template<class T>
void SortedLinkedList<T>::MakeEmpty()
{
	NodeType<T>* temp;
	while (m_pList != NULL)
	{
		temp = m_pList;
		m_pList = m_pList->next;

		delete temp;
	}
	m_Length = 0;
}

template<class T>
int SortedLinkedList<T>::AddItem(T& item)
{
	NodeType<T>* location;
	NodeType<T>* preloc;
	NodeType<T>* tempPtr = new NodeType<T>;
	
	tempPtr->info = item;
	location = preloc = m_pList;

	bool MoreToSearch = false;

	if (m_pList == NULL) // ���������
	{
		tempPtr->next = NULL;
		m_pList = tempPtr;
		m_Length++;
	}
	 
	else
	{
		MoreToSearch = (location != NULL);

		while (MoreToSearch)
		{
			if (item < location->info) // �������� �����̼ǵ����ͺ��� ������ �̵� x (�� �տ� �;��ϹǷ�)
			{
				MoreToSearch = false;
			}
			else if (item > location->info) // ũ�� �������̶� �����̼� ��ĭ�� ������ �̵�
			{
				preloc = location;
				location = location->next;
				MoreToSearch = (location != NULL);
			}
			else //������ �ߺ��̹Ƿ� 0 ����
			{
				return 0;
			}

		}
		if (preloc == location) // �� �������ٸ�
		{
			tempPtr->next = location->next;
			location->next = tempPtr;
		}
		else
		{
			preloc->next = tempPtr;
			tempPtr->next = location;
		}
		m_Length++;
	}
	return 1;
}

template<class T>
int SortedLinkedList<T>::DeleteItem(T item)
{
	NodeType<T>* location;
	NodeType<T>* preloc;
	location = preloc = m_pList;
	if(item == location->info) //ù��° ������ �����
	{
		m_pList = m_pList->next;
		delete location;
	}
	while (location != NULL)
	{
		if (item != location->info)
		{
			preloc = location;
			location = location->next;

		}
		else
		{
			preloc->next = location->next;
			delete location;
			return 1;
		}
	}

	return 0;
}

template<class T>
int SortedLinkedList<T>::Retrieve(T& item)
{
	m_pCurPointer = m_pList;
	while (m_pCurPointer != NULL)
	{
		if (item == m_pCurPointer->info) //id�� �� Ȥ�� �̸��� ��
		{
			item = m_pCurPointer->info; // ��°�� ����. �������簡 �̷��������
			return 1;
		}
		m_pCurPointer = m_pCurPointer->next;

	}
	return 0;
}

template<class T>
inline void SortedLinkedList<T>::Replace(T& item)
{
	NodeType<T>* location;
	NodeType<T>* preloc;
	NodeType<T>* tempPtr = new NodeType<T>;

	tempPtr->info = item;
	location = preloc = m_pList;

	bool MoreToSearch = false;



	MoreToSearch = (location != NULL);

	while (MoreToSearch)
	{
		if (item == location->info) // �������� �����̼ǵ����Ͷ� ������ �̵� x (�� �տ� �;��ϹǷ�)
		{
			MoreToSearch = false;
		}
		else  //�ٸ��� �������̶� �����̼� ��ĭ�� ������ �̵�
		{
			preloc = location;
			location = location->next;
			MoreToSearch = (location != NULL);
		}

	}
	if (preloc == location) // �� �������ٸ� �Ǿտ����� �������̹Ƿ�
	{
		tempPtr->next = preloc->next;
		m_pList = tempPtr;
		delete location;
	}
	else //�������ٸ� �� ���ؽ�Ʈ�� ������ ����Ű�� �����ؽ�Ʈ�� �����ؽ�Ʈ�� ����Ű�� ������ ����������
	{
		preloc->next = tempPtr;
		tempPtr->next = location->next;
		delete location;
	}

}



template<class T>
int SortedLinkedList<T>::GetLength() const
{
	return m_Length;
}

template<class T>
inline bool SortedLinkedList<T>::IsEmpty()
{
	return (m_pList == NULL);
}
