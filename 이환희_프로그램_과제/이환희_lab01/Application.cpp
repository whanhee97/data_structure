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
			PlayMusic();
			break;

		case 12:
			int a;
			cout << "1.일반재생   2.셔플재생" << endl;
			cout << "Answer : ";
			cin >> a;
			if (a == 1)
				PlayInsertOrder();
			else if (a == 2)
				ShufflePlay();
			else
				cout << "잘못입력!!" << endl;
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
			ShowFolderList();
			break;

		case 19:
			RecommendMusic();
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
	cout << "\t  11 : Play Music" << endl;
	cout << "\t  12 : Play PlayList" << endl;
	cout << "\t  13 : Show PlayList" << endl;
	cout << "\t  14 : Delete PlayList" << endl << endl;

	cout << "\t-------- Singer --------" << endl;
	cout << "\t  15 : Add Singer" << endl;
	cout << "\t  16 : Add Song" << endl;
	cout << "\t  17 : Delete Song(Only in SongList)" << endl;

	cout << endl << "\t-------- Folder --------" << endl;
	cout << "\t  18 : Folder List" << endl;

	cout << endl << "\t-------- System --------" << endl;
	cout << "\t  19 : Recommend Music" << endl;
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

void Application::SearchBySinger()
{

	SingerType stemp; //임시로 싱어타입 변수생성 //포인터로 안받는 경우 이 함수가 끝날때마다 소멸자가 호출되어 내용물을 지워버림 => 프로그램 종료시킬때 한번더 소멸자가 호출되어 지울게없어져 에러뜸

	string singer; 
	cout << "검색할 가수명을 입력하시오: ";
	cin >> singer; //가수명 입력받고
	stemp.SetName(singer); //임시 변수에 가수명 셋팅
	int result = m_SingerList.Retrieve(stemp); // 결과가 1이면 찾은것 0이면 못찾은것. 찾으면 stemp에 값이 복사됨. // 여기서 stemp가 얕은복사가됨
	if (result == 1) //찾았으면
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
	ItemType temp; //마스터리스트의 아이템
	string id;

	cout << "\n\t----------Master List----------\n" << endl;
	DisplayAllMusic();
	cout << "\n\t----------Master List----------\n" << endl;

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
	cout << "\n\t----------Play List----------\n" << endl;
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
	cout << "\n\t----------Play List----------\n" << endl;
}


