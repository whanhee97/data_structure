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
	int AddItem();
	void DisplayAllItem();
	int OpenInFile(const char *fileName);
	int OpenOutFile(const char *fileName);
	int ReadDataFromFile();
	int WriteDataToFile();

	void SearchByID_SequenS();
	void SearchByID_BinaryS();
	void RetrieveStudent();
	void DeleteStudent();
	void ReplaceItem();
	void SearchByName();

};


