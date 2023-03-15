#include <bits/stdc++.h>
using namespace std;

void dfs(bool **matrix, int vertices, bool *visited, int sv)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < vertices; i++)
    {
        if (matrix[sv][i] && !visited[i])
        {
            dfs(matrix, vertices, visited, i);
        }
    }
    return;
}

void bfs(bool **matrix, int vertices, int sv)
{
    bool *visited = new bool[vertices]{false};
    queue<int> pending_nodes;
    pending_nodes.push(sv);
    visited[sv] = true;

    while (!pending_nodes.empty())
    {
        int current = pending_nodes.front();
        pending_nodes.pop();
        cout << current << endl;
        for (int i = 0; i < vertices; i++)
        {
            if (matrix[current][i] && !visited[i])
            {
                pending_nodes.push(i);
                visited[i] = true;
            }
        }
    }
    return;
}

bool **take_input(int edges, int vertices)
{
    bool **matrix = new bool *[vertices];
    for (int i = 0; i < vertices; i++)
    {
        matrix[i] = new bool[vertices]{false};
    }

    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;
        matrix[a][b] = true;
        matrix[b][a] = true;
    }
    return matrix;
}

int main()
{
    int edges, vertices;
    cin >> vertices;
    cin >> edges;
    bool **matrix = take_input(edges, vertices);
    // bool *visited = new bool[vertices]{false};
    // dfs(matrix, vertices, visited, 1);
    bfs(matrix, vertices, 1);
}