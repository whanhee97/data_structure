#pragma once
#include<iostream>
#include"UnSortedList.h"
#include"ItemType.h"
using namespace std;

/**
*	폴터타입 클래스
*/

class FolderType
{
private:
	string name; /// 폴더의 이름
	UnSortedList<ItemType> songlist; /// 폴더안의 송리스트

public:
	/**
	*	폴더에 아이템 추가
	*/
	void AddSong(ItemType item);
	
	/**
	*	아이템 삭제
	*/
	void DeleteSong(ItemType item);
	
	/**
	*	폴더안에 있는 데이터 모두 출력
	*/
	void DisplayAllSong();
	
	/**
	*	이름 셋팅
	*/
	void SetName(string _name);

	/**
	*	키보드로 부터 이름 셋팅
	*/
	void SetNameFromKB();

	
	/**
	*	이름 반환 게터
	*/
	string GetName();
	
	/**
	*	송리스트를 반환하는 게터
	*/
	UnSortedList<ItemType>* GetSongList();

	/**
	*	비교를 위한 ==연산자
	*/
	bool operator==(FolderType& f);
	
	/**
	*	대입을 위한 =연산자
	*/
	FolderType& operator=(const FolderType& f);


};

