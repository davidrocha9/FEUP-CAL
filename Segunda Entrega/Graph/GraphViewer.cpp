//
// Created by josed on 13/05/2020.
//

#include "GraphViewer.h"

GraphViewer * createWindow(Graph g){
    double height = g.getMaxY() - g.getMinY();
    double width = g.getMaxX() - g.getMinX();
    int graphSize = 2000;

    auto *gv = new GraphViewer(600, 600, false);
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    for(Vertex* vertex: g.getVertexSet()) {
        double y = (vertex->getY() - g.getMinY())/height;
        double x = (vertex->getX() - g.getMinX())/width;

        gv->addNode(vertex->getId(), (int)(x*graphSize), (int)(y*1341));
        gv->setVertexSize(vertex->getId(), 5);
    }
    int id = 0;

    for(Vertex* vertex: g.getVertexSet()) {
        for(Edge edge: vertex->getAdj()) {
            gv->addEdge(id, vertex->getId(), edge.getDestID(), EdgeType::UNDIRECTED);
            id++;
        }
    }

    gv->rearrange();
    return gv;
}