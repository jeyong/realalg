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

using namespace std;


class Vertex {
public:
    string Name;

    bool operator< (const Vertex& obj) const
    {
        if(obj.Name < this->Name)
            return true;
        return false;
    }
};

class Neighbor {
public:
    string Name;
    int cost;
};

class Graph {
public:
    Graph(){
        
    }
    void AddVertex(Vertex x);
    void AddEdge(Vertex sour, Vertex dest, int weight);
    void Init();

    void Display();
    
    map<Vertex, vector<Neighbor>> vertexs;
};

void Graph::AddVertex(Vertex v)
{
    for (auto it = begin(vertexs); it!=end(vertexs); it++)
    {
        if (it->first.Name == v.Name )
        {
            return ;
        }
    }
    vertexs.insert(pair<Vertex, vector<Neighbor>>(v, vector<Neighbor>()));
}

void Graph::AddEdge(Vertex sour, Vertex dest, int weight)
{
    Neighbor n = {dest.Name, weight};
    
    auto it = vertexs.find(sour);
    if (it != vertexs.end()){
        it->second.push_back(n);
    }
}

void Graph::Display()
{
    for (auto it=begin(vertexs); it != end(vertexs); it++)
    {
        cout<<"Vertex : "<<it->first.Name<<" Neighbors : ";
        for (auto e : it->second)
        {
            cout<<e.Name << " weight: "<<e.cost<<" ";
        }
        cout<<endl;
    }
    
}

int main(int argc, const char * argv[])
{
    Graph g;
    Vertex v1, v2;
    v1.Name = "A";
    v2.Name = "B";
    g.AddVertex(v1);
    g.AddVertex(v2);
    g.AddEdge(v1, v2, 3);
    g.AddEdge(v2, v1, 2);
    g.Display();
    //g.AddEdge(<#Vertex sour#>, <#Vertex dest#>, <#int weight#>)
}
