#pragma once
#include<iostream>
#include<fstream>
#include"SortedList.h"
#include"ItemType.h"

using namespace std;

class Application
{
	ifstream m_InFile;
	ofstream m_OutFile;
	SortedList m_List;
	int m_Command;

public:
	Application();
	~Application();

	void Run();
	int GetCommand();
	int AddMusic();
	void DisplayAllMusic();
	int OpenInFile(const char *fileName);
	int OpenOutFile(const char *fileName);
	int ReadDataFromFile();
	int WriteDataToFile();

	void SearchBySinger();
	void SearchByGenre();

	void SearchIDByBinary();
	void DeleteMusic();
	void ReplaceMusic();

};
