#include <iostream>
#include <vector>
#include <stdexcept>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    // Crea un vector de 2D n x n
    Graph(int n) : numVertices(n), adjMatrix(n, std::vector<int>(n, 0)) {}

    // Add a vertex from node u to node v
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjMatrix[u][v] = 1;
        } else {
            std::out_of_range("Vertice fuera de rango");
        }
    }

    // Imprime la matriz de adyacencias
    void print() const {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Implementar!! 
    // Devuelve la cantidad de aristas
    //Recorre la matriz en busca de 1 (alternativamente se puede agregar un data member que incremente cada vez que se agregue un edge, but that aint the point, right?)
    int numEdges() const {
        int edgeCount = 0;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (adjMatrix[i][j] == 1)edgeCount++;
                }
            }
        return edgeCount;
}

    // Completa esta función
    // Devuelve el in-degree de un vertice
    //Recorre los edges en la columna u y los cuenta
    int inDegree(int u) const {

        int inCount = 0;
        if (u < 0 || u >= numVertices)
            throw std::out_of_range("Vertice fuera de rango");
        else {
            for (int i = 0; i < numVertices; i++)
            {
                if (adjMatrix[i][u] == 1) inCount++;
            }
        }
        return inCount;
    }

    // Completa esta función
    // Devuelve cierto si u es el nodo con mayor inDegree.
    // En caso de que haya varios nodos que tengan el mayor inDegree,
    // devuelve true si u es uno de ellos
    //May I return a string? :(
    bool isInfluencer(int u) const{
        int popularity_poll = inDegree(u);
        for (int i = 0; i < numVertices; i++)
        {
            if (i == u){ }
            if (inDegree(i) > popularity_poll) return false;
        }

        return true;
    }
};

