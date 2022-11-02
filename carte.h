/* Squelette de départ TP1
 * TP1 - Mission lunaire
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://cria2.uqam.ca/INF3105/tp1/
 */

#if !defined(__CARTE_)
#define __CARTE_

#include <string>
#include "coordonnees.h"
#include "tableau.h"

class Mission {
  
  public:
    int nbrSites = 3; 
    char nom = ' ';
    int numeroMission = 0;
    Tableau<Coordonnees> tabCoordoonees;

    Mission(){
      numeroMission = numeroMission;
    }

    Mission(char nomTab, Tableau<Coordonnees> tab){ //constructeur
      nom = nomTab;
      tabCoordoonees = tab;
    }

};

class Carte {
  // À compléter.
  public:
    int nbrSitesTotal;
    Tableau<char> nomsSites;
    Tableau<unsigned int> topOrder(const Coordonnees& depart) const;
  
  private:
    Tableau<Mission> _vMission;
    
  friend std::istream& operator >> (std::istream&, Carte&);

};

#endif

