
#include <iostream>
#include <string>
#include "headers/atoms.h"
#include "headers/simulacion.h"
#include "headers/vertice.h"
#include "headers/grafo.h"

using namespace std;


int main(){

    /*
    cout<<"DIGITE LA CANTIDAD DE GENERACIONES POR EJECUTAR"<<endl;

    int cant;

    cin>>cant;

    initSimulation(cant);
    */


    Grafo g = Grafo();
    
    Atom b0 = Atom();
    Atom b1 = Atom();
    Atom c2 = Atom();
    Atom d3 = Atom();
    Atom e4 = Atom();
    Atom f5 = Atom();
    Atom g6 = Atom();
    Atom h7 = Atom();

    Atom* a0 = &b0;
    Atom* a1 = &b1;
    Atom* a2 = &c2;
    Atom* a3 = &d3;
    Atom* a4 = &e4;
    Atom* a5 = &f5;
    Atom* a6 = &g6;
    Atom* a7 = &h7;




    g.agregarVertice(a0);
    g.agregarVertice(a1);
    g.agregarVertice(a2);
    g.agregarVertice(a3);
    g.agregarVertice(a4);
    g.agregarVertice(a5);
    g.agregarVertice(a6);
    g.agregarVertice(a7);
    
    g.agregarArista(g.buscarVertice(a0), g.buscarVertice(a2));
    g.agregarArista(g.buscarVertice(a2), g.buscarVertice(a0));
    g.agregarArista(g.buscarVertice(a0), g.buscarVertice(a7));
    g.agregarArista(g.buscarVertice(a7), g.buscarVertice(a0));
    g.agregarArista(g.buscarVertice(a0), g.buscarVertice(a5));
    g.agregarArista(g.buscarVertice(a5), g.buscarVertice(a0));
    g.agregarArista(g.buscarVertice(a1), g.buscarVertice(a7));
    g.agregarArista(g.buscarVertice(a7), g.buscarVertice(a1));
    g.agregarArista(g.buscarVertice(a2), g.buscarVertice(a6));
    g.agregarArista(g.buscarVertice(a6), g.buscarVertice(a2));
    g.agregarArista(g.buscarVertice(a3), g.buscarVertice(a4));
    g.agregarArista(g.buscarVertice(a4), g.buscarVertice(a3));
    g.agregarArista(g.buscarVertice(a3), g.buscarVertice(a5));
    g.agregarArista(g.buscarVertice(a5), g.buscarVertice(a3));
    g.agregarArista(g.buscarVertice(a4), g.buscarVertice(a7));
    g.agregarArista(g.buscarVertice(a7), g.buscarVertice(a4));
    g.agregarArista(g.buscarVertice(a4), g.buscarVertice(a6));
    g.agregarArista(g.buscarVertice(a6), g.buscarVertice(a4));
    g.agregarArista(g.buscarVertice(a4), g.buscarVertice(a5));
    g.agregarArista(g.buscarVertice(a5), g.buscarVertice(a4));

    
    cout<<"LLEGA HASTA AQUI"<<endl;
    //g.impriimir();

    g.profundidad();
    
    cout<<"HIZO PROFUNDIDAD"<<endl;

    g.anchura(g.getVertices()->at(0));




    return 0;
}