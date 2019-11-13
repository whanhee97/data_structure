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
	// ������
	BinarySearchTree();
	// �Ҹ���
	~BinarySearchTree();

	/**
	*	@brief	Tree�� Empty���� Ȯ��
	*	@pre	none
	*	@post	none
	*	@return	Tree�� ��������� true����, �ƴϸ� false ����
	*/
	bool IsEmpty()const;

	/**
	*	@brief	Tree�� Full���� Ȯ��
	*	@pre	none
	*	@post	none
	*	@return	Tree�� Full�̸� true ����, �ƴϸ� false ����
	*/
	bool IsFull() const;

	/**
	*	@brief	Tree�� ����
	*	@pre	none
	*	@post	none
	*/
	void MakeEmpty();

	/**
	*	@brief	Tree�� node�� �� ������ Ȯ����
	*	@pre	none
	*	@post	none
	*	@return	Tree�� node ������ ����
	*/
	int GetLenght() const;

	/**
	*	@brief	Tree�� �� node�� �߰��Ѵ�
	*	@pre	ItemType�� ��ü�� ����
	*	@post	Tree�� �� node�� �߰���
	*/
	void Add(T item);

	/**
	*	@brief	Tree���� ������� �ϴ� node�� ã�� ����
	*	@pre	ItemType�� ��ü�� ����
	*	@post	Tree���� �Է��� node�� ������
	*/
	void Delete(T item);

	/**
	*	@brief	�Է��� ���� node�� Tree���� �˻���
	*	@pre	ã���� �ϴ� item�� �˻������ ���� found ����
	*	@post	node�� Tree�� �ִ��� �˻������ �˷���
	*/
	void Retrieve(T& item, bool& found) const;

	void Replace(T item);

	/**
	*	@brief	Tree�� node�� ��ũ���� ����Ѵ�.
	*	@pre	none
	*	@post	��ũ���� Tree�� InOrder, PreOrder, PostOrder ������� ���� ��µ�.
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
	if (root == NULL)			// root ��尡 NULL�� ��� true ����
		return true;
	else
		return false;			// root ��尡 NULL�� �ƴ� ��� false ����
}

template<class T>
inline bool BinarySearchTree<T>::IsFull() const
{
	BinaryTreeNode<T>* temp;					// �ӽ��� node�� �����
	try
	{
		temp = new BinaryTreeNode<T>;		// �� ��带 �߰��� �� �ִ��� Ȯ��
		delete temp;			// �ӽ÷� ���� room ��带 ����
		return false;			// isFull�� ���� false ����
	}
	catch (std::bad_alloc exception)		// �� �̻� ������ �߰��� �� �� ���� Full�� ���
	{
		return true;					// isFull�� ���� true ����
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
	PrintInOT(root, out);			// InOrder ������� ���
	cout << endl << "[PreOrder]" << endl;
	PrintPreOT(root, out);			// PreOrder ������� ���
	cout << endl << "[PostOrder]" << endl;
	PrintPostOT(root, out);			// PostOrder ������� ���
}


///////////////////////////////////////////////////Global functions ����Լ��� ����///////////////////////////////////////////////////////

/////////////////�ʱ�ȭ
template<class T>
void MakeEmptyTree(BinaryTreeNode<T>* root)
{
	root = NULL;			// root ��带 Null�� ��
}

//��� ����
template<class T>
int CountNodes(BinaryTreeNode<T>* root)
{
	if (root == NULL)
		return 0;
	else
		return CountNodes(root->left) + CountNodes(root->right) + 1;
}


//////////////////��� �߰�
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


/////////////////��� ����
template<class T>
void GetPredecessor(BinaryTreeNode<T>* root, T& item)
{
	while (root->right != NULL)
	{
		root = root->right; // ���� ������ ���� ����
	}
	item = root->data;

} //���� ū ���� ã�� �Լ�

template<class T>
void DeleteNode(BinaryTreeNode<T>*& root) //root�� cur������ ���� 
{
	T item;
	BinaryTreeNode<T>* temp;
	temp = root;

	if (root->left == NULL) // ���ʳ�尡 ������� ������ ��带 ���ܿ��� ���� ��� ����
	{
		root = root->right;
		delete temp;
	}

	else if (root->right == NULL) // ������ ��� ������� ���� ��� ���ܿ��� ���� ��� ����
	{
		root = root->left;
		delete temp;
	}
	else // �߰� ��� ����� ������ �ڽź��� ���� ��� �� ���� ū ����� ���� �ڽŰ� �ٲٰ� �� �� ����
	{
		GetPredecessor(root->left, item);//�ڽź��� ���� ����� ���� ū ����� �� item�� ���������
		root->data = item; // ������ �� ���� ��Ʈ�� ���� ��ü
		Delete(root->left, item);// ��Ʈ�� ���ʿ������� item�� ��ġ�ϴ� ���� ���� ��� ����
	}
} //�ش� ��带 ����� �Լ�

template<class T>
void Delete(BinaryTreeNode<T>*& root, T item)
{
	if (root->data > item) // �������� �� ������ �������� �̵�
		Delete(root->left);
	else if (root->data < item) // �������� �� ũ�� ���������� �̵�
		Delete(root->right);
	else
		DeleteNode(root); //������ ���� ��Ʈ��带 ��������
} // ������� �ϴ� ��带 ã�� ����Լ�

//////////////////////////�˻�
template<class T>
void RetrieveNode(BinaryTreeNode<T>* root, T& item, bool& found)
{
	if (root == NULL) //������� false
		found = false;
	else if (root->data > item)
		RetrieveNode(root->left, item, found); //�������� �� ������ ��������
	else if (root->data < item) // �� ũ�� ���������� 
		RetrieveNode(root->right, item, found);
	else// ã������ �����ۿ� ������ �ְ� Ʈ��
	{
		item = root->data;
		found = true;
	}

}

//////////////////////////���
template<class T>
void PrintInOT(BinaryTreeNode<T>* root, ostream& out) // in order ũ�������(�������� ���� �ڱ� ����ϰ� ���������� ����)
{
	if (root != NULL)
	{
		PrintInOT(root->left, out);
		out << root->data;
		PrintInOT(root->right, out);
	}
}

template<class T>
void PrintPreOT(BinaryTreeNode<T>* root, ostream& out) // Pre Order Ž��������(�ڱ� ����ϰ� ���ʰ��� �����ʰ���)
{
	if (root != NULL)
	{

		out << root->data;
		PrintPreOT(root->left, out);
		PrintPreOT(root->right, out);
	}
}

template<class T>
void PrintPostOT(BinaryTreeNode<T>* root, ostream& out) // Post Order ���� ������ �ڱ� ������ ���
{
	if (root != NULL)
	{
		PrintPostOT(root->left, out);
		PrintPostOT(root->right, out);
		out << root->data;

	}
}