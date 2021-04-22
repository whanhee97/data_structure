#include "SortedList.h"



SortedList::SortedList()
{
	m_Length = 0;
	m_CurPointer = 0;
}


SortedList::~SortedList()
{
}

void SortedList::MakeEmpty()
{
	m_Length = 0;
}

int SortedList::GetLength()
{
	return m_Length;
}

bool SortedList::IsFull()
{
	if (GetLength() == MAXSIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SortedList::IsEmpty()
{
	if (m_Length == 0)
	{
		return true;
	}
	return false;
}



int SortedList::Get(ItemType& data)
{
	for (m_CurPointer = 0; m_CurPointer < m_Length; m_CurPointer++)
	{
		if (m_Array[m_CurPointer].CompareByID(data) == EQUAL)
		{
			return m_CurPointer;
		}
	}
	return -1;
}

int SortedList::Delete(ItemType data)
{
	ItemType temp;
	for (m_CurPointer = 0; m_CurPointer < m_Length; m_CurPointer++)
	{
		if (m_Array[m_CurPointer].CompareByID(data) == EQUAL)
		{
			if (m_CurPointer == m_Length - 1) // 마지막게 같을경우 그냥 마지막걸 없앰.
			{
				m_Length--;
				return 1;
			}
			for (int i = m_CurPointer; i < m_Length - 1; i++)
			{
				m_Array[i] = m_Array[i + 1]; // 한 칸씩 앞으로 땡겨서 복사
			}
			m_Length--;
			return 1;
		}
	}
	return -1;
}

int SortedList::Replace(ItemType data)
{
	m_Array[m_CurPointer] = data;
	return 1;
}

int SortedList::Add(ItemType data)
{
	if (IsEmpty() == true)
	{
		m_Array[m_Length] = data;
		m_Length++;
		return 1;
	}
	else if (IsFull() == true)
	{
		cout << "list가 꽉 찼습니다." << endl;
		return 0;
	}
	else
	{
		for (m_CurPointer = 0; m_CurPointer < m_Length; m_CurPointer++)
		{
			if (data.CompareByID(m_Array[m_CurPointer]) == LESS)
			{
				for (int i = m_Length; i > m_CurPointer; i--)
				{
					m_Array[i] = m_Array[i - 1]; // 한 칸씩 뒤로 땡겨서 복사
				}
				m_Length++;
				m_Array[m_CurPointer] = data;
				return 1;
			}
		}
		m_Length++;
		m_Array[m_CurPointer] = data;
		return 1;
	}
}

void SortedList::ResetList()
{
	m_CurPointer = -1;
}

int SortedList::GetNextItem(ItemType& data)
{
	m_CurPointer++;
	if (m_CurPointer == MAXSIZE)
	{
		return -1;
	}
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}

int SortedList::RetrieveBinary(ItemType& data)
{
	int start = 0;
	int end = m_Length - 1;
	while (1)
	{
		if (start > end)
		{
			break;
		}
		m_CurPointer = (start + end) / 2;
		if (data.CompareByID(m_Array[m_CurPointer]) == EQUAL)
		{
			data = m_Array[m_CurPointer];
			return 1;
		}
		else if (data.CompareByID(m_Array[m_CurPointer]) == LESS)
		{
			end = m_CurPointer - 1;
		}
		else
		{
			start = m_CurPointer + 1;
		}
	}
	return 0;
}
