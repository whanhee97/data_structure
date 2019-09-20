#include "Application.h"



Application::Application()
{
}


Application::~Application()
{
}

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
			RetrieveStudent();
			break;

		case 7:
			DeleteStudent();
			break;

		case 8:
			Replace();
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
	cout << "\t   6 : Search ID" << endl;
	cout << "\t   7 : Delete Student" << endl;
	cout << "\t   8 : Replace" << endl;
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
		if(m_InFile.get() == '\n')
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

void Application::Replace()
{
	ItemType temp;
	int id;
	string name;
	string address;

	cout << "ID�� �Է��Ͻÿ� ->";
	cin >> id;
	temp.SetId(id);
	if (m_List.Get(temp) == -1)
	{
		cout << "�ش� �л��� �����ϴ�." << endl;
		return;
	}
	cout << "������ ID�� �Է��Ͻÿ� ->";
	cin >> id;
	cout << "������ �̸��� �Է��Ͻÿ� ->";
	cin >> name;
	cout << "������ �ּҸ� �Է��Ͻÿ� ->";
	cin >> address;
	temp.SetRecord(id, name, address);
	m_List.Replace(temp);
}


