#include <iostream> 
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include "Graph.hpp"
#define INF 0x3f3f3f3f
typedef std::pair<int, Vertex*> qp;

Graph::Graph() {

    vlist = std::vector<Vertex *>();

}


void Graph::addVertex(std::string name) {

    vlist.push_back(new Vertex(name));

}


Vertex *Graph::getVertex(std::string name) {

    for (int i = 0; i < vlist.size(); i++) {
        if (vlist[i] -> name == name) {
            return vlist[i];
        }
    }

    return NULL;

}

void Graph::addEdge(std::string from, std::string to, int weight) {

    if (from == to) {
        Edge* _edge = (new Edge (getVertex(from), getVertex(from), weight));
        getVertex(from) -> adjlist.push_back(_edge);
    }
    else {
        Edge* _edge1 = (new Edge (getVertex(from), getVertex(to), weight));
        Edge* _edge2 = (new Edge (getVertex(to), getVertex(from), weight));
        getVertex(from) -> adjlist.push_back(_edge1);
        getVertex(to) -> adjlist.push_back(_edge2);
    }

}

Edge *Graph::getEdge(std::string from, std::string to) {

    for (int i = 0; i < vlist.size(); i++) {
        if (vlist[i] -> name == from) {
            for (auto j : vlist[i] -> adjlist) {
                if (((j -> from == getVertex(from))&&(j -> to == getVertex(to)))||((j -> from == getVertex(to))&&(j -> to == getVertex(from)))) {
                    return j;
                }
            }
        }
    } 

    return NULL;

}

int Graph::MSTCost() {
    int cost = 0;
    std::vector<Edge*> elist;

    for (auto i : MST() -> vlist) {
        elist.insert(elist.end(), i -> adjlist.begin(), i -> adjlist.end());
    }

    for (auto i : elist) {
        if (i -> from == i-> to) {
            cost += 2 * i -> weight;
        }

        else{
            cost += i -> weight;
        }
    }

    return cost/2;

}

Graph *Graph::MST() {
    Graph* T = new Graph();
    std::vector<Edge*> elist;
    
    if (!vlist.empty()) {
        T -> addVertex(vlist[0] -> name);
    }

    for (auto i : vlist) {
        elist.insert(elist.end(), i -> adjlist.begin(), i -> adjlist.end());
    }

    while (T -> vlist.size() < vlist.size()) {
        int w = 999999;
        Edge* newE;
        Vertex* newV;

        for (auto i : elist) {
            if((findVertex(i -> from, T -> vlist) && !(findVertex(i -> to, T -> vlist)))) {
                if (i -> weight < w) {
                    w = i -> weight;
                    newE = i;
                    newV = i -> to;
                }
            }
        } 
        T -> addVertex(newV -> name);
        T -> addEdge(newE -> from -> name, newE -> to -> name, newE -> weight);
    }
    
    return T;

}

bool Graph::findVertex(Vertex* V, std::vector<Vertex*> vertices) {

    for (auto i : vertices) {
        if (i -> name == V -> name) {
            return true;
        }
    }
    return false;

}

int Graph::SPCost(std::string from, std::string to) {

    int cost = 0;
    std::vector<Edge*> elist;

    for (auto i : SP(from, to) -> vlist) {
        elist.insert(elist.end(), i -> adjlist.begin(), i -> adjlist.end());
    }

    for (auto i : elist) {
        cost += i -> weight;
    }

    return cost/2;

}

Graph *Graph::SP(std::string from, std::string to) {

    Graph* T = new Graph();
    std::vector<int> dist(vlist.size(), INF);
    std::vector<Vertex*> prev(vlist.size());
    std::priority_queue<qp, std::vector<qp>, std::greater<qp>> q; 
    
    for (int i = 0; i < vlist.size(); i++) {
        if (vlist[i] -> name == from) {
            dist[i] = 0;
        }
        else {
            dist[i] = INF;
        }
        q.push(std::make_pair(i, vlist[i]));
    }

    while (!q.empty()) {
        Vertex* u = q.top().second;
        q.pop();

        if (u -> name == to) {
            std::stack<Vertex*> s;
            while (u -> name != from) { 
                s.push(u);
                u = prev[getIndex(u, vlist)];
            }

            std::string lastNode = from;
            std::vector<Edge*> elist;
            T -> addVertex(lastNode);

            while(!s.empty()) {
                T -> addVertex(s.top() -> name);
                Edge* newE = getEdge(lastNode, s.top() -> name);
                elist.push_back(newE);
                T -> addEdge(newE -> from -> name, newE -> to -> name, newE -> weight);
                lastNode = s.top() -> name;
                s.pop();
            }

            return T;
        
        }

        std::vector<Vertex*> neighbours;    
        for (auto i : u -> adjlist) {
            neighbours.push_back(i -> to); 
        }

        for (auto v : neighbours) {
            int d = dist[getIndex(u, vlist)] + getEdge(u -> name, v -> name) -> weight;

            if (d < dist[getIndex(v, vlist)]) {
                dist[getIndex(v, vlist)] = d;
                prev[getIndex(v, vlist)] = u;
                // decrease key
                q.push(std::make_pair(d, v));
        
            }
        }
        neighbours.clear();
    }

    return NULL;

}

int Graph::getIndex(Vertex* V, std::vector<Vertex*> vlist) {
	
    int index = 0;
    for (auto x : vlist){
        if (x == V) {
            return index;
        }
        index++;
    
    }

    return -1;
}
