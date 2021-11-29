#ifndef _READJSON_
#define _READJSON_ 

#include "json.hpp"
#include "fstream"
#include "iostream"
#include <vector>
#include <cstdlib>
#include "atoms.h"
#include "grafo.h"


using json = nlohmann::json;

using namespace std;


Grafo universo = Grafo(true);

Atom arrayAtomosCreados[3][6];

void crearATomos(){

    fstream archivo("universo.json");
    json infoUniverso;
    archivo>>infoUniverso;

    for (int i = 0; i < 3; i++)
    {
        for (int x = 0; x < 6; x++)
        {
            cout << infoUniverso["Universo"][i][x] << endl;
            Atom atomoActual = Atom("1");
            universo.addNode(&atomoActual);
            arrayAtomosCreados[i][x] = atomoActual;
        }
    }
}
void enlazarAtomos(){

    int cantidadConexiones;
    int tipoElementoAConectar;
    int contadorConexiones = 0;
    int contadorIndiceConexion=0;

    for (int i = 0; i < 3; i++)
    {
        for (int x = 0; x < 6; x++)
        {
            cantidadConexiones = rand() % 6;
            cout << "Cantidad: " << cantidadConexiones << endl;
            while(contadorConexiones != cantidadConexiones)
            {
                tipoElementoAConectar = rand() %3;
                if(arrayAtomosCreados[i][x].getName()!=arrayAtomosCreados[tipoElementoAConectar][contadorIndiceConexion].getName()){
                    int numeroRandom = rand() % 20 +1;
                    universo.addArc(&arrayAtomosCreados[i][x],&arrayAtomosCreados[tipoElementoAConectar][contadorIndiceConexion],numeroRandom);
                    //cout << infoUniverso["Universo"][i][x] << " : " << infoUniverso["Universo"][tipoElementoAConectar][contadorIndiceConexion] << endl;
                }
                contadorConexiones++;
                contadorIndiceConexion++;
            }
            contadorConexiones=0;
            contadorIndiceConexion=0;
        }
    }
}

#endif 