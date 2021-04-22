#pragma once
#include"ItemType.h"
#include"CircularQueueType.h"

/**
*@brief 싱어타입 클래스
*@details 가수 정보, 곡 리스트가 존재
*@author 이환희
*@date 2019-09-24

*/
class SingerType
{
private:
	string name;
	int age;
	int sex;
	CircularQueueType<string> SongList; // id만 저장
public:
	/**
	*@brief 생성자
	*@pre 
	*@post
	*/
	SingerType();

	/**
	*@brief 소멸자
	*@pre 
	*@post 
	*/
	~SingerType();

	/**
	*@brief 복사 생성자
	*@pre 
	*@post 
	*/
	SingerType(const SingerType& S); //복사생성자
	
	/**
	*@brief 이름 받아옴
	*@pre 
	*@post 이름 리턴
	*/
	string GetName();
	
	/**
	*@brief 나이 받아옴
	*@pre 
	*@post 나이 리턴
	*/
	int GetAge();
	
	
	/**
	*@brief 성별 받아옴
	*@pre 
	*@post 성별 리턴
	*/
	int GetSex();
	
	/**
	*@brief 곡 리스트 받아옴 포인터 값을 이용해 실제 큐에 접근
	*@pre 
	*@post 곡 리스트의 주소값이 반환됨.
	*/
	CircularQueueType<string>* GetSongList();

	/**
	*@brief 이름셋팅
	*/
	void SetName(string _name);
	
	/**
	*@brief 나이 셋팅
	*/
	void SetAge(int _age);
	
	
	/**
	*@brief 성별 셋팅
	*/
	void SetSex(int _sex);
	
	/**
	*@brief 키보드로 부터 이름 나이 성별 셋팅
	*/
	void SetRecordByKB();
	
	/**
	*@brief 곡 추가
	*@pre 리스트가 꽉 차면 안 됨.
	*@post 리스트에 아이디가 추가됨.
	*/
	void AddSong(string _id);
	

	void DeleteSong(string _id);
	/**
	*@brief ==연산자 id로 비교
	*@pre 비교대상 존재
	*@post 같으면 true 반환
	*/
	bool operator==(SingerType& data);
	
	/**
	*@brief >연산자 id로 비교
	*@pre 비교대상 존재
	*@post 비교대상보다 크면 true
	*/
	bool operator>(SingerType& data);
	
	/**
	*@brief >연산자 id로 비교
	*@pre 비교대상 존재
	*@post 비교대상보다 작으면 true
	*/
	bool operator<(SingerType& data);

	/**
	*@brief 이름 나이 성별 출력
	*/
	void Print();
};

