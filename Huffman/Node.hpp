
#ifndef NODE_HPP
#define NODE_HPP

#include <stdio.h>
#include <iostream>

using namespace std;

class Node {
  private:
    static int NbNode;                                 // Compter le nombre de noeuds instanciés

  public:
    Node() {NbNode++;}
    ~Node() {delete [] right; delete [] left;}
    Node * left;
    Node * right;
    char nodeValue;
    int frequence;
    string code;
    inline const char& getValue() const {return nodeValue;}
    inline int getNbNode() {return NbNode;}

    friend class Tree;
};


int Node::NbNode = 0;

#endif
