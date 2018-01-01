
#ifndef NODE_HPP
#define NODE_HPP

#include <stdio.h>
#include <iostream>

using namespace std;


// template <class T> class Tree;


template <class T>
class Node {
  private:
    static int NbNode;                                 // Compter le nombre de noeuds instanciés

  public:
    Node() {NbNode++;}
    ~Node() {delete [] right; delete [] left;}
    Node * left;
    Node * right;
    T nodeValue;
    inline T& getValue() const {return nodeValue;}
    inline int getNbNode() {return NbNode;}

    friend class Tree<T>;
};


template<class T>
int Node<T>::NbNode = 0;

#endif
