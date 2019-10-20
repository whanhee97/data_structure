#include "SingerType.h"

SingerType::SingerType()
{
}


SingerType::~SingerType()
{
}

SingerType::SingerType(const SingerType& S)
{
	name = S.name;
	age = S.age;
	sex = S.sex;
	SongList = S.SongList; // ���� ���簡 �Ͼ����
}

string SingerType::GetName()
{
	return name;
}

int SingerType::GetAge()
{
	return age;
}

int SingerType::GetSex()
{
	return sex;
}

CircularQueueType<string>* SingerType::GetSongList()
{
	return &SongList;
}

void SingerType::SetName(string _name)
{
	name = _name;
}

void SingerType::SetAge(int _age)
{
	age = _age;
}

void SingerType::SetSex(int _sex)
{
	sex = _sex;
}

void SingerType::SetRecordByKB()
{
	string iname;
	int iage;
	int isex;
	cout << "�̸��� �Է����ּ��� : ";
	cin >> iname;

	cout << "���̸� �Է����ּ��� : ";
	cin >> iage;

	cout << "������ �Է����ּ���(1.���� 2.����) : ";
	cin >> isex;

	SetName(iname);
	SetAge(iage);
	SetSex(isex);
}

void SingerType::AddSong(string _id)
{
	SongList.EnQueue(_id);
}

void SingerType::DeleteSong(string _id)
{
	SongList.Delete(_id);
}

bool SingerType::operator==(SingerType& data)
{
	return (this->name == data.GetName());
}

bool SingerType::operator>(SingerType& data)
{
	return (this->name > data.GetName());
}

bool SingerType::operator<(SingerType& data)
{
	return (this->name < data.GetName());
}

void SingerType::Print()
{
	cout << "�̸� : " << name << endl;
	cout << "���� : " << age << endl;
	cout << "���� : " << sex << " (1.�� 2.��)"<< endl;
	cout << "--- ������ -------------------------" << endl;
}


