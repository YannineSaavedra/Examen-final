#include "headerPrincipal.h"

vector<int> stovector_fecha(string fecha){
    string s;
    vector<int> v;
    int counter_hypens = 0;
    bool negative = false;
    for (int i = 0; i < fecha.size(); ++i) {
    if (fecha[i] == '-') {
    ++counter_hypens;
    if (!s.empty()) {
        v.push_back(stoi(s));
        s = "";
    }
    negative = true;
    } else if (fecha[i] == '+') {
        if (!s.empty()) {
            v.push_back(stoi(s));
            s = "";
        }
    negative = false;
    } else {
        s += fecha[i];
    }
    }
    if (!s.empty()) {
        v.push_back(stoi(s));
    }
    
    if(counter_hypens >= 4){
        cout << "Wrong date format: " << fecha << endl;
    }
    return v;
}

bool comprobar_mes(int mes){
    if(mes >= 1 && mes <= 12){
        return true;
    }
    return false;
}

bool comprobar_dia(int dia){
    if(dia >= 1 && dia <= 31){
        return true;
    }
    return false;
}