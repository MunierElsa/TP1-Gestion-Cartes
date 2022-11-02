/* Squelette de départ TP1
 * TP1 - Mission lunaire
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://cria2.uqam.ca/INF3105/tp1/
 */

#include "carte.h"
#include "coordonnees.h"
#include <cmath>
#include <istream>
#include <limits>
#include <string> 
#include <sstream>

Tableau<unsigned int> Carte::topOrder(const Coordonnees& depart) const
{
  Tableau<unsigned int> result;
  //ETAPE 1
  //comme la methode est appelé de cette maniere :
  //carte.topOrder
  //on doit tout dabord trouver le point le plus proche de la carte pour chaque point de depart du fichier de depart

  //ETAPE 2
  //quand pour un point de depart on a trouver le point le plus proche de lui 
  //On implemente l'algorithme naif présenté dans le tp

  //ESAII IMPLEMENTATION ALGO NAIF
   double mindist =std::numeric_limits<double>::infinity();
  for(int i=0;i<_vMission[0].nbrSites;i++){
    for(int j=0;j<_vMission[1].nbrSites;j++){
      for(int k=0;k<_vMission[2].nbrSites;k++){

        double d = (depart.distance(_vMission[0].tabCoordoonees[i])) + 
        (_vMission[0].tabCoordoonees[i].distance(_vMission[1].tabCoordoonees[j])) + 
        (_vMission[1].tabCoordoonees[j].distance(_vMission[2].tabCoordoonees[k]));

        if(d<mindist){
          mindist = d;
          result.vider();
          result.ajouter(i+1);
          result.ajouter(j+1);
          result.ajouter(k+1);

        }
      }

    }
  }
  
 
  
  //std::cout <<"TAILLE :"<< result.taille() << std::endl;
  return result;
}



std::istream& operator >> (std::istream& is, Mission& mission)
{

    //std::string name;
    is >> mission.nom; //nom mission
    //std::cout << mission.nom << std::endl; 
    
    //int nb;
    is >> mission.nbrSites; //nombre Sites
    //std::cout << mission.nbrSites << std::endl;

    //Coordonnees de chaque mission
    Coordonnees* c = new Coordonnees[mission.nbrSites];
    for(int i=0;i<mission.nbrSites;i++){
        is >> c[i];
        mission.tabCoordoonees.ajouter(c[i]);
    }
    
    return is;
}

std::istream& operator >> (std::istream& is, Carte& carte)
{
    int n;
    is >> n;
    if(!is || !(n > 0)) { // détecter une anomalie
        assert(false);
        return is;
    }

    for(int i=0; i<n; i++) {
        Mission mission;
        is >> mission;
        carte._vMission.ajouter(mission);
    }

    return is;
}
