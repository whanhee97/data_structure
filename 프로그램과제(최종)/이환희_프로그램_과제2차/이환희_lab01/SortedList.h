#pragma once
#define MAXSIZE 10
#include<iostream>
using namespace std;
/**
*@brief Sorted List
*@details ID������ ���ĵ� ����Ʈ
*@author ��ȯ��
*@date 2019-09-24

*/
template<class T>
class SortedList
{
	T* m_Array;
	int m_Length;
	int m_CurPointer;
public:
	/**
	*@brief ������
	*@param none
	*/
	SortedList();
	
	SortedList(const SortedList& S); // ���� ����

	SortedList<T>& operator= (SortedList<T>& S);
	
	T& operator[] (int index);

	/**
	*@brief ������ max ������� �����Ҵ�
	*@param max�� �����Ҵ� ���� ������
	*/
	SortedList(int max);

	/**
	*@brief �Ҹ���
	*@param none
	*/
	~SortedList();

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
	*@brief ���̳ʸ���ġ�� data�� ID�� ��ġ�ϴ� ������ ã��
	*@param [data] ID�� �ԷµǾ��ִ� ������ Ÿ���� ������
	*@return ã���� 1 �ƴϸ� 0
	*/
	int RetrieveBinary(T& data);
	
};

template<class T>
SortedList<T>::SortedList()
{
	m_Length = 0;
	m_CurPointer = 0;
	m_Array = new T[MAXSIZE];
}

template<class T>
inline SortedList<T>::SortedList(const SortedList& S)
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
inline SortedList<T>& SortedList<T>::operator=(SortedList<T>& S)
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
inline T& SortedList<T>::operator[](int index)
{

	if (index > MAXSIZE)
	{
		cout << "index �ʰ�" << endl;
		return m_Array[0];
	}
	return m_Array[index];
}

template<class T>
SortedList<T>::SortedList(int max)
{
	m_Length = 0;
	m_CurPointer = 0;
	m_Array = new T[max];
}

template<class T>
SortedList<T>::~SortedList()
{
	delete[] m_Array;
}

template<class T>
void SortedList<T>::MakeEmpty()
{
	m_Length = 0;
}

template<class T>
int SortedList<T>::GetLength()
{
	return m_Length;
}

template<class T>
bool SortedList<T>::IsFull()
{
	if (GetLength() == MAXSIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
bool SortedList<T>::IsEmpty()
{
	if (m_Length == 0)
	{
		return true;
	}
	return false;
}


template<class T>
int SortedList<T>::Get(T& data)
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
int SortedList<T>::Delete(T data)
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
int SortedList<T>::Replace(T data)
{
	m_Array[m_CurPointer] = data;
	return 1;
}

template<class T>
int SortedList<T>::Add(T data)
{
	if (IsEmpty() == true)
	{
		m_Array[m_Length] = data;
		m_Length++;
		return 1;
	}
	else if (IsFull() == true)
	{
		cout << "list�� �� á���ϴ�." << endl;
		return 0;
	}
	else
	{
		for (m_CurPointer = 0; m_CurPointer < m_Length; m_CurPointer++)
		{
			if (m_Array[m_CurPointer] == data)
			{
				cout << "\n�̹� �����ϴ� ID�Դϴ�." << endl;
				return 0;
			}
			if (m_Array[m_CurPointer] > data)
			{
				for (int i = m_Length; i > m_CurPointer; i--)
				{
					m_Array[i] = m_Array[i - 1]; // �� ĭ�� �ڷ� ���ܼ� ����
				}
				m_Length++;
				m_Array[m_CurPointer] = data;
				return 1;
			}
		}
		m_Length++;
		m_Array[m_CurPointer] = data;
		return 1;
	}
}

template<class T>
void SortedList<T>::ResetList()
{
	m_CurPointer = -1;
}

template<class T>
int SortedList<T>::GetNextItem(T& data)
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
int SortedList<T>::RetrieveBinary(T& data)
{
	int start = 0;
	int end = m_Length - 1;
	while (1)
	{
		if (start > end)
		{
			break;
		}
		m_CurPointer = (start + end) / 2;
		if (m_Array[m_CurPointer] == data)
		{
			data = m_Array[m_CurPointer];
			return 1;
		}
		else if (m_Array[m_CurPointer] > data)
		{
			end = m_CurPointer - 1;
		}
		else
		{
			start = m_CurPointer + 1;
		}
	}
	return 0;
}
