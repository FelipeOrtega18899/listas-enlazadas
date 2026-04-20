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
        inicial = NULL;
    }

    bool estaVacia() {
        return inicial == NULL;
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
        nuevo->siguiente = NULL;

        if (estaVacia()) {
            inicial = nuevo;
            return;
        }

        Nodo* auxiliar = inicial;
        while (auxiliar->siguiente != NULL) {
            auxiliar = auxiliar->siguiente;
        }
        auxiliar->siguiente = nuevo;
    }
    void mostrarLista(Nodo* auxiliar) {
        if (auxiliar == NULL) {
            return;
        }
        cout << auxiliar->valor << " -> ";
        auxiliar = auxiliar->siguiente;
        mostrarLista(auxiliar);
    }
    void mostrar2() {
        mostrarLista(inicial);
        cout <<"NULL\n";
    }
    void insertarAntesDe(int referencia, int valor) {
        if (estaVacia()) {
            cout <<"Nose seas menso esta vacia\n";
            return;
        }
        Nodo* nuevo = new Nodo();
        nuevo->valor = valor;

        Nodo* actual = inicial;
        Nodo* anterior= NULL;

        while (actual != NULL && actual->valor != referencia) {
            anterior= actual;
            actual = actual->siguiente;

        }
            if (actual == NULL) {
                cout <<"Nose encontro la referencia\n";
            }
            if (anterior == NULL) {
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
        while (actual != NULL && actual->valor != referencia) {
            actual = actual->siguiente;
        }
        if (actual == NULL) {
            cout <<"Nose encontro la referencia\n";
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
        if (inicial->siguiente == NULL) {
            delete inicial;
            inicial = NULL;
            return;
        }
        Nodo* anterior = NULL;
        Nodo* actual = inicial;
        while (actual -> siguiente != NULL) {
            anterior = actual;
            actual = actual -> siguiente;
        }
        delete actual;
        anterior -> siguiente = NULL;
    }
    void eliminarValor(int valor) {
        if (estaVacia()) {
            cout <<"No seas menso esta vacia\n";
            return;
        }
        Nodo* actual = inicial;
        Nodo* anterior = NULL;
        while (actual != NULL && actual->valor != valor) {
            anterior = actual;
            actual = actual->siguiente;
        }
        if (actual == NULL) {
            cout <<"Nose encontro el valor\n";
            return;
        }
        if (anterior == NULL) {
            inicial = inicial -> siguiente;
        }else {
            anterior -> siguiente = actual -> siguiente;
        }
        delete actual;
    }
    bool buscar(int valor) {
        Nodo* auxiliar = inicial;
        while (auxiliar != NULL) {
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
        while (actual != NULL) {
            actual = actual->siguiente;
            contador++;
        }
        return contador;
    }
    int nodoMaximo() {
        if (estaVacia()) {
            cout <<"No seas menso esta vacia\n";
        }
        Nodo* actual = inicial;
        int maximo = actual -> valor;
        while (actual != NULL) {
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
        }
        Nodo* actual = inicial;
        int minimo = actual -> valor;
        while (actual != NULL) {
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
        Nodo* anterior = NULL;
        Nodo* auxiliar = NULL;

        while (actual != NULL) {
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

        if (opcion == 1) {
            cout <<"Ingrese un valor: ";
            cin >> valor;
            lista.insertarInicio(valor);
        } else if (opcion == 2) {
            cout <<"Ingrese un valor: ";
            cin >> valor;
            lista.insertarFinal(valor);
        }else if (opcion == 3) {
            cout <<"Ingrese un valor: ";
            cin >> valor;
            cout <<"Ingrese un referencia: ";
            cin >> referencia;
            lista.insertarAntesDe(referencia,valor);
        }else if (opcion == 4) {
            cout <<"Ingresa un valor: ";
            cin >> valor;
            cout <<"Ingrese un referencia: ";
            cin >> referencia;
            lista.insertarDespuesDe(referencia,valor);
        }else if (opcion == 5){
            lista.eliminarInicial();
        }else if (opcion == 6) {
            cout <<"Ingrese un valor: ";
            cin >> valor;
            lista.eliminarValor(valor);
        }else if (opcion == 7) {
            lista.eliminarUltimo();
        }else if (opcion == 8) {
            cout <<"Ingrese un valor: ";
            cin >> valor;
            if (lista.buscar(valor)) {
                cout <<"Se encontro el valor\n";
            }else {
                cout <<"No se encontro el valor\n";
            }
        }else if (opcion == 9) {
            lista.mostrar2();
        }else if (opcion == 10) {
            cout <<"La cantidad de nodos es: " << lista.contarNodo() << endl;
        }else if (opcion == 11) {
            cout <<"El nodo maximo es: " << lista.nodoMaximo() << endl;
        }else if (opcion == 12) {
            cout <<" El nodo minimo es: " << lista.nodoMinimo() << endl;
        }else if (opcion == 13) {
            lista.invertir();
        }
    }while (opcion != 0);
    
    return 0;
}