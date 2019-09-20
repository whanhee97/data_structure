#include "ArrayList.h"



ArrayList::ArrayList()
{
	m_Length = 0;
	m_CurPointer = 0;
}


ArrayList::~ArrayList()
{
}

void ArrayList::MakeEmpty()
{
	m_Length = 0;
}

int ArrayList::GetLength()
{
	return m_Length;
}

bool ArrayList::IsFull()
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

bool ArrayList::IsEmpty()
{
	if (m_Length == 0)
	{
		return true;
	}
	return false;
}

int ArrayList::Get(ItemType & data)
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

int ArrayList::Delete(ItemType data)
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

int ArrayList::Replace(ItemType data)
{
	m_Array[m_CurPointer] = data;
	return 1;
}

int ArrayList::Add(ItemType data)
{
	if (IsFull() == true)
	{
		cout << "list가 꽉 찼습니다." << endl;
		return 0;
	}
	else
	{
		m_Array[m_Length] = data;
		m_Length++;
		return 1;
	}
}

void ArrayList::ResetList()
{
	m_CurPointer = -1;
}

int ArrayList::GetNextItem(ItemType& data)
{
	m_CurPointer++;
	if (m_CurPointer == MAXSIZE)
	{
		return -1;
	}
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}