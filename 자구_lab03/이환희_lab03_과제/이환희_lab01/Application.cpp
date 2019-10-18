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

void Application::SearchBySinger()
{
	ItemType temp;
	string singer;
	int Length = m_List.GetLength();

	cout << "검색할 가수명을 입력하시오: ";
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

	cout << "검색할 장르(1.발라드 2.힙합/댄스 3.R&B 4.인디 5.락)을 입력하시오: ";
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

	cout << "ID를 입력하시오 ->";
	cin >> id;
	temp.SetId(id);
	result = m_List.RetrieveBinary(temp);
	if (result == 0)
	{
		cout << "해당 ID가 없습니다." << endl;
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

//-------------------------------------------------------
void Application::AddToPlayList()
{
	PlayItemType data;
	ItemType temp;
	string id;
	cout << "id를 입력하시오 : ";
	cin >> id;
	temp.SetId(id);

	int result = m_List.RetrieveBinary(temp); // 바이너리 서치로 아이디값이 입력된 템프랑 아이디가 겹치는 아이템이 리스트에 존재할시 그 아이템을 템프에 복사
	if (result == 0)
	{
		cout << "해당 아이디를 찾을 수 없습니다." << endl;
		return;
	}
	data.SetID(id);
	
	m_PlayList.EnQueue(data); // data를 인큐
}

void Application::PrintAll()
{

	if (m_PlayList.IsEmpty())
	{
		cout << "Queue is Empty" << endl;
		return;
	}
	// 임시로 아이템 만들고
	ItemType data;
	m_PlayList.ResetList(); // m_Queue의 curpointer 초기화
	PlayItemType item;
	int Curpointer = m_PlayList.GetNextItem(item);

	while (1)
	{
		data.SetId(item.GetID()); // data 에 아이템의 아이디 받아와서
		m_List.RetrieveBinary(data); // m_list에서 해당 아이디 찾아서 data 집어넣은후
		if (Curpointer == m_PlayList.GetRear())
		{
			
			data.DisplayRecordOnScreen(); // data출력
			item.PrintPN();// 플레이 횟수 출력
			break;
		}
		data.DisplayRecordOnScreen(); 
		item.PrintPN();// 플레이 횟수 출력
		Curpointer = m_PlayList.GetNextItem(item);// 다음 아이템으로 이터레이터를 옮김
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
		cout << "플레이 리스트가 비었습니다." << endl;
		return;
	}


	while (1) {
		id = temp->GetID();
		temp->NumPlayUP(); // 플레이 횟수 업 실제값 접근해서 올려야함
		data.SetId(id);
		m_List.RetrieveBinary(data);
		data.DisplayRecordOnScreen();

		int answer;
		cout << "다음곡을 플레이 하시겠습니까? 1.yes  2.no  : ";
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
			cout << "잘못된 입력입니다." << endl;
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
	PlayItemType item; // 임시로 아이템 만들고
	item.SetIDFromKB(); // 키보드로 입력받고
	int result = m_PlayList.Delete(item);
	if (result == 0)
	{
		cout << "해당 아이디가 없습니다." << endl;
	}
	else
	{
		cout << "삭제가 완료되었습니다." << endl;
	}

}
