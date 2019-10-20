#pragma once
#include<iostream>
#include"UnSortedList.h"
#include"ItemType.h"
using namespace std;

class FolderType
{
private:
	string name;
	UnSortedList<ItemType> songlist;

public:
	void AddSong(ItemType item);
	void DeleteSong(ItemType item);
	void DisplayAllSong();
	void SetName(string _name);

	void SetNameFromKB();

	
	string GetName();
	UnSortedList<ItemType>* GetSongList();


	bool operator==(FolderType& f);
	FolderType& operator=(const FolderType& f);


};

