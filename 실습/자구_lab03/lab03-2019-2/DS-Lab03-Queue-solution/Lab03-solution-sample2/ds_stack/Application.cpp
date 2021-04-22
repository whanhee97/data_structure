
#include "Application.h"


// Program driver.
void Application::Run()
{
	try
	{
		while(1)
		{
			m_Command = GetCommand();

			switch(m_Command)
			{
			case 1:		// �߰�.
				EnqueueItem();
				break;
			case 2:		//����.
				DequeueItem();
				break;
			case 3:		// Is Empty?
				CheckEmpty();
				break;
			case 4:		// Is Full?
				CheckFull();
				break;
			case 5:		// Test EmptyStack Exception.
				TestEmptyException();
				break;
			case 6:		// Test FullStack Exception.
				TestFullException();
				break;
			case 7:		// Print all the elements in the stack.
				DisplayAllItem();
				break;
			case 8:		// Print all the elements in the stack.
				EmptyItem();
				break;
			case 0:
				return;
			default:
				cout << "\tIllegal selection...\n";
				break;
			}
		}
	}
	catch (FullStack e)
	{
		e.print();
	}
	
	catch (EmptyStack e)
	{		
		e.print();
	}
}

void Application::EmptyItem()
{
	m_Stack.MakeEmpty();
	DisplayAllItem();

}
// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout<<"\t--- ID - Command -----"<<endl;
	cout<<"\t    1. Enqueue Element"<<endl;
	cout<<"\t    2. Dequeue Element"<<endl;
	cout<<"\t    3. Is Empty?"<<endl;
	cout<<"\t    4. Is Full?"<<endl;
	cout<<"\t    5. Emptyqueue Exception test"<<endl;
	cout<<"\t    6. Fullqueue Exception test"<<endl;
	cout<<"\t    7. Print all the elements in stack"<<endl;
	cout<<"\t    8. Make Empty"<<endl;
	cout<<"\t    0. Quit"<<endl<<endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Enqueue new record into the stack.
int Application::EnqueueItem()
{
	if(!m_Stack.IsFull())	//�����ִ��� Ȯ��
	{
		ItemType item;		//main���� Application<�ڷ���>���� ����� �ڷ����� �����ϳ� ����
		cout << "EnQueue Element : ";
		cin >> item;

		m_Stack.EnQueue(item);	//��Ư�� �ڷ��� ���� �߰�
		DisplayAllItem();	//���
		
		return 1;
	}
	else
	{	
		throw FullStack();	//���������� FullStatck()���� �߻�
		return 0;
	}
}


// Pop a record of top from the stack.
int Application::DequeueItem()
{
	if(!m_Stack.IsEmpty())	//����ִ��� Ȯ��
	{
		ItemType item;			//� �����Ͱ� ������� �˱� ���� ��Ư�� �ڷ����� ���� ����
		m_Stack.DeQueue(item);	//������ ���� ����� �ش簪�� item�� ����
		cout << "DeQueue Element : " << item << endl << endl;
		
		DisplayAllItem();	//��簪 ���
		
		return 1;
	}

	return 0;
}


// Check the stack is empty state.
int Application::CheckEmpty()
{
	if(m_Stack.IsEmpty())	
	{
		cout << "Stack is Empty." << endl << endl;
		return 1;
	}
	else
	{
		cout << "Stack is not Empty." << endl << endl;
		return 0;
	}
}


// Check the stack is full state.
int Application::CheckFull()
{
	if(m_Stack.IsFull())
	{
		cout << "Stack is Full." << endl << endl;
		return 1;
	}
	else
	{
		cout << "Stack is not Full." << endl << endl;
		return 0;
	}
}


// Test the exeception of empty stack.
void Application::TestEmptyException()
{
	ItemType item;
	
	while(1){
	m_Stack.DeQueue(item);
	}
}


// Test the exeception of full stack.
void Application::TestFullException()
{
	ItemType item;
	srand((unsigned long)time(NULL));

	while(1)
	{
		item = rand();
		m_Stack.Print();
		m_Stack.EnQueue(item);				
	}
}


// Display all records in the stack on screen.
void Application::DisplayAllItem()
{
	m_Stack.Print();
}








