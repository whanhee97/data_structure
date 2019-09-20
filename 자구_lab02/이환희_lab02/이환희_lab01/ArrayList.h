#pragma once
#include"ItemType.h"
#define MAXSIZE 5
class ArrayList
{
	ItemType m_Array[MAXSIZE];
	int m_Length;
	int m_CurPointer;
public:
	ArrayList();
	~ArrayList();

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
};
