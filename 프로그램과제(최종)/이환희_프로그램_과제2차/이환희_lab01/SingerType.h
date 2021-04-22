#pragma once
#include"ItemType.h"
#include"CircularQueueType.h"

/**
*@brief �̾�Ÿ�� Ŭ����
*@details ���� ����, �� ����Ʈ�� ����
*@author ��ȯ��
*@date 2019-09-24

*/
class SingerType
{
private:
	string name;
	int age;
	int sex;
	CircularQueueType<string> SongList; // id�� ����
public:
	/**
	*@brief ������
	*@pre 
	*@post
	*/
	SingerType();

	/**
	*@brief �Ҹ���
	*@pre 
	*@post 
	*/
	~SingerType();

	/**
	*@brief ���� ������
	*@pre 
	*@post 
	*/
	SingerType(const SingerType& S); //���������
	
	/**
	*@brief �̸� �޾ƿ�
	*@pre 
	*@post �̸� ����
	*/
	string GetName();
	
	/**
	*@brief ���� �޾ƿ�
	*@pre 
	*@post ���� ����
	*/
	int GetAge();
	
	
	/**
	*@brief ���� �޾ƿ�
	*@pre 
	*@post ���� ����
	*/
	int GetSex();
	
	/**
	*@brief �� ����Ʈ �޾ƿ� ������ ���� �̿��� ���� ť�� ����
	*@pre 
	*@post �� ����Ʈ�� �ּҰ��� ��ȯ��.
	*/
	CircularQueueType<string>* GetSongList();

	/**
	*@brief �̸�����
	*/
	void SetName(string _name);
	
	/**
	*@brief ���� ����
	*/
	void SetAge(int _age);
	
	
	/**
	*@brief ���� ����
	*/
	void SetSex(int _sex);
	
	/**
	*@brief Ű����� ���� �̸� ���� ���� ����
	*/
	void SetRecordByKB();
	
	/**
	*@brief �� �߰�
	*@pre ����Ʈ�� �� ���� �� ��.
	*@post ����Ʈ�� ���̵� �߰���.
	*/
	void AddSong(string _id);
	

	void DeleteSong(string _id);
	/**
	*@brief ==������ id�� ��
	*@pre �񱳴�� ����
	*@post ������ true ��ȯ
	*/
	bool operator==(SingerType& data);
	
	/**
	*@brief >������ id�� ��
	*@pre �񱳴�� ����
	*@post �񱳴�󺸴� ũ�� true
	*/
	bool operator>(SingerType& data);
	
	/**
	*@brief >������ id�� ��
	*@pre �񱳴�� ����
	*@post �񱳴�󺸴� ������ true
	*/
	bool operator<(SingerType& data);

	/**
	*@brief �̸� ���� ���� ���
	*/
	void Print();
};

