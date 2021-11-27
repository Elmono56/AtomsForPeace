#ifndef _READJSON_
#define _READJSON_ 

#include "json.hpp"
#include "fstream"
#include "iostream"
#include <vector>

#include <cstdlib>

using json = nlohmann::json;

using namespace std;

void getFromJSON(){

    fstream archivo("universo.json");

    json infoUniverso;

    archivo>>infoUniverso;

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
                if(infoUniverso["Universo"][i][x]!=infoUniverso["Universo"][tipoElementoAConectar][contadorIndiceConexion]){
                    cout << infoUniverso["Universo"][i][x] << " : " << infoUniverso["Universo"][tipoElementoAConectar][contadorIndiceConexion] << endl;

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