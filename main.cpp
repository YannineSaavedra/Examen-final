#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

void respuesta(string fecha, string evento, string comando);

void add_repetidos(map<string, set<string>> mapa, string fecha, string evento);
void add_repetidos(map<string, set<string>> mapa, string fecha, string evento);
void add(map<string, set<string>> mapa, string fecha, string evento);
void del(map<string, set<string>> mapa, string fecha);
void delOne(map<string, set<string>> mapa, string fecha, string evento);
void find(map<string, set<string>> mapa, string fecha);
void print( const map<string, set<string>> mapa);
bool comprobar_dia(int dia);
bool comprobar_mes(int mes);