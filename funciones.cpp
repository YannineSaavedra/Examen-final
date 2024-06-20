#include "funciones.h"

vector<string> separar_input(string& input){
    string s_input;
    vector<string> v_input;
    for(int i = 0; i < input.size(); ++i){
        if(input[i] == ' '){
            if(!s_input.empty()){
                v_input.push_back(s_input);
                s_input = "";
            }
        } else{
            s_input += input[i];
        }
    }
    if(!s_input.empty()){ //Se agrega el ultimo elemento
        v_input.push_back(s_input);
        s_input = "";
    }
    return v_input;
}

bool validar_fecha(string& fecha){
//AÑO: for para reescribirlo o determinar si el formato es incorrecto 
    string s_año = "";
    int hy_año = 0;
    int i_año = 0;
    for(int i = 0; i < fecha.size(); ++i){
        if(fecha[i] == '-'){
            ++hy_año;
        }
        if(hy_año >= 2){
            cout << "Wrong date format: " << fecha << endl;
            v_fecha.clear();
            return false;
        } else {
            s_año += fecha[i];
            if(s_año == "-" || fecha[i] == '+'){
                if(fecha[i] == '+'){
                    s_año.erase(s_año.size() - 1);
                }
                continue;
            } else {
                if(fecha[i + 1] == '-'){
                    v_fecha.push_back(stoi(s_año));
                    i_año = i;
                    break;   
                } else {
                    continue;
                }
            }
        }
    }
//MES y DIA: for para reescribirlo o determinar si el formato es incorrecto
    string s_mes = "";
    int hy_mes = 0;
    for(i_año += 1; i_año < fecha.size(); ++i_año){
        if(fecha[i_año] == '-'){
            ++hy_mes;
        }
        if(hy_mes >= 3 || (hy_mes == 2 && fecha[i_año + 1] == '+')){
            cout << "Wrong date format: " << fecha << endl;
            v_fecha.clear();
            return false;
        } else {
            s_mes += fecha[i_año];
            if(fecha[i_año] == '-'){
                if(hy_mes == 1){
                    s_mes = "";
                    continue;   
                }
            } else if(fecha[i_año] == '+'){
                s_mes = "";
                continue;
            } else if(fecha[i_año + 1] == '-' || i_año == fecha.size() - 1){
                v_fecha.push_back(stoi(s_mes));
                s_mes = "";
                hy_mes = 0;
                continue;
            }
        }
    }
    if(v_fecha.size() != 3){
        cout << "Wrong date format: " << fecha << endl;
        return false;
    }
    f.año = v_fecha[0];
    f.mes = v_fecha[1];
    f.dia = v_fecha[2];
    if(comprobar_mes(f.mes) == false) {
        cout << "Month value is invalid: " + to_string(f.mes) << endl;
        return false;
    }
    if(comprobar_dia(f.dia) == false) {
        cout << "Day value is invalid: " + to_string(f.dia) << endl;
        return false;
    }
    v_fecha.clear();
    return true;  
}

bool comprobar_mes(int mes){
    if(mes > 0 && mes <= 12){
        return true;
    }
    return false;
}

bool comprobar_dia(int dia){
    if(dia > 0 && dia <= 31){
        return true;
    }
    return false;
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

void find(vector<string> fecha_Find, map<string, set<string>> mapa){
    int i = 0;
    int contador = 0;
    for(i += contador; i < fecha_Find.size(); ++i){
        set<string> eventos = mapa[fecha_Find[i]];
        for(auto& valor : eventos){
            cout << "evento = " << valor << endl;
            ++contador;
            break;
        }
    }
}