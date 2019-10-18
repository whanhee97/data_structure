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
	*@brief ������
	*/
	PlayItemType();
	/**
	*@brief �Ҹ���
	*/
	~PlayItemType();

	/**
	*@brief ���̵� ������
	*/
	string GetID();

	/**
	*@brief �÷��̵� Ƚ�� ������
	*/
	int GetNumPlay();
	
	/**
	*@brief ���Ե� �ð� ������
	*/
	int GetIntime();

	/**
	*@brief ���̵� ������
	*/
	void SetID(string id);

	/**
	*@brief ���̵� Ű����� ������
	*/
	void SetIDFromKB();

	/**
	*@brief ���Խð� ������
	*/
	void SetInTime(int it);

	void PrintPN(); // �÷��� Ƚ�� ���

	void NumPlayUP(); //�÷��� Ƚ�� ����

	/**
	*@brief �÷��̾�����Ÿ�԰� ���̵� ��
	*@pre �����Ϳ� ���̵� �ԷµǾ��־����
	*@return ������ EQUAL ������ LESS ũ�� GREATER ��ȯ
	*/
	RelationType CompareByID(const PlayItemType& data);

	/**
	*@brief ������Ÿ�԰� ���̵� ��
	*@pre �����Ϳ� ���̵� �ԷµǾ��־����
	*@return ������ EQUAL ������ LESS ũ�� GREATER ��ȯ
	*/
	RelationType CompareByID(const ItemType& data);
};

