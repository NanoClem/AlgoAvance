
#include <stdio.h>
#include <iostream>

using namespace std;
#include "Node.hpp"



class Tree {

	private:
		Node *root;
		void Insert(Node *);
		void Scan(Node *);
		inline Node *Root() const {return root;}
		//Node *Search(const int) const;

	public:
		inline Tree() {root = nullptr;}
		~Tree();
		Node* Create(const char, const int);
		void Delete(const char );
		void Viewing();
		inline void NbrNodes() {cout << Node::NbNode;}
};


void Tree::Viewing()
{
	if(root!=nullptr)
		Scan(root);
	else
		cout <<  "L'arbre est vide" << endl;
}


void Tree::Scan(Node *pNode)
{
	if(pNode->left)
		Scan(pNode->left);

	if(pNode)
		cout << pNode->nodeValue <<":"<<pNode->frequence << "/n";

	if(pNode->right)
		Scan(pNode->right);
}


Node* Tree::Create(const char val, const int freq)
{
	Node * pTmpNode = new Node;

	pTmpNode->left = nullptr;
	pTmpNode->right = nullptr;

	pTmpNode->nodeValue = val;
	pTmpNode->frequence = freq;
	
	return pTmpNode;
	
}


void Tree::Insert(Node  *pNode)
{
	Node * current = root;
	Node * previous = nullptr;

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

/*void Tree::Delete(const char val)
{
	Node *pNode = Search(val);

	if(!pNode)
	{
		cout << "Recherche ratée, cette valeur ne se trouve pas dans l'arbre"<<endl;
		return;
	}

	Node *right = pNode->right;
	Node *left = pNode->left;
	Node *current = root;

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


Node *Tree::Search(const char val)const
{
	Node *current = root;

	while(current)
	{
		if ( ? < current->frequence)
			current = current->left;
		else
			current = current->right;
	}

	return nullptr;
}*/
