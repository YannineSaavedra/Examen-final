#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

struct FECHA{
    int año;
    int mes;
    int dia;
};
int main(){
    string comando, fecha, evento;
    map<string, set<string>> mapa;
    vector<string> comandos;
    FECHA f;
    
    while(true){
        cin >> comando;
//exit para dejar de pedir lineas de comando en la entrada
        if(comando == "exit") break;
//para soportar lineas de entrada vacías
        if(comando.empty()) continue; //¿el comando esta vacío? YES: vaya a repetir el while
//Función PRINT
        if(comando == "Print"){
            comandos.push_back(comando);
            continue;
        }
    
        cin >> fecha;
        vector<int> v_fecha;

//En esta parte procesamos el AÑO, se hace un for para reescribirlo o determinar si el formato es incorrecto 
        string s_año = ""; //para reescribir el año
        int hy_año = 0; //para contar los guiones antes del año hypens
        int i_año = 0;
        for(int i = 0; i < fecha.size(); ++i){
            if(fecha[i] == '-'){ //¿el caracter donde nos encontramos es igual a '-'? YES: contar los guiones que hay antes del año
                ++hy_año;
            }
            if(hy_año >= 2){ //¿los guiones son mayor a 2? YES: el formato es incorrecto y sale del for
                cout << "Wrong date format: " << fecha << endl;
                s_año = "";
                v_fecha.clear();
                break;
            } else { //NO: se reescribe el año
                s_año += fecha[i];
                if(s_año == "-" || fecha[i] == '+'){ //¿el año es igual a '-' o el caracter donde estamos es igual a '+'? YES: vaya a repetir el for
                    if(fecha[i] == '+'){ //¿el caracter donde estamos es igual a '+'? YES: se borra el + de la string año, y recién se va a repetir el for
                        s_año.erase(s_año.size() - 1);
                    }
                    continue;
                } else { //NO: veamos si terminamos de reescribir el año o no..
                    if(fecha[i + 1] == '-'){ //¿el siguiente caracter es '-'? YES: guardamos en un vector el valor del año, guardamos el valor de i en otra variable y sale del for porque terminamos de reescribir el año
                        v_fecha.push_back(stoi(s_año));
                        i_año = i;
                        break;   
                    } else { //NO: vaya a repetir el for, porque no terminamos de reescribir el año
                        continue;
                    }
                }
            }
        }
        if(s_año.empty()){ //¿Esta vacía la string del año? YES: i_año es igual al tamaño de la fecha porque significa que el formato era incorrecto, entonces no necesitamos entrar el loop del mes
            i_año = fecha.size();
        } //NO: se procede a procesar el mes

        string s_mes = "";
        int hy_mes = 0;
        for(i_año += 1; i_año < fecha.size(); ++i_año){
            if(fecha[i_año] == '-'){
                ++hy_mes;
            }
            if(hy_mes >= 3 || (hy_mes == 2 && fecha[i_año + 1] == '+')){
                cout << "Wrong date format: " << fecha << endl;
                s_mes = "";
                v_fecha.clear();
                break;
            } else {
                s_mes += fecha[i_año];
                if(fecha[i_año] == '-'){ //para 1-1
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
        }
        
        //la fecha esta guardada en un vector de enteros, ahora hay que comprobar la validez del mes y del día
        f.año = v_fecha[0];
        f.mes = v_fecha[1];
        f.dia = v_fecha[2];
        if(f.mes < 1 && f.mes > 12){
            cout << "Month value invalid: " << f.mes << endl;
        }
        if (f.dia < 1 && f.dia > 31){
            cout << "Day value invalid: " << f.dia << endl;
        }

        if(comando == "Find"){
            comandos.push_back(comando);
            continue;
        }

        cin >> evento;

//Función ADD
        if(comando == "Add"){
            mapa[fecha].insert(evento);
        } else if(comando == "Del"){
            comandos.push_back(comando);
            continue;
        }

    }

//Para imprimir lo necesario después de haber sido ingresado "exit"    
    cout << comandos.size() << endl; //el tamaño es 1 pero el indice es 0
    for(int i = 0; i < comandos.size(); ++i){
        if(comandos[i] == "Print"){
            for(auto clave : mapa){
                set<string> eventos = clave.second;
                for(auto valor : eventos){
                    cout << clave.first << " : " << valor << endl;
                }
            }
        } else if(comandos[i] == "Find"){
            set<string> eventos = mapa[fecha];
            for (const auto& e : eventos) {
                cout << e << endl;
            }
        } else if(comando == "Del"){
            
        }
    }

    return 0;  
}