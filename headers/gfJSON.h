#ifndef _GETJSON_
#define _GETJSON_ 0

#include "json.hpp"
#include "fstream"
#include "iostream"
#include <vector>
#include <cstdlib>
#include "atoms.h"
#include "grafo.h"


using json = nlohmann::json;

using namespace std;


Grafo a = Grafo(true);
Grafo* universo = &a;
Grafo g = Grafo(true);

vector<vector<Atom*>*> vectorAtomosCreados = vector<vector<Atom*>*>();

void crearATomos(){

    fstream archivo("atomsdata.json");
    json infoUniverso;
    archivo>>infoUniverso;

    for (int i = 0; i <3; i++){
        vector<Atom*> aux = vector<Atom*>();
        for (int x = 0; x<6; x++){
            aux.push_back(nullptr);
        }
        vectorAtomosCreados.push_back(&aux);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int x = 0; x < 6; x++)
        {

            if (infoUniverso["Universo"][i][x] == "Galea"){
                Galea atomoActual = Galea();
                universo->addNode(&atomoActual);
                vectorAtomosCreados.at(i)->at(x) = &atomoActual;
            }
            else if (infoUniverso["Universo"][i][x] == "Inti"){
                Inti atomoActual = Inti();
                universo->addNode(&atomoActual);
                vectorAtomosCreados.at(i)->at(x) = &atomoActual;
            }
            else if (infoUniverso["Universo"][i][x] == "Katmeo"){
                Katmeo atomoActual = Katmeo();
                universo->addNode(&atomoActual);
                vectorAtomosCreados.at(i)->at(x) = &atomoActual;
            }
            else{
                Atom atomoActual = Atom("Atomo");
                universo->addNode(&atomoActual);
                vectorAtomosCreados.at(i)->at(x) = &atomoActual;
            }
        }
    }
}
Grafo* enlazarAtomos(){

    /*
    crearATomos();

    int cantidadConexiones;
    int tipoElementoAConectar;
    int contadorConexiones = 0;
    int contadorIndiceConexion=0;

    for (int i = 0; i < 3; i++)
    {
        for (int x = 0; x < 6; x++)
        {
            cantidadConexiones = rand() % 6;
            while(contadorConexiones != cantidadConexiones)
            {
                
                tipoElementoAConectar = rand() %3;
                if(vectorAtomosCreados.at(i)->at(x)->getId()!=vectorAtomosCreados.at(tipoElementoAConectar)->at(contadorIndiceConexion)->getId()){
                    int numeroRandom = rand() & 20;
                    numeroRandom = numeroRandom +1;
                    cout<<numeroRandom<<endl;
                    universo->addArc(vectorAtomosCreados.at(i)->at(x),vectorAtomosCreados.at(tipoElementoAConectar)->at(contadorIndiceConexion),numeroRandom);
                    //cout << infoUniverso["Universo"][i][x] << " : " << infoUniverso["Universo"][tipoElementoAConectar][contadorIndiceConexion] << endl;
                }
                contadorConexiones++;
                contadorIndiceConexion++;
            }
            contadorConexiones=0;
            contadorIndiceConexion=0;
        }
    }


    universo->printMatriz();
    */
    
    Galea a0 = Galea();
    Inti a1 = Inti();
    Katmeo a2 = Katmeo();
    Galea a3 = Galea();
    Inti a4 = Inti();
    Katmeo a5 = Katmeo();

    g.addNode(&a0);
    g.addNode(&a1);
    g.addNode(&a2);
    g.addNode(&a3);
    g.addNode(&a4);
    g.addNode(&a5);

    g.addArc(&a1,&a0,170);
    g.addArc(&a1,&a2,245);
    g.addArc(&a1,&a3,90);
    g.addArc(&a2,&a0,115);
    g.addArc(&a0,&a3,230);
    g.addArc(&a3,&a1,88);
    g.addArc(&a3,&a4,60);
    g.addArc(&a4,&a1,115);
    g.addArc(&a5,&a0,450);
    g.addArc(&a5,&a2,102);

    return &g;

}


#endif 