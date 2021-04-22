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
	SongList = S.SongList; // 깊은 복사가 일어나야함
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
	cout << "이름을 입력해주세요 : ";
	cin >> iname;

	cout << "나이를 입력해주세요 : ";
	cin >> iage;

	cout << "성별을 입력해주세요(1.남자 2.여자) : ";
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
	cout << "이름 : " << name << endl;
	cout << "나이 : " << age << endl;
	cout << "성별 : " << sex << " (1.남 2.여)"<< endl;
	cout << "--- 곡정보 -------------------------" << endl;
}


