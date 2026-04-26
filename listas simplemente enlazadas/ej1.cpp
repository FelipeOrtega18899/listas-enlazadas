#include<iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo *siguiente;
};

class Lista {
    private:
        Nodo *inicial;
    public:
    Lista() {
        inicial = nullptr;
    }
    bool estaVacia() {
        return inicial == nullptr;
    }
    void insertarInicio(int valor) {
        Nodo* nuevo = new Nodo();
        nuevo->valor = valor;
        nuevo->siguiente = inicial;
        inicial = nuevo;
    }
    void insertarFinal(int valor) {
        Nodo* nuevo = new Nodo();
        nuevo->valor = valor;
        nuevo->siguiente = nullptr;

        if (estaVacia()) {
            inicial = nuevo;
            return;
        }

        Nodo* auxiliar = inicial;
        while (auxiliar->siguiente != nullptr) {
            auxiliar = auxiliar->siguiente;
        }
        auxiliar->siguiente = nuevo;
    }
    void mostrarLista() {
        Nodo* auxiliar = inicial;
        while (auxiliar != nullptr) {
            cout << auxiliar->valor << " -> ";
            auxiliar = auxiliar->siguiente;
        }
    }
    void insertarAntesDe(int referencia, int valor) {
        if (estaVacia()) {
            cout <<"No seas menso esta vacia\n";
            return;
        }
        Nodo* nuevo = new Nodo();
        nuevo->valor = valor;

        Nodo* actual = inicial;
        Nodo* anterior= nullptr;

        while (actual != nullptr && actual->valor != referencia) {
            anterior= actual;
            actual = actual->siguiente;

        }
            if (actual == nullptr) {
                cout <<"No se encontro la referencia\n";
                return;
            }
            if (anterior == nullptr) {
                nuevo -> siguiente = inicial;
                inicial = nuevo;
            }else {
                anterior->siguiente = nuevo;
                nuevo -> siguiente = actual;
            }
    }
    void insertarDespuesDe(int referencia, int valor) {
        Nodo* nuevo = new Nodo();
        nuevo->valor = valor;
        Nodo* actual = inicial;
        while (actual != nullptr && actual->valor != referencia) {
            actual = actual->siguiente;
        }
        if (actual == nullptr) {
            cout <<"Nose encontro la referencia\n";
            return;
        }
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }
    void eliminarInicial() {
        if (estaVacia()) {
            cout <<"No seas menso esta vacia\n";
            return;
        }
        Nodo* auxiliar = inicial;
        inicial = inicial->siguiente;
        delete auxiliar;
    }
    void eliminarUltimo() {
        if (estaVacia()) {
            cout <<"No seas menso esta vacia\n";
            return;
        }
        if (inicial->siguiente == nullptr) {
            delete inicial;
            inicial = nullptr;
            return;
        }
        Nodo* anterior = nullptr;
        Nodo* actual = inicial;
        while (actual -> siguiente != nullptr) {
            anterior = actual;
            actual = actual -> siguiente;
        }
        delete actual;
        anterior -> siguiente = nullptr;
    }
    void eliminarValor(int valor) {
        if (estaVacia()) {
            cout <<"No seas menso esta vacia\n";
            return;
        }
        Nodo* actual = inicial;
        Nodo* anterior = nullptr;
        while (actual != nullptr && actual->valor != valor) {
            anterior = actual;
            actual = actual->siguiente;
        }
        if (actual == nullptr) {
            cout <<"Nose encontro el valor\n";
            return;
        }
        if (anterior == nullptr) {
            inicial = inicial -> siguiente;
        }else {
            anterior -> siguiente = actual -> siguiente;
        }
        delete actual;
    }
    bool buscar(int valor) {
        Nodo* auxiliar = inicial;
        while (auxiliar != nullptr) {
            if (auxiliar ->valor == valor) {
                return true;
            }
            auxiliar = auxiliar ->siguiente;
        }
        return false;
    }
    int contarNodo() {
        Nodo* actual = inicial;
        int contador = 0;
        while (actual != nullptr) {
            actual = actual->siguiente;
            contador++;
        }
        return contador;
    }
    int nodoMaximo() {
        if (estaVacia()) {
            cout <<"No seas menso esta vacia\n";
            return 0;
        }
        Nodo* actual = inicial;
        int maximo = actual -> valor;
        while (actual != nullptr) {
            if (maximo < actual->valor) {
                maximo = actual -> valor;
            }
            actual = actual->siguiente;
        }
        return maximo;
    }
    int nodoMinimo() {
        if (estaVacia()) {
            cout <<"No seas menso esta vacia\n";
            return 0;
        }
        Nodo* actual = inicial;
        int minimo = actual -> valor;
        while (actual != nullptr) {
            if (minimo > actual->valor) {
                minimo = actual -> valor;
            }
            actual = actual->siguiente;
        }
        return minimo;
    }
    void invertir() {
        if (estaVacia()) {
            cout << "No seas menso esta vacia\n";
            return;
        }

        Nodo* actual = inicial;
        Nodo* anterior = nullptr;
        Nodo* auxiliar = nullptr;

        while (actual != nullptr) {
            auxiliar = actual->siguiente;
            actual->siguiente = anterior;
            anterior = actual;
            actual = auxiliar;
        }
        inicial = anterior;
    }
};

