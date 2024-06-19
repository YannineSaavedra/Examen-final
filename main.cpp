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
    
        cin >> fecha;
        vector<int> v_fecha;

//En esta parte procesamos el AÑO, se hace un for para reescribirlo o determinar si el formato es incorrecto 
        string s_año = ""; //para reescribir el año
        int hy_año = 0; //para contar los guiones antes del año
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

        if(v_fecha.size() != 3){
            cout << "Wrong date format: " << fecha << endl;
        }
        for(auto n : v_fecha){
            cout << n << ", ";
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

    return 0;  
}
