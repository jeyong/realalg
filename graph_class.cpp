//
//  main.cpp
//  cppstl
//
//  Created by jeyong on 27/07/2018.
//  Copyright © 2018 jeyong. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;


class Vertex {
public:
    string Name;
    int id;

    bool operator< (const Vertex& obj) const
    {
        if(obj.Name < this->Name)
        {
            return true;
        }
        return false;
    }
    bool operator== (const Vertex& obj) const
    {
        if(obj.Name == this->Name)
        {
            return true;
        }
        return false;
    }
};

class Neighbor {
public:
    Vertex adj;
    int cost;
};

class Graph {
public:
    Graph(){
        
    }
    void AddVertex(Vertex x);
    void AddEdge(Vertex sour, Vertex dest, int weight);
    void BFS(Vertex sour);
    vector<Vertex> GetNeighbors(Vertex v);
    void Display();
private:
    map<Vertex, vector<Neighbor>> vertexs;
};

vector<Vertex> Graph::GetNeighbors(Vertex v)
{
    vector<Vertex> neighbors;
    for (auto it=begin(vertexs); it != end(vertexs); it++)
    {
        if (it->first == v)
        {
            for(auto e: it->second)
            {
                neighbors.push_back(e.adj);
            }
        }
    }
    return neighbors;
}

void Graph::AddVertex(Vertex v)
{
    for (auto it = begin(vertexs); it!=end(vertexs); it++)
    {
        if (it->first == v )
        {
            return ;
        }
    }
    vertexs.insert(pair<Vertex, vector<Neighbor>>(v, vector<Neighbor>()));
}

void Graph::AddEdge(Vertex sour, Vertex dest, int weight)
{
    Neighbor n = {dest, weight};
    
    auto it = vertexs.find(sour);
    if (it != vertexs.end()){
        it->second.push_back(n);
    }
}

void Graph::BFS(Vertex sour)
{
    queue<Vertex> q;
    set<Vertex> visited;
    
    q.push(sour);
    
    for ( ;!q.empty();)
    {
        auto cur = q.front();
        q.pop();
        const bool is_in = visited.find(cur) != visited.end();
        if (is_in)
        {
            continue;
        }
        cout<<"Traversal : "<<cur.Name<<endl;
        auto neighbors = GetNeighbors(cur);
        for (auto e : neighbors)
        {
            q.push(e);
        }
        visited.insert(cur);
    }
}

void Graph::Display()
{
    for (auto it=begin(vertexs); it != end(vertexs); it++)
    {
        cout<<"Vertex : "<<it->first.Name<<" Neighbors : ";
        for (auto e : it->second)
        {
            cout<<e.adj.Name << " weight: "<<e.cost<<" ";
        }
        cout<<endl;
    }
    
}

int main(int argc, const char * argv[])
{
    Graph g;
    Vertex v1, v2, v3, v4, v5;
    v1.Name = "A";
    v2.Name = "B";
    v3.Name = "C";
    v4.Name = "D";
    v5.Name = "E";
    
    g.AddVertex(v1);
    g.AddVertex(v2);
    g.AddVertex(v3);
    g.AddVertex(v4);
    g.AddVertex(v5);
    
    g.AddEdge(v1, v2, 3);
    g.AddEdge(v2, v1, 2);
    g.AddEdge(v1, v3, 3);
    g.AddEdge(v3, v1, 2);
    
    g.AddEdge(v2, v5, 3);
    g.AddEdge(v5, v2, 2);
    g.AddEdge(v2, v4, 3);
    g.AddEdge(v4, v2, 2);
    
    g.AddEdge(v3, v5, 3);
    g.AddEdge(v5, v3, 2);
    
    g.AddEdge(v4, v5, 3);
    g.AddEdge(v5, v4, 2);
    
    g.Display();
    g.BFS(v1);
}
