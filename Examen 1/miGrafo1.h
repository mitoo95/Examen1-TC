#include <iostream>
#include <vector>
using namespace std;

struct nodoAdy {
    int val, cost;
    nodoAdy* next;
};

struct edgeGrafo {
    int start_vert, end_vert, weight;
};

class miGrafo{

    nodoAdy* insertNodo(int _val, int _weight, nodoAdy* head);
    int N;

    public:
        nodoAdy** head;
        miGrafo();
        miGrafo(vector<edgeGrafo> edges, int n, int N);
        ~miGrafo();
        void printGrafo(nodoAdy* ptr, int i);

};