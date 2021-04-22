#include "PlayItemType.h"

PlayItemType::PlayItemType()
{
	NumPlay = 0;
}

PlayItemType::~PlayItemType()
{
}

string PlayItemType::GetID()
{
	return m_ID;
}

int PlayItemType::GetNumPlay()
{
	return NumPlay;
}

int PlayItemType::GetIntime()
{
	return InTime;
}

void PlayItemType::SetID(string id)
{
	m_ID = id;
}

void PlayItemType::SetIDFromKB()
{
	string id;
	cout << "ID를 입력하시오 : ";
	cin >> id;
	m_ID = id;
}

void PlayItemType::SetInTime(int it)
{
	InTime = it;
}

void PlayItemType::PrintPN()
{
	cout << "플레이 횟수 : " << NumPlay << endl;
}

void PlayItemType::NumPlayUP()
{
	NumPlay++;
}


RelationType PlayItemType::CompareByID(const PlayItemType& data)
{
	if (m_ID == data.m_ID)
		return EQUAL;

	else if (m_ID > data.m_ID)
		return GREATER;

	else
		return LESS;
}

RelationType PlayItemType::CompareByID(const ItemType& data)
{
	if (m_ID == data.GetId())
		return EQUAL;

	else if (m_ID > data.GetId())
		return GREATER;

	else
		return LESS;
}

bool PlayItemType::operator==(PlayItemType& data)
{
	return (this->m_ID == data.GetID());
}

bool PlayItemType::operator>(PlayItemType& data)
{
	return (this->m_ID > data.GetID());
}

bool PlayItemType::operator<(PlayItemType& data)
{
	return (this->m_ID < data.GetID());
}


