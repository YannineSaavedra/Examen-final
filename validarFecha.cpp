#include "funciones.h"
FECHA f;

bool validar_fecha(string& fecha){
//AÑO: for para reescribirlo o determinar si el formato es incorrecto 
    string s_año = "";
    int hy_año = 0;
    int i_año = 0;
    vector<int> v_fecha;
    for(int i = 0; i < fecha.size(); ++i){
        if(fecha[i] == '-'){
            ++hy_año;
        }
        if(hy_año >= 2){
            cout << "Wrong date format: " << fecha << endl;
            v_fecha.clear();
            return false; //Termina
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
            return false; //Termina
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
        return false; //Termina
    }
    f.año = v_fecha[0];
    f.mes = v_fecha[1];
    f.dia = v_fecha[2];
    if(comprobar_mes(f.mes) == false) {
        cout << "Month value is invalid: " + to_string(f.mes) << endl;
        return false; //Termina
    }
    if(comprobar_dia(f.dia) == false) {
        cout << "Day value is invalid: " + to_string(f.dia) << endl;
        return false; //Termina
    }
    v_fecha.clear();
    return true;  //Termina, pero el formato es correcto.
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