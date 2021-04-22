#pragma once
#include"ItemType.h"

class PlayItemType
{
private:
	string m_ID;
	int NumPlay;
	int InTime;

public:

	/**
	*@brief 생성자
	*/
	PlayItemType();
	/**
	*@brief 소멸자
	*/
	~PlayItemType();

	/**
	*@brief 아이디 가져옴
	*/
	string GetID();

	/**
	*@brief 플레이된 횟수 가져옴
	*/
	int GetNumPlay();
	
	/**
	*@brief 삽입된 시간 가져옴
	*/
	int GetIntime();

	/**
	*@brief 아이디 세팅함
	*/
	void SetID(string id);

	/**
	*@brief 아이디를 키보드로 세팅함
	*/
	void SetIDFromKB();

	/**
	*@brief 삽입시간 세팅함
	*/
	void SetInTime(int it);

	void PrintPN(); // 플레이 횟수 출력

	void NumPlayUP(); //플레이 횟수 증가

	/**
	*@brief 플레이아이템타입과 아이디 비교
	*@pre 데이터에 아이디가 입력되어있어야함
	*@return 같으면 EQUAL 작으면 LESS 크면 GREATER 반환
	*/
	RelationType CompareByID(const PlayItemType& data);

	/**
	*@brief 아이템타입과 아이디 비교
	*@pre 데이터에 아이디가 입력되어있어야함
	*@return 같으면 EQUAL 작으면 LESS 크면 GREATER 반환
	*/
	RelationType CompareByID(const ItemType& data);
};

