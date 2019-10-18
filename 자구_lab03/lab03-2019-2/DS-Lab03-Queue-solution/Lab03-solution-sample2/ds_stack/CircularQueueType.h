#pragma once
#include <iostream>
using namespace std;

#define maxsize 8

 /**
*	@brief	Exception class thrown by Push when stack is full.
*/
class FullStack
{
public:
	/**
	*	@brief	Display a message for full stack on screen.
	*/
	void print()
	{
		cout << "FullStack exception thrown." << endl;
	}
};

/**
*	@brief	Exception class thrown by Pop and Top when stack is empty.
*/
class EmptyStack
{
public:
	/**
	*	@brief	Display a message for full stack on screen.
	*/
	void print()
	{
		cout << "EmtpyStack exception thrown." << endl;
	}
};
template <typename T>	//generic data�� ���� template ����
class CircularQueueType
{
public:
		/**
	*	@brief	size�� �ش��ϴ� ũ���� �迭�� �����Ҵ�
	*	@post	size�� ���� �ش�Ǵ� ũ���� �迭�� �������,�� ����������� �ʱ�ȭ��
	*/
	CircularQueueType(int size);
		/**
	*	@brief	�ִ�ũ��� ����
	*	@pre	�ִ�ũ�Ⱑ ����������
	*	@post	�ִ�ũ���� �迭�� ���������, �� ����������� �ʱ�ȭ��
	*/
	CircularQueueType(void);
	
	~CircularQueueType(void);
	

	/**
	*	@brief	queue�� �������ִ��� Ȯ��.
	*	@pre	queue�� �ʱ�ȭ �Ǿ����.
	*	@post	�������� ture �ƴϸ� false
	*/
	bool IsFull() const;

	/**
	*	@brief	queue�� ����ִ��� Ȯ��
	*	@pre	queue�� �ʱ�ȭ �Ǿ����.
	*	@post	��������� ture �ƴϸ� false
	*/
    bool IsEmpty() const;

	/**
	*	@brief	queue�� ȸ���ϸ鼭 ���� ä��.
	*	@pre	queue�� �ʱ�ȭ �Ǿ����
	*	@post	������������ FullStack Exception�� throw��, �ƴϸ� ���ο� ���� �߰���,rear�� ����
	*/ 
    void EnQueue(T item);

	/**
	*	@brief	queue�� ȸ���ϸ鼭 ���� ����(=front���� �ϳ� ����)
	*	@pre	Stack has been initialized.
	*	@post	��������� empty Exception�� throw;�ƴϸ� ������ ���� ����
	*/
    void DeQueue(T& item);

	/**
	*	@brief	Returns a copy of top item on the stack.
	*	@pre	Stack has been initialized.
	*	@post	If (stack is empty), EmptyStack exception is thrown; otherwise, top element has been removed from stack.
	*/
    T Top();

	/**
	*	@brief	Print all the items in the stack on screen
	*	@pre	Stack has been initialized.
	*	@post	None.
	*/
	void Print();
	void MakeEmpty();
    
private:
	int m_iFront;
	int m_iRear;
	int m_nMaxQueue;
    int top;	///< Number of elements.
    T *items;	///< Pointer for a stack.

};

template <typename T>
CircularQueueType<T>::CircularQueueType(int size)
{
	items = new T [size];	//T�� �ڷ������� �����Ҵ�
	m_iFront=size-1;/
	m_iRear=size-1;
	m_nMaxQueue=size;
	top = -1;

}
template <typename T>
CircularQueueType<T>::CircularQueueType()
{
items = new T [maxsize];
 m_iFront=maxsize-1;
 m_iRear=maxsize-1;
 m_nMaxQueue=maxsize;
top = -1;
}


// Destruct the object. Free the array dynamically allocated.
template <typename T>
CircularQueueType<T>::~CircularQueueType()
{
delete[] items;
}


// Determines whether the CircularQueueType is full.
template <typename T>
bool CircularQueueType<T>::IsEmpty() const
{
if(m_iRear==m_iFront)
return true;
else
return false;
}


// Determines whether the CircularQueueType is empty.
template <typename T>
bool CircularQueueType<T>::IsFull() const
{
	
		if( (m_iRear+1)%m_nMaxQueue==m_iFront )	//rear�� ����ĭ�� front���� �ƴ��� �˻�
			return true;
		else
			return false;
	
}


// Adds newItem to the top of the CircularQueueType.
template <typename T>
void CircularQueueType<T>::EnQueue(T newItem) 
{
	if (IsFull())
		throw FullStack();
	else
	{
			m_iRear=(m_iRear+1)%m_nMaxQueue;
			items[m_iRear%m_nMaxQueue]=newItem;
			top++;
	}
}


// Removes top item from the CircularQueueType.
template <typename T>
void CircularQueueType<T>::DeQueue(T& item)
{
	top--;
	if (IsEmpty())			//����ִ��� �˻�
		throw EmptyStack();
	else
	{
		m_iFront=(m_iFront+1)%m_nMaxQueue; //front�� ������ ��ĭ �̵�
		item= items[m_iFront];	//��������, ���ٵ��� ���� ���� �˱����ؼ� item�� �ش� ���� ����
		
	}
}


// Removes top item from the CircularQueueType.
template <typename T>
T CircularQueueType<T>::Top()
{
if (IsEmpty())
throw EmptyStack();
else
return items[top];
}


// Print all the items in the CircularQueueType on screen
template <typename T>
void CircularQueueType<T>::Print()
{
	if (IsEmpty())				//������� it is empty���. Empty Stack�� throw�ϸ� ���α׷��� ����Ǿ �ٽ� Enqueue�Ҽ������Ƿ�
		cout<<"It is empty!"<<endl;				//�ε����ϰ� ���ο� ����ó��
	else 
	{
		cout << "CircularQueueType: ";
		// CircularQueueType ���Ǹ��element ���.
		int first=m_iFront;
		int last=m_iRear;
		while(first!=last)				//Rear���� front�� ���� �������ȸ�. front�� �����ؼ� ���� �ϳ��� ���.Enqueue�ϸ� rear�� front�� ���� �ռ������Ƿ�
		{
			cout << items[(first+1)%m_nMaxQueue] << " - ";
			first=(first+1)%m_nMaxQueue;
		}
			cout << endl;
	}
}
template <typename T>
void CircularQueueType<T>::MakeEmpty()
{
	m_iFront=m_iRear; //Front�� rear�� ���� ������ isEmpty���� �ֺ������ �����
}