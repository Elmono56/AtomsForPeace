#ifndef _ATOMS_
#define _ATOMS_ 0

#include <iostream>
#include <string>

using namespace std;

class Atom{

    private:
    
        string name;

    public:

        Atom(){
            name = "";
        }

        Atom(string pName){
            name = pName;
        }

        string getName(){
            return name;
        }
        
        void setName(string pName){
            name = pName;
        }


};


class Galea : public Atom{

    private:


    public:

        Galea():Atom("Galea"){

        }


};


class Inti : public Atom{

    private:


    public:

        Inti():Atom("Inti"){

        }


};

class Katmeo : public Atom{

    private:


    public:

        Katmeo():Atom("Katmeo"){

        }


};



#endif