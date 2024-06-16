#include <iostream>
#include <map>
#include <string>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

struct Fecha {
    int anho;
    int mes;
    int dia;
};
void add(map<string, set<string>>& mapa, string fecha, string evento);
void del(map<string, set<string>>& mapa, string fecha);
void delOne(map<string, set<string>>& mapa, string fecha, string evento);
void find(map<string, set<string>>& mapa, string fecha);
void print(const map<string, set<string>>& mapa);

string convertirFecha(Fecha fecha);
vector<int> leerFecha(string line);

bool comprobar_dia(int dia);
bool comprobar_mes(int mes);