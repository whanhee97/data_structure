#pragma once
#include"DoublyLinkedList.h"

template<class T>
class DoublyLinkedList;

template<class T>
struct DoublyNodeType;


/**
*	연결리스트에서 쓰이는 Iterator의 클래스.
*/
template<class T>
class DoublyIterator
{
	friend class DoublyLinkedList<T>; ///< DoublySortedLinkedList와 친구 클래스.
public:

	/**
	*	디폴트 생성자.
	*/
	DoublyIterator(const DoublyLinkedList<T>& list) :m_List(list), m_pCurPointer(list.m_pFirst) {};

	bool NotNull(); // 현재 이터의 컬포인터가 널이 아닌지

	bool NextNotNull(); // 현재 이터의 다음 노드가 널이 아닌지

	bool IsNextLast(); // 현재 이터의 컬포인터의 넥스트가 라스트인지

	/**
	*	이터레이터를 퍼스트로 초기화시킴
	*/
	void First();

	/**
	*	이터레이터의 커렌트포인터를 다음으로 옮기고 그 데이터 반환
	*/
	T Next();


	/**
	*	현재노드 반환
	*/
	DoublyNodeType<T>& GetCurrentNode();

private:
	const DoublyLinkedList<T>& m_List;
	DoublyNodeType<T>* m_pCurPointer;
};

template<class T>
inline bool DoublyIterator<T>::NotNull()
{
	if (m_pCurPointer == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<class T>
inline bool DoublyIterator<T>::NextNotNull()
{
	if (m_pCurPointer->next == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<class T>
inline bool DoublyIterator<T>::IsNextLast()
{
	if (m_pCurPointer->next == m_List.m_pLast)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
inline void DoublyIterator<T>::First()
{
	m_pCurPointer = m_List.m_pFirst;
}

template<class T>
inline T DoublyIterator<T>::Next()
{
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->info;
}

template<class T>
inline DoublyNodeType<T>& DoublyIterator<T>::GetCurrentNode()
{
	return *m_pCurPointer;
}
