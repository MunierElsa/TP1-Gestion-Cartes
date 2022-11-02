/* Squelette pour classe générique Tableau<T>.
 * Lab3 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://cria2.uqam.ca/INF3105/lab3/
 */

#if !defined(_TABLEAU___H_)
#define _TABLEAU___H_

#include <assert.h>

template <class T>
class Tableau{

  public:
    Tableau(int capacite_initiale=4);
    Tableau(const Tableau&);
    ~Tableau();

    // Ajouter un element à la fin
    void           ajouter(const T& element);
    // Vider le tableau
    void           vider();
    // Retourne le nombre d'éléments dans le tableau
    int            taille() const;

    // Insère element à position index. Les éléments à partir de index sont décalés d'une position.
    void           inserer(const T& element, int index=0);

    // Enlève l'element à position index. Les éléments après index sont décalés d'une position.
    void           enlever(int index=0);

    // Cherche et retourne la position de l'élément. Si non trouvé, retourne -1.
    int            chercher(const T& element);

    const T&       operator[] (int index) const;
    T&             operator[] (int index);

    bool           operator == (const Tableau<T>& autre) const;
    Tableau<T>&    operator = (const Tableau<T>& autre);

  private:
    void           redim();
    T*             elements;
    int            nbElements;
    int            capacite;
};


// ---------- Définitions -------------


template <class T>
Tableau<T>::Tableau(int capacite_)
{
    capacite = capacite_;
    elements = new T[capacite]; 
    nbElements = 0;
}

template <class T>
Tableau<T>::Tableau(const Tableau& autre)
{
    capacite = autre.capacite;
    nbElements = autre.nbElements;
    elements = new T[capacite];
    for (int i = 0; i < nbElements; i++) {
        elements[i] = autre.elements[i];
    }
}

template <class T>
Tableau<T>::~Tableau()
{
    delete[] elements;
}

template <class T>
int Tableau<T>::taille() const
{
    return nbElements;
}

template <class T>
void Tableau<T>::ajouter(const T& item)
{
    if (nbElements >= capacite) 
        redim();
        
    elements[nbElements] = item;
   
    nbElements++;
}

template <class T>
void Tableau<T>::inserer(const T& element, int index)
{
    assert (index <= nbElements);
    if (nbElements >= capacite) 
        redim();
         
    T temp2,  temp = elements[index];
    elements[index] = element;
    nbElements++;
    for (int i = index +1; i < nbElements; i++) {
        temp2 = elements[i];
        elements[i] = temp;
        temp = temp2;    
    }
}

template <class T>
void Tableau<T>::enlever(int index)
{
    assert (index < nbElements);
    for (int i = index; i < nbElements; i++) {
        elements[i] = elements[i +1];
    }
    nbElements--;
}

template <class T>
int Tableau<T>::chercher(const T& element)
{
    int index = -1;
    for (int i = 0; i < nbElements; i++) {
        if(elements[i] == element) index = i;
    }
    return index;
}

template <class T>
void Tableau<T>::vider()
{
    nbElements = 0;
}

template<class T>
void Tableau<T>::redim(){
    T* temp = new T[capacite*2];
    for (int i = 0; i < nbElements; i++) {
        temp[i] = elements[i];
    }
    capacite = capacite *2;
    delete[] elements;
    elements = temp;
}

template <class T>
const T& Tableau<T>::operator[] (int index) const
{
    assert(index < nbElements);
    return elements[index];
}

template <class T>
T& Tableau<T>::operator[] (int index)
{
    assert(index < nbElements);
    return elements[index];
}

template <class T>
Tableau<T>& Tableau<T>::operator = (const Tableau<T>& autre)
{
    if (this == &autre) return *this;
    capacite = autre.capacite;
    nbElements = autre.nbElements;
    delete[] elements  ;
    elements = new T[capacite];
    for (int i = 0; i < nbElements; i++) {
        elements[i] = autre.elements[i];
    }
    return *this;
}

template <class T>
bool Tableau<T>::operator == (const Tableau<T>& autre) const
{
    bool egal = capacite  == autre.capacite 
    && nbElements == autre.nbElements;
    if(egal)
        for (int i = 0; i < nbElements; i++) {
            if(elements[i] != autre.elements[i]) egal = false;
        }
    
    return egal;
}

#endif //define _TABLEAU___H_
