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
	*@brief 생성자
	*@param none
	*/
	UnSortedList();

	/**
	*@brief 생성자 max 사이즈로 동적할당
	*@param max값 동적할당 받을 사이즈
	*/
	UnSortedList(int max);


	/**
	*@brief 리스트에서 플레이리스트로 추가
	*@pre 리스트가 비워져있으면 안됨
	*@post 플레이리스트에 아이템이 추가됨.
	*/
	UnSortedList(const UnSortedList& S); // 깊은 복사

	/**
	*@brief 깊은복사를 위한 =연산자
	*/
	UnSortedList<T>& operator= (UnSortedList<T>& S);

	/**
	*@brief 접근의 용이성을 위한 []연산자
	*/
	T& operator[] (int index);

	/**
	*@brief 소멸자
	*@param none
	*/
	~UnSortedList();

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
	int Get(T& data);

	/**
	*@brief 아이템 지움
	*@param [data] ID가 입력되어있는 아이템 타입의 데이터
	*@return 지우면 1, 아니면 -1
	*/
	int Delete(T data);

	/**
	*@brief data와 일치하는 아이템 찾은 후 치환
	*@param [data] ID가 입력되어있는 아이템 타입의 데이터
	*@return 교체하면 1 반환
	*/
	int Replace(T data);


	/**
	*@brief 아이템 추가
	*@param [data] ID가 입력되어있는 아이템 타입의 데이터
	*@return ID가 중복되거나 리스트가 꽉 차있으면 0, 추가하면 1 반환
	*/
	int Add(T data);

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
	int GetNextItem(T& data);

	/**
	*@data의 ID와 일치하는 아이템 찾음
	*@param [data] ID가 입력되어있는 아이템 타입의 데이터
	*@return 찾으면 1 아니면 0
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
		cout << "index 초과" << endl;
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
		cout << "list가 꽉 찼습니다." << endl;
		return 0;
	}
	for (m_CurPointer = 0; m_CurPointer < m_Length; m_CurPointer++)
	{
		if (m_Array[m_CurPointer] == data)
		{
			cout << "\n이미 존재하는 ID입니다." << endl;
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
inline int UnSortedList<T>::Retrieve(T& data) // Get함수는 컬포인터만 리턴, 리트리브함수는 데이터를 찾아서 가져옴
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
