#ifndef EQUIPO_H
#define EQUIPO_H
#include <iostream>
#include <string>
using namespace std;
class Equipo
{
private:
    string Nombre;
    int pj;
    int g;
    int p;
    int e;
    int ga;
    int gc;
    int dg;
    int pts;

public:
    Equipo() {}
    Equipo(string _nombre, int _pj, int _g, int _p, int _e, int _ga, int _gc, int _dg, int _pts)
    {
        Nombre = _nombre;
        pj = _pj;
        g = _g;
        p = _p;
        e = _e;
        ga = _ga;
        gc = _gc;
        dg = _dg;
        pts = _pts;
    }
    string getnombre() { return Nombre; }
    int getpj() { return pj; }
    int getg() { return g; }
    int getp() { return p; }
    int gete() { return e; }
    int getga() { return ga; }
    int getgc() { return gc; }
    int getdg() { return dg; }
    int getpts() { return pts; }
    void setnombre(string _nombre)
    {
        Nombre = _nombre;
    }
    void setganados(int _g)
    {
        g = _g;
    }
    void setperdidos(int _p)
    {
        p = _p;
    }
    void setempatados(int _e)
    {
        e = _e;
    }
    void setgolesan(int _ga)
    {
        ga = _ga;
    }
    void setgolescont(int _gc)
    {
        gc = _gc;
    }
    void setdifgol(int _dg)
    {
        dg = _dg;
    }
    void setpuntos(int _pts)
    {
        pts = _pts;
    }
    void setpartj(int _pj)
    {
        pj= _pj;
    }

};
#endif