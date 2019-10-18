#pragma once
#include"ItemType.h"

#define maxsize 8
template<typename T>
class CircularQueueType
{
public:
	CircularQueueType();
	CircularQueueType(int max);
	~CircularQueueType();

	bool IsFull();
	bool IsEmpty();
	void MakeEmpty();
	void EnQueue(T& item);
	void DeQueue(T& item);
	void Print();

	int GetTop();
	int GetRear();

	void ResetList();
	int GetNextItem(T& data);
	int Search(ItemType& item);
	int Delete(ItemType& item);
	int Replace(ItemType& item);

private:
	int m_iFront;
	int m_iRear;
	int m_nMaxQueue;

	int top; // 아이템 개수
	int m_CulPointer;

	T* m_pItems;
};

//-------템플릿 클래스에서 함수는 선언과 정의를 한 파일에 넣자!

template<typename T>
CircularQueueType<T>::CircularQueueType()
{
	top = 0;
	m_nMaxQueue = maxsize;
	m_iFront = maxsize - 1;
	m_iRear = maxsize - 1;
	m_pItems = new T[maxsize];
}

template<typename T>
CircularQueueType<T>::CircularQueueType(int max)
{
	top = 0;
	m_nMaxQueue = max + 1;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;
	m_pItems = new T[max];
}

template<typename T>
CircularQueueType<T>::~CircularQueueType()
{
	delete[] m_pItems;
}


template<typename T>
bool CircularQueueType<T>::IsFull()
{

	return ((m_iRear + 1) % m_nMaxQueue == m_iFront);
}


template<typename T>
bool CircularQueueType<T>::IsEmpty()
{
	return (m_iRear == m_iFront);
}


template<typename T>
void CircularQueueType<T>::MakeEmpty()
{
	m_iRear = m_iFront;
}

template<typename T>
void CircularQueueType<T>::EnQueue(T& item)
{
	if (IsFull())
	{
		cout << "리스트가 꽉 찼습니다!" << endl;
	}
	else
	{
		top++;
		m_iRear = (m_iRear + 1) % m_nMaxQueue;
		m_pItems[m_iRear] = item;
	}

}

template<typename T>
void CircularQueueType<T>::DeQueue(T& item)
{
	if (IsEmpty())
	{
		cout << "리스트가 비었습니다!" << endl;
	}
	else
	{
		top--;
		m_iFront = (m_iFront + 1) % m_nMaxQueue;
		item = m_pItems[m_iFront]; // 삭제된 아이템을 파라미터로 받아온 아이템에 저장
	}
}

template<typename T>
void CircularQueueType<T>::Print()
{
	if ((m_iFront + 1) % m_nMaxQueue > m_iRear)
	{
		int next = (m_iFront + 1) % m_nMaxQueue;
		for (int i = 0; i < m_nMaxQueue - (m_iFront - m_iRear); i++)
		{
			cout << "아이템{" << next << "]  ";
			next = (next + 1) % m_nMaxQueue;
		}
	}
	else
	{
		int next = (m_iFront + 1) % m_nMaxQueue;
		for (int i = 0; i < m_iRear - m_iFront; i++)
		{
			cout << "아이템{" << next << "]  ";
			next = (next + 1) % m_nMaxQueue;
		}
		
	}
	cout << endl;
}

template<typename T>
int CircularQueueType<T>::GetTop()
{
	return top;
}

template<typename T>
int CircularQueueType<T>::GetRear()
{
	return m_iRear;
}

template<typename T>
void CircularQueueType<T>::ResetList()
{
	m_CulPointer = m_iFront;
}

template<typename T>
int CircularQueueType<T>::GetNextItem(T& data)
{
	if (!IsEmpty()) 
	{
		m_CulPointer = (m_CulPointer + 1) % m_nMaxQueue;
		data = m_pItems[m_CulPointer];
	}
	return m_CulPointer;

}

template<typename T>
inline int CircularQueueType<T>::Search(ItemType& item)
{
	ItemType temp;
	m_CulPointer = (m_iFront + 1) % maxsize; 
	while (1)
	{
		
		temp = m_pItems[m_CulPointer];
		if (temp.CompareByID(item) == EQUAL)
		{
			item = temp;
			return 1;
		}
		if (m_CulPointer == m_iRear)
			break;
		m_CulPointer = (m_CulPointer + 1) % maxsize;
	}
	return 0;
}

template<typename T>
inline int CircularQueueType<T>::Delete(ItemType& item)
{
	ItemType temp;
	m_CulPointer = (m_iFront + 1) % maxsize; // 컬포인트 프론트+1로 초기화
	while (1)
	{

		temp = m_pItems[m_CulPointer]; //m_pitems가 T타입이기때문에 템프에 복사(아이템타입 멤버변수 쓰려고)
		if (temp.CompareByID(item) == EQUAL) // 템프랑 아이템 아이디가 같으면
		{
			item = temp; //아이템에 템프복사하고
			while (1)
			{
				m_pItems[m_CulPointer] = m_pItems[(m_CulPointer + 1) % maxsize]; // 아이템리스트 컬포인터인덱스에 그 뒤에꺼를 땡겨서 복사
				if (((m_CulPointer + 1) % maxsize) == m_iRear) // 컬포인터+1이 리어랑 같으면 리어에 컬포인트 넣고(-1 하기 어렵기때문) 와일문 종료
				{
					m_iRear = m_CulPointer;
					break;
				}
				m_CulPointer = (m_CulPointer + 1) % maxsize; // 컬포인트 하나 올리고
			}
			return 1;
		}
		if (m_CulPointer == m_iRear)
			break;
		m_CulPointer = (m_CulPointer + 1) % maxsize;
	}
	return 0;
}

template<typename T>
inline int CircularQueueType<T>::Replace(ItemType& item)
{
	ItemType temp;
	m_CulPointer = (m_iFront + 1) % maxsize; // 컬포인트 프론트+1로 초기화
	while (1)
	{
		temp = m_pItems[m_CulPointer]; //m_pitems가 T타입이기때문에 템프에 복사(아이템타입 멤버변수 쓰려고)
		if (temp.CompareByID(item) == EQUAL) // 템프의 아이디와 비교해서
		{
			m_pItems[m_CulPointer] = item; //원래 값에 아이템넣고 1리턴
			return 1;
		}
		if (m_CulPointer == m_iRear)
			break;
		m_CulPointer = (m_CulPointer + 1) % maxsize;
	}
	return 0;
}
