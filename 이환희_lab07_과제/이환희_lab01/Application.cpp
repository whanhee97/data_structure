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

		case 15:
			AddSinger();
			break;
		
		case 16:
			AddSong();
			break;
		
		case 17:
			DeleteSong();
			break;

		case 18:
			PlayIOFreq();
			break;
		
		case 19:
			SufflePlay();
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
	cout << "\t  11 : Play PlayList(Add Time)" << endl;
	cout << "\t  12 : Add To PlayList" << endl;
	cout << "\t  13 : Show PlayList" << endl;
	cout << "\t  14 : Delete PlayList" << endl;
	cout << "\t  18 : Play PlayList(Frequency)" << endl;
	cout << "\t  19 : Play PlayList(Suffle)" << endl << endl;

	cout << "\t-------- Singer --------" << endl;
	cout << "\t  15 : Add Singer" << endl;
	cout << "\t  16 : Add Song" << endl;
	cout << "\t  17 : Delete Song(Only in SongList)" << endl;

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

	SingerType stemp; //임시로 싱어타입 변수생성 //포인터로 안받는 경우 이 함수가 끝날때마다 소멸자가 호출되어 내용물을 지워버림 => 프로그램 종료시킬때 한번더 소멸자가 호출되어 지울게없어져 에러뜸

	string singer; 
	cout << "검색할 가수명을 입력하시오: ";
	cin >> singer; //가수명 입력받고
	stemp.SetName(singer); //임시 변수에 가수명 셋팅
	bool found = false;
	m_SingerList.Retrieve(stemp,found); // 결과가 1이면 찾은것 0이면 못찾은것. 찾으면 stemp에 값이 복사됨. // 여기서 stemp가 얕은복사가됨
	if (found == true) //찾았으면
	{
		stemp.Print(); //이름 나이 성별 출력하고
		if (stemp.GetSongList()->IsEmpty()) // stemp.GetSongList() 는 stemp에있는 곡 리스트(id만 저장된 큐)
		{
			cout << "Queue is Empty" << endl;
			return;
		}
		ItemType temp; //아이템타입의 임시변수
		string data; 
		stemp.GetSongList()->ResetList(); //컬포인터 리셋하고
		int CurPointer = stemp.GetSongList()->GetNextItem(data);// 컬포인터에 현재 컬포인트 저장하고 data에 Songlist의 값 받아오기 data에 id가 받아와짐
		while (1)
		{
			temp.SetId(data); //아이디 셋팅하고
			m_List.RetrieveBinary(temp); // temp와 같은 아이디 검색해서 있으면 받아옴
			if (CurPointer == stemp.GetSongList()->GetRear())// 컬포인터와 큐의 rear가 같으면 출력하고 브레이크
			{
				temp.DisplayRecordOnScreen();
				break;
			}
			temp.DisplayRecordOnScreen();
			CurPointer = stemp.GetSongList()->GetNextItem(data);

		}
	}
	else
	{
		cout << "해당하는 이름의 가수가 없습니다." << endl;
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
	
	m_PlayList.Add(data); // data를 추가
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
	DoublyIterator<PlayItemType> itor(m_PlayList);
	PlayItemType item;
	item = itor.Next(); // 
	
	

	while (itor.NextNotNull())
	{
		data.SetId(item.GetID()); // data 에 아이템의 아이디 받아와서
		m_List.RetrieveBinary(data); // m_list에서 해당 아이디 찾아서 data 집어넣은후
		data.DisplayRecordOnScreen(); 
		item.PrintPN();// 플레이 횟수 출력
		item = itor.Next();// 다음 아이템으로 이터레이터를 옮김
	}
}


