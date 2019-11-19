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
			cout << "1.�Ϲ����   2.�������" << endl;
			cout << "Answer : ";
			cin >> a;
			if (a == 1)
				PlayInsertOrder();
			else if (a == 2)
				ShufflePlay();
			else
				cout << "�߸��Է�!!" << endl;
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

	SingerType stemp; //�ӽ÷� �̾�Ÿ�� �������� //�����ͷ� �ȹ޴� ��� �� �Լ��� ���������� �Ҹ��ڰ� ȣ��Ǿ� ���빰�� �������� => ���α׷� �����ų�� �ѹ��� �Ҹ��ڰ� ȣ��Ǿ� ����Ծ����� ������

	string singer; 
	cout << "�˻��� �������� �Է��Ͻÿ�: ";
	cin >> singer; //������ �Է¹ް�
	stemp.SetName(singer); //�ӽ� ������ ������ ����
	int result = m_SingerList.Retrieve(stemp); // ����� 1�̸� ã���� 0�̸� ��ã����. ã���� stemp�� ���� �����. // ���⼭ stemp�� �������簡��
	if (result == 1) //ã������
	{
		stemp.Print(); //�̸� ���� ���� ����ϰ�
		if (stemp.GetSongList()->IsEmpty()) // stemp.GetSongList() �� stemp���ִ� �� ����Ʈ(id�� ����� ť)
		{
			cout << "Queue is Empty" << endl;
			return;
		}
		ItemType temp; //������Ÿ���� �ӽú���
		string data; 
		stemp.GetSongList()->ResetList(); //�������� �����ϰ�
		int CurPointer = stemp.GetSongList()->GetNextItem(data);// �������Ϳ� ���� ������Ʈ �����ϰ� data�� Songlist�� �� �޾ƿ��� data�� id�� �޾ƿ���
		while (1)
		{
			temp.SetId(data); //���̵� �����ϰ�
			m_List.RetrieveBinary(temp); // temp�� ���� ���̵� �˻��ؼ� ������ �޾ƿ�
			if (CurPointer == stemp.GetSongList()->GetRear())// �������Ϳ� ť�� rear�� ������ ����ϰ� �극��ũ
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
		cout << "�ش��ϴ� �̸��� ������ �����ϴ�." << endl;
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
	ItemType temp; //�����͸���Ʈ�� ������
	string id;

	cout << "\n\t----------Master List----------\n" << endl;
	DisplayAllMusic();
	cout << "\n\t----------Master List----------\n" << endl;

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
	cout << "\n\t----------Play List----------\n" << endl;
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
		cout << "�÷��� ����Ʈ�� ������ϴ�." << endl;
		return;
	}


	while (1) {
		id = temp.GetID();
		temp.NumPlayUP(); // �÷��� Ƚ�� �÷��ְ�
		m_PlayList.Replace(temp); // �÷��ذ� ���� ����Ʈ�����۰� ��ü
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
			Curpointer = m_PlayList.GetNextItem(temp);
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
	PrintAll();
	cout << "������ ";
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

void Application::ShufflePlay()
{
	if (m_PlayList.IsEmpty())
	{
		cout << "�÷��� ����Ʈ�� ������ϴ�." << endl;
		return;
	}
	
	
	if (m_RandomPlay.IsEmpty()) // �����÷��̸���Ʈ�� ��������� ����
	{
		int top = m_PlayList.GetTop(); // �÷��̸���Ʈ ���� ����
		UnSortedList<PlayItemType> temp(top); // ���� ������ŭ ����Ʈ ����

		PlayItemType item; //�ӽ� �÷���Ÿ�� ������ �����
		m_PlayList.ResetList();
		int Cur = m_PlayList.GetNextItem(item);

		while (1)
		{
			if (Cur == m_PlayList.GetRear())
			{
				temp.Add(item); // ����Ʈ�� ����� ������ �߰�
				break;
			}
			temp.Add(item);
			Cur = m_PlayList.GetNextItem(item);
		}
		//------ �÷��̸���Ʈ ���빰�� ����Ʈ�� �Ű�����.
		UnSortedList<PlayItemType> NewList(top); // ���ο� ����Ʈ ����(������ �̷�� ������)
		srand(time(NULL));
		int index = rand() % top;
		int* CheckArr = new int[top]; // �ε��� �ߺ��˻縦 ���� �迭
		int flag = 0;
		bool result = 0;

		while (flag != top)
		{
			result = 0;
			for (int i = 0; i <= flag; i++) //�ߺ��˻�
			{
				if (index == CheckArr[i])
				{
					result = 1; // �ߺ�
				}
			}
			switch (result)
			{
			case 0: // �ߺ��ƴϸ�
				NewList[flag] = temp[index];
				CheckArr[flag] = index; // �ε����� ��������Ƿν� �̰� �� �ε������� �Ⱦ� �ε������� üũ����
				flag++;
				index = rand() % top;
				break;

			case 1: //�ߺ��̸�
				index = rand() % top;
				break;
			}

		}
		//------------- NewList�� ���õ�.

		for (int i = 0; i < top; i++) // �����÷��̸���Ʈ�� NewList(���õ�)���� ��ť
		{
			m_RandomPlay.EnQueue(NewList[i]);
		}

		delete[] CheckArr;
	}
	//-------------------------------���⼭���� �÷��̸���Ʈ �÷��̿� ���� �� �����÷��̸���Ʈ�� �÷���
	ItemType data;
	PlayItemType item;
	m_RandomPlay.ResetList();
	int Cur = m_RandomPlay.GetNextItem(item);
	string id;
	if (m_RandomPlay.IsEmpty())
	{
		cout << "�÷��� ����Ʈ�� ������ϴ�." << endl;
		return;
	}


	while (1) {
		id = item.GetID();
		m_PlayList.Search(item);// �÷��̸���Ʈ���� �����۰� ��ġ�ϴ� �׸� �ҷ�����
		item.NumPlayUP(); // �÷��� Ƚ�� �÷��ְ�
		m_PlayList.Replace(item); // �÷��ذ� ���� ����Ʈ�����۰� ��ü
		data.SetId(id);
		m_List.RetrieveBinary(data);
		data.DisplayRecordOnScreen();

		int answer;
		cout << "�������� �÷��� �Ͻðڽ��ϱ�? 1.yes  2.no  : ";
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
			cout << "�߸��� �Է��Դϴ�." << endl;
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
	cout << "�˻��� �������� �Է��Ͻÿ� : ";
	cin >> _name;
	item.SetName(_name);
	int result = m_SingerList.Retrieve(item);
	if (result == 1)
	{
		cout << "���� �߰� �մϴ�." << endl;
		cout << "1. �����߰�" << endl;
		cout << "2. �� ����Ʈ���� �߰�" << endl;
		cout << "Command : ";
		cin >> answer;
		if (answer == 1)
		{
			cout << "\n���� ���� �߰��մϴ�.\n" << endl;
			Song.SetRecordFromKB();
			m_List.Add(Song);
			item.AddSong(Song.GetId()); // id�� ������ �뷡����Ʈ�� �߰�
			m_SingerList.Replace(item);//���÷��̽�
		}
		else if (answer == 2)
		{
			cout << "\n\t----------Master List----------\n" << endl;
			DisplayAllMusic();
			cout << "\n\t----------Master List----------\n" << endl;
			cout << "ID�� �Է��Ͻÿ� : ";
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
				cout << "�ش� ID�� �����ϴ�." << endl;
			}

		}
		else
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
	}
	else
	{
		cout << "�ش��ϴ� ������ �����ϴ�." << endl;
		
	}
}
void Application::DeleteSong()
{
	SingerType item;
	ItemType Song;
	string _name;
	cout << "�˻��� �������� �Է��Ͻÿ� : ";
	cin >> _name;
	item.SetName(_name);
	int result = m_SingerList.Retrieve(item);
	if (result == 1)
	{
		cout << "���� ���� �մϴ�." << endl;
		Song.SetIdFromKB();
		item.DeleteSong(Song.GetId()); // idã�Ƽ� �۸���Ʈ���� ����
		m_SingerList.Replace(item);//���÷��̽�
	}
	else
	{
		cout << "�ش��ϴ� ������ �����ϴ�." << endl;
	}
}

void Application::ShowFolderList()
{
	while (1) 
	{
		cout << "\t---------���� ���---------" << endl;
		if (m_FolderList.IsEmpty())
		{
			cout << "\t������ �����ϴ�.\n" << endl;
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
		case 1: //���� ����
			cout << "������ ���� ";
			tempF.SetNameFromKB();
			m_FolderList.Add(tempF);
			break;

		case 2: //���� ����
			cout << "������ ���� ";
			tempF.SetNameFromKB();
			m_FolderList.Delete(tempF);
			break;

		case 3: // ���� �̸�����
			cout << "������ ���� ";
			tempF.SetNameFromKB();
			result = m_FolderList.RetrieveBinary(tempF);
			if (result == 1)
			{
				string cname; // ������ �̸�
				cout << "������ �̸��� �Է��Ͻÿ� : ";
				cin >> cname;
				tempF.SetName(cname);
				m_FolderList.Replace(tempF);
			}
			else
			{
				cout << "�ش� �̸��� ������ ã�� �� �����ϴ�." << endl;
			}
			break;

		case 4: // ���� ����
			cout << "������ ���� ";
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
					case 1: //������ ���߰�
						cout << endl << "\t---------Master List----------" << endl;
						DisplayAllMusic();
						cout << endl << "\t---------Master List----------" << endl;

						cout << "\n�߰��� ";
						item.SetIdFromKB(); // id�����ϰ�
						result = m_List.RetrieveBinary(item); // �ش���̵��� ������ �����ͼ�
						if (result == 1)
						{
							tempF.AddSong(item); //item�� �뷡(������Ÿ��)
							m_FolderList.Replace(tempF); // temp�� ����(����Ÿ��)
						}
						else
						{
							cout << "�ش� ID�� �����ϴ�." << endl;
						}

						break;

					case 2: //�� ����
						cout << "\n������ ";
						item.SetIdFromKB();
						tempF.DeleteSong(item);
						m_FolderList.Replace(tempF);
						break;

					case 3: //�÷��� ����Ʈ�� �߰�
						cout << "\n1. ��ü �߰�" << endl;
						cout << "2. ���� �߰�" << endl;
						cout << "Command : ";
						int cm;
						cin >> cm;

						if (cm == 1)
						{
							int CurP; 
							tempF.GetSongList()->ResetList();
							while (1)
							{

								CurP = tempF.GetSongList()->GetNextItem(item); // �����۰����ͼ�
								if (CurP == tempF.GetSongList()->GetLength())
								{
									break;
								}
								PlayTemp.SetID(item.GetId()); // ���̵� �����ϰ�
								if (m_PlayList.Search(PlayTemp)== 0 )// �÷��� ����Ʈ�� ������
								{
									m_PlayList.EnQueue(PlayTemp); //�߰�
								}
							

							}
						}
						else if (cm == 2)
						{
							int check;
							cout << "\n�߰��� ";
							item.SetIdFromKB(); // ������Ÿ���� �����ۿ� id�����ϰ�
							check = tempF.GetSongList()->Retrieve(item); // �ش� id�� ������ �����ͼ� ������ 1 ������ 0����
							if (check == 1)
							{
								PlayTemp.SetID(item.GetId());
								if (m_PlayList.Search(PlayTemp))// ������
								{
									cout << "�̹� �÷��̸���Ʈ�� �����մϴ�." << endl;
								} 
								else
								{
									m_PlayList.EnQueue(PlayTemp); // ������ �߰�
								}
							}
							else
							{
								cout << "�ش� ID�� �����ϴ�." << endl;
							}
							
						}
						else
						{
							cout << "�߸��� �Է��Դϴ�." << endl;
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
				cout << "�ش� �̸��� ������ ã�� �� �����ϴ�." << endl;
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

		cout << "�÷����ϰ���� ���� ID�� �Է��Ͻÿ� : ";
		cin >> id;
		song.SetId(id);

		if (m_List.RetrieveBinary(song))
		{
			SimpleSong.SetID(id);
			if(m_PlayList.Search(SimpleSong)) // �̹� �÷��̸���Ʈ�� ���� ������
			{
				SimpleSong.NumPlayUP();
				m_PlayList.Replace(SimpleSong);
			}
			else // ������ �÷��� Ƚ�� �ø��� �÷��̸���Ʈ�� �߰�
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
			cout << "�ش��ϴ� ID�� �����ϴ�." << endl;
		}
		cout << "�ٸ� ���� �÷��� �Ͻðڽ��ϱ�? (1. Yes    2. No)" << endl;
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
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
	}

}

void Application::RecommendMusic()
{
	FolderType Ballade, Hiphop, RnB, Indie, Rock;//�߶�� ���� �Ⱦغ� �ε� ��

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
	//-----------------------------------------�帣���� ������ �з��Ϸ�------------------

	cout << "��õ ���� ���� �帣�� �Է��Ͻÿ�(1.�߶��  2.����/��  3.R&B  4.�ε�  5.��): ";
	cin >> genre;
	int RandRec; //������õ ����
	srand(time(NULL));

	switch (genre)
	{
	case 1:
		Length = Ballade.GetSongList()->GetLength();  //���� �޾Ƽ�
		if (Length == 0)
		{
			cout << "�ش� �帣�� ���� �������� �ʽ��ϴ�." << endl;
			break;
		}
		RandRec = (rand() % (Length-1))+1; //���� ���� 1~ Length ����
		Ballade.GetSongList()->ResetList();
		for (int i = 0; i < RandRec; i++) //�������� ��ŭ �ٳؽ�Ʈ������
		{
			Ballade.GetSongList()->GetNextItem(temp);
		}
		cout << "\n\t<<<< �� �뷡�� ���? >>>>" << endl;
		temp.DisplayRecordOnScreen();

		break;
	case 2:
		Length = Hiphop.GetSongList()->GetLength();
		if (Length == 0)
		{
			cout << "�ش� �帣�� ���� �������� �ʽ��ϴ�." << endl;
			break;
		}
		RandRec = (rand() % (Length - 1)) + 1;
		Hiphop.GetSongList()->ResetList();
		for (int i = 0; i < RandRec; i++)
		{
			Hiphop.GetSongList()->GetNextItem(temp);
		}
		cout << "\n\t<<<< �� �뷡�� ���? >>>>" << endl;
		temp.DisplayRecordOnScreen();

		break;
	case 3:
		Length = RnB.GetSongList()->GetLength();
		if (Length == 0)
		{
			cout << "�ش� �帣�� ���� �������� �ʽ��ϴ�." << endl;
			break;
		}
		RandRec = (rand() % (Length - 1)) + 1;
		RnB.GetSongList()->ResetList();
		for (int i = 0; i < RandRec; i++)
		{
			RnB.GetSongList()->GetNextItem(temp);
		}
		cout << "\n\t<<<< �� �뷡�� ���? >>>>" << endl;
		temp.DisplayRecordOnScreen();

		break;
	case 4:
		Length = Indie.GetSongList()->GetLength();
		if (Length == 0)
		{
			cout << "�ش� �帣�� ���� �������� �ʽ��ϴ�." << endl;
			break;
		}
		RandRec = (rand() % (Length - 1)) + 1;
		Indie.GetSongList()->ResetList();
		for (int i = 0; i < RandRec; i++)
		{
			Indie.GetSongList()->GetNextItem(temp);
		}
		cout << "\n\t<<<< �� �뷡�� ���? >>>>" << endl;
		temp.DisplayRecordOnScreen();

		break;
	case 5:

		Length = Rock.GetSongList()->GetLength();
		if (Length == 0)
		{
			cout << "�ش� �帣�� ���� �������� �ʽ��ϴ�." << endl;
			break;
		}
		RandRec = (rand() % (Length - 1)) + 1;
		Rock.GetSongList()->ResetList();
		for (int i = 0; i < RandRec; i++)
		{
			Rock.GetSongList()->GetNextItem(temp);
		}
		cout << "\n\t<<<< �� �뷡�� ���? >>>>" << endl;
		temp.DisplayRecordOnScreen();

		break;
	default:
		break;
	}
	
}
