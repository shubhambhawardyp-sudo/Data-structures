#include <iostream>
#include <climits>
using namespace std;

class UtilityGrid {
    int adj[20][20];
    string station[20];
    int n;

public:

    // Create Graph
    void createGraph() {

        cout << "Enter number of power stations: ";
        cin >> n;

        cout << "Enter station names:\n";

        for(int i=0; i<n; i++) {
            cin >> station[i];
        }

        // Initialize matrix
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {

                if(i == j)
                    adj[i][j] = 0;
                else
                    adj[i][j] = INT_MAX;
            }
        }

        int edges;

        cout << "Enter number of connections: ";
        cin >> edges;

        cout << "\nEnter source destination time:\n";

        for(int i=0; i<edges; i++) {

            int u, v, weight;

            cin >> u >> v >> weight;

            adj[u][v] = weight;
            adj[v][u] = weight;
        }
    }

    // Dijkstra Algorithm
    void dijkstra(int start) {

        int dist[20];
        bool visited[20];

        for(int i=0; i<n; i++) {

            dist[i] = INT_MAX;
            visited[i] = false;
        }

        dist[start] = 0;

        for(int count=0; count<n-1; count++) {

            int min = INT_MAX, u;

            for(int i=0; i<n; i++) {

                if(!visited[i] && dist[i] <= min) {

                    min = dist[i];
                    u = i;
                }
            }

            visited[u] = true;

            for(int v=0; v<n; v++) {

                if(!visited[v] &&
                   adj[u][v] != INT_MAX &&
                   dist[u] + adj[u][v] < dist[v]) {

                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }

        cout << "\nMinimum power transmission time:\n";

        for(int i=0; i<n; i++) {

            cout << station[start]
                 << " -> "
                 << station[i]
                 << " = "
                 << dist[i]
                 << endl;
        }
    }

    // Reachable Stations
    void reachableStations(int start, int limit) {

        int dist[20];
        bool visited[20];

        for(int i=0; i<n; i++) {

            dist[i] = INT_MAX;
            visited[i] = false;
        }

        dist[start] = 0;

        for(int count=0; count<n-1; count++) {

            int min = INT_MAX, u;

            for(int i=0; i<n; i++) {

                if(!visited[i] && dist[i] <= min) {

                    min = dist[i];
                    u = i;
                }
            }

            visited[u] = true;

            for(int v=0; v<n; v++) {

                if(!visited[v] &&
                   adj[u][v] != INT_MAX &&
                   dist[u] + adj[u][v] < dist[v]) {

                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }

        cout << "\nStations reachable within time "
             << limit << ":\n";

        for(int i=0; i<n; i++) {

            if(dist[i] <= limit)

                cout << station[i]
                     << " (time "
                     << dist[i]
                     << ")" << endl;
        }
    }
};

int main() {

    UtilityGrid g;

    int start, limit;

    g.createGraph();

    cout << "\nEnter source station index: ";
    cin >> start;

    g.dijkstra(start);

    cout << "\nEnter maintenance time limit: ";
    cin >> limit;

    g.reachableStations(start, limit);

    return 0;
}