#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdexcept>

using namespace std;

// Estructura para registrar la informacion de cada estudiante

struct estudiantes{
    string nombre;
    int edad;
    string carrera;
    float promedio;
};


// Funcion para validar el nombre del estudiante

string LeerNombre(string mensaje){
    string nombreEstudiante;
    
    while(true){
        cout<<mensaje;
        getline(cin>> ws, nombreEstudiante);
        bool valido = true;

        for(char n : nombreEstudiante){
            if(!isalpha(n) && !isspace(n)){
                valido = false;
                break;
            }
        }

        if(nombreEstudiante.empty()){
            cout<<"Error: El nombre del estudiante se encuentra vacio."<<endl;
            continue;
        }else if(!valido){
            cout<<"Error: El nombre del estudiante contiene caracteres invalidos."<<endl;
        }else{
            return nombreEstudiante;
        }
    }
}


// Funcion para validad la edad del estudiante

int LeerEdad(string mensaje, int min, int max){
    int edad;
    string texto;

    while(true){
        cout<<mensaje;
        getline(cin>> ws, texto);

        if(texto.empty()){
            cout<<"Error: El campo se encuentra vacio, Ingrese una edad."<<endl;
            continue;
        }

        try{
            edad = stoi(texto);
            if(edad > max || edad < min){
                cout<<"Error: Ingrese una edad dentro del rango de "<<min<<" a "<<max<<" ."<<endl;
                continue;
            }
            return edad;
        }catch(invalid_argument& e){
            cout<<"Error: Ingrese una edad valida."<<endl;
        }catch(out_of_range& e){
            cout<<"Error: La edad es demasiado grande."<<endl;
        }catch(...){
            cout<<"Error: Ocurrio un error al procesar la edad."<<endl;
        }
    }
}


// Funcion para validar el promedio del estudiante

float LeerPromedio(string mensaje, float min, float max){
    float promedio;
    string texto;

    while(true){
        cout<<mensaje;
        getline(cin>> ws, texto);

        if(texto.empty()){
            cout<<"Error: El campo se encuentra vacio, Ingrese un promedio."<<endl;
            continue;
        }

        try{
            promedio = stof(texto);
            if(promedio > max || promedio < min){
                cout<<"Error: Ingrese un promedio dentro del rango de "<<min<<" a "<<max<<" ."<<endl;
                continue;
            }
            return promedio;
        }catch(invalid_argument& e){
            cout<<"Error: Ingrese un promedio valido."<<endl;
        }catch(out_of_range& e){
            cout<<"Error: El promedio es demasiado grande."<<endl;
        }catch(...){
            cout<<"Error: Ocurrio un error al procesar el promedio."<<endl;
        }
    }
}


// Funcion para validar la carrera del estudiante

string LeerCarrera(string mensaje){
    string carrera;

    while(true){
        cout<<mensaje;
        getline(cin>> ws, carrera);
        bool valido = true;

        for(char n : carrera){
            if(!isalpha(n) && !isspace(n)){
                valido = false;
                break;
            }
        }

        if(carrera.empty()){
            cout<<"Error: La carrera del estudiante se encuentra vacia."<<endl;
            continue;
        }else if(!valido){
            cout<<"Error: La carrera del estudiante contiene caracteres invalidos."<<endl;
        }else{
            return carrera;
        }
    }
}


// Almacenar la informacion del estudiante dentro del archivo de texto

void GuardarRegistro(const string& nombre, int edad, const string& carrera, float promedio) {
    
    ifstream prueba("estudiantes.txt");
    bool archivoNuevo = !prueba.is_open();
    prueba.close();
    
    ofstream archivo;

    archivo.open("estudiantes.txt", ios::app);

    // Verificación de apertura del archivo.
    if (!archivo.is_open()) {
        throw runtime_error("Error critico: No se pudo acceder al archivo de persistencia.");
    }

    if (archivoNuevo) {
        archivo << "======================================================================" << endl;
        archivo << "                REPORTE DE ESTUDIANTES REGISTRADOS                    " << endl;
        archivo << "======================================================================" << endl;
        archivo << left << setw(20) << "NOMBRE" << " | " 
                << setw(4)  << "EDAD" << " | " 
                << setw(20) << "CARRERA" << " | " 
                << "PROMEDIO" << endl;
        archivo << "----------------------------------------------------------------------" << endl;
    }

    archivo << left << setw(20) << nombre << " | "
            << setw(4)  << edad   << " | "
            << setw(20) << carrera << " | "
            << fixed << setprecision(2) << promedio << endl;

    // Cierre obligatorio del flujo de datos.
    archivo.close();

    cout << "\n[SISTEMA] Persistencia completada con exito." << endl;
}


// Metodo para mostrar el reporte de los estudiantes registrados

void MostrarReporte() {
    
    ifstream archivo("estudiantes.txt");
    string linea;

    if (!archivo.is_open()) {
        cout << "\n[!] No hay registros guardados todavia." << endl;
        return;
    }

    cout << endl;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
    cout << "======================================================================\n" << endl;
}


// Metodo para mostrar el reporte de los estudiantes registrados

void EjecutarRegistro() {

    // Variables locales para mayor orden
    
    string nombre = LeerNombre("Ingrese el nombre completo: ");
    int edad = LeerEdad("Ingrese la edad (17-90): ", 17, 90);
    string carrera = LeerCarrera("Ingrese la carrera: ");
    float promedio = LeerPromedio("Ingrese el promedio (0.0 - 10.0): ", 0, 10);

    try {
        GuardarRegistro(nombre, edad, carrera, promedio);
    } catch (const exception& e) {
        cout << "\a" << e.what() << endl; // \a emite un pitido de alerta
    }
}


// Metodo para mostrar el menu principal del sistema

void MostrarMenu() {
    cout << "\n========================================" << endl;
    cout << "   SISTEMA DE GESTION ACADEMICA - UTA   " << endl;
    cout << "========================================" << endl;
    cout << "1. Registrar Nuevo Estudiante" << endl;
    cout << "2. Ver Reporte General" << endl;
    cout << "3. Salir" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Seleccione una opcion: ";
}


// Metodo principal del programa

int main() {
    int opcion;

    do {
        MostrarMenu();
        if (!(cin >> opcion)) {
            cout << "\n[!] Error: Entrada no valida. Ingrese un numero." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        // Limpiar el salto de linea que deja cin >> antes de ir a los getline
        cin.ignore(1000, '\n');

        switch (opcion) {
            case 1:
                EjecutarRegistro();
                break;
            case 2: 
                MostrarReporte(); 
                break;
            case 3:
                cout << "\n[INFO] Finalizando programa. Datos asegurados." << endl;
                break;
            default:
                cout << "\n[!] Error: Opcion fuera del rango (1-3)." << endl;
        }
    } while (opcion != 3);

    return 0;
}