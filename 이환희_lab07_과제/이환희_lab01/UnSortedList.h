#pragma once
#define MAXSIZE 10
#include<iostream>
using namespace std;

template<class T>
class UnSortedList
{
	T* m_Array;
	int m_Length;
	int m_CurPointer;
public:
	/**
	*@brief ������
	*@param none
	*/
	UnSortedList();

	/**
	*@brief ������ max ������� �����Ҵ�
	*@param max�� �����Ҵ� ���� ������
	*/
	UnSortedList(int max);


	/**
	*@brief ����Ʈ���� �÷��̸���Ʈ�� �߰�
	*@pre ����Ʈ�� ����������� �ȵ�
	*@post �÷��̸���Ʈ�� �������� �߰���.
	*/
	UnSortedList(const UnSortedList& S); // ���� ����

	/**
	*@brief �������縦 ���� =������
	*/
	UnSortedList<T>& operator= (UnSortedList<T>& S);

	/**
	*@brief ������ ���̼��� ���� []������
	*/
	T& operator[] (int index);

	/**
	*@brief �Ҹ���
	*@param none
	*/
	~UnSortedList();

	/**
	*@brief ����Ʈ ��� ���� ����
	*@param none
	*/
	void MakeEmpty();

	/**
	*@brief ����Ʈ�� m_Length�� ��ȯ
	*@param none
	*@return m_Length
	*/
	int GetLength();


	/**
	*@brief ����Ʈ�� �� á���� Ȯ��
	*@param none
	*@return full�̸� 1 �ƴϸ� 0 ��ȯ
	*/
	bool IsFull();

	/**
	*@brief ����Ʈ�� ������� Ȯ��
	*@param none
	*@return ������� 1 �ƴϸ� 0 ��ȯ
	*/
	bool IsEmpty();


	/**
	*@brief ����Ʈ �����۵��� data�� ID�� ��ġ�� ID�� ������ �ش� m_Curpointer ��ȯ
	*@param [data] ID�� �ԷµǾ��ִ� ������ Ÿ���� ������
	*@return ��ġ�ϸ� m_Curpointer, �ƴϸ� -1
	*/
	int Get(T& data);

	/**
	*@brief ������ ����
	*@param [data] ID�� �ԷµǾ��ִ� ������ Ÿ���� ������
	*@return ����� 1, �ƴϸ� -1
	*/
	int Delete(T data);

	/**
	*@brief data�� ��ġ�ϴ� ������ ã�� �� ġȯ
	*@param [data] ID�� �ԷµǾ��ִ� ������ Ÿ���� ������
	*@return ��ü�ϸ� 1 ��ȯ
	*/
	int Replace(T data);


	/**
	*@brief ������ �߰�
	*@param [data] ID�� �ԷµǾ��ִ� ������ Ÿ���� ������
	*@return ID�� �ߺ��ǰų� ����Ʈ�� �� �������� 0, �߰��ϸ� 1 ��ȯ
	*/
	int Add(T data);

	/**
	*@brief ����Ʈ�� �������� �ʱ�ȭ
	*@param none
	*@return none
	*/
	void ResetList();

	/**
	*@brief �������� �ϳ��ø��� �ش� �������� data�� ����
	*@param [data] ID�� �ԷµǾ��ִ� ������ Ÿ���� ������
	*@return m_CurPointer
	*/
	int GetNextItem(T& data);

	/**
	*@data�� ID�� ��ġ�ϴ� ������ ã��
	*@param [data] ID�� �ԷµǾ��ִ� ������ Ÿ���� ������
	*@return ã���� 1 �ƴϸ� 0
	*/
	int Retrieve(T& data);

};

template<class T>
inline UnSortedList<T>::UnSortedList()
{
	m_Length = 0;
	m_CurPointer = 0;
	m_Array = new T[MAXSIZE];
}

template<class T>
inline UnSortedList<T>::UnSortedList(int max)
{
	m_Length = 0;
	m_CurPointer = 0;
	m_Array = new T[max];
}

template<class T>
inline UnSortedList<T>::UnSortedList(const UnSortedList& S)
{
	m_Length = S.m_Length;
	m_CurPointer = S.m_CurPointer;
	m_Array = new T[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
	{
		m_Array[i] = S.m_Array[i];
	}
}

template<class T>
inline UnSortedList<T>& UnSortedList<T>::operator=(UnSortedList<T>& S)
{
	m_Length = S.m_Length;
	m_CurPointer = S.m_CurPointer;
	m_Array = new T[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
	{
		m_Array[i] = S.m_Array[i];
	}
	return *this;
}

template<class T>
inline T& UnSortedList<T>::operator[](int index)
{
	if (index > MAXSIZE)
	{
		cout << "index �ʰ�" << endl;
		return m_Array[0];
	}
	return m_Array[index];
}

template<class T>
inline UnSortedList<T>::~UnSortedList()
{
	delete[] m_Array;
}

template<class T>
inline void UnSortedList<T>::MakeEmpty()
{

	m_Length = 0;
}

template<class T>
inline int UnSortedList<T>::GetLength()
{
	return m_Length;
}

template<class T>
inline bool UnSortedList<T>::IsFull()
{
	return (GetLength() == MAXSIZE);
}

template<class T>
inline bool UnSortedList<T>::IsEmpty()
{
	return (m_Length == 0);
}

template<class T>
inline int UnSortedList<T>::Get(T& data)
{
	for (m_CurPointer = 0; m_CurPointer < m_Length; m_CurPointer++)
	{
		if (m_Array[m_CurPointer] == data)
		{
			return m_CurPointer;
		}
	}
	return -1;
}

template<class T>
inline int UnSortedList<T>::Delete(T data)
{
	for (m_CurPointer = 0; m_CurPointer < m_Length; m_CurPointer++)
	{
		if (m_Array[m_CurPointer] == data)
		{
			if (m_CurPointer == m_Length - 1) // �������� ������� �׳� �������� ����.
			{
				m_Length--;
				return 1;
			}
			for (int i = m_CurPointer; i < m_Length - 1; i++)
			{
				m_Array[i] = m_Array[i + 1]; // �� ĭ�� ������ ���ܼ� ����
			}
			m_Length--;
			return 1;
		}
	}
	return -1;
}

template<class T>
inline int UnSortedList<T>::Replace(T data)
{
	m_Array[m_CurPointer] = data;
	return 1;
}

template<class T>
inline int UnSortedList<T>::Add(T data)
{
	if (IsFull() == true)
	{
		cout << "list�� �� á���ϴ�." << endl;
		return 0;
	}
	for (m_CurPointer = 0; m_CurPointer < m_Length; m_CurPointer++)
	{
		if (m_Array[m_CurPointer] == data)
		{
			cout << "\n�̹� �����ϴ� ID�Դϴ�." << endl;
			return 0;
		}
	}
	m_Array[m_Length] = data;
	m_Length++;
	return 1;
}

template<class T>
inline void UnSortedList<T>::ResetList()
{
	m_CurPointer = -1;
}

template<class T>
inline int UnSortedList<T>::GetNextItem(T& data)
{
	m_CurPointer++;
	if (m_CurPointer == MAXSIZE)
	{
		return -1;
	}
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}

template<class T>
inline int UnSortedList<T>::Retrieve(T& data) // Get�Լ��� �������͸� ����, ��Ʈ�����Լ��� �����͸� ã�Ƽ� ������
{
	for (m_CurPointer = 0; m_CurPointer < m_Length; m_CurPointer++)
	{
		if (m_Array[m_CurPointer] == data)
		{
			data = m_Array[m_CurPointer];
			return 1;
		}
	}
	return 0;
}