void menu() {
    cout <<"--- LISTAS SIMPLEMENTE LIGADAS ---\n";
    cout <<"1. Insertar inicio\n";
    cout <<"2. Insertar final\n";
    cout <<"3. Insertar antes de\n";
    cout <<"4. Insertar despues de\n";
    cout <<"5. Eliminar inicio\n";
    cout <<"6. Eliminar valor\n";
    cout <<"7. Eliminar ultimo\n";
    cout <<"8. Buscar\n";
    cout <<"9. Imprimir lista\n";
    cout <<"10. Contar Nodos\n";
    cout <<"11. Nodo Maximo\n";
    cout <<"12. Nodo Minimo\n";
    cout <<"13. Invertir\n";
    cout <<"0. Salir\n";
    cout <<"Selecciona una opcion: ";
}

int main() {
    Lista lista;
    int opcion,valor,referencia;

    do {
        menu();
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout <<"Ingresa el valor a insertar al inicio: ";
                cin >> valor;
                lista.insertarInicio(valor);
                break;
            case 2:
                cout <<"Ingresa el valor a insertar al final: ";
                cin >> valor;
                lista.insertarFinal(valor);
                break;
            case 3:
                cout <<"Ingresa el valor de referencia: ";
                cin >> referencia;
                cout <<"Ingresa el valor a insertar antes de la referencia: ";
                cin >> valor;
                lista.insertarAntesDe(referencia,valor);
                break;
            case 4:
                cout <<"Ingresa el valor de referencia: ";
                cin >> referencia;
                cout <<"Ingresa el valor a insertar despues de la referencia: ";
                cin >> valor;
                lista.insertarDespuesDe(referencia,valor);
                break;
            case 5:
                lista.eliminarInicial();
                break;
            case 6:
                cout <<"Ingresa el valor a eliminar: ";
                cin >> valor;
                lista.eliminarValor(valor);
                break;
            case 7:
                lista.eliminarUltimo();
                break;
            case 8:
                cout <<"Ingresa el valor a buscar: ";
                cin >> valor;
                if (lista.buscar(valor)) {
                    cout <<"Valor encontrado en la lista\n";
                }else {
                    cout <<"Valor no encontrado en la lista\n";
                }
                break;
            case 9:
                lista.mostrarLista();
                cout << endl;
                break;
            case 10:
                cout <<"Cantidad de nodos en la lista: " << lista.contarNodo() << endl;
                break;
            case 11:
                 cout <<"Valor del nodo maximo en la lista: " << lista.nodoMaximo() << endl;
                 break;
            case 12:
                 cout <<"Valor del nodo minimo en la lista: " << lista.nodoMinimo() << endl;
                 break; 
            case 13:
                 lista.invertir();
                 cout <<"Lista invertida\n";
                 break; 
             case 0:
                 cout <<"Saliendo del programa...\n";
                 break; 
             default:
                 cout <<"Opcion no valida\n";
        }

    }while (opcion != 0);
    
    return 0;
}