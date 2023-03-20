#include <bits/stdc++.h>
using namespace std;

void print_dfs(bool **matrix, int vertices, bool *visited, int sv)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < vertices; i++)
    {
        if (matrix[sv][i] && !visited[i])
        {
            print_dfs(matrix, vertices, visited, i);
        }
    }
    return;
}

void DFS(bool **matrix, int vertices)
{
    bool *visited = new bool[vertices]{false};
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
            print_dfs(matrix, vertices, visited, i);
    }
    delete[] visited;
    return;
}

void print_bfs(bool **matrix, int vertices, bool *visited, int sv)
{
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

void BFS(bool **matrix, int vertices)
{
    bool *visited = new bool[vertices]{false};
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
            print_bfs(matrix, vertices, visited, i);
    }
    delete[] visited;
    return;
}

bool has_path_helper(bool **matrix, int vertices, int a, int b, bool *visited)
{
    if (matrix[a][b])
    {
        cout << a << ' ' << b << endl;
        return true;
    }

    bool hasPath = false;
    for (int i = 0; i < vertices; i++)
    {
        if (hasPath)
            return hasPath;
        if (!visited[i] && matrix[a][i])
        {
            visited[i] = true;
            hasPath |= has_path_helper(matrix, vertices, i, b, visited);
        }
    }
    return hasPath;
}

bool has_path(bool **matrix, int vertices, int a, int b)
{
    bool *visited = new bool[vertices]{false};
    bool ans = has_path_helper(matrix, vertices, a, b, visited);
    delete[] visited;
    return ans;
}

vector<int> *get_path_helper(bool **matrix, int vertices, bool *visited, int a, int b)
{
    visited[a] = true;

    if (a == b)
    {
        vector<int> *ans = new vector<int>;
        ans->push_back(a);
        return ans;
    }

    for (int i = 0; i < vertices; i++)
    {
        if (matrix[a][i] && !visited[i])
        {
            auto temp = get_path_helper(matrix, vertices, visited, i, b);
            if (temp != NULL)
            {
                temp->push_back(a);
                return temp;
            }
        }
    }

    return NULL;
}

vector<int> *get_path(bool **matrix, int vertices, int a, int b)
{
    bool *visited = new bool[vertices]{false};
    auto ans = get_path_helper(matrix, vertices, visited, a, b);
    delete[] visited;
    return ans;
}

vector<int> *get_path_bfs_helper(bool **matrix, int vertices, bool *visited, int a, int b)
{
    queue<int> pending_nodes;
    unordered_map<int, int> parent_rel;

    pending_nodes.push(a);
    parent_rel.insert(make_pair(a, a));

    while (!pending_nodes.empty())
    {
        auto current = pending_nodes.front();
        pending_nodes.pop();
        visited[current] = true;

        for (int i = 0; i < vertices; i++)
        {
            if (matrix[current][i] && !visited[i])
            {
                pending_nodes.push(i);
                parent_rel.insert(make_pair(i, current));

                if (i == b)
                    break;
            }
        }
    }

    vector<int> *ans = new vector<int>;
    while (!pending_nodes.empty())
    {
        ans->push_back(pending_nodes.front());
        pending_nodes.pop();
    }
    return ans;
}

vector<int> *get_path_bfs(bool **matrix, int vertices, int a, int b)
{
    bool *visited = new bool[vertices]{false};
    auto ans = get_path_bfs_helper(matrix, vertices, visited, a, b);
    delete[] visited;
    return ans;
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
    cin >> vertices >> edges;
    bool **matrix = take_input(edges, vertices);
    int a, b;
    cin >> a >> b;
    auto ans = get_path(matrix, vertices, a, b);
    if (ans == NULL)
    {
        return 0;
    }
    auto it = ans->begin();
    while (it != ans->end())
    {
        cout << *it << ' ';
        it++;
    }
    cout << endl;
    return 0;
}