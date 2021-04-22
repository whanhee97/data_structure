#pragma once
#include"ItemType.h"
#define MAXSIZE 10

/**
*@brief Sorted List
*@details ID순으로 정렬된 리스트
*@author 이환희
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
	*@brief 생성자
	*@param none
	*/
	SortedList(); 
	
	/**
	*@brief 생성자 max 사이즈로 동적할당
	*@param max값 동적할당 받을 사이즈
	*/
	SortedList(int max);

	/**
	*@brief 소멸자
	*@param none
	*/
	~SortedList();

	/**
	*@brief 리스트 모든 내용 삭제
	*@param none
	*/
	void MakeEmpty();
	
	/**
	*@brief 리스트의 m_Length값 반환
	*@param none
	*@return m_Length
	*/
	int GetLength();
	

	/**
	*@brief 리스트가 꽉 찼는지 확인
	*@param none
	*@return full이면 1 아니면 0 반환
	*/
	bool IsFull();
	
	/**
	*@brief 리스트가 비었는지 확인
	*@param none
	*@return 비었으면 1 아니면 0 반환
	*/
	bool IsEmpty();
	

	/**
	*@brief 리스트 아이템들중 data의 ID와 일치한 ID가 있을시 해당 m_Curpointer 반환
	*@param [data] ID가 입력되어있는 아이템 타입의 데이터
	*@return 일치하면 m_Curpointer, 아니면 -1
	*/
	int Get(ItemType& data);
	
	/**
	*@brief 아이템 지움
	*@param [data] ID가 입력되어있는 아이템 타입의 데이터
	*@return 지우면 1, 아니면 -1
	*/
	int Delete(ItemType data);
	
	/**
	*@brief data와 일치하는 아이템 찾은 후 치환
	*@param [data] ID가 입력되어있는 아이템 타입의 데이터
	*@return 교체하면 1 반환
	*/
	int Replace(ItemType data);
	

	/**
	*@brief 아이템 추가
	*@param [data] ID가 입력되어있는 아이템 타입의 데이터
	*@return ID가 중복되거나 리스트가 꽉 차있으면 0, 추가하면 1 반환
	*/
	int Add(ItemType data);
	
	/**
	*@brief 리스트의 컬포인터 초기화
	*@param none
	*@return none
	*/
	void ResetList();
	
	/**
	*@brief 컬포인터 하나올리고 해당 아이템을 data에 복사
	*@param [data] ID가 입력되어있는 아이템 타입의 데이터
	*@return m_CurPointer
	*/
	int GetNextItem(ItemType& data);
	
	/**
	*@brief 바이너리서치로 data의 ID와 일치하는 아이템 찾음
	*@param [data] ID가 입력되어있는 아이템 타입의 데이터
	*@return 찾으면 1 아니면 0
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
			if (m_CurPointer == m_Length - 1) // 마지막게 같을경우 그냥 마지막걸 없앰.
			{
				m_Length--;
				return 1;
			}
			for (int i = m_CurPointer; i < m_Length - 1; i++)
			{
				m_Array[i] = m_Array[i + 1]; // 한 칸씩 앞으로 땡겨서 복사
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
		cout << "list가 꽉 찼습니다." << endl;
		return 0;
	}
	else
	{
		for (m_CurPointer = 0; m_CurPointer < m_Length; m_CurPointer++)
		{
			if (data.CompareByID(m_Array[m_CurPointer]) == EQUAL)
			{
				cout << "\n이미 존재하는 ID입니다." << endl;
				return 0;
			}
			if (data.CompareByID(m_Array[m_CurPointer]) == LESS)
			{
				for (int i = m_Length; i > m_CurPointer; i--)
				{
					m_Array[i] = m_Array[i - 1]; // 한 칸씩 뒤로 땡겨서 복사
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
