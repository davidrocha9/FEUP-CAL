#include <iostream>
#include "Graph.h"

/************************* Edge  **************************/
Edge::Edge(int destID, double weight, double slope, double dur) {
    this->destID = destID;
    this->weight = weight;
    this->slope = slope;
    this->dur = dur;
}

int Edge::getDestID() {
    return destID;
}

double Edge::getWeight() {
    return weight;
}

double Edge::getSlope() {
    return slope;
}

double Edge::getDur() {
    return dur;
}

/************************* Vertex  **************************/
// Constructor
Vertex::Vertex(int id, int x, int y) : id(id), x(x), y(y){
    this->visited = false;
}

// Get Methods
int Vertex::getId() {
    return id;
}

int Vertex::getX() {
    return x;
}

int Vertex::getY() {
    return y;
}

bool Vertex::getVisited() {
    return visited;
}

// Set Methods
void Vertex::setId(int id) {
    this->id = id;
}

void Vertex::setX(int x) {
    this->x = x;
}

void Vertex::setY(int y) {
    this->y = y;
}

void Vertex::setVisited() {
    this->visited = true;
}

vector<Edge> Vertex::getAdj() {
    return adj;
}

void Vertex::addEdge(const int &dest, const double &w, const double &s, const double &d) {
    adj.emplace_back(dest, w, s, d);
}


/************************* Vertex **************************/

Graph::Graph() {

}

double Graph::getMinX() const {
    return minX;
}

double Graph::getMaxX() const {
    return maxX;
}

double Graph::getMinY() const {
    return minY;
}

double Graph::getMaxY() const {
    return maxY;
}

vector<Vertex *> Graph::getVertexSet() {
    return vertexSet;
}

Vertex *Graph::findVertex(const int &id) const {
    for (auto v : vertexSet)
        if (v->id == id)
            return v;
    return nullptr;
}

bool Graph::addVertex(const int &id, const double &x, const double &y) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(id, x, y));
    if(x > maxX) maxX = x;
    if(x < minX) minX = x;
    if(y > maxY) maxY = y;
    if(y < minY) minY = y;
    return true;
}

bool Graph::addEdge(const int &sourc, const int &dest, const double &weight, const double &slope, const double &dur) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2->getId(), weight, slope, dur);
    return true;
}
