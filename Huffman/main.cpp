#include <fstream>
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <unordered_map>

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
// il reste à mettre en paramètre les données qui doivent être écrites
void writeFileData(string filename)
{
  ofstream ofs;
  ofs.open(filename.c_str(), ios::out | ios::app);          // on écrit à la fin du fichier avec "app" pour éviter l'overwrite
  if(ofs)
  {
    ofs << " \n";

    ofs.close();
  }
  else
    throw runtime_error("Erreur : impossible d'ecrire dans le fichier !");
}



//LECTURE DE DONNEES DANS UN FICHIER
//penser à remplacer les char par des string pour lire les mots à l'avenir
void DoWordFreq(string filename, unordered_map<char, int> word_freq)
{
  ifstream ifs(filename.c_str());
  if(ifs)
  {
    char letter;
    while( ifs.good() )
    {
      ifs.get(letter);      //char par char pour le moment
      pair<char, int> word (letter, 1);
      unordered_map<char, int>::iterator search = word_freq.find(letter);  // itérateur pour rechercher le mot passé en paramètre

      if( search == word_freq.end() )
        word_freq.insert(word);
      else
      {
        search->second += 1;
        cout << search->first << " : " << search->second << endl;
      }
    }
  }
  else
    throw runtime_error("ERROR : can't open file in reading mode");
}



//MAIN
int main(int argc, char * argv[])
{
  cout << "ok \n";

  return 0;
}
