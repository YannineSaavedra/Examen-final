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
//variables globales:
    vector<int> v_fecha;
    FECHA f;
    vector<string> fecha_Find;

//funciones:
vector<string> separar_input(string& input);
bool validar_fecha(string& fecha);
bool comprobar_mes(int mes);
bool comprobar_dia(int dia);
string format_fecha_print(FECHA f);

//Comandos:
void print(const map<string, set<string>> mapa);
void find(vector<string> fecha_Find, map<string, set<string>> mapa);