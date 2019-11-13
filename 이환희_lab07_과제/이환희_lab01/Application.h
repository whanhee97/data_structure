#pragma once
#include<iostream>
#include<fstream>
#include"SortedList.h"
#include"ItemType.h"
#include"CircularQueueType.h"
#include"SortedLinkedList.h"
#include"SingerType.h"
#include"PlayItemType.h"
#include"DoublyLinkedList.h"
#include"UnSortedList.h"
#include<ctime>
#include"BinarySearchTree.h"

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
	DoublyLinkedList<PlayItemType> m_PlayList; // �÷��̸���Ʈ
	DoublyLinkedList<PlayItemType> m_PLSortedByFreq; // �÷����� Ƚ�������� �÷����ϴ� �÷��̸���Ʈ
	DoublyLinkedList<PlayItemType> m_RandomPlay; // ���� �÷��̸���Ʈ

	BinarySearchTree<SingerType> m_SingerList;

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

	//---------------�÷��̸���Ʈ------------------
	
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
	*@brief �÷��̸���Ʈ�� �߰��� ������ �ϳ��� �÷����Ѵ�
	*@pre �÷��̸���Ʈ�� ����������� �ȵ�
	*/
	void PlayInsertOrder(); //PlayIOAddTime �� ����

	/**
	*@brief �÷��̸���Ʈ�� �����÷����� ������ �ϳ��� �÷����Ѵ�
	*@pre �÷��̸���Ʈ�� ����������� �ȵ�
	*/
	void PlayIOFreq();
	

	/**
	*@brief ������ �����
	*@pre ����Ʈ�� ����������� �ȵ�
	*@post �÷��̸���Ʈ�� �������� ������.
	*/
	void DeleteFrPlayList();

	/**
	*@brief ���� ���
	*@pre ����Ʈ�� ����������� �ȵ�
	*@post �����÷��̸���Ʈ�� ���õ�.
	*/
	void SufflePlay();
	

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
	*@brief �̾��Ʈ�� �۸���Ʈ���� �� ����.
	*@pre ����Ʈ�� �����ϰ� ����Ʈ�� ����������� �ȵ�
	*@post �̾��Ʈ�� �۸���Ʈ�� ���� ������.
	*/
	void DeleteSong();
};
