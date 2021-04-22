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
*@brief ���ø����̼� Ŭ����
*@details ���� ��� ����
*@author ��ȯ��
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
	*@brief ������
	*/
	Application();
	 
	/**
	*@brief �Ҹ���
	*/
	~Application();
	 
	/**
	*@brief ����� ������ ���ø����̼��� �����Ŵ
	*/
	void Run();
	 
	/**
	*@brief Ű����� Ŀ�ǵ带 �޾ƿ�
	*@return �޾ƿ� Ŀ�ǵ�
	*/
	int GetCommand();
	 
	/**
	*@brief ����Ʈ�� add�Լ��� �̿��Ͽ� ������ ����Ʈ�� �߰�
	*@return 0
	*/
	int AddMusic();
	 

	/**
	*@brief ��� �����۵��� ȭ�鿡 ���
	*@return 0
	*/
	void DisplayAllMusic();
	 

	/**
	*@brief ������ �о�� �뵵�� ������
	*@param [fileName] ������ ������ �̸�
	*@return 0
	*/
	int OpenInFile(const char *fileName);
	 

	/**
	*@brief ������ ���� �뵵�� ������
	*@param [fileName] ������ ������ �̸�
	*@return 0
	*/
	int OpenOutFile(const char *fileName);
	 

	/**
	*@brief ���Ϸκ��� ������ ���� �о��
	*@return 0
	*/
	int ReadDataFromFile();
	 

	/**
	*@brief �������� ���Ͽ� �Ű� ��
	*@return 0
	*/
	int WriteDataToFile();
	 
	/**
	*@brief ������ �Է� �޾� �ش簡���� ��� ������ ���
	*/
	void SearchBySinger();
	
	/**
	*@brief �帣�� �Է� �޾� �ش��帣�� ��� ������ ���
	*/
	void SearchByGenre();
	
	/**
	*@brief ���̳ʸ���ġ�� �ش���̵� ã�� �� ���
	*/
	void SearchIDByBinary();
	
	/**
	*@brief ������ �����
	*/
	void DeleteMusic();
	 

	/**
	*@brief ������ ��ü
	*/
	void ReplaceMusic();


	/**
	*@brief ����Ʈ���� �÷��̸���Ʈ�� �߰�
	*@pre ����Ʈ�� ����������� �ȵ�
	*@post �÷��̸���Ʈ�� �������� �߰���.
	*/
	void AddToPlayList();
	
	/**
	*@brief �÷��̸���Ʈ�� ȭ�鿡 ��� ���
	*@pre �÷��̸���Ʈ�� ����������� �ȵ�
	*@post ȭ�鿡 ��� ����� �ȴ�.
	*/
	void PrintAll();
	 

	/**
	*@brief �÷��̸���Ʈ�� �ϳ��� �÷����Ѵ�
	*@pre �÷��̸���Ʈ�� ����������� �ȵ�
	*/
	void PlayInsertOrder();
	


	/**
	*@brief ������ �����
	*@pre ����Ʈ�� ����������� �ȵ�
	*@post �÷��̸���Ʈ�� �������� ������.
	*/
	void DeleteFrPlayList();
	
	/**
	*@brief �������
	*@pre ����Ʈ�� ����������� �ȵ�
	*@post �÷��̸���Ʈ�� �������� �������� ����� �� ������ ����Ʈ�� ����.
	*/
	void ShufflePlay();

	//-----------------------------------

	/**
	*	@brief	�̾��Ʈ�� �̾��߰�
	*	@pre	�̾��Ʈ�� �־���ϰ� �� ������ �ʾƾ���.
	*	@post	�̾��Ʈ�� �̾�Ÿ���� �߰���.
	*/
	void AddSinger();

	/**
	*	@brief	�̾ �̾��Ʈ���� �˻��ϰ� ������ �� �̾��� �۸���Ʈ�� ���߰� ������ �̾��߰��� ���߰�
	*	@pre	�̾��Ʈ�� �־����.
	*	@post	�̾��Ʈ�� �۸���Ʈ�� ��(id)�� �߰���.
	*/
	void AddSong();


	/**
	*@brief ������ �����
	*@pre ����Ʈ�� ����������� �ȵ�
	*@post �� ����Ʈ�� �������� ������.
	*/
	void DeleteSong();

	void ShowAllSinger();
	//----------------------------------------
	

	/**
	*@brief �������̱�
	*@pre ����Ʈ�� ����������� �ȵ�
	*/
	void ShowFolderList();
	
	/**
	*@brief �� � �÷����ϰ� �÷��̸���Ʈ�� ����
	*/
	void PlayMusic();


	/**
	*@brief �帣���� �뷡 ��õ
	*/
	void RecommendMusic();
};
