#pragma once
#include<iostream>
using namespace std;

#define maxsize 8
template<typename T>
class CircularQueueType
{
public:
	/**
	*	@brief	�ִ�ũ��� ����
	*	@pre	�ִ�ũ�Ⱑ ����������
	*	@post	�ִ�ũ���� �迭�� ���������, �� ����������� �ʱ�ȭ��
	*/
	CircularQueueType();
	

	/**
	*	@brief	size�� �ش��ϴ� ũ���� �迭�� �����Ҵ�
	*	@post	size�� ���� �ش�Ǵ� ũ���� �迭�� �������,�� ����������� �ʱ�ȭ��
	*/
	CircularQueueType(int max);
	/**
	*	@brief	���� ���縦 ���� ������
	*	@pre	�ִ�ũ�Ⱑ ����������
	*	@post	�ִ�ũ���� �迭�� ���������, �� ����������� �ʱ�ȭ�� �̶� �������Ʈ�� �������ּҰ� �Ű����°� �ƴ϶� ���������� �ϳ��ϳ� �� �Ű���
	*/
	CircularQueueType(const CircularQueueType& C); // ���� ���� (���� �������ּҰ� �Ű����� �Ǹ� �ΰ��� �����Ͱ� ���� ���� ����Ű�� �ǰ� �Լ��� ������ �Ҹ��ڸ� ȣ��� �ߺ����� delete�� �Ǿ� ��������.)
	
	/**
	*	@brief	�Ҹ���
	*	@pre	CircularQueueType�� ��ü�� �����Ǿ��־����.
	*	@post	m_pItems�� delete�� ��ü�� �����.
	*/
	~CircularQueueType();


	/**
	*	@brief	=������(���� ���縦 ����)
	*	@pre	������ ����� ����.
	*	@post	C�� ���� �����ؼ� ����
	*/
	CircularQueueType<T>& operator=(const CircularQueueType& C); // �����ڸ� ������൵ ���� =�����ڸ� ����� ����� ���������..

	/**
	*	@brief	queue�� �������ִ��� Ȯ��.
	*	@pre	queue�� �ʱ�ȭ �Ǿ����.
	*	@post	�������� ture �ƴϸ� false
	*/
	bool IsFull();
	

		/**
	*	@brief	queue�� ����ִ��� Ȯ��
	*	@pre	queue�� �ʱ�ȭ �Ǿ����.
	*	@post	��������� ture �ƴϸ� false
	*/
	bool IsEmpty();


	/**
	*	@brief	ť�� ��� ���
	*	@pre	CircularQueueType�� ��ü�� �����Ǿ��־����.
	*	@post	����� ����Ʈ�� ������.
	*/
	void MakeEmpty();

	/**
	*	@brief	queue�� ȸ���ϸ鼭 ���� ä��.
	*	@pre	queue�� �ʱ�ȭ �Ǿ����
	*	@post	������������ FullStack Exception�� throw��, �ƴϸ� ���ο� ���� �߰���,rear�� ����
	*/
	void EnQueue(T& item);

	/**
	*	@brief	queue�� ȸ���ϸ鼭 ���� ����(=front���� �ϳ� ����)
	*	@pre	Stack has been initialized.
	*	@post	��������� empty Exception�� throw;�ƴϸ� ������ ���� ����
	*/
	void DeQueue(T& item);

	/**
	*	@brief	Print all the items in the stack on screen
	*	@pre	Stack has been initialized.
	*	@post	None.
	*/
	void Print();

	/**
	*	@brief	top������
	*/
	int GetTop();

	/**
	*	@brief	�������
	*/
	int GetRear();

	/**
	*	@brief	�������� �ʱ�ȭ
	*	@post	m_CulPointer�� m_iFront�� �ʱ�ȭ��
	*/
	void ResetList();

