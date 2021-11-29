#ifndef _NODOGRAFO_
#define _NODOGRAFO_ 1

#include <vector>
#include "atoms.h"
#include "arco.h"

using namespace std;

class NodoGrafo {
    private:
        Atom* dato;
        vector<Arco*>* listaArcos;
        bool visitado = false;
        bool procesado = false;

    public:

        NodoGrafo(Atom* pDato) {
            this->dato = pDato;
            this->listaArcos = new vector<Arco*>();
        }

        NodoGrafo() {
            this->listaArcos = new vector<Arco*>();            
        }

        void setInfo(Atom* pDato) {
           this->dato = pDato; 
        }

        Atom* getDato() {
            return dato;
        }

        void addArc(Arco* pArco) {
            this->listaArcos->push_back(pArco);
        }

        vector<Arco*>* getArcs() {
            return this->listaArcos;
        }

        bool getVisitado(){
            return visitado;
        }

        bool getProcesado(){
            return procesado;
        }

        void setVisitado(bool pVisita){
            visitado = pVisita;
        }

        void setProcesado(bool pProceso){
            procesado = pProceso;
        }


};

#endif