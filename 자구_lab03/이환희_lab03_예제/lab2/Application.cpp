#include "Application.h"


void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1:
			AddItem();
			break;
		case 2:
			DisplayAllItem();
			break;
		case 3:
			m_List.MakeEmpty();
			break;
		case 4:
			ReadDataFromFile();
			break;
		case 5:
			WriteDataToFile();
			break;

		case 6:
			SearchByID_SequenS();
			break;

		case 7:
			DeleteStudent();
			break;

		case 8:
			ReplaceItem();
			break;

		case 9:
			SearchByName();
			break;

		case 10:
			SearchByID_BinaryS();
			break;

		case 11:
			Enqueue();
			break;

		case 12:
			Dequeue();
			break;

		case 13:
			CheckEmpty();
			break;

		case 14:
			CheckFull();
			break;

		case 15:
			EmptyTest();
			break;

		case 16:
			FullTest();
			break;

		case 17:
			PrintAll();
			break;

		case 18:
			Search();
			break;
		
		case 19:
			Replace();
			break;

		case 20:
			AddRecordToQL();
			break;
		
		case 21:
			DeleteQList();
			break;

		case 0:
			return;

		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Print all on screen" << endl;
	cout << "\t   3 : Make empty list" << endl;
	cout << "\t   4 : Get from file" << endl;
	cout << "\t   5 : Put to file" << endl;
	cout << "\t   6 : Search ID(SeqS)" << endl;
	cout << "\t   7 : Delete Student" << endl;
	cout << "\t   8 : Replace" << endl;
	cout << "\t   9 : Search by name" << endl;
	cout << "\t  10 : Search ID(BinaryS)" << endl <<endl;
	
	cout << "\t-------- Queue --------" << endl;
	cout << "\t  11 : Enqueue" << endl;
	cout << "\t  12 : Dequeue" << endl;
	cout << "\t  13 : Is Empty?" << endl;
	cout << "\t  14 : Is Full?" << endl;
	cout << "\t  15 : Empty Queue exception test" << endl;
	cout << "\t  16 : Full Queue exception test" << endl;
	cout << "\t  17 : Print All(Queue list)" << endl;
	cout << "\t  18 : Search ID(Queue list)" << endl;
	cout << "\t  19 : Replace(Queue list)" << endl;
	cout << "\t  20 : Add Item To Queue From ArrayList" << endl;
	cout << "\t  21 : Delete" << endl << endl;

	
	cout << "\t-----------------------" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

int Application::AddItem()
{
	ItemType temp;
	temp.SetRecordFromKB();
	m_List.Add(temp);
	return 0;
}

void Application::DisplayAllItem()
{
	ItemType item; // �ӽ÷� ������ �����
	m_List.ResetList(); // m_List�� curpointer �ʱ�ȭ

	int Curpointer = m_List.GetNextItem(item); // Curpointer ��� ���ͷ����� ����� m_List�� 0��° ������ �������� �ε����� ���ͷ����Ϳ� ����
	int Length = m_List.GetLength();

	while (Curpointer < Length && Curpointer != -1)
	{
		item.DisplayRecordOnScreen(); // ����� (���ͷ����Ͱ� ����Ű��) ������ ���
		Curpointer = m_List.GetNextItem(item); // ���� ���������� ���ͷ����͸� �ű�
	}

}

int Application::OpenInFile(const char * fileName)
{
	m_InFile.open(fileName);
	return 0;
}

int Application::OpenOutFile(const char * fileName)
{
	m_OutFile.open(fileName);
	return 0;
}

int Application::ReadDataFromFile()
{
	int iid;
	string iname, iaddress;
	OpenInFile("temp.txt");
	ItemType item;
	while (!m_InFile.eof())
	{
		item.ReadDataFromFile(m_InFile);
		if (m_InFile.get() == '\n')
			m_List.Add(item);
	}

	m_InFile.close();  // �� close���ֱ�!!
	return 0;
}

