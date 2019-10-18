#include "ItemType.h"



ItemType::ItemType()
{
}


ItemType::~ItemType()
{
}

int ItemType::GetId()
{
	return m_Id;
}

string ItemType::GetName()
{

	return m_sName;
}

string ItemType::GetAddress()
{
	return m_sAddress;
}

void ItemType::SetId(int inId)
{
	m_Id = inId;
}

void ItemType::SetName(string inName)
{
	m_sName = inName;
}

void ItemType::SetAddress(string inAddress)
{
	m_sAddress = inAddress;
}

void ItemType::SetRecord(int inId, string inName, string inAdddress)
{
	m_Id = inId;
	m_sName = inName;
	m_sAddress = inAdddress;

}

void ItemType::DisplayIdOnScreen()
{
	cout << endl;
	cout << "ID : " << GetId() << endl;
}

void ItemType::DisplayNameOnScreen()
{
	cout << endl;
	cout << "Name : " << GetName() << endl;
}

void ItemType::DisplayAddressOnScreen()
{
	cout << endl;
	cout << "Address : " << GetAddress() << endl;
}

void ItemType::DisplayRecordOnScreen()
{
	cout << endl;
	cout << "ID : " << GetId() << endl;
	cout << "Name : " << GetName() << endl;
	cout << "Address : " << GetAddress() << endl;
}

void ItemType::SetIdFromKB()
{
	int inId;
	cout << "ID를 입력하세요: " << endl;
	cin >> inId;
	m_Id = inId;
}

void ItemType::SetNameFromKB()
{

	string inName;
	cout << "이름을 입력하세요: " << endl;
	cin >> inName;
	m_sName = inName;
}

void ItemType::SetAddressFromKB()
{
	string inAddress;
	cout << "주소를 입력하세요: " << endl;
	cin >> inAddress;
	m_sAddress = inAddress;
}

void ItemType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
	SetAddressFromKB();
}

int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Id >> m_sName >> m_sAddress;
	return 0;
}

int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << m_Id << ' ' << m_sName << ' ' << m_sAddress << endl;
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