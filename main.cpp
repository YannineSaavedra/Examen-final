#include <iostream>
#include <map>
#include <string>
#include <set>
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
         cin >> fecha;
        vector<int> vectorfecha = leerFecha(fecha);

        if (vectorfecha.size() != 3) {
            cout << "Wrong Date Format: "<< fecha << endl;
            continue;
        }
        f.anho = vectorfecha[0];
        f.mes = vectorfecha[1];
        f.dia = vectorfecha[2];
         if(comprobar_mes(f.mes) == false) {
            cout << "Month value is invalid: " + to_string(f.mes) << endl;
            continue;
        }
        if(comprobar_dia(f.dia) == false) {
            cout << "Day value is invalid: " + to_string(f.dia) << endl;
            continue;
        }
        fecha = convertirFecha(f);
        
        getline(cin, evento); // Leer el resto de la línea para el event
        if (comando == "Add") {
            if (evento.empty()) {
            
            }
            add(eventos, fecha, evento);
            } else if (comando == "Del") {
            if (!evento.empty()) {
                delOne(eventos, fecha, evento);
            } else {
                del(eventos, fecha);
            }
            } else if (comando == "Find") {
            if (eventos.count(fecha) != 0) {
                find(eventos, fecha);
            } else {
                cout << "No existe" << endl;
            }
        } else {
            cout << "Unknow command: "<< comando << endl;
        }
    }
     return 0;
}

// Funcion para analizar una linea y convertirla en un vector de enteros
vector<int> leerFecha(string sdate) {
    string s;
    vector<int> v;
    for(int i = 0; i < sdate.size(); ++i){
        s += sdate[i];
        if(sdate[i] == '-' || i == sdate.size() - 1){
            v.push_back(stoi(s));
            s = "";
        }
    }
    return v;
    // función para agregar un evento a una fecha en el mapa de eventos
void add(map<string, set<string>>& mapa, string fecha, string evento) {
    mapa[fecha].insert(evento); // Insertar el evento en el conjunto correspondiente a la fecha
}

// función para encontrar y mostrar todos los eventos de una fecha
void find(map<string, set<string>>& mapa, string fecha) {
    set<string> eventos = mapa[fecha]; 
    for (const auto& e : eventos) {
        cout << fecha << " : " << e << endl; // mostrar cada evento de la fecha
    }
}

// función para eliminar todos los eventos de una fecha
void del(map<string, set<string>>& mapa, string fecha) {
    mapa.erase(fecha); // eliminar la fecha y su conjunto de eventos del mapa
}
}



