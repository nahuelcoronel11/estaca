#include <iostream>
#include <string>

using namespace std;

int MAX_TAREAS = 10;

void mostrarMenu() {
    cout << "\nMenu:\n";
    cout << "1. Agregar tarea\n";
    cout << "2. Ver tareas\n";
    cout << "3. Actualizar tarea\n";
    cout << "4. Eliminar tarea\n";
    cout << "5. Salir\n";
    cout << "Elige una opcion: ";
}

void agregarTarea(string tareas[], int &numTareas) {
    if (numTareas < MAX_TAREAS) {
        cout << "Ingresa la nueva tarea (una sola palabra): ";
        cin >> tareas[numTareas];
        numTareas++;
        cout << "Tarea agregada.\n";
    } else {
        cout << "No es posible agregar mas tareas, limite alcanzado.\n";
    }
}

void verTareas(string tareas[], int numTareas) {
    if (numTareas == 0) {
        cout << "No hay tareas en la lista.\n";
    } else {
        cout << "Lista de tareas:\n";
        for (int i = 0; i < numTareas; ++i) {
            cout << i + 1 << ". " << tareas[i] << '\n';
        }
    }
}

void actualizarTarea(string tareas[], int numTareas) {
    int num;
    cout << "Ingresa el numero de la tarea a actualizar: ";
    cin >> num;

    if (num > 0 && num <= numTareas) {
        cout << "Ingresa la nueva descripcion de la tarea (una sola palabra): ";
        cin >> tareas[num - 1];
        cout << "Tarea actualizada.\n";
    } else {
        cout << "Numero de tarea invalido.\n";
    }
}

void eliminarTarea(string tareas[], int &numTareas) {
    int num;
    cout << "Ingresa el numero de la tarea a eliminar: ";
    cin >> num;

    if (num > 0 && num <= numTareas) {
        for (int i = num - 1; i < numTareas - 1; ++i) {
            tareas[i] = tareas[i + 1];
        }
        numTareas--;
        cout << "Tarea eliminada.\n";
    } else {
        cout << "Numero de tarea invalido.\n";
    }
}

int main() {
    string tareas[MAX_TAREAS];
    int numTareas = 0;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarTarea(tareas, numTareas);
                break;
            case 2:
                verTareas(tareas, numTareas);
                break;
            case 3:
                actualizarTarea(tareas, numTareas);
                break;
            case 4:
                eliminarTarea(tareas, numTareas);
                break;
            case 5:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion invalida. Intentalo de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
