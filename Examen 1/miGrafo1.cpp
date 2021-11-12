#include <iostream>
#include "miGrafo1.h"

nodoAdy* miGrafo::insertNodo(int _val, int _weight, nodoAdy* head)   {
    nodoAdy* newNode = new nodoAdy;
    newNode->val = _val;
    newNode->cost = _weight;

    newNode->next = head;
    return newNode;
}

miGrafo::miGrafo(){
    
}

miGrafo::miGrafo(vector<edgeGrafo> edges, int n, int N)  {
    // allocate new node
    head = new nodoAdy*[N]();
    this->N = N;
    // initialize head pointer for all vertices
    for (int i = 0; i < N; ++i)
        head[i] = nullptr;
    // construct directed graph by adding edges to it
    for (unsigned i = 0; i < n; i++)  {
        int start_vert = edges[i].start_vert;
        int end_vert = edges[i].end_vert;
        int weight = edges[i].weight;
        // insert in the beginning
        nodoAdy* newNode = insertNodo(end_vert, weight, head[start_vert]);
             
        // point head pointer to new node
        head[start_vert] = newNode;
    }
}

miGrafo::~miGrafo() {
    for (int i = 0; i < N; i++){
        delete[] head[i];
        delete[] head;
    }
}

void miGrafo::printGrafo(nodoAdy* ptr, int i) {

    while (ptr != nullptr) {
        cout << "(" << i << ", " << ptr->val << ", " << ptr->cost << ") ";
        ptr = ptr->next;
    }
    cout << endl;
}