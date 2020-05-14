#ifndef SEGUNDA_ENTREGA_GRAPH_H
#define SEGUNDA_ENTREGA_GRAPH_H

#include <vector>

using namespace std;

/************************* Edge **************************/
class Edge{
    int destID;
    double weight, slope, dur;
public:
    //Constructor
    Edge(int destID, double weight, double slope, double dur);

    //Get Methods
    int getDestID();
    double getWeight();
    double getSlope();
    double getDur();

    friend class Graph;
    friend class Vertex;
};

/************************* Vertex **************************/
class Vertex{
    int id;
    double x, y;
    bool visited;
    vector<Edge> adj;

public:
    //Constructor
    Vertex(int id, int x, int y);

    // Get Methods
    int getId();
    int getX();
    int getY();
    bool getVisited();
    vector<Edge> getAdj();

    // Set Methods
    void setId(int id);
    void setX(int x);
    void setY(int y);
    void setVisited();
    void addEdge(const int &dest, const double &w, const double &s, const double &d);

    friend class Graph;
};

/************************* Vertex **************************/
class Graph{
    double minX, maxX, minY, maxY;
    vector<Vertex*> vertexSet;
public:
    //Constructor
    Graph();

    //Get Methods
    double getMinX() const;
    double getMaxX() const;
    double getMinY()const;
    double getMaxY() const;
    vector<Vertex*> getVertexSet();

    Vertex *findVertex(const int &id) const;
    bool addVertex(const int &id, const double &x, const double &y);
    bool addEdge(const int &sourc, const int &dest, const double &weight, const double &slope, const double &dur);
};

#endif //SEGUNDA_ENTREGA_GRAPH_H
