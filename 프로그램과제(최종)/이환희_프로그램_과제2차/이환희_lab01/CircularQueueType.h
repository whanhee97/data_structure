#pragma once
#include<iostream>
using namespace std;

#define maxsize 8
template<typename T>
class CircularQueueType
{
public:
	/**
	*	@brief	최대크기로 생성
	*	@pre	최대크기가 정해져야함
	*	@post	최대크기의 배열이 만들어지고, 각 멤버변수들이 초기화됨
	*/
	CircularQueueType();
	

	/**
	*	@brief	size에 해당하는 크기의 배열을 동적할당
	*	@post	size의 값에 해당되는 크기의 배열이 만들어짐,각 멤버변수들이 초기화됨
	*/
	CircularQueueType(int max);
	/**
	*	@brief	깊은 복사를 위한 생성자
	*	@pre	최대크기가 정해져야함
	*	@post	최대크기의 배열이 만들어지고, 각 멤버변수들이 초기화됨 이때 멤버리스트의 포인터주소가 옮겨지는게 아니라 실제값들이 하나하나 다 옮겨짐
	*/
	CircularQueueType(const CircularQueueType& C); // 깊은 복사 (만약 포인터주소가 옮겨지게 되면 두개의 포인터가 같은 값을 가르키게 되고 함수가 끝나고 소멸자를 호출시 중복으로 delete가 되어 오류가남.)
	
	/**
	*	@brief	소멸자
	*	@pre	CircularQueueType의 객체가 생성되어있어야함.
	*	@post	m_pItems를 delete함 객체가 사라짐.
	*/
	~CircularQueueType();


	/**
	*	@brief	=연산자(깊은 복사를 위한)
	*	@pre	대입할 대상이 존재.
	*	@post	C를 깊은 복사해서 대입
	*/
	CircularQueueType<T>& operator=(const CircularQueueType& C); // 생성자를 만들어줘도 따로 =연산자를 만들어 줘야함 깊은복사시..

	/**
	*	@brief	queue가 가득차있는지 확인.
	*	@pre	queue가 초기화 되어야함.
	*	@post	차있으면 ture 아니면 false
	*/
	bool IsFull();
	

		/**
	*	@brief	queue가 비어있는지 확인
	*	@pre	queue가 초기화 되어야함.
	*	@post	비어있으면 ture 아니면 false
	*/
	bool IsEmpty();


	/**
	*	@brief	큐를 모두 비움
	*	@pre	CircularQueueType의 객체가 생성되어있어야함.
	*	@post	리어와 프런트가 같아짐.
	*/
	void MakeEmpty();

	/**
	*	@brief	queue에 회전하면서 값을 채움.
	*	@pre	queue가 초기화 되어야함
	*	@post	가득차있으면 FullStack Exception을 throw함, 아니면 새로운 값을 추가함,rear값 증가
	*/
	void EnQueue(T& item);

	/**
	*	@brief	queue에 회전하면서 값을 삭제(=front값이 하나 증가)
	*	@pre	Stack has been initialized.
	*	@post	비어있으면 empty Exception을 throw;아니면 맨위의 값을 삭제
	*/
	void DeQueue(T& item);

	/**
	*	@brief	Print all the items in the stack on screen
	*	@pre	Stack has been initialized.
	*	@post	None.
	*/
	void Print();

	/**
	*	@brief	top가져옴
	*/
	int GetTop();

	/**
	*	@brief	리어가져옴
	*/
	int GetRear();

	/**
	*	@brief	컬포인터 초기화
	*	@post	m_CulPointer가 m_iFront로 초기화됨
	*/
	void ResetList();

	/**
	*	@brief	컬포인터가 다음을 가르키고 다음 아이템으로 넘어감
	*	@pre	
	*	@post	데이터에 다음 아이템이 복사됨
	*/
	int GetNextItem(T& data); 

	/**
	*	@brief	컬포인터가 다음을 가르키고 다음 아이템으로 넘어감(실제값을 건드리고 싶을때)
	*	@pre
	*	@post	Cul에 다음 m_CurPointer 복사됨
	*	@return data 포인터값
	*/
	T* GetNextItem(T* data, int& Cul); 

	/**
	*	@brief	아이템에 찾고자하는 리스트의 아이템이 복사됨
	*	@pre	아이템에 아이디가 입력되어있어야함
	*	@post	아이템에 찾고자하는 리스트의 아이템이 복사됨
	*/
	int Search(T& item);

	/**
	*	@brief	찾고자 하는 아이템 삭제
	*	@pre	아이템에 아이디가 입력되어있어야함
	*	@post	아이템에 찾고자하는 리스트의 아이템이 복사됨
	*/
	int Delete(T& item);

	/**
		*	@brief	리스트의 아이템이 교체됨
		*	@pre	아이템에 아이디가 입력되어있어야함
		*	@post	아이템에 찾고자하는 리스트의 아이템이 복사됨
		*/
	int Replace(T& item);

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
inline CircularQueueType<T>::CircularQueueType(const CircularQueueType& C)
{
	m_iFront = C.m_iFront;
	m_iRear = C.m_iRear;
	m_nMaxQueue = C.m_nMaxQueue;

	top = C.top; // 아이템 개수
	m_CulPointer = C.m_CulPointer;

	m_pItems = new T[maxsize];
	for (int i = 0; i < maxsize; i++)
	{
		m_pItems[i] = C.m_pItems[i];
	}

}

template<typename T>
CircularQueueType<T>::~CircularQueueType()
{
	delete[] m_pItems;
}

template<typename T>
inline CircularQueueType<T>& CircularQueueType<T>::operator=(const CircularQueueType& C)
{
	m_iFront = C.m_iFront;
	m_iRear = C.m_iRear;
	m_nMaxQueue = C.m_nMaxQueue;

	top = C.top; // 아이템 개수
	m_CulPointer = C.m_CulPointer;

	m_pItems = new T[maxsize];
	for (int i = 0; i < maxsize; i++)
	{
		m_pItems[i] = C.m_pItems[i];
	}
	return *this;
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
		T temp;
		DeQueue(temp);
		top++;
		m_iRear = (m_iRear + 1) % m_nMaxQueue;
		m_pItems[m_iRear] = item;
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
T* CircularQueueType<T>::GetNextItem(T* data, int& Cul)
{

	if (!IsEmpty())
	{
		m_CulPointer = (m_CulPointer + 1) % m_nMaxQueue;
		data = &m_pItems[m_CulPointer];
		Cul = m_CulPointer;
	}

	return data;
}

template<typename T>
inline int CircularQueueType<T>::Search(T& item)
{
	m_CulPointer = (m_iFront + 1) % maxsize;
	while (1)
	{
		if (m_pItems[m_CulPointer] == item)
		{
			item = m_pItems[m_CulPointer];
			return 1;
		}
		if (m_CulPointer == m_iRear)
			break;
		m_CulPointer = (m_CulPointer + 1) % maxsize;
	}
	return 0;
}

template<typename T>
inline int CircularQueueType<T>::Delete(T& item)
{
	m_CulPointer = (m_iFront + 1) % maxsize; // 컬포인트 프론트+1로 초기화
	while (1)
	{
		if (m_pItems[m_CulPointer] == item) // 템프랑 아이템 아이디가 같으면
		{
			item = m_pItems[m_CulPointer]; //아이템에 템프복사하고
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
inline int CircularQueueType<T>::Replace(T& item)
{
	m_CulPointer = (m_iFront + 1) % maxsize; // 컬포인트 프론트+1로 초기화
	while (1)
	{
		if (m_pItems[m_CulPointer] == item) // 템프의 아이디와 비교해서 같으면
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

