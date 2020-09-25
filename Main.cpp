#include <iostream>
#include <vector>
#include <iomanip>
#include "Nodo.hpp"
#include <string>
#include <stdlib.h>
#include <bits\stdc++.h>
using namespace std;
void sort(struct node **list)
{
}
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

    Nodo *aux;
    Nodo *temp;
    int vaux;
    int cont = 0;
    aux = new Nodo();
    temp = new Nodo();
    aux = topepila;
    while (aux != NULL)
    {
        vaux = aux->equipo->getpts();
        while (aux->nextnode != NULL)
        {
            if (vaux > aux->nextnode->equipo->getpts())
            {

                vaux = aux->nextnode->equipo->getpts();
                cout<<vaux<<endl;
            }
        }
cout<<"Aqui estoy"<<endl;
        temp = aux;
        aux = aux->nextnode;
        aux->nextnode = temp;
    }
    ptr = topepila;
    while (ptr != NULL)
    {
        cout << ptr->getequipo() << " ";
        ptr = ptr->nextnode;
    }
    cout << endl;
}