void Application::PlayInsertOrder() // 플레이리스트 추가된 순으로 play
{
	ItemType data;
	PlayItemType temp;
	DoublyIterator<PlayItemType> itor(m_PlayList);
	temp = itor.Next();
	string id;
	if (m_PlayList.IsEmpty())
	{
		cout << "플레이 리스트가 비었습니다." << endl;
		return;
	}


	while (1)
	{
		id = temp.GetID();
		temp.NumPlayUP(); // 플레이 횟수 업
		m_PlayList.Replace(temp); // 횟수 업 해줬으므로 교체
		
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
			if (itor.IsNextLast()) // 넥스트가 라스트면
			{
				itor.First();
			}
			temp = itor.Next();
		}
		else
		{
			cout << "잘못된 입력입니다." << endl;
			return;
		}
	}
}

void Application::PlayIOFreq()
{
	if (m_PlayList.IsEmpty())
	{
		cout << "플레이 리스트가 비었습니다." << endl;
		return;
	}

	UnSortedList<PlayItemType> tempList(m_PlayList.GetLength());
	DoublyIterator<PlayItemType> itor(m_PlayList);
	itor.Next();
	while (itor.NextNotNull())
	{
		tempList.Add(itor.GetCurrentNode().info);
		itor.Next();
	} //새로운 리스트에 다 옮기고

	int index = 0, cur, max;
	PlayItemType temp;
	while (index != m_PlayList.GetLength()-1)
	{
		cur = index + 1;
		max = index;
		while (cur != m_PlayList.GetLength())
		{
			if (tempList[cur].GetNumPlay() > tempList[max].GetNumPlay())
			{
				max = cur;
			}
			cur++;
		}
		temp = tempList[index];
		tempList[index] = tempList[max];
		tempList[max] = temp;
		index++;
	}
	//선택정렬

	for (int i = 0; i < tempList.GetLength(); i++)
	{
		m_PLSortedByFreq.Add(tempList[i]);
	}
	//리스트에 추가하고

	//여기서 부터는 출력--------------------------------------
	ItemType data;
	DoublyIterator<PlayItemType> itor1(m_PLSortedByFreq);
	temp = itor1.Next();
	string id;


	while (1)
	{
		id = temp.GetID();
		temp.NumPlayUP(); // 플레이 횟수 업
		m_PLSortedByFreq.Replace(temp); // 횟수 업 해줬으므로 교체
		m_PlayList.Replace(temp); // 플레이 리스트도 교체


		data.SetId(id);
		m_List.RetrieveBinary(data);
		data.DisplayRecordOnScreen();
		temp.PrintPN();

		int answer;
		cout << "다음곡을 플레이 하시겠습니까? 1.yes  2.no  : ";
		cin >> answer;

		if (answer == 2)
		{
			return;
		}
		else if (answer == 1)
		{
			if (itor1.IsNextLast()) // 넥스트가 라스트면
			{
				itor1.First();
			}
			temp = itor1.Next();
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

void Application::SufflePlay()
{
	if (m_PlayList.IsEmpty())
	{
		cout << "플레이 리스트가 비었습니다." << endl;
		return;
	}


	if (m_RandomPlay.IsEmpty()) // 랜덤플레이리스트가 비어있으면 실행
	{
		int top = m_PlayList.GetLength();
		UnSortedList<PlayItemType> temp(top); // 음악 개수만큼 리스트 생성
		
		PlayItemType item; //임시 플레이타입 아이템 만들고
		DoublyIterator<PlayItemType> itor(m_PlayList);
		itor.Next();

		while (itor.NextNotNull())
		{
			temp.Add(itor.GetCurrentNode().info);
			itor.Next();
		}
		//------ 플레이리스트 내용물이 리스트로 옮겨졌음.

		UnSortedList<PlayItemType> NewList(top); // 새로운 리스트 생성(셔플이 이루어 질것임)
		srand(time(NULL));
		int index = rand() % top;
		int* CheckArr = new int[top]; // 인덱스 중복검사를 위한 배열
		int flag = 0;
		bool result = 0;

		while (flag != top)
		{
			result = 0;
			for (int i = 0; i <= flag; i++) //중복검사
			{
				if (index == CheckArr[i])
				{
					result = 1; // 중복
				}
			}
			switch (result)
			{
			case 0: // 중복아니면
				NewList[flag] = temp[index];
				CheckArr[flag] = index; // 인덱스를 집어넣으므로써 이게 쓴 인덱스인지 안쓴 인덱스인지 체크가능
				flag++;
				index = rand() % top;
				break;

			case 1: //중복이면
				index = rand() % top;
				break;
			}

		}
		//------------- NewList가 셔플됨.

		for (int i = 0; i < top; i++) // 랜덤플레이리스트에 NewList(셔플된)내용 인큐
		{
			m_RandomPlay.Add(NewList[i]);
		}

		delete[] CheckArr;
	}
	//-------------------------------여기서부턴 플레이리스트 플레이와 동일 단 랜덤플레이리스트를 플레이
	ItemType data;
	PlayItemType item;
	DoublyIterator<PlayItemType> itor1(m_RandomPlay);
	item = itor1.Next();
	string id;
	if (m_RandomPlay.IsEmpty())
	{
		cout << "플레이 리스트가 비었습니다." << endl;
		return;
	}


	while (1) 
	{
		id = item.GetID();
		m_PlayList.Get(item);// 플레이리스트에서 아이템과 일치하는 항목 불러오기
		item.NumPlayUP(); // 플레이 횟수 올려주고
		m_PlayList.Replace(item); // 올려준거 실제 리스트아이템과 교체
		data.SetId(id);
		m_List.RetrieveBinary(data);
		data.DisplayRecordOnScreen();

		int answer;
		cout << "다음곡을 플레이 하시겠습니까? 1.yes  2.no  : ";
		cin >> answer;

		if (answer == 2)
		{
			m_RandomPlay.MakeEmpty();
			return;
		}
		else if (answer == 1)
		{
			if (itor1.IsNextLast()) // 넥스트가 라스트면
			{
				itor1.First();
			}
			item = itor1.Next();
		}
		else
		{
			cout << "잘못된 입력입니다." << endl;
			return;
		}
	}

}



void Application::AddSinger()
{
	SingerType item;
	item.SetRecordByKB();
	m_SingerList.Add(item);
}

void Application::AddSong()
{
	SingerType item;
	ItemType Song;
	string _name;
	cout << "검색할 가수명을 입력하시오 : ";
	cin >> _name;
	item.SetName(_name);
	bool found = false;
	m_SingerList.Retrieve(item,found);
	if (found == true)
	{
		cout << "곡을 추가 합니다." << endl;
		Song.SetRecordFromKB();
		m_List.Add(Song);
		item.AddSong(Song.GetId()); // id만 가수의 노래리스트에 추가
		m_SingerList.Replace(item);//리플레이스
	}
	else
	{
		cout << "해당하는 가수가 없습니다. 가수를 추가합니다." << endl;
		AddSinger(); // 가수추가하고
		m_SingerList.Retrieve(item,found); // 다시 찾아서 item값 갖고온후
		cout << "곡을 추가 합니다." << endl;
		Song.SetRecordFromKB(); 
		m_List.Add(Song); //노래 추가
		item.AddSong(Song.GetId());
		m_SingerList.Replace(item);
	}
}
void Application::DeleteSong()
{
	SingerType item;
	ItemType Song;
	string _name;
	cout << "검색할 가수명을 입력하시오 : ";
	cin >> _name;
	item.SetName(_name);
	bool found = false;
	m_SingerList.Retrieve(item,found);
	if (found == true)
	{
		cout << "곡을 제거 합니다." << endl;
		Song.SetIdFromKB();
		item.DeleteSong(Song.GetId()); // id찾아서 송리스트에서 제거
		m_SingerList.Replace(item);//리플레이스
	}
	else
	{
		cout << "해당하는 가수가 없습니다." << endl;
	}
}