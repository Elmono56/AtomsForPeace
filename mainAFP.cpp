
#include <iostream>
#include <string>
#include "headers/arco.h"
#include "headers/atoms.h"
#include "headers/grafo.h"
#include "headers/nodografo.h"
#include "headers/simulacion.h"
#include "headers/gfJSON.h"

using namespace std;


int main(){

    
    cout<<"DIGITE LA CANTIDAD DE GENERACIONES POR EJECUTAR"<<endl;

    int cant;

    cin>>cant;

    Grafo* universo = enlazarAtomos();

    initSimulation(cant, universo);
    

    return 0;

}