#include <fstream>
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

#include "Node.hpp"
#include "Tree.hpp"



//TESTER L'EXISTENCE D'UN FICHIER
bool doExists(string filename)
{
  ifstream ifs(filename.c_str(), ios::in);
  if(ifs)
    return true;
  else
    return false;
}



// CREATION DU FICHIER DES RESULTATS
void createFile(string filename)
{
  ofstream ofs(filename.c_str(), ios::out);
  if(ofs)
  {
    cout << "fichier cree avec succes \n";
    ofs.close();
  }
  else
    throw runtime_error("Erreur : impossible de creer le fichier !");
}



// ECRIRE LES DONNEES DANS LE FICHIER DES RESULTATS
void writeFileData(string filename, string text)
{
  ofstream ofs;
  ofs.open(filename.c_str(), ios::out | ios::app);          // on écrit à la fin du fichier avec "app" pour éviter l'overwrite
  if(ofs)
  {
    ofs << text;

    ofs.close();
  }
  else
    throw runtime_error("Erreur : impossible d'ecrire dans le fichier !");
}



//LECTURE DE DONNEES DANS UN FICHIER
void DoWordFreq(string filename, unordered_map<char, int>& word_freq, string& chaine)
{
  ifstream ifs(filename.c_str());
  if(ifs)
  {
    char letter;                          //une lettre du mot inscrit dans le fichier txt
    while( ifs.good() )
    {
      ifs.get(letter);                    //on récupère la lettre
      pair<char, int> word (letter, 1);   //préparation d'une paire pour la future insertion dans notre map
      unordered_map<char, int>::iterator search = word_freq.find(letter);   // itérateur pour rechercher la lettre passé en paramètre

      if( search == word_freq.end() )   //si on atteint la fin du fichier sans trouver la lettre
      {
        word_freq.insert(word);         //on l'insère dans la map
		    chaine += letter;
	    }
      else                              //sinon on incémente son occurence
        search->second += 1;
    }
    word_freq[letter] -= 1;             //on fait ceci car la boucle semble tourner une dernière fois sur la dernière lettre
  }
  else
    throw runtime_error("ERROR : can't open file in reading mode");
}


//MAIN
int main(int argc, char * argv[])
{
  unordered_map<char, int> freq;
  string filename = "test.txt";
  string chaine="";

  try {
    if ( doExists(filename) )
      cerr << "Le fichier existe déjà ! \n";
    else
    {
      createFile(filename);
      writeFileData(filename, "anticonstitutionnellement");   //on écrit un mot dans un fichier texte
      DoWordFreq(filename, freq, chaine);                     //remplissage de notre map
    }

    vector<Node*> nodeList (freq.size());     //vector de noeuds : on stocke leur références pour les retrouver plus facilement
    Tree * Huff = new Tree();                 //nouvel arbre
    char letter = ' ';                        //lettre du mot

    for (size_t i=0 ; i < freq.size() ; i++)  //on parcours le mot
    {
    	letter = chaine[i];
    	nodeList[i] = Huff->Tree::Create(letter, freq[letter]);  //création d'un noeud avec la ième lettre du mot et son occurence
    	cout << "Liste de noeud : " <<  nodeList.at(i) <<endl;   //ce qui est affiché est une référence sur un noeud
    }
  }
  catch(exception& e) {
    cerr << e.what() << endl;
  }


  return 0;
}
