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

void Application::SearchByID_SequenS()
{
	int id;
	ItemType temp;
	int result;
	cout << "검색하실 ID를 입력하시오: ";
	cin >> id;
	temp.SetId(id);

	result = m_List.Retrieve_SeqS(temp);
	if (result == 0)
	{
		cout << "해당 ID를 찾지 못하였습니다." << endl;
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
	cout << "검색하실 ID를 입력하시오: ";
	cin >> id;
	temp.SetId(id);

	result = m_List.Retrieve_Binary(temp);
	if (result == 0)
	{
		cout << "해당 ID를 찾지 못하였습니다." << endl;
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
	cout << "이름을 입력하시오: ";
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
		cout << "해당하는 이름의 학생이 없습니다" << endl;
	}
	else
	{
		cout  << endl << "총 " << plag << "개의 검색결과가 나왔습니다." << endl;
	}

}



void Application::RetrieveStudent()
{
	ItemType temp;
	int id;
	int index;
	int Length = m_List.GetLength();

	cout << "ID를 입력하시오 ->";
	cin >> id;
	temp.SetId(id);
	index = m_List.Get(temp); // 인덱스에 같은 아이디의 데이터의 컬포인트 저장(Get함수 자체가 m_List 안의 데이터와 temp의 아이디를 비교하여 일치할경우 그 인덱스를 가져옴)

	if (index == -1)
	{
		cout << "해당 ID의 학생이 없습니다." << endl;
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



void Application::DeleteStudent()
{
	ItemType temp;
	int id;
	int result;

	cout << "ID를 입력하시오 ->";
	cin >> id;
	temp.SetId(id);
	result = m_List.Delete(temp);
	if (result == -1)
	{
		cout << "해당 학생이 없습니다." << endl;
	}

}

void Application::ReplaceItem()
{
	ItemType temp;
	int id;
	string name;
	string address;

	cout << "ID를 입력하시오 ->";
	cin >> id;
	cout << "수정할 이름을 입력하시오 ->";
	cin >> name;
	cout << "수정할 주소를 입력하시오 ->";
	cin >> address;
	temp.SetRecord(id, name, address);
	
	int result = m_List.Replace(temp);

	if (result == 0)
	{
		cout << "해당 학생이 없습니다." << endl;
		return;
	}

}

//------------------------------------------------------


int Application::Enqueue()
{
	if (m_Queue.IsFull())
	{
		cout << "리스트가 꽉 참!" << endl;
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
		cout << "리스트가 비어있음!" << endl;
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
		cout << "DeQueue 했습니다." << endl;

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
		cout << "EnQueue 했습니다" << endl;
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
	ItemType item; // 임시로 아이템 만들고
	
	m_Queue.ResetList(); // m_Queue의 curpointer 초기화

	int Curpointer = m_Queue.GetNextItem(item); 

	while (1)
	{
		if (Curpointer == m_Queue.GetRear()) 
		{
			item.DisplayRecordOnScreen(); // 복사된 (이터레이터가 가르키는) 아이템 출력
			break;
		}
		item.DisplayRecordOnScreen(); // 복사된 (이터레이터가 가르키는) 아이템 출력
		Curpointer = m_Queue.GetNextItem(item); // 다음 아이템으로 이터레이터를 옮김
	}
}

void Application::Search()
{
	ItemType temp;
	temp.SetIdFromKB();
	int result = m_Queue.Search(temp);
	if (result == 0)
	{
		cout << "해당 아이디를 찾지 못하였습니다." << endl;
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
		cout << "해당 아이디가 없습니다." << endl;
	}
	else
	{
		cout << "교체 완료" << endl;
	}
}

void Application::AddRecordToQL()
{
	ItemType temp;
	temp.SetIdFromKB();
	int result = m_List.Retrieve_Binary(temp); // 바이너리 서치로 아이디값이 입력된 템프랑 아이디가 겹치는 아이템이 리스트에 존재할시 그 아이템을 템프에 복사
	if (result == 0)
	{
		cout << "해당 아이디를 찾을 수 없습니다." << endl;
		return;
	}
	m_Queue.EnQueue(temp); // 템프를 인큐
}

void Application::DeleteQList()
{
	if (m_Queue.IsEmpty())
	{
		cout << "Queue is Empty" << endl;
		return;
	}
	ItemType item; // 임시로 아이템 만들고
	item.SetIdFromKB(); // 키보드로 입력받고
	int result = m_Queue.Delete(item);
	if (result == 0)
	{
		cout << "해당 아이디가 없습니다." << endl;
	}
	else
	{
		cout << "삭제가 완료되었습니다." << endl;
	}

}
