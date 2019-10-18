#pragma once
#include<iostream>
using namespace std;


/**
*@brief 노드타입 구조체
*@details 아이템의 값과 다음 노드포인터가 존재
*@author 이환희
*@date 2019-09-24

*/
template<class T>
struct NodeType
{
	T info;
	NodeType<T>* next;
};

/**
*@brief 정열된 링크드리스트 클래스
*@details 아이템 추가를 할때 정렬해서 추가
*@author 이환희
*@date 2019-09-24

*/
template<class T>
class SortedLinkedList
{
public:

	/**
	*@brief 생성자
	*@pre
	*@post
	*/
	SortedLinkedList();
	/**
	*@brief 소멸자
	*@pre
	*@post MakeEmpty() 실행해 모두 지움
	*/
	~SortedLinkedList();

	/**
	*@brief 값에 하나씩 접근하며 delete함
	*@pre 
	*@post 리스트포인터가 NULL을 가르킴
	*/
	void MakeEmpty();

	/**
	*	@brief	Add item into appropriate spot of this list.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int AddItem(T& item); //singer타입과 아이템타입 둘다 연산자 오버로딩 해주기!
	
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
	*@brief 비었는지 확인
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

	if (m_pList == NULL) // 비어있을때
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
			if (item < location->info) // 아이템이 로케이션데이터보다 작으면 이동 x (맨 앞에 와야하므로)
			{
				MoreToSearch = false;
			}
			else if (item > location->info) // 크면 프리록이랑 로케이션 한칸씩 옆으로 이동
			{
				preloc = location;
				location = location->next;
				MoreToSearch = (location != NULL);
			}
			else //같으면 중복이므로 0 리턴
			{
				return 0;
			}

		}
		if (preloc == location) // 안 움직였다면
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
	if(item == location->info) //첫번째 아이템 지우기
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
		if (item == m_pCurPointer->info) //id만 비교 혹은 이름만 비교
		{
			item = m_pCurPointer->info; // 통째로 복사. 깊은복사가 이루어져야함
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
		if (item == location->info) // 아이템이 로케이션데이터랑 같으면 이동 x (맨 앞에 와야하므로)
		{
			MoreToSearch = false;
		}
		else  //다르면 프리록이랑 로케이션 한칸씩 옆으로 이동
		{
			preloc = location;
			location = location->next;
			MoreToSearch = (location != NULL);
		}

	}
	if (preloc == location) // 안 움직였다면 맨앞에꺼가 같은것이므로
	{
		tempPtr->next = preloc->next;
		m_pList = tempPtr;
		delete location;
	}
	else //움직였다면 전 노드넥스트가 템프를 가르키고 템프넥스트가 현노드넥스트를 가르키고 현노드는 지워버리기
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
