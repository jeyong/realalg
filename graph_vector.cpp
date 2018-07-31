
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Graph {
    map<int, vector<int>> vs;
};

void breadth_traversal(Graph& g, int source);

int main(int argc, const char * argv[])
{
    Graph g;
    g.vs.insert({0, {1, 6, 8}});
    g.vs.insert({1, {0, 4, 6, 9} });
    g.vs.insert({2, {4, 6}});
    g.vs.insert({3, {4, 5, 8}});
    g.vs.insert({4, {1, 2, 3, 5, 9} });
    g.vs.insert({5, {3, 4} });
    g.vs.insert({6, {0, 1, 2} });
    g.vs.insert({7, {8, 9} });
    g.vs.insert({8, {0, 3, 7} });
    g.vs.insert({9, {1, 4, 7} });
    breadth_traversal(g, 0);
}

void breadth_traversal(Graph& g, int source)
{
    map<int, bool> visited;
    vector<int> queue;
    queue.push_back(source);
    
    while (!queue.empty())
    {
        int v = queue.front();
        queue.erase(begin(queue));
        
        if (visited[v] == true)
        {
            continue;
        }
            
        visited[v] = true;
        cout<<v<<"->";

        for (auto e: g.vs[v])
        {
            if (visited[e] == true)
            {
                continue;
            }
            else {
                queue.push_back(e);
            }
        }
    }
}
