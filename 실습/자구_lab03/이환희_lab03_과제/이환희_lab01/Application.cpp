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
			AddMusic();
			break;
		case 2:
			DeleteMusic();
			break;

		case 3:
			ReplaceMusic();
			break;

		case 4:
			SearchIDByBinary();
			break;

		case 5:
			DisplayAllMusic();
			break;

		case 6:
			m_List.MakeEmpty();
			break;

		case 7:
			ReadDataFromFile();
			break;

		case 8:
			WriteDataToFile();
			break;

		case 9:
			SearchBySinger();
			break;

		case 10:
			SearchByGenre();
			break;

		case 11:
			PlayInsertOrder();
			break;

		case 12:
			AddToPlayList();
			break;

		case 13:
			PrintAll();
			break;

		case 14:
			DeleteFrPlayList();
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
	cout << "\t   1 : Add Music" << endl;
	cout << "\t   2 : Delete Music" << endl;
	cout << "\t   3 : Replace" << endl;
	cout << "\t   4 : Search ID" << endl;
	cout << "\t   5 : Print all on screen" << endl;
	cout << "\t   6 : Make empty list" << endl;
	cout << "\t   7 : Get from file" << endl;
	cout << "\t   8 : Put to file" << endl;
	cout << "\t   9 : Search by singer" << endl;
	cout << "\t  10 : Search by genre" << endl << endl;
	
	cout << "\t-------- PlayList --------" << endl;
	cout << "\t  11 : Play PlayList" << endl;
	cout << "\t  12 : Add To PlayList" << endl;
	cout << "\t  13 : Show PlayList" << endl;
	cout << "\t  14 : Delete PlayList" << endl;

	cout << endl << "\t-----------------------" << endl;
	cout <<"\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

int Application::AddMusic()
{
	ItemType temp;
	temp.SetRecordFromKB();
	m_List.Add(temp);
	return 0;
}

void Application::DisplayAllMusic()
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

void Application::SearchBySinger()
{
	ItemType temp;
	string singer;
	int Length = m_List.GetLength();

	cout << "�˻��� �������� �Է��Ͻÿ�: ";
	cin >> singer;

	m_List.ResetList();
	int Curpointer = m_List.GetNextItem(temp);

	while (Curpointer < Length && Curpointer != -1)
	{
		if (temp.GetSinger() == singer)
		{
			temp.DisplayRecordOnScreen();
		}
		Curpointer = m_List.GetNextItem(temp);
	}


}

void Application::SearchByGenre()
{
	ItemType temp;
	int genre;
	int Length = m_List.GetLength();

	cout << "�˻��� �帣(1.�߶�� 2.����/�� 3.R&B 4.�ε� 5.��)�� �Է��Ͻÿ�: ";
	cin >> genre;

	m_List.ResetList();
	int Curpointer = m_List.GetNextItem(temp);

	while (Curpointer < Length && Curpointer != -1)
	{
		if (temp.GetGenre() == genre)
		{
			temp.DisplayRecordOnScreen();
		}
		Curpointer = m_List.GetNextItem(temp);
	}
}

void Application::SearchIDByBinary()
{
	ItemType temp;
	string id;
	int result;
	int index;
	int Length = m_List.GetLength();

	cout << "ID�� �Է��Ͻÿ� ->";
	cin >> id;
	temp.SetId(id);
	result = m_List.RetrieveBinary(temp);
	if (result == 0)
	{
		cout << "�ش� ID�� �����ϴ�." << endl;
	}
	else
	{
		temp.DisplayRecordOnScreen();
	}
}



void Application::DeleteMusic()
{
	ItemType temp;
	string id;
	int result;

	cout << "ID�� �Է��Ͻÿ� ->";
	cin >> id;
	temp.SetId(id);
	result = m_List.Delete(temp);
	if (result == -1)
	{
		cout << "�ش� ���� �����ϴ�." << endl;
	}

}

void Application::ReplaceMusic()
{
	ItemType temp;
	string id;

	cout << "ID�� �Է��Ͻÿ� ->";
	cin >> id;
	temp.SetId(id);
	if (m_List.Get(temp) == -1)
	{
		cout << "�ش� �л��� �����ϴ�." << endl;
		return;
	}

	temp.SetRecordFromKB();
	m_List.Replace(temp);
}

//-------------------------------------------------------
void Application::AddToPlayList()
{
	PlayItemType data;
	ItemType temp;
	string id;
	cout << "id�� �Է��Ͻÿ� : ";
	cin >> id;
	temp.SetId(id);

	int result = m_List.RetrieveBinary(temp); // ���̳ʸ� ��ġ�� ���̵��� �Էµ� ������ ���̵� ��ġ�� �������� ����Ʈ�� �����ҽ� �� �������� ������ ����
	if (result == 0)
	{
		cout << "�ش� ���̵� ã�� �� �����ϴ�." << endl;
		return;
	}
	data.SetID(id);
	
	m_PlayList.EnQueue(data); // data�� ��ť
}

void Application::PrintAll()
{

	if (m_PlayList.IsEmpty())
	{
		cout << "Queue is Empty" << endl;
		return;
	}
	// �ӽ÷� ������ �����
	ItemType data;
	m_PlayList.ResetList(); // m_Queue�� curpointer �ʱ�ȭ
	PlayItemType item;
	int Curpointer = m_PlayList.GetNextItem(item);

	while (1)
	{
		data.SetId(item.GetID()); // data �� �������� ���̵� �޾ƿͼ�
		m_List.RetrieveBinary(data); // m_list���� �ش� ���̵� ã�Ƽ� data ���������
		if (Curpointer == m_PlayList.GetRear())
		{
			
			data.DisplayRecordOnScreen(); // data���
			item.PrintPN();// �÷��� Ƚ�� ���
			break;
		}
		data.DisplayRecordOnScreen(); 
		item.PrintPN();// �÷��� Ƚ�� ���
		Curpointer = m_PlayList.GetNextItem(item);// ���� ���������� ���ͷ����͸� �ű�
	}
}


void Application::PlayInsertOrder()
{
	ItemType data;
	PlayItemType* temp = NULL;
	int Curpointer;
	m_PlayList.ResetList();
	temp = m_PlayList.GetNextItem(temp, Curpointer);
	string id;
	if (m_PlayList.IsEmpty())
	{
		cout << "�÷��� ����Ʈ�� ������ϴ�." << endl;
		return;
	}


	while (1) {
		id = temp->GetID();
		temp->NumPlayUP(); // �÷��� Ƚ�� �� ������ �����ؼ� �÷�����
		data.SetId(id);
		m_List.RetrieveBinary(data);
		data.DisplayRecordOnScreen();

		int answer;
		cout << "�������� �÷��� �Ͻðڽ��ϱ�? 1.yes  2.no  : ";
		cin >> answer;

		if (answer == 2)
		{
			return;
		}
		else if (answer == 1) 
		{
			if (Curpointer == m_PlayList.GetRear())
			{
				m_PlayList.ResetList();
			}
			temp = m_PlayList.GetNextItem(temp,Curpointer);
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			return;
		}
	}
}

void Application::DeleteFrPlayList()
{
	if (m_PlayList.IsEmpty())
	{
		cout << "Queue is Empty" << endl;
		return;
	}
	PlayItemType item; // �ӽ÷� ������ �����
	item.SetIDFromKB(); // Ű����� �Է¹ް�
	int result = m_PlayList.Delete(item);
	if (result == 0)
	{
		cout << "�ش� ���̵� �����ϴ�." << endl;
	}
	else
	{
		cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
	}

}
