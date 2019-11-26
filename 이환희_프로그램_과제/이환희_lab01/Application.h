#pragma once
#include<iostream>
#include<fstream>
#include<ctime>
#include"SortedList.h"
#include"UnSortedList.h"
#include"ItemType.h"
#include"CircularQueueType.h"
#include"SortedLinkedList.h"
#include"SingerType.h"
#include"PlayItemType.h"
#include"FolderType.h"
#include"DoublyLinkedList.h"


using namespace std;

/**
*@brief 어플리케이션 클래스
*@details 여러 기능 수행
*@author 이환희
*@date 2019-09-24

*/

class Application
{
	ifstream m_InFile;
	ofstream m_OutFile;
	SortedList<ItemType> m_List;
	CircularQueueType<PlayItemType> m_PlayList;
	DoublyLinkedList<SingerType> m_SingerList;
	CircularQueueType<PlayItemType> m_RandomPlay;
	SortedList<FolderType> m_FolderList;

	int m_Command;

public:
	
	/**
	*@brief 생성자
	*/
	Application();
	 
	/**
	*@brief 소멸자
	*/
	~Application();
	 
	/**
	*@brief 기능을 수행할 어플리케이션을 실행시킴
	*/
	void Run();
	 
	/**
	*@brief 키보드로 커맨드를 받아옴
	*@return 받아온 커맨드
	*/
	int GetCommand();
	 
	/**
	*@brief 리스트의 add함수를 이용하여 음악을 리스트에 추가
	*@return 0
	*/
	int AddMusic();
	 

	/**
	*@brief 모든 아이템들을 화면에 출력
	*@return 0
	*/
	void DisplayAllMusic();
	 

	/**
	*@brief 파일을 읽어올 용도로 오픈함
	*@param [fileName] 오픈할 파일의 이름
	*@return 0
	*/
	int OpenInFile(const char *fileName);
	 

	/**
	*@brief 파일을 쓰기 용도로 오픈함
	*@param [fileName] 오픈할 파일의 이름
	*@return 0
	*/
	int OpenOutFile(const char *fileName);
	 

	/**
	*@brief 파일로부터 아이템 내용 읽어옴
	*@return 0
	*/
	int ReadDataFromFile();
	 

	/**
	*@brief 아이템을 파일에 옮겨 씀
	*@return 0
	*/
	int WriteDataToFile();
	 
	/**
	*@brief 가수를 입력 받아 해당가수의 모든 아이템 출력
	*/
	void SearchBySinger();
	
	/**
	*@brief 장르를 입력 받아 해당장르의 모든 아이템 출력
	*/
	void SearchByGenre();
	
	/**
	*@brief 바이너리서치로 해당아이디를 찾은 후 출력
	*/
	void SearchIDByBinary();
	
	/**
	*@brief 아이템 지우기
	*/
	void DeleteMusic();
	 

	/**
	*@brief 아이템 교체
	*/
	void ReplaceMusic();


	/**
	*@brief 리스트에서 플레이리스트로 추가
	*@pre 리스트가 비워져있으면 안됨
	*@post 플레이리스트에 아이템이 추가됨.
	*/
	void AddToPlayList();
	
	/**
	*@brief 플레이리스트를 화면에 모두 출력
	*@pre 플레이리스트가 비워져있으면 안됨
	*@post 화면에 모두 출력이 된다.
	*/
	void PrintAll();
	 

	/**
	*@brief 플레이리스트를 하나씩 플레이한다
	*@pre 플레이리스트가 비워져있으면 안됨
	*/
	void PlayInsertOrder();
	


	/**
	*@brief 아이템 지우기
	*@pre 리스트가 비워져있으면 안됨
	*@post 플레이리스트에 아이템이 지워짐.
	*/
	void DeleteFrPlayList();
	
	/**
	*@brief 랜덤재생
	*@pre 리스트가 비워져있으면 안됨
	*@post 플레이리스트에 아이템을 랜덤으로 재생후 다 끝나면 리스트를 지움.
	*/
	void ShufflePlay();

	//-----------------------------------

	/**
	*	@brief	싱어리스트에 싱어추가
	*	@pre	싱어리스트가 있어야하고 꽉 차있지 않아야함.
	*	@post	싱어리스트에 싱어타입이 추가됨.
	*/
	void AddSinger();

	/**
	*	@brief	싱어를 싱어리스트에서 검색하고 있으면 그 싱어의 송리스트에 곡추가 없으면 싱어추가후 곡추가
	*	@pre	싱어리스트가 있어야함.
	*	@post	싱어리스트의 송리스트에 곡(id)가 추가됨.
	*/
	void AddSong();


	/**
	*@brief 아이템 지우기
	*@pre 리스트가 비워져있으면 안됨
	*@post 곡 리스트에 아이템이 지워짐.
	*/
	void DeleteSong();

	void ShowAllSinger();
	//----------------------------------------
	

	/**
	*@brief 폴더보이기
	*@pre 리스트가 비워져있으면 안됨
	*/
	void ShowFolderList();
	
	/**
	*@brief 한 곡씩 플레이하고 플레이리스트에 저장
	*/
	void PlayMusic();


	/**
	*@brief 장르별로 노래 추천
	*/
	void RecommendMusic();
};
