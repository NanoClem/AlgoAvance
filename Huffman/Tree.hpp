
#include <stdio.h>
#include <iostream>

using namespace std;
#include "Node.hpp"

template <class T> class Node;


template<class T>
class Tree {

	private:
		Node<T> *root;
		void Insert(Node<T> *);
		void Scan(Node<T> *);
		inline Node<T> *Root() const {return root;}
		Node<T> *Search(const int) const;

	public:
		inline Tree() {root = nullptr;}
		~Tree();
		void Create(const T, const int);
		void Delete(const T );
		void Viewing();
		inline void NbrNodes() {cout << Node<T>::NbNode;}
};


template <class T>
void Tree<T>::Viewing()
{
	if(root!=nullptr)
		Scan(root);
	else
		cout <<  "L'arbre est vide" << endl;
}


template<class T>
void Tree<T>::Scan(Node<T> *pNode)
{
	if(pNode->left)
		Scan(pNode->left);

	if(pNode)
		cout << pNode->nodeValue <<":"<<pNode->frequence << "/n";

	if(pNode->right)
		Scan(pNode->right);
}


template<class T>
void Tree<T>::Create(const T val, const int freq)
{
	Node<T> * pTmpNode = new Node<T>;

	pTmpNode->left = nullptr;
	pTmpNode->right = nullptr;

	pTmpNode->nodeValue = val;
	pTmpNode->frequence = freq;

	Insert(pTmpNode);
}


template <class T>
void Tree<T>::Insert(Node <T> *pNode)
{
	if(root == nullptr)
	{
		root=pNode;
		return;
	}

	Node<T> * current = root;
	Node<T> * previous = nullptr;

	while(current)
	{
		previous=current;

		if(pNode->frequence < current->frequence)
			current = current->left;
		else
			current = current->right;
	}

	if(pNode->frequence < previous->frequence)
		previous->left = pNode;
	else
		previous->right = pNode;
}

template<class T>
void Tree<T>::Delete(const T val)
{
	Node<T> *pNode = Search(val);

	if(!pNode)
	{
		cout << "Recherche ratée, cette valeur ne se trouve pas dans l'arbre"<<endl;
		return;
	}

	Node<T> *right = pNode->right;
	Node<T> *left = pNode->left;
	Node<T> *current = root;

	if (pNode == root)
	{
		root = right;

		if (left) Insert(left);

		delete pNode;
		return;
	}

	while(current)
	{
		if (current->right == pNode || current->left == pNode) break;

		if (pNode->frequence >= current->frequence)
			current = current->droite;
		else
			current = current->gauche;
	}

	if (current->right == pNode)
		current->right = right;
	else
		current->left = right;

	if (left) Insert(left);

	delete pNode;
	cout <<"Noeud effacé!"<<endl;
}


template <class T>
Node<T> *Tree<T>::Search(const T val)const
{
	Node<T> *current = root;

	while(current)
	{
		if ( ? < current->frequence)
			current = current->left;
		else
			current = current->right;
	}

	return nullptr;
}
