#include <iostream>
#include "miGrafo1.h"

using namespace std;

int main(){

    int opc, sizeGraph;
    miGrafo mg;
    do {
        vector<edgeGrafo> edges;
        int cantEdges = 0;

        cout << "------ Opciones ------" << endl;
        cout << "1) Ingresar cantidad de nodos" << endl;
        cout << "2) Ingresar aristas" << endl;
        cout << "3) Imprimir grafo" << endl;
        cout << "4) Limpiar grafo" << endl;
        cout << "0) Salir" << endl;

        cout << "Ingresar opcion: ";
        cin >> opc;

        switch (opc) {
        case 0:
            break;
        case 1:
            cout << "Ingrese cantidad N de nodos: ";
            cin >> sizeGraph;
            edges.resize(sizeGraph);
            cantEdges = sizeof(edges)/ sizeof(edges[0]);
            continue;
        case 2:{
            int x, y, w = 0;
            for(int i = 0; i < sizeGraph; i++){
                cout << "Ingrese node inicial: ";
                cin >> x;
                cout << "Ingrese nodo final: ";
                cin >> y;
                cout << "Ingrese peso de arista: ";
                cin >> w;
                edges.insert(edges.begin() + i, {x,y,w});
            }
            continue;
        }
        case 3:{
            miGrafo miG(edges,cantEdges,sizeGraph);
            for (int i = 0; i < edges.size(); i++) {
                mg.printGrafo(miG.head[i], i);
            }
            continue;
        }
        case 4:
            edges.clear();
            continue;
        default:
            cout << "Opcion no existe. Intente de nuevo." << endl;
            continue;
        }

    } while (opc != 0);
    
    return 0;
}