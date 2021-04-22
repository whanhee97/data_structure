#pragma once
#include<iostream>
using namespace std;

template<class T>
struct BinaryTreeNode
{
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};


template<class T>
class BinarySearchTree
{
public:
	// 생성자
	BinarySearchTree();
	// 소멸자
	~BinarySearchTree();

	/**
	*	@brief	Tree가 Empty인지 확인
	*	@pre	none
	*	@post	none
	*	@return	Tree가 비어있으면 true리턴, 아니면 false 리턴
	*/
	bool IsEmpty()const;

	/**
	*	@brief	Tree가 Full인지 확인
	*	@pre	none
	*	@post	none
	*	@return	Tree가 Full이면 true 리턴, 아니면 false 리턴
	*/
	bool IsFull() const;

	/**
	*	@brief	Tree를 비운다
	*	@pre	none
	*	@post	none
	*/
	void MakeEmpty();

	/**
	*	@brief	Tree에 node가 몇 개인지 확인함
	*	@pre	none
	*	@post	none
	*	@return	Tree의 node 개수를 리턴
	*/
	int GetLenght() const;

	/**
	*	@brief	Tree에 새 node를 추가한다
	*	@pre	ItemType의 객체를 생성
	*	@post	Tree에 새 node가 추가됨
	*/
	void Add(T item);

	/**
	*	@brief	Tree에서 지우고자 하는 node를 찾고 지움
	*	@pre	ItemType의 객체를 생성
	*	@post	Tree에서 입력한 node가 삭제됨
	*/
	void Delete(T item);

	/**
	*	@brief	입력한 값의 node를 Tree에서 검색함
	*	@pre	찾고자 하는 item과 검색결과에 대한 found 설정
	*	@post	node가 Tree에 있는지 검색결과를 알려줌
	*/
	void Retrieve(T& item, bool& found) const;

	void Replace(T item);

	/**
	*	@brief	Tree의 node를 스크린에 출력한다.
	*	@pre	none
	*	@post	스크린에 Tree가 InOrder, PreOrder, PostOrder 방법으로 각각 출력됨.
	*/
	void PrintTree(ostream& out)const;

private:
	BinaryTreeNode<T>* root;
};

template<class T>
inline BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}

template<class T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
}

template<class T>
inline bool BinarySearchTree<T>::IsEmpty() const
{
	if (root == NULL)			// root 노드가 NULL인 경우 true 리턴
		return true;
	else
		return false;			// root 노드가 NULL이 아닌 경우 false 리턴
}

template<class T>
inline bool BinarySearchTree<T>::IsFull() const
{
	BinaryTreeNode<T>* temp;					// 임시의 node를 만들고
	try
	{
		temp = new BinaryTreeNode<T>;		// 새 노드를 추가할 수 있는지 확인
		delete temp;			// 임시로 만든 room 노드를 지움
		return false;			// isFull에 대한 false 리턴
	}
	catch (std::bad_alloc exception)		// 더 이상 아이템 추가를 할 수 없고 Full일 경우
	{
		return true;					// isFull에 대한 true 리턴
	}
}

template<class T>
inline void BinarySearchTree<T>::MakeEmpty()
{
	MakeEmptyTree(root);
}

template<class T>
inline int BinarySearchTree<T>::GetLenght() const
{
	return CountNodes(root);
}

template<class T>
inline void BinarySearchTree<T>::Add(T item)
{
	Insert(root, item);
}

template<class T>
inline void BinarySearchTree<T>::Delete(T item)
{
	Delete(root, item);
}

template<class T>
inline void BinarySearchTree<T>::Retrieve(T& item, bool& found) const
{
	RetrieveNode(root, item, found);
}

template<class T>
inline void BinarySearchTree<T>::Replace(T item)
{
	ReplaceNode(root, item);
}

template<class T>
inline void BinarySearchTree<T>::PrintTree(ostream& out) const
{
	cout << "[InOrder]" << endl;
	PrintInOT(root, out);			// InOrder 방법으로 출력
	cout << endl << "[PreOrder]" << endl;
	PrintPreOT(root, out);			// PreOrder 방법으로 출력
	cout << endl << "[PostOrder]" << endl;
	PrintPostOT(root, out);			// PostOrder 방법으로 출력
}


///////////////////////////////////////////////////Global functions 재귀함수를 위한///////////////////////////////////////////////////////

/////////////////초기화
template<class T>
void MakeEmptyTree(BinaryTreeNode<T>* root)
{
	root = NULL;			// root 노드를 Null로 함
}