int Application::WriteDataToFile()
{
	int iid;
	string iname, iaddress;
	OpenOutFile("temp.txt");
	ItemType item;
	m_List.ResetList();
	int Curpointer = m_List.GetNextItem(item);
	int Length = m_List.GetLength();
	while (Curpointer < Length && Curpointer != -1)
	{
		item.WriteDataToFile(m_OutFile);
		Curpointer = m_List.GetNextItem(item);
	}

	m_OutFile.close(); // �� close���ֱ�!!
	return 0;
}

void Application::SearchByID_SequenS()
{
	int id;
	ItemType temp;
	int result;
	cout << "�˻��Ͻ� ID�� �Է��Ͻÿ�: ";
	cin >> id;
	temp.SetId(id);

	result = m_List.Retrieve_SeqS(temp);
	if (result == 0)
	{
		cout << "�ش� ID�� ã�� ���Ͽ����ϴ�." << endl;
	}
	else
	{
		temp.DisplayRecordOnScreen();
	}
}

void Application::SearchByID_BinaryS()
{
	int id;
	ItemType temp;
	int result;
	cout << "�˻��Ͻ� ID�� �Է��Ͻÿ�: ";
	cin >> id;
	temp.SetId(id);

	result = m_List.Retrieve_Binary(temp);
	if (result == 0)
	{
		cout << "�ش� ID�� ã�� ���Ͽ����ϴ�." << endl;
	}
	else
	{
		temp.DisplayRecordOnScreen();
	}
}

void Application::SearchByName()
{
	ItemType temp;
	string name;
	cout << "�̸��� �Է��Ͻÿ�: ";
	cin >> name;

	int Length = m_List.GetLength();
	m_List.ResetList();
	int Curpointer = m_List.GetNextItem(temp);

	int plag = 0;

	while (Curpointer < Length && Curpointer != -1)
	{
		if (temp.GetName() == name) 
		{
			temp.DisplayRecordOnScreen();
			plag++;
		}
		Curpointer = m_List.GetNextItem(temp);
	}

	if (plag == 0)
	{
		cout << "�ش��ϴ� �̸��� �л��� �����ϴ�" << endl;
	}
	else
	{
		cout  << endl << "�� " << plag << "���� �˻������ ���Խ��ϴ�." << endl;
	}

}



void Application::RetrieveStudent()
{
	ItemType temp;
	int id;
	int index;
	int Length = m_List.GetLength();

	cout << "ID�� �Է��Ͻÿ� ->";
	cin >> id;
	temp.SetId(id);
	index = m_List.Get(temp); // �ε����� ���� ���̵��� �������� ������Ʈ ����(Get�Լ� ��ü�� m_List ���� �����Ϳ� temp�� ���̵� ���Ͽ� ��ġ�Ұ�� �� �ε����� ������)

	if (index == -1)
	{
		cout << "�ش� ID�� �л��� �����ϴ�." << endl;
		return;
	}

	m_List.ResetList();
	int Curpointer = m_List.GetNextItem(temp);

	while (Curpointer < Length && Curpointer != -1)
	{
		if (Curpointer == index)  // �ε����� ���� ���ͷ�����(��������)�� ������ ���
		{
			temp.DisplayRecordOnScreen();
			break;
		}
		Curpointer = m_List.GetNextItem(temp);
	}
}



void Application::DeleteStudent()
{
	ItemType temp;
	int id;
	int result;

	cout << "ID�� �Է��Ͻÿ� ->";
	cin >> id;
	temp.SetId(id);
	result = m_List.Delete(temp);
	if (result == -1)
	{
		cout << "�ش� �л��� �����ϴ�." << endl;
	}

}

void Application::ReplaceItem()
{
	ItemType temp;
	int id;
	string name;
	string address;

	cout << "ID�� �Է��Ͻÿ� ->";
	cin >> id;
	cout << "������ �̸��� �Է��Ͻÿ� ->";
	cin >> name;
	cout << "������ �ּҸ� �Է��Ͻÿ� ->";
	cin >> address;
	temp.SetRecord(id, name, address);
	
	int result = m_List.Replace(temp);

	if (result == 0)
	{
		cout << "�ش� �л��� �����ϴ�." << endl;
		return;
	}

}

//------------------------------------------------------


