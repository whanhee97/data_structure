#pragma once
#include"ItemType.h"
#define MAXSIZE 10

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
	int Get(ItemType& data);
	
	/**
	*@brief ������ ����
	*@param [data] ID�� �ԷµǾ��ִ� ������ Ÿ���� ������
	*@return ����� 1, �ƴϸ� -1
	*/
	int Delete(ItemType data);
	
	/**
	*@brief data�� ��ġ�ϴ� ������ ã�� �� ġȯ
	*@param [data] ID�� �ԷµǾ��ִ� ������ Ÿ���� ������
	*@return ��ü�ϸ� 1 ��ȯ
	*/
	int Replace(ItemType data);
	

	/**
	*@brief ������ �߰�
	*@param [data] ID�� �ԷµǾ��ִ� ������ Ÿ���� ������
	*@return ID�� �ߺ��ǰų� ����Ʈ�� �� �������� 0, �߰��ϸ� 1 ��ȯ
	*/
	int Add(ItemType data);
	
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
	int GetNextItem(ItemType& data);
	
	/**
	*@brief ���̳ʸ���ġ�� data�� ID�� ��ġ�ϴ� ������ ã��
	*@param [data] ID�� �ԷµǾ��ִ� ������ Ÿ���� ������
	*@return ã���� 1 �ƴϸ� 0
	*/
	int RetrieveBinary(ItemType& data);
	
};

template<class T>
SortedList<T>::SortedList()
{
	m_Length = 0;
	m_CurPointer = 0;
	m_Array = new T[MAXSIZE];
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
int SortedList<T>::Get(ItemType& data)
{
	for (m_CurPointer = 0; m_CurPointer < m_Length; m_CurPointer++)
	{
		if (data.CompareByID(m_Array[m_CurPointer]) == EQUAL)
		{
			return m_CurPointer;
		}
	}
	return -1;
}

template<class T>
int SortedList<T>::Delete(ItemType data)
{
	ItemType temp;
	for (m_CurPointer = 0; m_CurPointer < m_Length; m_CurPointer++)
	{
		if (data.CompareByID(m_Array[m_CurPointer]) == EQUAL)
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
int SortedList<T>::Replace(ItemType data)
{
	m_Array[m_CurPointer] = data;
	return 1;
}

template<class T>
int SortedList<T>::Add(ItemType data)
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
			if (data.CompareByID(m_Array[m_CurPointer]) == EQUAL)
			{
				cout << "\n�̹� �����ϴ� ID�Դϴ�." << endl;
				return 0;
			}
			if (data.CompareByID(m_Array[m_CurPointer]) == LESS)
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
int SortedList<T>::GetNextItem(ItemType& data)
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
int SortedList<T>::RetrieveBinary(ItemType& data)
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
		if (data.CompareByID(m_Array[m_CurPointer]) == EQUAL)
		{
			data = m_Array[m_CurPointer];
			return 1;
		}
		else if (data.CompareByID(m_Array[m_CurPointer]) == LESS)
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