//노드 개수
template<class T>
int CountNodes(BinaryTreeNode<T>* root)
{
	if (root == NULL)
		return 0;
	else
		return CountNodes(root->left) + CountNodes(root->right) + 1;
}


//////////////////노드 추가
template<class T>
void Insert(BinaryTreeNode<T>*& root, T item)
{
	if (root == NULL)
	{
		root = new BinaryTreeNode<T>;
		root->data = item;
		root->left = NULL;
		root->right = NULL;
	}
	else if (root->data > item)
	{
		Insert(root->left, item);
	}
	else if (root->data < item)
	{
		Insert(root->right, item);
	}

}

template<class T>
void ReplaceNode(BinaryTreeNode<T>*& root, T item)
{
	if (root == NULL)
	{
		return;
	}
	else if (root->data > item)
	{
		ReplaceNode(root->left, item);
	}
	else if (root->data < item)
	{
		ReplaceNode(root->right, item);
	}
	else
	{
		root->data = item;
	}
}


/////////////////노드 삭제
template<class T>
void GetPredecessor(BinaryTreeNode<T>* root, T& item)
{
	while (root->right != NULL)
	{
		root = root->right; // 가장 오른쪽 노드로 가서
	}
	item = root->data;

} //가장 큰 값을 찾는 함수

template<class T>
void DeleteNode(BinaryTreeNode<T>*& root) //root가 cur포인터 개념 
{
	T item;
	BinaryTreeNode<T>* temp;
	temp = root;

	if (root->left == NULL) // 왼쪽노드가 비었으면 오른쪽 노드를 땡겨오고 원래 노드 지움
	{
		root = root->right;
		delete temp;
	}

	else if (root->right == NULL) // 오른쪽 노드 비었으면 왼쪽 노드 땡겨오고 원래 노드 지움
	{
		root = root->left;
		delete temp;
	}
	else // 중간 노드 지우고 싶으면 자신보다 작은 노드 중 가장 큰 노드의 값을 자신과 바꾸고 그 놈 지움
	{
		GetPredecessor(root->left, item);//자신보다 작은 노드중 가장 큰 노드의 값 item에 가지고오기
		root->data = item; // 가져온 값 원래 루트에 값에 교체
		Delete(root->left, item);// 루트의 왼쪽에서부터 item과 일치하는 값을 가진 노드 삭제
	}
} //해당 노드를 지우는 함수

template<class T>
void Delete(BinaryTreeNode<T>*& root, T item)
{
	if (root->data > item) // 아이템이 더 작으면 왼쪽으로 이동
		Delete(root->left);
	else if (root->data < item) // 아이템이 더 크면 오른쪽으로 이동
		Delete(root->right);
	else
		DeleteNode(root); //같으면 현재 루트노드를 지워버림
} // 지우려고 하는 노드를 찾는 재귀함수

//////////////////////////검색
template<class T>
void RetrieveNode(BinaryTreeNode<T>* root, T& item, bool& found)
{
	if (root == NULL) //비었으면 false
		found = false;
	else if (root->data > item)
		RetrieveNode(root->left, item, found); //아이템이 더 작으면 왼쪽으로
	else if (root->data < item) // 더 크면 오른쪽으로 
		RetrieveNode(root->right, item, found);
	else// 찾았으면 아이템에 데이터 넣고 트루
	{
		item = root->data;
		found = true;
	}

}

//////////////////////////출력
template<class T>
void PrintInOT(BinaryTreeNode<T>* root, ostream& out) // in order 크기순으로(왼쪽으로 가고 자기 출력하고 오른쪽으로 가고)
{
	if (root != NULL)
	{
		PrintInOT(root->left, out);
		out << root->data;
		PrintInOT(root->right, out);
	}
}

template<class T>
void PrintPreOT(BinaryTreeNode<T>* root, ostream& out) // Pre Order 탐색순으로(자기 출력하고 왼쪽가고 오른쪽가고)
{
	if (root != NULL)
	{

		out << root->data;
		PrintPreOT(root->left, out);
		PrintPreOT(root->right, out);
	}
}

template<class T>
void PrintPostOT(BinaryTreeNode<T>* root, ostream& out) // Post Order 왼쪽 오른쪽 자기 순으로 출력
{
	if (root != NULL)
	{
		PrintPostOT(root->left, out);
		PrintPostOT(root->right, out);
		out << root->data;

	}
}