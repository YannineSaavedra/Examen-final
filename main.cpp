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