void Application::PlayInsertOrder()
{
	ItemType data;
	PlayItemType temp;
	m_PlayList.ResetList();
	int Curpointer = m_PlayList.GetNextItem(temp);
	string id;
	if (m_PlayList.IsEmpty())
	{
		cout << "플레이 리스트가 비었습니다." << endl;
		return;
	}


	while (1) {
		id = temp.GetID();
		temp.NumPlayUP(); // 플레이 횟수 올려주고
		m_PlayList.Replace(temp); // 올려준거 실제 리스트아이템과 교체
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
			Curpointer = m_PlayList.GetNextItem(temp);
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
	PrintAll();
	cout << "삭제할 ";
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

void Application::ShufflePlay()
{
	if (m_PlayList.IsEmpty())
	{
		cout << "플레이 리스트가 비었습니다." << endl;
		return;
	}
	
	
	if (m_RandomPlay.IsEmpty()) // 랜덤플레이리스트가 비어있으면 실행
	{
		int top = m_PlayList.GetTop(); // 플레이리스트 음악 개수
		UnSortedList<PlayItemType> temp(top); // 음악 개수만큼 리스트 생성

		PlayItemType item; //임시 플레이타입 아이템 만들고
		m_PlayList.ResetList();
		int Cur = m_PlayList.GetNextItem(item);

		while (1)
		{
			if (Cur == m_PlayList.GetRear())
			{
				temp.Add(item); // 리스트에 갖고온 아이템 추가
				break;
			}
			temp.Add(item);
			Cur = m_PlayList.GetNextItem(item);
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
			m_RandomPlay.EnQueue(NewList[i]);
		}

		delete[] CheckArr;
	}
	//-------------------------------여기서부턴 플레이리스트 플레이와 동일 단 랜덤플레이리스트를 플레이
	ItemType data;
	PlayItemType item;
	m_RandomPlay.ResetList();
	int Cur = m_RandomPlay.GetNextItem(item);
	string id;
	if (m_RandomPlay.IsEmpty())
	{
		cout << "플레이 리스트가 비었습니다." << endl;
		return;
	}


	while (1) {
		id = item.GetID();
		m_PlayList.Search(item);// 플레이리스트에서 아이템과 일치하는 항목 불러오기
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
			if (Cur == m_RandomPlay.GetRear())
			{
				m_RandomPlay.ResetList();
			}
			Cur = m_RandomPlay.GetNextItem(item);
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
	m_SingerList.AddItem(item);
}

void Application::AddSong()
{
	SingerType item;
	ItemType Song;
	string _name;
	string _id;
	int answer;
	cout << "검색할 가수명을 입력하시오 : ";
	cin >> _name;
	item.SetName(_name);
	int result = m_SingerList.Retrieve(item);
	if (result == 1)
	{
		cout << "곡을 추가 합니다." << endl;
		cout << "1. 직접추가" << endl;
		cout << "2. 곡 리스트에서 추가" << endl;
		cout << "Command : ";
		cin >> answer;
		if (answer == 1)
		{
			cout << "\n곡을 직접 추가합니다.\n" << endl;
			Song.SetRecordFromKB();
			m_List.Add(Song);
			item.AddSong(Song.GetId()); // id만 가수의 노래리스트에 추가
			m_SingerList.Replace(item);//리플레이스
		}
		else if (answer == 2)
		{
			cout << "\n\t----------Master List----------\n" << endl;
			DisplayAllMusic();
			cout << "\n\t----------Master List----------\n" << endl;
			cout << "ID를 입력하시오 : ";
			cin >> _id;
			Song.SetId(_id);
			result = m_List.RetrieveBinary(Song);
			if (result == 1)
			{
				item.AddSong(_id);
				m_SingerList.Replace(item);
			}
			else
			{
				cout << "해당 ID가 없습니다." << endl;
			}

		}
		else
		{
			cout << "잘못된 입력입니다." << endl;
		}
	}
	else
	{
		cout << "해당하는 가수가 없습니다." << endl;
		
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
	int result = m_SingerList.Retrieve(item);
	if (result == 1)
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

void Application::ShowFolderList()
{
	while (1) 
	{
		cout << "\t---------폴더 목록---------" << endl;
		if (m_FolderList.IsEmpty())
		{
			cout << "\t폴더가 없습니다.\n" << endl;
		}
		else
		{
			for (int i = 0; i < m_FolderList.GetLength(); i++)
			{
				cout << "\t[ " << m_FolderList[i].GetName() << " ]" << endl;
			}
		}
		//------------------------------------

		int answer;
		cout << "\t--------Command---------" << endl;
		cout << "\t   1 : Create Folder" << endl;
		cout << "\t   2 : Delete Folder" << endl;
		cout << "\t   3 : ReName Folder" << endl;
		cout << "\t   4 : Access Folder" << endl;
		cout << "\t   5 : Exit" << endl;
		cout << endl << "\t Choose a Command--> ";
		cin >> answer;
		
		FolderType tempF;
		PlayItemType PlayTemp;
		ItemType item;


		int result;
		switch (answer)
		{
		case 1: //폴더 생성
			cout << "생성할 폴더 ";
			tempF.SetNameFromKB();
			m_FolderList.Add(tempF);
			break;

		case 2: //폴더 삭제
			cout << "삭제할 폴더 ";
			tempF.SetNameFromKB();
			m_FolderList.Delete(tempF);
			break;

		case 3: // 폴더 이름변경
			cout << "변경할 폴더 ";
			tempF.SetNameFromKB();
			result = m_FolderList.RetrieveBinary(tempF);
			if (result == 1)
			{
				string cname; // 변경할 이름
				cout << "변경할 이름을 입력하시오 : ";
				cin >> cname;
				tempF.SetName(cname);
				m_FolderList.Replace(tempF);
			}
			else
			{
				cout << "해당 이름의 폴더를 찾을 수 없습니다." << endl;
			}
			break;

		case 4: // 폴더 접근
			cout << "접근할 폴더 ";
			tempF.SetNameFromKB();
			result = m_FolderList.RetrieveBinary(tempF);
			if (result == 1)
			{
				while (1)
				{
					cout << endl << "\t------------[ " << tempF.GetName() << " ]------------" << endl;
					
					tempF.DisplayAllSong();
					
					cout << endl << "\t------------[ " << tempF.GetName() << " ]------------" << endl;

					cout << "1. Add Song" << endl;
					cout << "2. Delete Song" << endl;
					cout << "3. Add to PlayList" << endl;
					cout << "4. Exit" << endl;
					cout << "Your Command : ";
					cin >> answer;
					
					if (answer == 4)
					{
						break;
					}
					switch (answer)
					{
					case 1: //폴더에 곡추가
						cout << endl << "\t---------Master List----------" << endl;
						DisplayAllMusic();
						cout << endl << "\t---------Master List----------" << endl;

						cout << "\n추가할 ";
						item.SetIdFromKB(); // id셋팅하고
						result = m_List.RetrieveBinary(item); // 해당아이디의 아이템 가져와서
						if (result == 1)
						{
							tempF.AddSong(item); //item은 노래(아이템타입)
							m_FolderList.Replace(tempF); // temp는 폴더(폴더타입)
						}
						else
						{
							cout << "해당 ID가 없습니다." << endl;
						}

						break;

					case 2: //곡 삭제
						cout << "\n삭제할 ";
						item.SetIdFromKB();
						tempF.DeleteSong(item);
						m_FolderList.Replace(tempF);
						break;

					case 3: //플레이 리스트에 추가
						cout << "\n1. 전체 추가" << endl;
						cout << "2. 개별 추가" << endl;
						cout << "Command : ";
						int cm;
						cin >> cm;

						if (cm == 1)
						{
							int CurP; 
							tempF.GetSongList()->ResetList();
							while (1)
							{

								CurP = tempF.GetSongList()->GetNextItem(item); // 아이템가져와서
								if (CurP == tempF.GetSongList()->GetLength())
								{
									break;
								}
								PlayTemp.SetID(item.GetId()); // 아이디 셋팅하고
								if (m_PlayList.Search(PlayTemp)== 0 )// 플레이 리스트에 없으면
								{
									m_PlayList.EnQueue(PlayTemp); //추가
								}
							

							}
						}
						else if (cm == 2)
						{
							int check;
							cout << "\n추가할 ";
							item.SetIdFromKB(); // 아이템타입의 아이템에 id셋팅하고
							check = tempF.GetSongList()->Retrieve(item); // 해당 id의 아이템 가져와서 있으면 1 없으면 0리턴
							if (check == 1)
							{
								PlayTemp.SetID(item.GetId());
								if (m_PlayList.Search(PlayTemp))// 있으면
								{
									cout << "이미 플레이리스트에 존재합니다." << endl;
								} 
								else
								{
									m_PlayList.EnQueue(PlayTemp); // 없으면 추가
								}
							}
							else
							{
								cout << "해당 ID가 없습니다." << endl;
							}
							
						}
						else
						{
							cout << "잘못된 입력입니다." << endl;
						}
						break;

					default:
						cout << "\tIllegal selection...\n";
						break;

					}
				}

				
			}
			else
			{
				cout << "해당 이름의 폴더를 찾을 수 없습니다." << endl;
			}
			break;
		
		case 5:
			return;

		default:
			cout << "\tIllegal selection...\n";
			break;

		}
		

	}
}

void Application::PlayMusic()
{
	string id;
	ItemType song;
	PlayItemType SimpleSong;
	int answer;
	while (1)
	{
		cout << "\n\t----------Master List----------\n" << endl;
		DisplayAllMusic();
		cout << "\n\t----------Master List----------\n" << endl;

		cout << "플레이하고싶은 곡의 ID를 입력하시오 : ";
		cin >> id;
		song.SetId(id);

		if (m_List.RetrieveBinary(song))
		{
			SimpleSong.SetID(id);
			if(m_PlayList.Search(SimpleSong)) // 이미 플레이리스트에 곡이 있으면
			{
				SimpleSong.NumPlayUP();
				m_PlayList.Replace(SimpleSong);
			}
			else // 없으면 플레이 횟수 늘리고 플레이리스트에 추가
			{
				if (SimpleSong.GetNumPlay() == 0)
				{
					SimpleSong.NumPlayUP();
				}
				m_PlayList.EnQueue(SimpleSong);
			}
			song.DisplayRecordOnScreen();
		}
		else
		{
			cout << "해당하는 ID가 없습니다." << endl;
		}
		cout << "다른 곡을 플레이 하시겠습니까? (1. Yes    2. No)" << endl;
		cout << "Answer : ";
		cin >> answer;
		if (answer == 1)
		{
			continue;
		}
		else if (answer == 2)
		{
			break;
		}
		else
		{
			cout << "잘못된 입력입니다." << endl;
		}
	}

}

void Application::RecommendMusic()
{
	FolderType Ballade, Hiphop, RnB, Indie, Rock;//발라드 힙합 안앤비 인디 락

	ItemType temp;
	int genre;
	int Length = m_List.GetLength();

	m_List.ResetList();
	int Curpointer = m_List.GetNextItem(temp);
	genre = temp.GetGenre();

	while (Curpointer < Length && Curpointer != -1)
	{
		if (temp.GetGenre() == 1)
		{
			Ballade.AddSong(temp);
		}
		else if (temp.GetGenre() == 2)
		{
			Hiphop.AddSong(temp);
		}
		else if (temp.GetGenre() == 3)
		{
			RnB.AddSong(temp);
		}
		else if (temp.GetGenre() == 4)
		{
			Indie.AddSong(temp);
		}
		else
		{
			Rock.AddSong(temp);
		}
		Curpointer = m_List.GetNextItem(temp);
		genre = temp.GetGenre();
	}
	//-----------------------------------------장르별로 폴더에 분류완료------------------

	cout << "추천 받을 곡의 장르를 입력하시오(1.발라드  2.힙합/댄스  3.R&B  4.인디  5.락): ";
	cin >> genre;
	int RandRec; //랜덤추천 변수
	srand(time(NULL));

	switch (genre)
	{
	case 1:
		Length = Ballade.GetSongList()->GetLength();  //길이 받아서
		if (Length == 0)
		{
			cout << "해당 장르의 곡이 존재하지 않습니다." << endl;
			break;
		}
		RandRec = (rand() % (Length-1))+1; //랜덤 변수 1~ Length 저장
		Ballade.GetSongList()->ResetList();
		for (int i = 0; i < RandRec; i++) //랜덤변수 만큼 겟넥스트아이템
		{
			Ballade.GetSongList()->GetNextItem(temp);
		}
		cout << "\n\t<<<< 이 노래는 어때요? >>>>" << endl;
		temp.DisplayRecordOnScreen();

		break;
	case 2:
		Length = Hiphop.GetSongList()->GetLength();
		if (Length == 0)
		{
			cout << "해당 장르의 곡이 존재하지 않습니다." << endl;
			break;
		}
		RandRec = (rand() % (Length - 1)) + 1;
		Hiphop.GetSongList()->ResetList();
		for (int i = 0; i < RandRec; i++)
		{
			Hiphop.GetSongList()->GetNextItem(temp);
		}
		cout << "\n\t<<<< 이 노래는 어때요? >>>>" << endl;
		temp.DisplayRecordOnScreen();

		break;
	case 3:
		Length = RnB.GetSongList()->GetLength();
		if (Length == 0)
		{
			cout << "해당 장르의 곡이 존재하지 않습니다." << endl;
			break;
		}
		RandRec = (rand() % (Length - 1)) + 1;
		RnB.GetSongList()->ResetList();
		for (int i = 0; i < RandRec; i++)
		{
			RnB.GetSongList()->GetNextItem(temp);
		}
		cout << "\n\t<<<< 이 노래는 어때요? >>>>" << endl;
		temp.DisplayRecordOnScreen();

		break;
	case 4:
		Length = Indie.GetSongList()->GetLength();
		if (Length == 0)
		{
			cout << "해당 장르의 곡이 존재하지 않습니다." << endl;
			break;
		}
		RandRec = (rand() % (Length - 1)) + 1;
		Indie.GetSongList()->ResetList();
		for (int i = 0; i < RandRec; i++)
		{
			Indie.GetSongList()->GetNextItem(temp);
		}
		cout << "\n\t<<<< 이 노래는 어때요? >>>>" << endl;
		temp.DisplayRecordOnScreen();

		break;
	case 5:

		Length = Rock.GetSongList()->GetLength();
		if (Length == 0)
		{
			cout << "해당 장르의 곡이 존재하지 않습니다." << endl;
			break;
		}
		RandRec = (rand() % (Length - 1)) + 1;
		Rock.GetSongList()->ResetList();
		for (int i = 0; i < RandRec; i++)
		{
			Rock.GetSongList()->GetNextItem(temp);
		}
		cout << "\n\t<<<< 이 노래는 어때요? >>>>" << endl;
		temp.DisplayRecordOnScreen();

		break;
	default:
		break;
	}
	
}
