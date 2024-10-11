#include <iostream>

using namespace std;

template <typename T>
struct Nodo {
    T data;
    Nodo<T>* derecha;
    Nodo<T>* izquierda;
    Nodo<T>* padre;
    Nodo<T>* hijo;
    bool mark; // indica si perdió o no un hijo
    int rank; // cantidad de hijos
    Nodo(): data(0), derecha(nullptr), izquierda(nullptr), padre(nullptr), hijo(nullptr), mark(false), rank(0){};
    Nodo(T valor): data(valor), derecha(nullptr), izquierda(nullptr), padre(nullptr), hijo(nullptr), mark(false), rank(0){};
};

template<typename T>
class FHeap{
    private:
    Nodo<T>* rootlist: // lista raiz del heap
    Nodo<T>* ptr_min; // puntero al nodo min de rootlist
    int cont; // contador de la cantidad de nodos en el heap
    public:
    FHeap(): rootlist(nullptr), ptr_min(nullptr), cont(0){};
    // declaracion de los metodos 
    // de la clase principal
    void insert(T valor);
    T valor_min();
    bool empty();
    int size();

};

template <typename T>
void FHeap<T>::insert(T valor){
    // creamos una pequeña lista circular
    // con el nodo a insertar
    Nodo<T>* nnodo = new Nodo<T>(valor);
    nnodo->derecha = nnodo->izquierda = nnodo;

    // preguntamos si el rootlist esta vacío o no
    if(rootlist == nullptr){
        // en caso lo sea, el nuevo nodo ocupada ese lugar
        rootlist == nnodo;
        // al igual que el puntero minimo
        ptr_min == nnodo;
    } else {
        // en caso rootlist no sea vacío
        nnodo->derecha = rootlist;
        nnodo->izquierda = rootlist->izquierda;
        rootlist->izquierda->derecha = nnodo;
        root->izquirda = nnodo;
        // actualizamos el puntero minimo si es el caso
        if (nnodo->data < ptr_min->data){
            ptr_min = nnodo;
        }
    }
    // incrementamos en 1 la cantidad de nodos en el Heap
    cont = cont + 1;
};

template <typename T>
T FHeap<T>::valor_min(){
    return ptr_min->data;
};

template <typename T>
bool FHeap<T>::empty(){
    return rootlist == nullptr;
};

template <typename T>
int FHeap<T>::size(){
    return cont;
}

int main(){
    return 0;
};
