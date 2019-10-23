#pragma once
#include<iostream>
#include"DoublyIterator.h"
using namespace std;

template<class T> // ���ø��̶�°� �˷��ִ� ���� ���ӽ����̽� ���� ����.
class DoublyIterator;


/**
*	���Ḯ��Ʈ���� ���̴� NodeType�� ����ü
*/
template<class T>
struct DoublyNodeType
{
	T info;
	DoublyNodeType* prev;
	DoublyNodeType* next;
};

/**
*	���ĵ� �����Ḯ��Ʈ Ŭ����
*/
template<class T>
class DoublyLinkedList
{
	friend class DoublyIterator<T>;
public:

	/**
	*	����Ʈ ������.
	*/
	DoublyLinkedList();

	/**
	*	�Ҹ���.
	*/
	~DoublyLinkedList();

	/**
	*	@brief	����Ʈ�� ������� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	������� �ƴ����� �˷��ش�.
	*	@return	��������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsEmpty();

	/**
	*	@brief	����Ʈ�� ����.
	*	@pre	����.
	*	@post	m_pFirst�� m_pLast�� ������ ��� �����͸� �����.
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� ���̸� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	����Ʈ�� ���̸� ��ȯ.
	*	@return	m_nLength ����Ʈ�� ���� ��ȯ.
	*/
	int GetLength()const;

	/**
	*	@brief	���ο� �������� ����Ʈ�� �߰��Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�������� ����Ʈ�� �߰��Ѵ�.
	*	@return	���� �������� ������ 0�� ��ȯ�ϰ�, �Է¿� �����ϸ� 1�� ��ȯ.
	*/
	void Add(T item);

	/**
	*	@brief	�Է¹��� �������� ����Ʈ���� �����Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�Է¹��� �������� ����Ʈ���� ã�� �����Ѵ�.
	*/
	int Delete(T item);

	/**
	*	@brief	�Է¹��� ���������� ������ �ٲ۴�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	���ο� ������ ��ü�ȴ�.
	*/
	int Replace(T item);

	/**
	*	@brief	�Է¹��� �������� ������ ���Ͽ� ���� ����Ʈ�� �������� �����´�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�˻��� �����͸� �����ۿ� �ִ´�.
	*	@return	��ġ�ϴ� �����͸� ã���� 1, �׷��� ������ 0�� ��ȯ.
	*/
	int Get(T& item);

private:
	DoublyNodeType<T>* m_pFirst; // ó��(�� ������־����)
	DoublyNodeType<T>* m_pLast; // ��(�� ������־����)
	int m_nLength; ///����Ʈ�� ����

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
	itor.Next(); //pFirst��� �������ΰ�

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
inline void DoublyLinkedList<T>::Add(T item) //���������ʰ� �������� �ִ´�.
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
	return 0; // ��ġ�ϴ� item�� ������
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
	return 0; // ��ġ�ϴ� item�� ������
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