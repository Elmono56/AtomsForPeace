
#include <iostream>
#include <string>
#include "headers/atoms.h"
#include "headers/simulacion.h"
#include "headers/vertice.h"
#include "headers/grafo.h"

using namespace std;


int main(){

    cout<<"DIGITE LA CANTIDAD DE GENERACIONES POR EJECUTAR"<<endl;

    int cant;

    cin>>cant;

    initSimulation(cant);

}