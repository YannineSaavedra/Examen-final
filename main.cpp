#include "funciones.h"

int main() {
    string input;
    string comando;
    string fecha;
    string evento;
    vector<string> v_comandos;
    map<string, set<string>> mapa;
    
while(true){
    getline(cin, input);
    if(input == "exit") break;
    if(input.empty()) continue;
//Separando lo ingresado según los espacios   
    vector<string> v_input = separar_input(input);

//Según el comando:    
    comando = v_input[0];
    if(comando == "Add"){
        fecha = v_input[1];
        if(!validar_fecha(fecha)){
            break;
        }
        evento = v_input[2];
        mapa[fecha].insert(evento);
        v_input.clear();
    } else if(comando == "Find"){
        v_comandos.push_back(comando);
        fecha = v_input[1];
        if(!validar_fecha(fecha)){
            break;
        }
        //se guarda la fecha ingresada en esta linea de comando
        fecha_Find.push_back(fecha);
        v_input.clear();
    } else if(comando == "Del"){
        v_comandos.push_back(comando);
        fecha = v_input[1];
        if(!validar_fecha(fecha)){
            break;
        }
        if(v_input.size() == 2){ //fundion del
            mapa.erase(fecha);
        } else {
            evento = v_input[2]; //funcion del_one
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
    } else if(comando == "Print"){
        v_comandos.push_back(comando);
        v_input.clear();
    } else {
        cout << "Unknown command: " << comando << endl;
        break;
    }
}
//Los comandos que imprimen algo
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