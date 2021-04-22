#include "ItemType.h"



ItemType::ItemType()
{
}


ItemType::~ItemType()
{
}

int ItemType::GetType()
{
	return m_Type;
}

string ItemType::GetName()
{
	return m_Name;
}

string ItemType::GetComposer()
{
	return m_Composer;
}

string ItemType::GetSinger()
{
	return m_Singer;
}

int ItemType::GetGenre()
{
	return m_Genre;
}

string ItemType::GetId() const
{
	return m_Id;
}

void ItemType::SetId(string id)
{
	m_Id = id;
}



void ItemType::SetRedcord(int inType, string inName, string inComp, string inSinger, int inGenre, string inId)
{
	m_Type = inType;
	m_Name = inName;
	m_Composer = inComp;
	m_Singer = inSinger;
	m_Genre = inGenre;
	m_Id = inId;
}

void ItemType::DisplayRecordOnScreen()
{
	cout << endl;
	cout << "Type(1.가요 2.연주) : " << GetType() << endl;
	cout << "Name : " << GetName() << endl;
	cout << "Composer : " << GetComposer() << endl;
	cout << "Singer : " << GetSinger() << endl;
	cout << "Genre : " << GetGenre() << endl;
	cout << "ID : " << GetId() << endl;
}


void ItemType::SetIdFromKB()
{
	string id;
	cout << "고유번호를 입력하시오: ";
	cin >> id;
	m_Id = id;
}

void ItemType::SetRecordFromKB()
{
	int type;
	string name;
	string comp;
	string singer;
	int genre;
	string id;

	cout << "Type을 입력하시오(1.가요 2.연주): ";
	cin >> type;
	
	cout << "이름을 입력하시오: ";
	cin >> name;

	cout << "작곡가를 입력하시오: ";
	cin >> comp;

	cout << "가수를 입력하시오: ";
	cin >> singer;

	cout << "장르(1.발라드 2.힙합/댄스 3.R&B 4.인디 5.락)를 입력하시오: ";
	cin >> genre;

	cout << "고유번호를 입력하시오: ";
	cin >> id;

	m_Type = type;
	m_Name = name;
	m_Composer = comp;
	m_Singer = singer;
	m_Genre = genre;
	m_Id = id;
}

int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Type >> m_Name >> m_Composer >> m_Singer >> m_Genre >> m_Id;
	return 0;
}

int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << m_Type << ' ' << m_Name << ' ' << m_Composer << ' ' << m_Singer << ' ' << m_Genre << ' ' << m_Id << endl;
	return 0;
}

RelationType ItemType::CompareByID(const ItemType& data)
{
	if (m_Id == data.m_Id)
		return EQUAL;

	else if (m_Id > data.m_Id)
		return GREATER;

	else
		return LESS;
}