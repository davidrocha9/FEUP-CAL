#include "FileReader.h"
#include <fstream>
#include <iostream>
#include "math.h"
#include "../Graph/Graph.h"
#include "../Graph/GraphViewer.h"

using namespace std;

double getDur(double w, double s){
    if (s > 0)
        return w/1.25;
    else
        return w/1.75;
}

double getDistance(int src, int dest, Graph graph, double s){
    Vertex* v1 = graph.findVertex(src);
    Vertex* v2 = graph.findVertex(dest);

    double res = sqrt(pow(v1->getX() - v2->getX(), 2) + pow(v1->getY() - v2->getY(), 2));

    return res / cos(abs(s) * (3.14/180.0));
}

double getSlope(){
    double slopeNum = rand() % 30000 + 1;
    double slopeDen = 1000 + rand() % 5000 + 1;

    return slopeNum/slopeDen;
}

void createGraph(){
    Graph graph;
    readNodes(graph);
    readEdges(graph);

    createWindow(graph);
}

void readNodes(Graph &graph) {
    ifstream file;
    file.open("../Maps/GridGraphs/4x4/nodes.txt");
    string temp = "";
    int id, var = 0;
    double x, y;

    if(file.is_open()){
        getline(file, temp);
        while(getline(file, temp)){
            while(temp.find(',') != string::npos){
                int index = temp.find(',');
                if (var == 0) {
                    id = stoi(temp.substr(1, index));
                    var++;
                } else {
                    x = stoi(temp.substr(1, index));
                }
                temp = temp.erase(0, index + 1);
            }
            y = stoi(temp);
            var = 0;
            graph.addVertex(id, x ,y);
        }
    }
    file.close();
}

void readEdges(Graph &graph) {
    ifstream file;
    file.open("../Maps/GridGraphs/4x4/edges.txt");
    string temp = "";
    int src, dest;
    double weight, slope;

    if(file.is_open()){
        getline(file, temp);
        while(getline(file, temp)){
            while(temp.find(',') != string::npos){
                int index = temp.find(',');
                src = stoi(temp.substr(1, index));
                temp = temp.erase(0, index + 1);
                dest = stoi(temp);
            }
            slope = getSlope();
            weight = getDistance(src, dest, graph, slope);
            graph.addEdge(src, dest, weight, slope, getDur(weight, slope));
            graph.addEdge(dest, src, weight, -slope, getDur(weight, slope));

            cout << slope << endl;
            cout << weight << endl;
            cout << getDur(weight, slope) << endl << endl;
        }
    }
    file.close();
}