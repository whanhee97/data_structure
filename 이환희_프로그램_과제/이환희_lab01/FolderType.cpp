#include "FolderType.h"

void FolderType::AddSong(ItemType item)
{
	songlist.Add(item);
}

void FolderType::DeleteSong(ItemType item)
{
	songlist.Delete(item);
}

void FolderType::DisplayAllSong()
{
	if (songlist.GetLength() == 0)
	{
		cout << "\t폴더가 비었습니다." << endl;
	}
	else 
	{
		for (int i = 0; i < songlist.GetLength(); i++)
		{
			songlist[i].DisplayRecordOnScreen();
		}
	}
}

void FolderType::SetName(string _name)
{
	this->name = _name;
}

void FolderType::SetNameFromKB()
{
	string _name;
	cout << "이름을 입력하시오: ";
	cin >> _name;
	this->name = _name;
}

string FolderType::GetName()
{
	return name;
}

UnSortedList<ItemType>* FolderType::GetSongList()
{
	return &songlist;
}



bool FolderType::operator==(FolderType& f)
{
	return (this->name == f.name);
}

FolderType& FolderType::operator=(const FolderType& f)
{
	name = f.name;
	songlist = f.songlist;
	return *this;
}