int Application::Enqueue()
{
	if (m_Queue.IsFull())
	{
		cout << "����Ʈ�� �� ��!" << endl;
		return 0;
	}
	else
	{
		ItemType temp;
		temp.SetRecordFromKB();
		m_Queue.EnQueue(temp);
		return 1;
	}
}

int Application::Dequeue()
{
	if (m_Queue.IsEmpty())
	{
		cout << "����Ʈ�� �������!" << endl;
		return 0;
	}
	else
	{
		ItemType temp;
		m_Queue.DeQueue(temp);
		return 1;
	}
}

int Application::CheckEmpty()
{
	if (m_Queue.IsEmpty())
	{
		cout << "Queue is Empty." << endl << endl;
		return 1;
	}
	else
	{
		cout << "Queue is not Empty." << endl << endl;
		return 0;
	}
}

int Application::CheckFull()
{
	if (m_Queue.IsFull())
	{
		cout << "Queue is Full." << endl << endl;
		return 1;
	}
	else
	{
		cout << "Queue is not Full." << endl << endl;
		return 0;
	}
}

void Application::EmptyTest()
{
	ItemType item;

	while (1) {
		if (m_Queue.IsEmpty())
		{
			break;
		}
		m_Queue.DeQueue(item);
		cout << "DeQueue �߽��ϴ�." << endl;

	}
	CheckEmpty();
}

void Application::FullTest()
{
	ItemType item;
	item.SetRecord(0, "0", "0");

	while (1)
	{
		if (m_Queue.IsFull())
		{
			break;
		}
		m_Queue.EnQueue(item);
		cout << "EnQueue �߽��ϴ�" << endl;
	}
	CheckFull();
}

void Application::PrintAll()
{
	if (m_Queue.IsEmpty())
	{
		cout << "Queue is Empty" << endl;
		return;
	}
	ItemType item; // �ӽ÷� ������ �����
	
	m_Queue.ResetList(); // m_Queue�� curpointer �ʱ�ȭ

	int Curpointer = m_Queue.GetNextItem(item); 

	while (1)
	{
		if (Curpointer == m_Queue.GetRear()) 
		{
			item.DisplayRecordOnScreen(); // ����� (���ͷ����Ͱ� ����Ű��) ������ ���
			break;
		}
		item.DisplayRecordOnScreen(); // ����� (���ͷ����Ͱ� ����Ű��) ������ ���
		Curpointer = m_Queue.GetNextItem(item); // ���� ���������� ���ͷ����͸� �ű�
	}
}

void Application::Search()
{
	ItemType temp;
	temp.SetIdFromKB();
	int result = m_Queue.Search(temp);
	if (result == 0)
	{
		cout << "�ش� ���̵� ã�� ���Ͽ����ϴ�." << endl;
		return;
	}
	
	temp.DisplayRecordOnScreen();
	
}

void Application::Replace()
{
	ItemType temp;
	temp.SetRecordFromKB();
	int result = m_Queue.Replace(temp);
	if (result == 0)
	{
		cout << "�ش� ���̵� �����ϴ�." << endl;
	}
	else
	{
		cout << "��ü �Ϸ�" << endl;
	}
}

void Application::AddRecordToQL()
{
	ItemType temp;
	temp.SetIdFromKB();
	int result = m_List.Retrieve_Binary(temp); // ���̳ʸ� ��ġ�� ���̵��� �Էµ� ������ ���̵� ��ġ�� �������� ����Ʈ�� �����ҽ� �� �������� ������ ����
	if (result == 0)
	{
		cout << "�ش� ���̵� ã�� �� �����ϴ�." << endl;
		return;
	}
	m_Queue.EnQueue(temp); // ������ ��ť
}

void Application::DeleteQList()
{
	if (m_Queue.IsEmpty())
	{
		cout << "Queue is Empty" << endl;
		return;
	}
	ItemType item; // �ӽ÷� ������ �����
	item.SetIdFromKB(); // Ű����� �Է¹ް�
	int result = m_Queue.Delete(item);
	if (result == 0)
	{
		cout << "�ش� ���̵� �����ϴ�." << endl;
	}
	else
	{
		cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
	}

}
