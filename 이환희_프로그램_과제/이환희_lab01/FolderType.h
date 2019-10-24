#pragma once
#include<iostream>
#include"UnSortedList.h"
#include"ItemType.h"
using namespace std;

/**
*	����Ÿ�� Ŭ����
*/

class FolderType
{
private:
	string name; /// ������ �̸�
	UnSortedList<ItemType> songlist; /// �������� �۸���Ʈ

public:
	/**
	*	������ ������ �߰�
	*/
	void AddSong(ItemType item);
	
	/**
	*	������ ����
	*/
	void DeleteSong(ItemType item);
	
	/**
	*	�����ȿ� �ִ� ������ ��� ���
	*/
	void DisplayAllSong();
	
	/**
	*	�̸� ����
	*/
	void SetName(string _name);

	/**
	*	Ű����� ���� �̸� ����
	*/
	void SetNameFromKB();

	
	/**
	*	�̸� ��ȯ ����
	*/
	string GetName();
	
	/**
	*	�۸���Ʈ�� ��ȯ�ϴ� ����
	*/
	UnSortedList<ItemType>* GetSongList();

	/**
	*	�񱳸� ���� ==������
	*/
	bool operator==(FolderType& f);
	
	/**
	*	������ ���� =������
	*/
	FolderType& operator=(const FolderType& f);


};

