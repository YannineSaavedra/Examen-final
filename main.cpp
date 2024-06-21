#include "funciones.h"

int main() {
    string input;
    string comando;
    string fecha;
    string evento;
    map<string, set<string>> mapa;
    
    vector<string> v_comandos;
    vector<int> v_fecha;
    vector<string> fecha_Find;

    while(true){
    getline(cin, input);
    if(input == "exit") break;
    if(input.empty()) continue;
     
    vector<string> v_input = separar_input(input);
    comando = v_input[0];

//ADD:
    if(comando == "Add"){
        fecha = v_input[1];
            if(!validar_fecha(fecha)) break;
        evento = v_input[2];
            mapa[fecha].insert(evento);
            v_input.clear();
    }

//FIND:   
    else if(comando == "Find"){
        v_comandos.push_back(comando);
        fecha = v_input[1];
        if(!validar_fecha(fecha)) break;
        fecha_Find.push_back(fecha); //se guarda la fecha ingresada en esta linea de comando
        v_input.clear();
    }

//DEL:
    else if(comando == "Del"){
        v_comandos.push_back(comando);
        fecha = v_input[1];
        if(!validar_fecha(fecha)) break;
 //DEL_fecha:      
        if(v_input.size() == 2){
            mapa.erase(fecha);
            cout << "Deleted N events" << endl;
        }
 //DEL_evento:       
        else {
            evento = v_input[2];
            if(mapa.count(fecha)){
                if(mapa[fecha].erase(evento)){
                    cout << "Deleted successfully" << endl;
                } 
                if(mapa[fecha].empty()){
                    mapa.erase(fecha);
                }
            } else {
                cout << "Event not found" << endl;
            }
        }
        v_input.clear();
    }

//PRINT:
    else if(comando == "Print"){ 
        v_comandos.push_back(comando);
        v_input.clear();
    }

//Error:
    else {
        cout << "Unknown command: " << comando << endl;
        break;
    }
    }

//Los comandos que imprimen:
    for(int i = 0; i < v_comandos.size(); ++i){
        if(v_comandos[i] == "Find"){
            find(fecha_Find, mapa);
        } else if(v_comandos[i] == "Del"){
        } else if(v_comandos[i] == "Print"){
            print(mapa);
        }
    }
    
    return 0;
}