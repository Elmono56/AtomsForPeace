
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

    /*
    cout<<"DIGITE LA CANTIDAD DE GENERACIONES POR EJECUTAR"<<endl;

    int cant;

    cin>>cant;

    initSimulation(cant);
    */


    Grafo g = Grafo(false);
    
    Atom a0 = Atom("0");
    Atom a1 = Atom("1");
    Atom a2 = Atom("2");
    Atom a3 = Atom("3");
    Atom a4 = Atom("4");

    g.addNode(&a0);
    g.addNode(&a1);
    g.addNode(&a2);
    g.addNode(&a3);
    g.addNode(&a4);

    cout<<g.getSize()<<endl;

    g.addArc(&a1,&a0,170);
    g.addArc(&a1,&a2,245);
    g.addArc(&a1,&a3,90);
    g.addArc(&a2,&a0,115);
    g.addArc(&a0,&a3,230);
    g.addArc(&a3,&a1,88);
    g.addArc(&a3,&a4,60);
    g.addArc(&a4,&a1,115);

    cout<<"LLEGA"<<endl;

    g.printMatriz();



    /*
    cout<<a0->getId()<<endl;
    cout<<a1->getId()<<endl;
    cout<<a2->getId()<<endl;
    cout<<a3->getId()<<endl;
    cout<<a4->getId()<<endl;
    cout<<a5->getId()<<endl;
    cout<<a6->getId()<<endl;
    cout<<a7->getId()<<endl;
    */


    
    //cout<<"LLEGA HASTA AQUI"<<endl;

    //cout<<a4->getName()<<endl;

    //g.imprimir();

    //g.profundidad();
    
    //cout<<"HIZO PROFUNDIDAD"<<endl;

    //g.anchura(g.getVertices()->at(0));




    return 0;
}