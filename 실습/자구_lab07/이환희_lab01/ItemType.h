#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };

/**
*@brief ������ Ÿ�� Ŭ����
*@details ���� Ÿ��, �̸�, �۰, ����, �帣, ID ����
*@author ��ȯ��
*@date 2019-09-24

*/

class ItemType
{
	int m_Type;
	string m_Name;
	string m_Composer;
	string m_Singer;
	int m_Genre;
	string m_Id;

public:
	/**
	*@brief ������
	*@param
	*@return
	*/
	ItemType();
	
	/**
	*@brief �Ҹ���
	*@param
	*@return
	*/
	~ItemType();
	 
	/**
	*@brief Ÿ���� ��ȯ
	*@param
	*@return m_Type ��ȯ
	*/
	int GetType();
	 

	/**
	*@brief �̸��� ��ȯ
	*@param
	*@return m_Name ��ȯ
	*/
	string GetName();
	 

	/**
	*@brief �۰�� ��ȯ
	*@param
	*@return m_Composer ��ȯ
	*/
	string GetComposer();
	 

	/**
	*@brief ���� ��ȯ
	*@param
	*@return m_Singer ��ȯ
	*/
	string GetSinger();
	 

	/**
	*@brief �帣 ��ȯ
	*@param
	*@return m_Genre ��ȯ
	*/
	int GetGenre();
	 

	/**
	*@brief ID ��ȯ
	*@param
	*@return m_Id ��ȯ
	*/
	string GetId() const;
	 


	/**
	*@brief ID ����
	*@param �Է¹��� Id
	*@return
	*/
	void SetId(string id);
	 
	void SetName(string name);

	/**
	*@brief ������ ���� ����
	*@param �Է¹��� �����
	*@return
	*/
	void SetRedcord(int inType, string inName, string inComp, string inSinger, int inGenre, string inId);
	 
	
	/**
	*@brief ȭ�鿡 ������ ����� ���
	*/
	void DisplayRecordOnScreen();
	 
	
	/**
	*@brief Ű����κ��� �Է¹޾Ƽ� ������ ���� ����
	*/
	void SetIdFromKB();


	/**
	*@brief Ű����κ��� �Է¹޾Ƽ� ������ ���� ����
	*/
	void SetRecordFromKB();

	

	/**
	*@brief ���Ϸκ��� ������ ���� �о��
	*@param �ش� ������ ������ fin
	*@return �о���� 1 �ƴϸ� 0
	*/
	int ReadDataFromFile(ifstream& fin);
	 

	/**
	*@brief ����Ʈ���� ���Ϸ� �Űܾ�
	*@param �ش� ������ ������ fout
	*@return �Է��ϸ� 1 �ƴϸ� 0
	*/
	int WriteDataToFile(ofstream& fout);
	 

	/**
	*@brief data�� id�� ����
	*@param [data] ID�� �ԷµǾ��ִ� ������ Ÿ���� ������
	*@return ������ EQUAL, data���� ũ�� GREATER, ������ LESS
	*/
	RelationType CompareByID(const ItemType& data);

	/**
	*@brief ==������ id�� ��
	*@pre �񱳴�� ����
	*@post ������ true ��ȯ
	*/
	bool operator==(ItemType& data);

	/**
	*@brief >������ id�� ��
	*@pre �񱳴�� ����
	*@post �񱳴�󺸴� ũ�� true
	*/
	bool operator>(ItemType& data);

	/**
	*@brief >������ id�� ��
	*@pre �񱳴�� ����
	*@post �񱳴�󺸴� ������ true
	*/
	bool operator<(ItemType& data);
	
	// cout�� ���� << ������ �����ε�
	friend ostream& operator << (ostream& out, ItemType& item)
	{
		out << endl;
		out << "Type(1.���� 2.����) : " << item.m_Type << endl;
		out << "Name : " << item.m_Name << endl;
		out << "Composer : " << item.m_Composer << endl;
		out << "Singer : " << item.m_Singer << endl;
		out << "Genre : " << item.m_Genre << endl;
		out << "ID : " << item.m_Id << endl;

		return out;
	}
};
