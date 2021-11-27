#ifndef _GRAFO_
#define _GRAFO_ 0

#include <iostream>
#include <string>
#include <vector>
#include "atoms.h"
#include "vertice.h"

using namespace std;

class Grafo{

    private:

        vector<Vertice*> vertices;

    public:

        Grafo(){
            vertices = vector<Vertice*>();
        }

        
        Vertice* buscarVertice(Vertice* pVert){

            for (int i = 0; i<vertices.size(); i++){

                if (pVert->getDato()==vertices.at(i)->getDato()){
                    return vertices.at(i);
                }
            }
        
        return nullptr;
        }

        Vertice* buscarVertice(Atom* pData){

            for (int i = 0; i<vertices.size(); i++){

                if (pData==vertices.at(i)->getDato()){
                    return vertices.at(i);
                }
            }
        
        return nullptr;
        }

        void agregarVertice(Atom* pData){
            
            Vertice nuevo = Vertice(pData);

            vertices.push_back(&nuevo);
        }

        void agregarArista(Vertice* pOrigen, Vertice* pDestino){
            
            if(pOrigen!=nullptr && pDestino!=nullptr){
                pOrigen->agregarAristas(pDestino);
            }
        }

        void agregarArista(Vertice* pOrigen, Vertice* pDestino, int pPeso){
            
            if(pOrigen!=nullptr && pDestino!=nullptr){
                pOrigen->agregarAristas(pDestino, pPeso);
            }
        }

        void eliminarVertice(Vertice* pVert){
            
            int aux;

            for (int i = 0; i < vertices.size(); i++){

                for (int j = 0; j <vertices.size(); j++){

                    if(vertices.at(i)->getAristas()->at(j)->getDato() == pVert->getDato()){
                        vertices.at(i)->getAristas()->erase(vertices.at(i)->getAristas()->begin()+j);
                    }

                }

                if (pVert == vertices.at(i)){
                    aux = i;
                }
                
            }

            vertices.at(aux)->getAristas()->erase(vertices.begin()+aux);


        }

        void visitarVertice(Vertice* pNodo){

            for (int i = 0; i<vertices.size();i++){

                if (pNodo->getDato() == vertices.at(i)->getDato()){
                    vertices.at(i)->setVisitado(true);
                }

            }


        }

        bool verticeVisitado(Vertice* pNodo){
            
            for (int i = 0; i<vertices.size(); i++){

                if (pNodo->getDato()==vertices.at(i)->getDato()){
                    return vertices.at(i)->getVisitado();
                }

            }
            return false;
            
        }

        void visitarAdyacentes(Vertice* pOrigen){
            
            visitarVertice(pOrigen);
            cout<<pOrigen->getDato()->getName()<<"    ";

            //para cada arista
            for (int i = 0; i<pOrigen->getAristas()->size(); i++){

                //marcar adyacentes
                if(!verticeVisitado(pOrigen->getAristas()->at(i))){
                    visitarVertice(buscarVertice(pOrigen->getAristas()->at(i)));
                }

            }
            cout<<endl;

        }

        void profundidad(){
            
            for (int i = 0; i < vertices.size(); i++){

                cout<<vertices.at(i)->getDato()->getName()<<endl;

                if(!vertices.at(i)->getVisitado()){
                    visitarAdyacentes(vertices.at(i));
                    cout<<vertices.at(i)->getDato()->getName()<<"   ";
                }
                cout<<i<<endl;

            }
            cout<<endl;
            cout<<"sale"<<endl;
            limpiarVisitados();

        }
        
        void limpiarVisitados(){
            
            cout<<"LIMPIA"<<endl;

            for (int i = 0; i<vertices.size();i++){

                vertices.at(i)->setVisitado(false);

            }

        }

        void anchura(Vertice* pVert){

            visitarVertice(pVert);
            cout<<pVert->getDato()->getName()<<"    ";

            vector<Vertice*> cola = vector<Vertice*>();

            //meter a la cola los adyacentes del nodo inicial
            for (int i = 0; i < pVert->getAristas()->size(); i++) {
                cola.push_back(buscarVertice(pVert->getAristas()->at(i)));// es para buscar el nodo en vertices
                visitarVertice(pVert->getAristas()->at(i));
              
            }

            while (!cola.empty()){

                //primer elemento de la cola
                Vertice* actual = cola.at(0);
                cola.erase(cola.begin());
                cout<<actual->getDato()->getName()<<"    ";

                //cada arista del vertice en la cola
                for (int i = 0; i<actual->getAristas()->size();i++){

                    //si no se ha visitado se mete a la cola del adyacente
                    if (verticeVisitado(actual->getAristas()->at(i))==false){

                        visitarVertice(buscarVertice(actual->getAristas()->at(i)));

                        cola.push_back(actual->getAristas()->at(i));
                    }

                }

            }

            limpiarVisitados();

        }

        /*
        void imprimir (){
            for (int i = 0; i < vertices.size(); i++){
                cout<<"Vertice " << vertices.at(i)->getDato()->getName()+":  ");
                for (int j = 0; j < vertices.at(i)->aristas.size(); j++){
                    System.out.print(vertices.get(i).aristas.get(j).dato +"  ");
                }
                System.out.println("");
            }
        }*/



        vector<Vertice*>* getVertices(){
            return &vertices;
        }


};




#endif