	/**
	*	@brief	�������Ͱ� ������ ����Ű�� ���� ���������� �Ѿ
	*	@pre	
	*	@post	�����Ϳ� ���� �������� �����
	*/
	int GetNextItem(T& data); 

	/**
	*	@brief	�������Ͱ� ������ ����Ű�� ���� ���������� �Ѿ(�������� �ǵ帮�� ������)
	*	@pre
	*	@post	Cul�� ���� m_CurPointer �����
	*	@return data �����Ͱ�
	*/
	T* GetNextItem(T* data, int& Cul); 

	/**
	*	@brief	�����ۿ� ã�����ϴ� ����Ʈ�� �������� �����
	*	@pre	�����ۿ� ���̵� �ԷµǾ��־����
	*	@post	�����ۿ� ã�����ϴ� ����Ʈ�� �������� �����
	*/
	int Search(T& item);

	/**
	*	@brief	ã���� �ϴ� ������ ����
	*	@pre	�����ۿ� ���̵� �ԷµǾ��־����
	*	@post	�����ۿ� ã�����ϴ� ����Ʈ�� �������� �����
	*/
	int Delete(T& item);

	/**
		*	@brief	����Ʈ�� �������� ��ü��
		*	@pre	�����ۿ� ���̵� �ԷµǾ��־����
		*	@post	�����ۿ� ã�����ϴ� ����Ʈ�� �������� �����
		*/
	int Replace(T& item);

private:
	int m_iFront;
	int m_iRear;
	int m_nMaxQueue;

	int top; // ������ ����
	int m_CulPointer;

	T* m_pItems;
};

//-------���ø� Ŭ�������� �Լ��� ����� ���Ǹ� �� ���Ͽ� ����!

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

	top = C.top; // ������ ����
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

	top = C.top; // ������ ����
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
		cout << "����Ʈ�� ������ϴ�!" << endl;
	}
	else
	{
		top--;
		m_iFront = (m_iFront + 1) % m_nMaxQueue;
		item = m_pItems[m_iFront]; // ������ �������� �Ķ���ͷ� �޾ƿ� �����ۿ� ����
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
			cout << "������{" << next << "]  ";
			next = (next + 1) % m_nMaxQueue;
		}
	}
	else
	{
		int next = (m_iFront + 1) % m_nMaxQueue;
		for (int i = 0; i < m_iRear - m_iFront; i++)
		{
			cout << "������{" << next << "]  ";
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
	m_CulPointer = (m_iFront + 1) % maxsize; // ������Ʈ ����Ʈ+1�� �ʱ�ȭ
	while (1)
	{
		if (m_pItems[m_CulPointer] == item) // ������ ������ ���̵� ������
		{
			item = m_pItems[m_CulPointer]; //�����ۿ� ���������ϰ�
			while (1)
			{
				m_pItems[m_CulPointer] = m_pItems[(m_CulPointer + 1) % maxsize]; // �����۸���Ʈ ���������ε����� �� �ڿ����� ���ܼ� ����
				if (((m_CulPointer + 1) % maxsize) == m_iRear) // ��������+1�� ����� ������ ��� ������Ʈ �ְ�(-1 �ϱ� ��Ʊ⶧��) ���Ϲ� ����
				{
					m_iRear = m_CulPointer;
					break;
				}
				m_CulPointer = (m_CulPointer + 1) % maxsize; // ������Ʈ �ϳ� �ø���
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
	m_CulPointer = (m_iFront + 1) % maxsize; // ������Ʈ ����Ʈ+1�� �ʱ�ȭ
	while (1)
	{
		if (m_pItems[m_CulPointer] == item) // ������ ���̵�� ���ؼ� ������
		{
			m_pItems[m_CulPointer] = item; //���� ���� �����۳ְ� 1����
			return 1;
		}
		if (m_CulPointer == m_iRear)
			break;
		m_CulPointer = (m_CulPointer + 1) % maxsize;
	}
	return 0;
}

