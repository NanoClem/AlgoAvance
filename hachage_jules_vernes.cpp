#include <iostream>
#include <fstream>
#include <unordered_map>
#include <regex>

using namespace std;


int main()
{
  ifstream jules("jules_vernes.txt");
  // voir basic_regex
  regex const pattern {R"(\.)"};  //, R"(\,)", R"(\;)", R"(\-)", R"(\_)", R"(\?)", R"(\!)", R"(\")", R"(\:)"};   // pattern des expressions régulières à retirer des mots

  unordered_map<string, int> book;               // Le conteneur clé/valeur
  pair<string, int> test ("Chapitre", 0);        // paire de test
  book.insert(test);

  if(jules)                             // True si il n'y a pas d'erreur de flags
  {
    cout << "DEBUT \n";
    string line;                        // On stocke chaque ligne lue ici
    while( jules.good() )               // Tant qu'on est pas à la fin du fichier
    {
      jules >> line;                    // on lit les lignes mot par mot
      line = regex_replace(line, pattern, "");

      pair<string, int> word (line, 1); // paire clé/valeur
      unordered_map<string,int>::iterator search = book.find(line); // itérateur pour rechercher le mot passé en paramètre

      if( search == book.end() )
        book.insert(word);
      else
      {
        search->second += 1;
        cout << search->first << " : " << search->second << "\n";
      }
    }
  }
  else
    cerr << "ERROR : can't open file in reading mode \n";


 // cout << "DEBUT AFFICHAGE \n";
 //  for(auto& x: book)
 //  {
 //    cout << x.first << ": " << x.second << endl;
 //  }
 //  cout << "FIN AFFICHAGE \n";
   return 0;
}
