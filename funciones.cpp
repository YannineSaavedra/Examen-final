#include "funciones.h"

vector<string> separar_input(string& input){
    string s_input;
    vector<string> v_input;
    for(int i = 0; i < input.size(); ++i){
        if(input[i] == ' '){ //¿Es un espacio? YES: guarda la palabra en el vector
            if(!s_input.empty()){
                v_input.push_back(s_input);
                s_input = "";
            }
        } else { //NO: sigue reescribiendo el input
            s_input += input[i];
        }
    }
    if(!s_input.empty()){ //Se agrega la ultima palabra
        v_input.push_back(s_input);
        s_input = "";
    }
    return v_input;
}

void find(vector<string> fecha_Find, map<string, set<string>> mapa){
    int i = 0;
    int contador = 0; //Se queria imprimir la fecha indicada en esa linea de comando
    for(i += contador; i < fecha_Find.size(); ++i){
        set<string> eventos = mapa[fecha_Find[i]];
        for(auto& valor : eventos){
            cout << valor << endl;
            ++contador;
            break;
        }
    }
}

void print(const map<string, set<string>> mapa){
    for(auto clave : mapa){
        set<string> eventos = clave.second;
        for(auto valor : eventos){
            cout << clave.first << " : " << valor << endl;
        }
    }
}

string format_fecha_print(FECHA f) {
    string año;
    if(f.año < 1000){
        año = "0" + to_string(f.año);
    }
    if(f.año < 100){
        año = "00" + to_string(f.año);
    }
    if(f.año < 10){
        año = "000" + to_string(f.año);
    } else {
        año = to_string(f.año);
    }

    string mes, dia;
    if(f.mes < 10){
        mes = "0" + to_string(f.mes);
    } else {
        mes = to_string(f.mes);
    }

    if(f.dia < 10){
        dia = "0" + to_string(f.dia);
    } else {
        dia = to_string(f.dia);
    }
    string fecha_P = año + "-" + mes + "-" + dia ;
    return fecha_P;
}