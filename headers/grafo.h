#ifndef _GRAFO_
#define _GRAFO_ 1

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>

#include "atoms.h"
#include "arco.h"
#include "nodografo.h"

using namespace std;

class Grafo {
    private:
        vector<NodoGrafo*> listaNodos;
        bool esDirigido = true;
        std::map<int,NodoGrafo*> hashNodos;
        vector<vector<int>> matrizGrafo = vector<vector<int>>();

        void resetNodes() {
            for (std::vector<NodoGrafo*>::iterator current = listaNodos.begin() ; current != listaNodos.end(); ++current) {
                NodoGrafo* actual = (*current);
                actual->setProcesado(false);
                actual->setVisitado(false);
            }
        }

        NodoGrafo* findNotVisited() {
            NodoGrafo* result = nullptr;
            for (std::vector<NodoGrafo*>::iterator current = listaNodos.begin() ; current != listaNodos.end(); ++current) {
                NodoGrafo* actual = (*current);
                if (!actual->getVisitado()) {
                    result = actual;
                    break;
                }
            }
            return result;
        }

    public:
        Grafo(bool pDirigido) {
            this->esDirigido =  pDirigido;
        }

        int getSize() {
            return this->listaNodos.size();
        }

        void addNode(Atom* pNodo) {
            NodoGrafo* nuevoNodo = new NodoGrafo(pNodo);
            agrandarMatriz();
            this->listaNodos.push_back(nuevoNodo);
            hashNodos.insert(pair<int,NodoGrafo*>(pNodo->getId(),nuevoNodo));
        }

        void agrandarMatriz(){
            vector<int> auxiliar = vector<int>();

            for(int i = 0; i <listaNodos.size();i++){
                matrizGrafo.at(i).push_back(0);
            }

            for(int i = 0; i<listaNodos.size()+1;i++){
                auxiliar.push_back(0);
            }

            matrizGrafo.push_back(auxiliar);

        }

        void printMatriz(){
            
            for (int i = 0; i<matrizGrafo.size(); i++){

                for (int j = 0; j<matrizGrafo.size(); j++){

                   cout<<matrizGrafo[i][j]<<"\t";
                    
                }
                cout<<endl;

            }
        }

        void add_edge(int pOrigen, int pDestino, int pPeso) {
            matrizGrafo.at(pOrigen).at(pDestino) = pPeso;
        }

        void addArc(NodoGrafo* pOrigen, NodoGrafo* pDestino, int pPeso) {
            Arco* newArc = new Arco(pOrigen, pDestino, pPeso);
            int index1;
            for (int i = 0; i<listaNodos.size(); i++){
                if (pOrigen == listaNodos.at(i)){
                    index1 = i;
                    break;
                }
            }

            int index2;
            for (int i = 0; i<listaNodos.size(); i++){
                if (pDestino == listaNodos.at(i)){
                    index2 = i;
                    break;
                }
            }

            pOrigen->addArc(newArc);
            add_edge(index1,index2,pPeso);
            if (!this->esDirigido) {
                Arco* reverseArc = new Arco(pDestino, pOrigen , pPeso);
                pDestino->addArc(reverseArc);
                add_edge(index2,index1,pPeso);
            }
        }

        void addArc(NodoGrafo* pOrigen, NodoGrafo* pDestino) {
            this->addArc(pOrigen, pDestino, 0);
        }
        
        void addArc(Atom* pOrigen, Atom* pDestino) {
            this->addArc(pOrigen->getId(), pDestino->getId(), 0);
        }

        void addArc(Atom* pOrigen, Atom* pDestino, int pPeso) {
            this->addArc(pOrigen->getId(), pDestino->getId(), pPeso);
        }
        
        void addArc(int pOrigen, int pDestino) {
            this->addArc(pOrigen, pDestino, 0);
        }

        void addArc(int pOrigen, int pDestino, int pPeso) {
            this->addArc(this->getNodo(pOrigen), this->getNodo(pDestino), pPeso);
        }

        NodoGrafo* getNodo(int pId) { 
            return hashNodos.at(pId);
        }

        int minDistance(vector<int> dist, vector<bool> sptSet){
        
            //inciarlizar valor mínimo
            int min = INT_MAX, min_index;
        
            for (int i = 0; i < dist.size(); i++){
                if (sptSet[i] == false && dist[i] <= min){
                    min = dist[i], min_index = i;
                }
                    
            }
        
            return min_index;
            
        }
        
        void dijkstra(int pOrigen){//número de como se metió al grafo

            vector<int> dist = vector<int>();
            vector<bool> sptSet = vector<bool>();
        
            for (int i = 0; i < listaNodos.size(); i++){
                dist.push_back(INT_MAX);
                sptSet.push_back(false);
            }

            dist.at(pOrigen) = 0;
        
            for (int count = 0; count < matrizGrafo.size() - 1; count++) {
                int u = minDistance(dist, sptSet);
        
                sptSet.at(u) = true;
        
                for (int i = 0; i < matrizGrafo.size(); i++){

                    if (!sptSet.at(i) && matrizGrafo.at(u).at(i) && dist.at(u) != INT_MAX && dist.at(u) + matrizGrafo.at(u).at(i) < dist.at(i)){
                        dist.at(i) = dist.at(u) + matrizGrafo.at(u).at(i);
                    }

                }
                    
            }


            //accionAtom(pOrigen, &dist);

            for (int i = 0; i<dist.size(); i++){
                cout<<dist.at(i)<<" ";
            }
            cout<<endl;
            
        }

        void accionAtom(int pOrigen, vector<int>* pCaminos){

            NodoGrafo* nodoOrigen = listaNodos.at(pOrigen);

            Atom* atomoOrigen = nodoOrigen->getDato();

            int i1 = getIndexMinino(pCaminos);
            int i2 = getIndexMaximo(pCaminos);

            Atom* atomoMinimo = listaNodos.at(i1)->getDato();
            Atom* atomoMaximo = listaNodos.at(i2)->getDato();

            if (atomoOrigen->getName() == atomoMinimo->getName()){
                //REPRODUCCION

                if (atomoMinimo->getName()=="Galea"){
                    Galea aux = Galea();
                    addNode(&aux);
                    addArc(atomoMinimo,&aux,pCaminos->at(i1));
                }
                else if (atomoMinimo->getName()=="Inti"){
                    Inti aux = Inti();
                    addNode(&aux);
                    addArc(atomoMinimo,&aux,pCaminos->at(i1));
                }
                else if (atomoMinimo->getName()=="Katmeo"){
                    Katmeo aux = Katmeo();
                    addNode(&aux);
                    addArc(atomoMinimo,&aux,pCaminos->at(i1));
                }

            }
            cout<<listaNodos.size()<<endl;



        }

        int getIndexMinino(vector<int>* pCaminos){
            int minimo = 0;
            for (int i = 0; i<pCaminos->size();i++){
                if (pCaminos->at(i)<minimo & pCaminos->at(i)>0){
                    minimo = i;
                }
            }

            return minimo;

        }   

        int getIndexMaximo(vector<int>* pCaminos){
            int maximo = 0;
            for (int i = 0; i<pCaminos->size();i++){
                if (pCaminos->at(i)>maximo & pCaminos->at(i)<10000){
                    maximo = i;
                }
            }

            return maximo;

        } 


        
};

#endif