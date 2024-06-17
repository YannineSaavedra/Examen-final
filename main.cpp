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
// función para eliminar un evento específico de una fecha
void delOne(map<string, set<string>>& mapa, string fecha, string evento) {
    if (mapa.count(fecha)) { // verificar si la fecha existe en el mapa
        mapa[fecha].erase(evento); // eliminar el evento específico del conjunto de eventos de la fecha
        if (mapa[fecha].empty()) {
            mapa.erase(fecha); // si el conjunto de eventos está vacío, eliminar la fecha del mapa
        }
    }
}

// función para mostrar todos los eventos en el mapa, ordenados por fecha y evento
void print(const map<string, set<string>>& mapa) {
    for (const auto& item : mapa) {
        const set<string>& eventos = item.second; // obtener el conjunto de eventos para la fecha actual
        for (const auto& e : eventos) {
            cout << item.first << " : " << e << endl; // mostrar cada evento de la fecha actual
        }
    }
}

// función para convertir una estructura Fecha a una cadena en formato AAAA-MM-DD
string convertirFecha(Fecha fecha) {
    string mes, dia;
    if (fecha.mes < 10) {
        mes = "0" + to_string(fecha.mes); // agregar un cero adelante si el mes es de un solo dígito
    } else {
        mes = to_string(fecha.mes);
    }

    if (fecha.dia < 10) {
        dia = "0" + to_string(fecha.dia); // agregar un cero adelante si el día es de un solo dígito
    } else {
        dia = to_string(fecha.dia);
    }

    string f = to_string(fecha.anho) + "-" + mes + "-" + dia; // construir la cadena AAAA-MM-DD
    return f;
}
// Función para validar que el día esté en el rango correcto (1-31)
bool comprobar_dia(int dia) {
    return dia > 0 && dia <= 31; // Devolver true si el día está en el rango correcto, false de lo contrario
}

// Función para validar que el mes esté en el rango correcto (1-12)
bool comprobar_mes(int mes) {
    return mes > 0 && mes <= 12; // Devolver true si el mes está en el rango correcto, false de lo contrario
}





