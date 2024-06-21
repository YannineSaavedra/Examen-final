#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct FECHA{
    int año;
    int mes;
    int dia;
};

//Funciones:
vector<string> separar_input(string& input);
string format_fecha_print(FECHA f);
void print(const map<string, set<string>> mapa);
void find(vector<string> fecha_Find, map<string, set<string>> mapa);

//Para validar fecha:
bool validar_fecha(string& fecha);
bool comprobar_mes(int mes);
bool comprobar_dia(int dia);