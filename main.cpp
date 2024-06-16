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

int main()
{
    string comando, fecha, evento;
    map<string, set<string>> eventos;
    Fecha f;
    while (true) {
        cout << "Comando (x para terminar): "<<endl;
        cin >> comando;

        if (comando == "x") break;

        if (comando == "Print") {
            print(eventos);
            continue;
        }