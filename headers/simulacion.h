#ifndef _SIMU_
#define _SIMU_ 0

#include <iostream>
#include <string>
#include "atoms.h"
#include "grafo.h"

using namespace std;


void initSimulation(int pCant, Grafo* universo){

    while (pCant!=0){
        
        for (int i = 0; i <universo->getSize()-1; i++){
            
            universo->dijkstra(i);
             
        }
        pCant--;
    }

    universo->printMatriz();
}


#endif