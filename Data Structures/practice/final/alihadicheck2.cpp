#include <bits/stdc++.h>
using namespace std;

#define N 10
#define leave cout << endl;
#define loop(n) for (int i = 0; i < n; ++i)
#define print(n) cout << n
#define rep(ptr) for (Node *temp = ptr; temp; temp = temp->next)

class Node
{
    friend class AdjList;
    int vertex;
    Node *next;
    Node(int x) : vertex(x), next(nullptr) {}
};

class AdjList
{
    vector<Node *> list;

public:
    AdjList()
    {
        list.resize(N, nullptr);
    }

    void insertEdge(int u, int v) // Undirected Graph
    {
        if (u >= N || v >= N)
            return;

        auto addEdge = [&](int u, int v) -> void
        {
            if (list[u] == nullptr)
            {
                list[u] = new Node(v);
                return;
            }
            else
            {
                Node *ptr = list[u];
                while (ptr->next)
                {
                    ptr = ptr->next;
                }
                ptr->next = new Node(v);
            }
        };

        addEdge(u, v);
        addEdge(v, u);
    }

    void deleteEdge(int u, int v)
    {
        if (u >= N || v >= N || list[u] == nullptr || list[v] == nullptr)
            return;

        auto helpDelete = [&](int from, int to) -> void
        {
            Node *ptr = list[from];
            Node *previous = nullptr;
            while (ptr && ptr->vertex != to)
            {
                previous = ptr;
                ptr = ptr->next;
            }

            if (ptr == nullptr)
                return;

            if (previous == nullptr)
            {
                list[from] = ptr->next;
            }
            else
            {
                previous->next = ptr->next;
            }
        };

        helpDelete(u, v);
        helpDelete(v, u);
    }

    void bfs(int start = 1)
    {
        queue<int> q;
        vector<bool> visited(N, false);
        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            cout << current << " ";
            Node *ptr = list[current];
            while (ptr)
            {
                if (!visited[ptr->vertex])
                {
                    visited[ptr->vertex] = true;
                    q.push(ptr->vertex);
                }
                ptr = ptr->next;
            }
        }
    }

    void displayGraph()
    {
        loop(N)
        {
            Node *ptr = list[i];
            if (ptr == nullptr)
                continue;
            print(i) << " : ";
            while (ptr)
            {
                (ptr->next == nullptr) ? print(ptr->vertex) : print(ptr->vertex) << "->";
                ptr = ptr->next;
            }
            leave;
        }
    }

    void dfs()
    {
        int start = 1;
        vector<bool> visited(N, false);
        function<void(int)> help = [&](int current) -> void
        {
            visited[current] = true;
            print(current);

            Node *ptr = list[current];
            rep(ptr)
            {
                if (!visited[ptr->vertex])
                {
                    visited[ptr->vertex] = true;
                    help(ptr->vertex);
                }
            }
        };
        help(start);
    }
};

signed main()
{
    AdjList list;
    list.insertEdge(1, 2);
    list.insertEdge(2, 3);
    list.insertEdge(3, 4);
    list.displayGraph();
    leave;
    list.deleteEdge(1, 2);
    list.displayGraph();
    return 0;
}