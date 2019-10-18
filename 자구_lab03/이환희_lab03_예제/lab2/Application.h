#include"SortedList.h"
#include"CircularQueueType.h"
#include"ItemType.h"

using namespace std;

class Application
{
	ifstream m_InFile;
	ofstream m_OutFile;
	SortedList m_List;

	CircularQueueType<ItemType> m_Queue;
	int m_Command;

public:

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
	//-------------------------------------

	int Enqueue();
	int Dequeue();
	int CheckEmpty();
	int CheckFull();
	void EmptyTest();
	void FullTest();
	void PrintAll();
	void Search();
	void Replace();
	//--------------------------------------

	void AddRecordToQL();
	void DeleteQList();
};


