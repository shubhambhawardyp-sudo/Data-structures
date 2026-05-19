#include <iostream>
#include <queue>
using namespace std;

int adj[50][50] = {0};
int visited[50] = {0};
string loc[50];
int n;

void resetVisited()
{
    for(int i = 0; i < n; i++)
        visited[i] = 0;
}

void dfs(int s)
{
    visited[s] = 1;
    cout << loc[s] << " ";

    for(int i = 0; i < n; i++)
    {
        if(adj[s][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

void bfs(int s)
{
    queue<int> q;

    visited[s] = 1;
    q.push(s);

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        cout << loc[v] << " ";

        for(int i = 0; i < n; i++)
        {
            if(adj[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

void createGraph()
{
    cout << "Enter number of locations: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter location " << i << ": ";
        cin >> loc[i];
    }

    cout << "\nEnter connections (1 = Yes, 0 = No)\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            cout << loc[i] << " <-> " << loc[j] << " : ";
            cin >> adj[i][j];
            adj[j][i] = adj[i][j];
        }
    }

    cout << "\nGraph Created.\n";
}

void display()
{
    cout << "\nAdjacency Matrix:\n\t";

    for(int i = 0; i < n; i++)
        cout << loc[i] << "\t";

    cout << endl;

    for(int i = 0; i < n; i++)
    {
        cout << loc[i] << "\t";

        for(int j = 0; j < n; j++)
            cout << adj[i][j] << "\t";

        cout << endl;
    }
}

int main()
{
    int choice, start;

    do
    {
        cout << "\n----- MENU -----\n";
        cout << "1. Create Graph\n";
        cout << "2. Display Graph\n";
        cout << "3. DFS\n";
        cout << "4. BFS\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                createGraph();
                break;

            case 2:
                display();
                break;

            case 3:
                resetVisited();

                cout << "Enter starting vertex index: ";
                cin >> start;

                if(start >= 0 && start < n)
                {
                    cout << "DFS: ";
                    dfs(start);
                    cout << endl;
                }
                else
                {
                    cout << "Invalid index.\n";
                }

                break;

            case 4:
                resetVisited();

                cout << "Enter starting vertex index: ";
                cin >> start;

                if(start >= 0 && start < n)
                {
                    cout << "BFS: ";
                    bfs(start);
                    cout << endl;
                }
                else
                {
                    cout << "Invalid index.\n";
                }

                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while(choice != 5);

    return 0;
}