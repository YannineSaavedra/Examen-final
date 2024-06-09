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
