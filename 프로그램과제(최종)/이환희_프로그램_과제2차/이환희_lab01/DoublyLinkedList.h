#pragma once
#include<iostream>
#include"DoublyIterator.h"
using namespace std;

template<class T> // 템플릿이라는걸 알려주는 역할 네임스페이스 같은 개념.
class DoublyIterator;


/**
*	연결리스트에서 쓰이는 NodeType의 구조체
*/
template<class T>
struct DoublyNodeType
{
	T info;
	DoublyNodeType* prev;
	DoublyNodeType* next;
};

/**
*	정렬된 더블연결리스트 클래스
*/
template<class T>
class DoublyLinkedList
{
	friend class DoublyIterator<T>;
public:

	/**
	*	디폴트 생성자.
	*/
	DoublyLinkedList();

	/**
	*	소멸자.
	*/
	~DoublyLinkedList();

	/**
	*	@brief	리스트가 비었는지 아닌지 검사한다.
	*	@pre	m_nLength가 값을 가지고 있어야 한다.
	*	@post	비었는지 아닌지를 알려준다.
	*	@return	비어있으면 true, 아니면 false를 반환.
	*/
	bool IsEmpty();

	/**
	*	@brief	리스트를 비운다.
	*	@pre	없음.
	*	@post	m_pFirst와 m_pLast를 제외한 모든 데이터를 지운다.
	*/
	void MakeEmpty();

	/**
	*	@brief	리스트의 길이를 반환한다.
	*	@pre	없음.
	*	@post	리스트의 길이를 반환.
	*	@return	m_nLength 리스트의 길이 반환.
	*/
	int GetLength()const;

	/**
	*	@brief	새로운 아이템을 리스트에 추가한다.
	*	@pre	item을 입력받는다.
	*	@post	아이템을 리스트에 추가한다.
	*	@return	같은 아이템이 있으면 0을 반환하고, 입력에 성공하면 1을 반환.
	*/
	void Add(T item);

	/**
	*	@brief	입력받은 아이템을 리스트에서 삭제한다.
	*	@pre	item을 입력받는다.
	*	@post	입력받은 아이템을 리스트에서 찾아 삭제한다.
	*/
	int Delete(T item);

	/**
	*	@brief	입력받은 아이템으로 정보를 바꾼다.
	*	@pre	item을 입력받는다.
	*	@post	새로운 정보로 교체된다.
	*/
	int Replace(T item);

	/**
	*	@brief	입력받은 아이템의 정보와 비교하여 같은 리스트의 아이템을 가져온다.
	*	@pre	item을 입력받는다.
	*	@post	검색된 데이터를 아이템에 넣는다.
	*	@return	일치하는 데이터를 찾으면 1, 그렇지 않으면 0을 반환.
	*/
	int Get(T& item);

private:
	DoublyNodeType<T>* m_pFirst; // 처음(값 비워져있어야함)
	DoublyNodeType<T>* m_pLast; // 끝(값 비워져있어야함)
	int m_nLength; ///리스트의 길이

};

template<class T>
inline DoublyLinkedList<T>::DoublyLinkedList()
{
	m_pFirst = new DoublyNodeType<T>;
	m_pLast = new DoublyNodeType<T>;

	m_pFirst->prev = NULL;
	m_pFirst->next = m_pLast;
	m_pLast->prev = m_pFirst;
	m_pLast->next = NULL;

	m_nLength = 0;
}

template<class T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
	if (!IsEmpty())
	{
		MakeEmpty();
	}
	delete m_pFirst;
	delete m_pLast;
}

template<class T>
inline bool DoublyLinkedList<T>::IsEmpty()
{
	if (m_nLength == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
inline void DoublyLinkedList<T>::MakeEmpty()
{
	DoublyIterator<T> itor(*this);
	DoublyNodeType<T>* pTemp;
	itor.Next(); //pFirst노드 다음껄로감

	while (!itor.NextNotNull())
	{
		pTemp = itor.m_pCurPointer;
		itor.Next();
		delete pTemp;
	}
	m_pFirst->next = m_pLast;
	m_pFirst->prev = NULL;
	m_pLast->prev = m_pFirst;
	m_pLast->next = NULL;

	m_nLength = 0;

}

template<class T>
inline int DoublyLinkedList<T>::GetLength() const
{
	return m_nLength;
}

template<class T>
inline void DoublyLinkedList<T>::Add(T item) //정렬하지않고 마지막에 넣는다.
{
	DoublyNodeType<T>* pItem = new DoublyNodeType<T>;
	pItem->info = item;
	m_pLast->prev->next = pItem;
	pItem->prev = m_pLast->prev;

	pItem->next = m_pLast;
	m_pLast->prev = pItem;

	m_nLength++;
}

template<class T>
inline int DoublyLinkedList<T>::Delete(T item)
{
	DoublyNodeType<T>* pItem;
	DoublyIterator<T> itor(*this);
	itor.Next();
	while (itor.NextNotNull())
	{
		if (itor.m_pCurPointer->info == item)
		{
			pItem = itor.m_pCurPointer;
			itor.m_pCurPointer->prev->next = itor.m_pCurPointer->next;
			itor.m_pCurPointer->next->prev = itor.m_pCurPointer->prev;
			delete pItem;
			m_nLength--;
			return 1;
		}
		itor.Next();
	}
	return 0; // 일치하는 item이 없을때
}

template<class T>
inline int DoublyLinkedList<T>::Replace(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next();

	while (itor.NextNotNull())
	{
		if (itor.m_pCurPointer->info == item)
		{
			itor.m_pCurPointer->info = item;
			return 1;
		}
		itor.Next();
	}
	return 0; // 일치하는 item이 없을때
}

template<class T>
inline int DoublyLinkedList<T>::Get(T& item)
{
	DoublyIterator<T> itor(*this);
	itor.Next();
	while (itor.NextNotNull())
	{
		if (itor.m_pCurPointer->info == item)
		{
			item = itor.m_pCurPointer->info;
			return 1;
		}
		itor.Next();
	}
	return 0;
}