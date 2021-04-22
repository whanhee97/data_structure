#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };

class ItemType
{
	int m_Type;
	string m_Name;
	string m_Composer;
	string m_Singer;
	int m_Genre;
	string m_Id;

public:
	ItemType();
	~ItemType();

	int GetType();
	string GetName();
	string GetComposer();
	string GetSinger();
	int GetGenre();
	string GetId();

	void SetId(string id);

	void SetRedcord(int inType, string inName, string inComp, string inSinger, int inGenre, string inId);
	
	void DisplayRecordOnScreen();
	
	void SetRecordFromKB();
	
	int ReadDataFromFile(ifstream& fin);
	int WriteDataToFile(ofstream& fout);
	RelationType CompareByID(const ItemType& data);
};
