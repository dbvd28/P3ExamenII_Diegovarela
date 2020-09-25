#ifndef NODO_H
#define NODO_H
#include "Equipo.hpp"
class Nodo
{
private:

public:
 Nodo *nextnode;
Equipo* equipo;
    Nodo() {}
    Nodo(Equipo *_equipo)
    {
        equipo = _equipo;
    }
    void setnext_node(Nodo *_apuntador)
    {
        nextnode = _apuntador;
    }
    string getequipo(){
        return equipo->getnombre();
    }
    Nodo* next_node(){
        return nextnode;
    }
};
#endif