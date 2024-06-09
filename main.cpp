#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// Declaración de la función SplitString
vector<string> SplitString(const string& str, char delimiter);

// Estructura de datos para almacenar los eventos por fecha
struct Database {
    map<string, set<string>> data;
    // Función para agregar un evento a una fecha dada
    void Add(const string& date, const string& event) {
        data[date].insert(event);  // Inserta el evento en el conjunto correspondiente a la fecha
    }
    bool DeleteEvent(const string& date, const string& event) {
        auto it = data.find(date);
        if (it != data.end() && it->second.count(event)) {  // Verifica si la fecha y el evento existen
            it->second.erase(event);  // Elimina el evento
            if (it->second.empty()) {  // Si no hay más eventos en esa fecha, elimina la fecha
                data.erase(it);
            }
