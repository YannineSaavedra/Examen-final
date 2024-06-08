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

int main()
{

    string comando, fecha, evento;
    do {
        cout<<"Comando: "<<endl;
        cin >> comando;
        cout<<"Fecha y Evento: "<<endl;
        cin >> fecha >> evento;
        respuesta(fecha, evento, comando);
    } while (comando != "x");
     return 0;
}
void respuesta(string fecha, string evento, string comando){
     map<string, set<string>> eventos;
     if( comando == "Add") {
        if (eventos.count(fecha) != 0){
            add_repetidos(eventos, fecha, evento);
        }
        else {
            add(eventos, fecha, evento); //anhadir evento
        }
    }
    else if( comando == "Del") {
        if(evento != ""){ //eliminar un solo evento
        delOne(eventos, fecha, evento);
        } else{ //eliminar todos los eventos de una fecha
            del(eventos, fecha);
        }
    }
    else if( comando == "Find") {
        if (eventos.count(fecha) != 0){
            find(eventos, fecha); //encontrar eventos por fecha
        }
        else {
            "No existe";
        }
 
    }
    else if ( comando ==  "Print") {
        print(eventos); //mostrar todos los eventos
    }
}

void add_repetidos(map<string, set<string>> mapa, string fecha, string evento){
    set<string> eventos = mapa.find(fecha)->second;
    eventos.insert(evento);
    mapa[fecha] = eventos;
}
//anhadir eventos por fecha si no existen
void add(map<string, set<string>> mapa, string fecha, string evento){
    set<string> eventos;
    eventos.insert(evento);
    mapa[fecha] = eventos;
}
//encontrar todos los eventos por fecha
void find(map<string, set<string>> mapa, string fecha){
    set<string> eventos = mapa.find(fecha)->second; //guardar todos los eventos de la fecha en un set
for (auto e : eventos){
        cout<<fecha<<" : "<<e<<endl; //muestra todos los eventos de la fecha
    }
}
            
