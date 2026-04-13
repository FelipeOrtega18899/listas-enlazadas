#include <iostream>
using namespace std;


struct nodo {
    int valor;
    nodo* siguiente;
};

class Lista {
    private:
        nodo* inicio;
    public:
        // Constructor
        Lista() {
            inicio =  NULL;
        }

        bool estaVacia() {
            return inicio == NULL;
        }

        void insertarInicio (int valor) {
            nodo* nuevo = new nodo;
            nuevo->valor = valor;
            nuevo->siguiente = inicio;
            inicio = nuevo;
        }
        void insertarFinal (int valor) {
            nodo* nuevo = new nodo;
            nuevo->valor = valor;
            nuevo->siguiente = NULL;

            if (estaVacia()) {
                inicio = nuevo;
            } else {
                nodo* actual = inicio;
                while (actual->siguiente != NULL) {
                    actual = actual->siguiente;
                }
                actual->siguiente = nuevo;
            }

            nodo* aux = inicio;
            while (aux -> siguiente != NULL) {
                aux = aux->siguiente;
            }
            cout << endl;
        }
    };

void menu () {
    cout << "1. Insertar al inicio" << endl;
    cout << "2. Insertar al final" << endl;
    cout << "3. Insertar antes de:" << endl;
    cout << "4. Insertar después de:" << endl;
    cout << "5. Eliminar al inicio" << endl;
    cout << "6. Eliminar valor" << endl;
    cout << "7. Eliminar al final" << endl;
    cout << "8. Buscar" << endl;
    cout << "9. Mostrar lista" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese una opción: ";
}

int main () {
    int opcion, valor;
    Lista lista;


    do {
        menu();
        cin >> opcion;
    
        if (opcion == 1) {
            cout << "Ingresa un valor: " << endl;
            cin >> valor;
            lista.insertarInicio(valor);
        } else if (opcion == 2) {
            cout << "Ingresa un valor: " << endl;
            cin >> valor;
            lista.insertarFinal(valor);
        }


    } while (opcion != 0);    
}