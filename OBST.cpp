#include <iostream>
using namespace std;

#define MAX 20
#define INF 9999

int n;
float p[MAX];
float cost[MAX][MAX];

void createOBST() {
    int i, j, len, r;

    for(i = 1; i <= n; i++)
        cost[i][i] = p[i];

    for(len = 2; len <= n; len++) {
        for(i = 1; i <= n - len + 1; i++) {
            j = i + len - 1;
            cost[i][j] = INF;

            float sum = 0;
            for(int k = i; k <= j; k++)
                sum += p[k];

            for(r = i; r <= j; r++) {
                float left = (r > i) ? cost[i][r - 1] : 0;
                float right = (r < j) ? cost[r + 1][j] : 0;

                float val = left + right + sum;

                if(val < cost[i][j])
                    cost[i][j] = val;
            }
        }
    }

    cout << "\nMinimum Search Cost: " << cost[1][n] << endl;
}

int main() {
    int choice;

    do {
        cout << "\n--- OBST MENU ---";
        cout << "\n1. Input Keys Probabilities";
        cout << "\n2. Build Optimal BST";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter number of keys: ";
                cin >> n;

                cout << "Enter probabilities:\n";
                for(int i = 1; i <= n; i++)
                    cin >> p[i];
                break;

            case 2:
                createOBST();
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 3);

    return 0;
}