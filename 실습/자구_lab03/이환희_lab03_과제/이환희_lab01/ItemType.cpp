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
	cout << "Type(1.���� 2.����) : " << GetType() << endl;
	cout << "Name : " << GetName() << endl;
	cout << "Composer : " << GetComposer() << endl;
	cout << "Singer : " << GetSinger() << endl;
	cout << "Genre : " << GetGenre() << endl;
	cout << "ID : " << GetId() << endl;
}


void ItemType::SetIdFromKB()
{
	string id;
	cout << "������ȣ�� �Է��Ͻÿ�: ";
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

	cout << "Type�� �Է��Ͻÿ�(1.���� 2.����): ";
	cin >> type;
	
	cout << "�̸��� �Է��Ͻÿ�: ";
	cin >> name;

	cout << "�۰�� �Է��Ͻÿ�: ";
	cin >> comp;

	cout << "������ �Է��Ͻÿ�: ";
	cin >> singer;

	cout << "�帣(1.�߶�� 2.����/�� 3.R&B 4.�ε� 5.��)�� �Է��Ͻÿ�: ";
	cin >> genre;

	cout << "������ȣ�� �Է��Ͻÿ�: ";
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