#ifndef _VERTICE_
#define _VERTICE_ 0

#include <iostream>
#include <string>
#include <vector>
#include "atoms.h"

using namespace std;

class Vertice{

    private:

        Atom* dato;
        bool visitado;
        vector<Vertice*> aristas;
        int peso;

    public:

    Vertice(Atom* pDato){
        aristas = vector<Vertice*>();
        dato = pDato;
        visitado = false;
        peso = 0;
    }


    Vertice(Atom* pDato, int pPeso){
        aristas = vector<Vertice*>();
        dato = pDato;
        visitado = false;
        peso = pPeso;

    }

    int buscarArista(Vertice* pVert){
        
        for (int i = 0; i < aristas.size(); i++){

            if (pVert->dato == aristas.at(i)->dato){
                return i;
            }

        }

        return -1;

    }

    void agregarAristas(Vertice* pVert){
        
        //no repetir la arista
        if (buscarArista(pVert)==-1){
            Vertice nuevo = Vertice(pVert->dato);
            aristas.push_back(&nuevo);
        }

    }

    void agregarAristas(Vertice* pVert, int pPeso){
        
        //no repetir la arista
        if (buscarArista(pVert)==-1){
            Vertice nuevo = Vertice(pVert->dato, pPeso);
            aristas.push_back(&nuevo);
        }

    }




    Atom* getDato(){
        return dato;
    }

    vector<Vertice*>* getAristas(){
        return &aristas;
    }

    bool getVisitado(){
        return visitado;
    }

    void setVisitado(bool visit){
        visitado = visit;
    }


};


#endif