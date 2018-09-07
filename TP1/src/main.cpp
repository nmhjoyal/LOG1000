/*
 * File:   main.cpp
 * Author: bram
 *
 * Created on November 8, 2015, 8:39 PM
 */

#include <iostream>
#include "HashMap.h"
#include <fstream>
using namespace std;


/*
    Le but du programme est de compter la fréquence d'apparition des mots d'un texte (fichier.txt)
    Il prend en argument le nom du fichier et affiche en sorti le mot avec la plus grande occurence ainse que l'occurence elle même.
*/

int main(int argc, char* argv[]) {
  HashMap map;
  std::string fileName = argv[1];
  if(!fileName.empty()){
	std::ifstream file;
    file.open(fileName);
    std::string word;
    std::cout<< "Nom du fichier: " << fileName << '\n';

    if (file.is_open()){
        printf("file opened\n");
    }else{
        printf("file closed\n");
    }

    while (file >> word)
    {
 	  map.put( word , map.compteur(word) );
        // std::cout<< word << " " << nbOccurences << '\n';
    }

//    int nbOccurences = myMap.compteur(word);
    std::vector<std::string> myMapKeys = map.getKeys();

    std::string resultatString;
    int resultatsOccurences = 0;

    for(int i = 0; i<myMapKeys.size() ; i++){
        int currentValue = 0;
        map.get(myMapKeys[i],currentValue);

        if(currentValue > resultatsOccurences){
            resultatsOccurences = currentValue;
            resultatString = myMapKeys[i];
        }

    }

    std::cout << "Plus grande occurence : "<< resultatString << "---" << resultatsOccurences << '\n';
}

  //utilisation normale
  return 0;
}
