#ifndef _APPLICATION_H
#define _APPLICATION_H


#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "CircularQueueType.h"
#include "ItemType.h"

/**
*	application class for item management simply.
*/
//circular queue type�� �ڷ����� �����ϰ� �ϱ� ���� template����
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_Command = 0;
	}
	
	/**
	*	destructor.
	*/
	~Application()	{}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	����� ǥ���ϰ� Ű����� ���� �Է¹���
	*	@pre	none.
	*	@post	none.
	*	@return	������� ���.
	*/
	int GetCommand();

	/**
	*	@brief	���ο� ���� queue�� �߰�
	*	@pre	queue�� ������ �ʾƾ���.
	*	@post	���ο� ���� queue�� �߰���.
	*	@return	������ 1, ���н� 0.
	*/
	int EnqueueItem();

	/**
	*	@brief	������ queue���� ����
	*	@pre	queue�� ���� �־����
	*	@post	������ ���� ������
	*	@return	������ 1, ���н� 0.
	*/
	int DequeueItem();

	/**
	*	@brief	queue�� ������� Ȯ��
	*	@return	��������� 1 ����  �׷��� ������ 0.
	*/
	int CheckEmpty();

	/**
	*	@brief	queue�� ��á���� Ȯ��
	*	@return	������ 1 ����, �ƴϸ� 0.
	*/
	int CheckFull();

	/**
	*	@brief	Test the exeception of empty stack.
	*	@pre	The stack should be initialized.
	*	@post	Do exception funciton when the stack is empty.
	*/
	void TestEmptyException();
	
	/**
	*	@brief	Test the exeception of full stack.
	*	@pre	The stack should be initialized.
	*	@post	Do exception funciton when the stack is full.
	*/
	void TestFullException();

	/**
	*	@brief	��� ���� ȭ�鿡 ���.
	*	@pre	ť�� ��������� �ȵ�.
	*	@post	��簪�� ���, ��������� It is empty ���.
	*/
	void DisplayAllItem();
	/**
	*	@brief	queue�� �ֺ�� ����
	*	@post	queue�� �ֺ��ó�� ����.front=rear;
	*/
	void EmptyItem();
	
private:
	CircularQueueType<ItemType> m_Stack;		///< item stack.
	int m_Command;			///< current command number.
};

#endif	// _APPLICATION_H