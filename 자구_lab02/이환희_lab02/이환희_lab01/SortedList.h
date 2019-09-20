#pragma once
#include"ItemType.h"
#define MAXSIZE 10
class SortedList
{
	ItemType m_Array[MAXSIZE];
	int m_Length;
	int m_CurPointer;
public:
	SortedList();
	~SortedList();

	void MakeEmpty();
	int GetLength();
	bool IsFull();

	bool IsEmpty();
	int Get(ItemType& data);
	int Delete(ItemType data);
	int Replace(ItemType data);

	int Add(ItemType data);
	void ResetList();
	int GetNextItem(ItemType& data);
	int RetrieveBinary(ItemType& data);
};