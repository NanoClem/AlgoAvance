#include <fstream>
#include <stdio.h>
#include <stdexcept>
#include <iostream>

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


//MAIN
int main(int argc, char * argv[])
{
  cout << "ok \n";

  return 0;
}
