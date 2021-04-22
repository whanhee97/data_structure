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
	int result = m_SingerList.Get(stemp); // ����� 1�̸� ã���� 0�̸� ��ã����. ã���� stemp�� ���� �����. // ���⼭ stemp�� �������簡��
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
	
	m_PlayList.Add(data); // data�� �߰�
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
	DoublyIterator<PlayItemType> itor(m_PlayList);
	PlayItemType item;
	item = itor.Next(); // 
	
	

	while (itor.NextNotNull())
	{
		data.SetId(item.GetID()); // data �� �������� ���̵� �޾ƿͼ�
		m_List.RetrieveBinary(data); // m_list���� �ش� ���̵� ã�Ƽ� data ���������
		data.DisplayRecordOnScreen(); 
		item.PrintPN();// �÷��� Ƚ�� ���
		item = itor.Next();// ���� ���������� ���ͷ����͸� �ű�
	}
}


void Application::PlayInsertOrder() // �÷��̸���Ʈ �߰��� ������ play
{
	ItemType data;
	PlayItemType temp;
	DoublyIterator<PlayItemType> itor(m_PlayList);
	temp = itor.Next();
	string id;
	if (m_PlayList.IsEmpty())
	{
		cout << "�÷��� ����Ʈ�� ������ϴ�." << endl;
		return;
	}


	while (1)
	{
		id = temp.GetID();
		temp.NumPlayUP(); // �÷��� Ƚ�� ��
		m_PlayList.Replace(temp); // Ƚ�� �� �������Ƿ� ��ü
		
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
			if (itor.IsNextLast()) // �ؽ�Ʈ�� ��Ʈ��
			{
				itor.First();
			}
			temp = itor.Next();
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			return;
		}
	}
}

void Application::PlayIOFreq()
{
	if (m_PlayList.IsEmpty())
	{
		cout << "�÷��� ����Ʈ�� ������ϴ�." << endl;
		return;
	}

	UnSortedList<PlayItemType> tempList(m_PlayList.GetLength());
	DoublyIterator<PlayItemType> itor(m_PlayList);
	itor.Next();
	while (itor.NextNotNull())
	{
		tempList.Add(itor.GetCurrentNode().info);
		itor.Next();
	} //���ο� ����Ʈ�� �� �ű��

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
	//��������

	for (int i = 0; i < tempList.GetLength(); i++)
	{
		m_PLSortedByFreq.Add(tempList[i]);
	}
	//����Ʈ�� �߰��ϰ�

	//���⼭ ���ʹ� ���--------------------------------------
	ItemType data;
	DoublyIterator<PlayItemType> itor1(m_PLSortedByFreq);
	temp = itor1.Next();
	string id;


	while (1)
	{
		id = temp.GetID();
		temp.NumPlayUP(); // �÷��� Ƚ�� ��
		m_PLSortedByFreq.Replace(temp); // Ƚ�� �� �������Ƿ� ��ü
		m_PlayList.Replace(temp); // �÷��� ����Ʈ�� ��ü


		data.SetId(id);
		m_List.RetrieveBinary(data);
		data.DisplayRecordOnScreen();
		temp.PrintPN();

		int answer;
		cout << "�������� �÷��� �Ͻðڽ��ϱ�? 1.yes  2.no  : ";
		cin >> answer;

		if (answer == 2)
		{
			return;
		}
		else if (answer == 1)
		{
			if (itor1.IsNextLast()) // �ؽ�Ʈ�� ��Ʈ��
			{
				itor1.First();
			}
			temp = itor1.Next();
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

void Application::SufflePlay()
{
	if (m_PlayList.IsEmpty())
	{
		cout << "�÷��� ����Ʈ�� ������ϴ�." << endl;
		return;
	}


	if (m_RandomPlay.IsEmpty()) // �����÷��̸���Ʈ�� ��������� ����
	{
		int top = m_PlayList.GetLength();
		UnSortedList<PlayItemType> temp(top); // ���� ������ŭ ����Ʈ ����
		
		PlayItemType item; //�ӽ� �÷���Ÿ�� ������ �����
		DoublyIterator<PlayItemType> itor(m_PlayList);
		itor.Next();

		while (itor.NextNotNull())
		{
			temp.Add(itor.GetCurrentNode().info);
			itor.Next();
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
			m_RandomPlay.Add(NewList[i]);
		}

		delete[] CheckArr;
	}
	//-------------------------------���⼭���� �÷��̸���Ʈ �÷��̿� ���� �� �����÷��̸���Ʈ�� �÷���
	ItemType data;
	PlayItemType item;
	DoublyIterator<PlayItemType> itor1(m_RandomPlay);
	item = itor1.Next();
	string id;
	if (m_RandomPlay.IsEmpty())
	{
		cout << "�÷��� ����Ʈ�� ������ϴ�." << endl;
		return;
	}


	while (1) 
	{
		id = item.GetID();
		m_PlayList.Get(item);// �÷��̸���Ʈ���� �����۰� ��ġ�ϴ� �׸� �ҷ�����
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
			if (itor1.IsNextLast()) // �ؽ�Ʈ�� ��Ʈ��
			{
				itor1.First();
			}
			item = itor1.Next();
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
	m_SingerList.Add(item);
}

void Application::AddSong()
{
	SingerType item;
	ItemType Song;
	string _name;
	cout << "�˻��� �������� �Է��Ͻÿ� : ";
	cin >> _name;
	item.SetName(_name);
	int result = m_SingerList.Get(item);
	if (result == 1)
	{
		cout << "���� �߰� �մϴ�." << endl;
		Song.SetRecordFromKB();
		m_List.Add(Song);
		item.AddSong(Song.GetId()); // id�� ������ �뷡����Ʈ�� �߰�
		m_SingerList.Replace(item);//���÷��̽�
	}
	else
	{
		cout << "�ش��ϴ� ������ �����ϴ�. ������ �߰��մϴ�." << endl;
		AddSinger(); // �����߰��ϰ�
		m_SingerList.Get(item); // �ٽ� ã�Ƽ� item�� �������
		cout << "���� �߰� �մϴ�." << endl;
		Song.SetRecordFromKB(); 
		m_List.Add(Song); //�뷡 �߰�
		item.AddSong(Song.GetId());
		m_SingerList.Replace(item);
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
	int result = m_SingerList.Get(item);
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