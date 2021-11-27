
#include <iostream>
#include <string>
#include "atoms.h"
#include "simulacion.h"

using namespace std;


int main(){

    cout<<"DIGITE LA CANTIDAD DE GENERACIONES POR EJECUTAR"<<endl;

    int cant;

    cin>>cant;

    initSimulation(cant);

}