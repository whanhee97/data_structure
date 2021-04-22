#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };

/**
*@brief 아이템 타입 클래스
*@details 곡의 타입, 이름, 작곡가, 가수, 장르, ID 포함
*@author 이환희
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
	*@brief 생성자
	*@param
	*@return
	*/
	ItemType();
	
	/**
	*@brief 소멸자
	*@param
	*@return
	*/
	~ItemType();
	 
	/**
	*@brief 타입을 반환
	*@param
	*@return m_Type 반환
	*/
	int GetType();
	 

	/**
	*@brief 이름을 반환
	*@param
	*@return m_Name 반환
	*/
	string GetName();
	 

	/**
	*@brief 작곡가를 반환
	*@param
	*@return m_Composer 반환
	*/
	string GetComposer();
	 

	/**
	*@brief 가수 반환
	*@param
	*@return m_Singer 반환
	*/
	string GetSinger();
	 

	/**
	*@brief 장르 반환
	*@param
	*@return m_Genre 반환
	*/
	int GetGenre();
	 

	/**
	*@brief ID 반환
	*@param
	*@return m_Id 반환
	*/
	string GetId() const;
	 


	/**
	*@brief ID 세팅
	*@param 입력받은 Id
	*@return
	*/
	void SetId(string id);
	 
	void SetName(string name);

	/**
	*@brief 아이템 내용 세팅
	*@param 입력받은 내용들
	*@return
	*/
	void SetRedcord(int inType, string inName, string inComp, string inSinger, int inGenre, string inId);
	 
	
	/**
	*@brief 화면에 아이템 내용들 출력
	*/
	void DisplayRecordOnScreen();
	 
	
	/**
	*@brief 키보드로부터 입력받아서 아이템 내용 세팅
	*/
	void SetIdFromKB();


	/**
	*@brief 키보드로부터 입력받아서 아이템 내용 세팅
	*/
	void SetRecordFromKB();

	

	/**
	*@brief 파일로부터 아이템 내용 읽어옴
	*@param 해당 파일을 오픈한 fin
	*@return 읽어오면 1 아니면 0
	*/
	int ReadDataFromFile(ifstream& fin);
	 

	/**
	*@brief 리스트에서 파일로 옮겨씀
	*@param 해당 파일을 오픈한 fout
	*@return 입력하면 1 아니면 0
	*/
	int WriteDataToFile(ofstream& fout);
	 

	/**
	*@brief data와 id를 비교함
	*@param [data] ID가 입력되어있는 아이템 타입의 데이터
	*@return 같으면 EQUAL, data보다 크면 GREATER, 작으면 LESS
	*/
	RelationType CompareByID(const ItemType& data);

	/**
	*@brief ==연산자 id로 비교
	*@pre 비교대상 존재
	*@post 같으면 true 반환
	*/
	bool operator==(ItemType& data);

	/**
	*@brief >연산자 id로 비교
	*@pre 비교대상 존재
	*@post 비교대상보다 크면 true
	*/
	bool operator>(ItemType& data);

	/**
	*@brief >연산자 id로 비교
	*@pre 비교대상 존재
	*@post 비교대상보다 작으면 true
	*/
	bool operator<(ItemType& data);
	
	// cout을 위한 << 연산자 오버로딩
	friend ostream& operator << (ostream& out, ItemType& item)
	{
		out << endl;
		out << "Type(1.가요 2.연주) : " << item.m_Type << endl;
		out << "Name : " << item.m_Name << endl;
		out << "Composer : " << item.m_Composer << endl;
		out << "Singer : " << item.m_Singer << endl;
		out << "Genre : " << item.m_Genre << endl;
		out << "ID : " << item.m_Id << endl;

		return out;
	}
};
