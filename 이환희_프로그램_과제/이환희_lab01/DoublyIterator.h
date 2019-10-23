#pragma once
#include"DoublyLinkedList.h"

template<class T>
class DoublyLinkedList;

template<class T>
struct DoublyNodeType;


/**
*	���Ḯ��Ʈ���� ���̴� Iterator�� Ŭ����.
*/
template<class T>
class DoublyIterator
{
	friend class DoublyLinkedList<T>; ///< DoublySortedLinkedList�� ģ�� Ŭ����.
public:

	/**
	*	����Ʈ ������.
	*/
	DoublyIterator(const DoublyLinkedList<T>& list) :m_List(list), m_pCurPointer(list.m_pFirst) {};

	bool NotNull(); // ���� ������ �������Ͱ� ���� �ƴ���

	bool NextNotNull(); // ���� ������ ���� ��尡 ���� �ƴ���

	bool IsNextLast(); // ���� ������ ���������� �ؽ�Ʈ�� ��Ʈ����

	/**
	*	���ͷ����͸� �۽�Ʈ�� �ʱ�ȭ��Ŵ
	*/
	void First();

	/**
	*	���ͷ������� Ŀ��Ʈ�����͸� �������� �ű�� �� ������ ��ȯ
	*/
	T Next();


	/**
	*	������ ��ȯ
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
