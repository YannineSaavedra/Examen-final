#include "headerPrincipal.h"
#include "funciones.h"

struct FECHA {
    int año;
    int mes;
    int dia;
    };

int main() {
    string comando, fecha, evento;
    map<string, set<string>> FechaEventos;
    FECHA f;
    
    while(true){
    cin >> comando;
    if(comando == "exit") break;
    if(comando.empty()) continue;
    if(comando == "Print"){
        print(FechaEventos);
        continue;
    }
    
    if(comando != "Add" && comando != "Del" && comando != "Find" && comando != "Print"){
        cout << "Unknown command: " << comando << endl;
        continue;
    }
    
    cin >> fecha;
    vector<int> vi = stovector_fecha(fecha);
    if(vi.size() != 3){
        cout << "Wrong date format: " << fecha << endl;
        continue;
    }
    
        f.año = vi[0];
        f.mes = vi[1];
        f.dia = vi[2];
    
    if(comprobar_mes(f.mes) == false) {
        cout << "Month value is invalid: " + to_string(f.mes) << endl;
        continue;
    }
    if(comprobar_dia(f.dia) == false) {
        cout << "Day value is invalid: " + to_string(f.dia) << endl;
        continue;
        }
    
    cin >> evento;
    if(comando == "Add"){
        add(fecha, evento, FechaEventos);
    } else if(comando == "Del"){
        if(!evento.empty()){
            del_one(fecha, evento, FechaEventos);
            /*if(FechaEventos[fecha].erase(evento)){
                cout << "Deleted successfully" << endl;
            } else {
            cout << "Event not found" << endl;
        }*/
        } else {
            del(fecha, FechaEventos); //Falta el mensaje
        }
    } else if(comando == "Find"){
        if (FechaEventos.count(fecha) != 0) {
                find(fecha, FechaEventos);
            } else {
                cout << "No existe" << endl;
            } //se imprime despues del comando no después.
    }
    
    
    }
    return 0;
}