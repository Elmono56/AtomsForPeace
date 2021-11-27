#ifndef _GETJSON_
#define _GETJSON_ 0

#include "json.hpp"
#include "fstream"
#include "iostream"
#include <vector>
#include "atoms.h"

using json = nlohmann::json;

using namespace std;

vector<Atom> getFromJSON(){

    std::vector<Atom> vectorAtoms;

    fstream archivo("atomsdata.json");

    json infoDioses;

    archivo>>infoDioses;

    for (int i = 0; i < 20; i++){
        
        vectorDioses.push_back(Dios(infoDioses["Dioses"][i],infoDioses["Fieles"][i]));
    }
    return vectorDioses;
}

#endif 