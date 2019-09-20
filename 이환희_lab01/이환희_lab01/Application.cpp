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
			RetrieveMusic();
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
	cout << "\t   2 : Delete Student" << endl;
	cout << "\t   3 : Replace" << endl;
	cout << "\t   4 : Search ID" << endl;
	cout << "\t   5 : Print all on screen" << endl;
	cout << "\t   6 : Make empty list" << endl;
	cout << "\t   7 : Get from file" << endl;
	cout << "\t   8 : Put to file" << endl;
	cout << "\t   0 : Quit" << endl;

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
	ItemType item; // 임시로 아이템 만들고
	m_List.ResetList(); // m_List의 curpointer 초기화

	int Curpointer = m_List.GetNextItem(item); // Curpointer 라는 이터레이터 만들고 m_List의 0번째 아이템 복사한후 인덱스를 이터레이터에 저장
	int Length = m_List.GetLength();

	while (Curpointer < Length && Curpointer != -1)
	{
		item.DisplayRecordOnScreen(); // 복사된 (이터레이터가 가르키는) 아이템 출력
		Curpointer = m_List.GetNextItem(item); // 다음 아이템으로 이터레이터를 옮김
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

	m_InFile.close();  // 꼭 close해주기!!
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

	m_OutFile.close(); // 꼭 close해주기!!
	return 0;
}

void Application::RetrieveMusic()
{
	ItemType temp;
	string id;
	int index;
	int Length = m_List.GetLength();

	cout << "ID를 입력하시오 ->";
	cin >> id;
	temp.SetId(id);
	index = m_List.Get(temp); // 인덱스에 같은 아이디의 데이터의 컬포인트 저장(Get함수 자체가 m_List 안의 데이터와 temp의 아이디를 비교하여 일치할경우 그 인덱스를 가져옴)

	if (index == -1)
	{
		cout << "해당 ID의 곡이 없습니다." << endl;
		return;
	}

	m_List.ResetList();
	int Curpointer = m_List.GetNextItem(temp);

	while (Curpointer < Length && Curpointer != -1)
	{
		if (Curpointer == index)  // 인덱스와 현재 이터레이터(컬포인터)가 같으면 출력
		{
			temp.DisplayRecordOnScreen();
			break;
		}
		Curpointer = m_List.GetNextItem(temp);
	}
}

void Application::DeleteMusic()
{
	ItemType temp;
	string id;
	int result;

	cout << "ID를 입력하시오 ->";
	cin >> id;
	temp.SetId(id);
	result = m_List.Delete(temp);
	if (result == -1)
	{
		cout << "해당 곡이 없습니다." << endl;
	}

}

void Application::ReplaceMusic()
{
	ItemType temp;
	string id;

	cout << "ID를 입력하시오 ->";
	cin >> id;
	temp.SetId(id);
	if (m_List.Get(temp) == -1)
	{
		cout << "해당 학생이 없습니다." << endl;
		return;
	}

	temp.SetRecordFromKB();
	m_List.Replace(temp);
}