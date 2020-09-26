#include <iostream>
#include <vector>
#include <iomanip>
#include "Nodo.hpp"
#include <string>
#include <stdlib.h>
#include <bits\stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    Nodo *topepila = nullptr;
    fstream lector(argv[1]);
    string linea = "";
    string nombre = "";
    int gan = 0;
    int emp = 0;
    int per = 0;
    int partj = 0;
    int difg = 0;
    int gola = 0;
    int golc = 0;
    int punts = 0;
    while (!lector.eof())
    {
        lector >> linea;
        string line = linea;
        // Vector of string to save tokens
        vector<string> tokens;

        // stringstream class check1
        stringstream check1(line);

        string intermediate;

        // Tokenizing w.r.t. space ' '
        while (getline(check1, intermediate, ','))
        {
            tokens.push_back(intermediate);
        }
        nombre = tokens[0];
        gan = stoi(tokens[1]);
        per = stoi(tokens[2]);
        emp = stoi(tokens[3]);
        gola = stoi(tokens[4]);
        golc = stoi(tokens[5]);
        partj = stoi(tokens[1]) + stoi(tokens[2]) + stoi(tokens[3]);
        difg = stoi(tokens[4]) - stoi(tokens[5]);
        punts = (stoi(tokens[1]) * 3) + (stoi(tokens[3]) * 1) + (stoi(tokens[2]) * 0);
        Equipo *equipo = new Equipo();
        equipo->setnombre(nombre);
        equipo->setganados(gan);
        equipo->setempatados(emp);
        equipo->setperdidos(per);
        equipo->setgolesan(gola);
        equipo->setgolescont(golc);
        equipo->setpartj(partj);
        equipo->setdifgol(difg);
        equipo->setpuntos(punts);
        Nodo *nuevo = new Nodo(equipo);
        nuevo->setnext_node(topepila);
        topepila = nuevo;
    }
    lector.close();
    Nodo *ptr = topepila;
    while (ptr != NULL)
    {
        cout << ptr->getequipo() << " ";
        ptr = ptr->nextnode;
    }
    cout << endl;

    Nodo *actual;
    Nodo *siguiente;
    Nodo *vaux = new Nodo();
    actual = new Nodo();
    siguiente = new Nodo();
    actual = topepila;
    while (actual != NULL)
    {
        siguiente = actual->nextnode;
        while (siguiente != NULL)
        {
            if (actual->equipo->getpts() < siguiente->equipo->getpts())
            {
                vaux->equipo = siguiente->equipo;
                siguiente->equipo = actual->equipo;
                actual->equipo = vaux->equipo;
            }
            siguiente = siguiente->nextnode;
        }
        cout << "Aqui estoy" << endl;
        actual = actual->nextnode;
    }
    cout << setw(17) << "PJ" << setw(4) << "G" << setw(4) << "E" << setw(4) << "P" << setw(5) << "GA" << setw(5) << "GC" << setw(5) << "DG" << setw(6) << "PTS" << endl;
    int cont = 1;
    Nodo *ptr2 = topepila;
    while(ptr2!=NULL)
    {
        int letras = 14 - ptr2->equipo->getnombre().size();
        cout << cont << "  " << ptr2->equipo->getnombre() << setw(letras) << ptr2->equipo->getpj() << setw(4) << ptr2->equipo->getg() << setw(4)
             << ptr2->equipo->gete() << setw(4) << ptr2->equipo->getp() << setw(5) << ptr2->equipo->getga() << setw(5) << ptr2->equipo->getgc() << setw(5) << ptr2->equipo->getdg() << setw(5) << ptr2->equipo->getpts() << endl;
    cont++;
    ptr2=ptr2->nextnode;
    }
}
