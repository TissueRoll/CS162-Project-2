#include <bits/stdc++.h>
using namespace std;

const int N = 10001;

int free_resources[N], held_resources[N][N], requested_resources[N][N];
bool finished[N];

int main() {
    int T, P, R; 
    cin >> T;
    for (int t = 1; t <= T; t++) {
        // input
        {
            cin >> P >> R;
            for (int i = 0; i < P; i++)
                finished[i] = 0;
            for (int i = 0; i < R; i++) 
                cin >> free_resources[i];
            for (int i = 0; i < P; i++)
                for (int j = 0; j < R; j++)
                    cin >> held_resources[i][j];
            for (int i = 0; i < P; i++)
                for (int j = 0; j < R; j++)
                    cin >> requested_resources[i][j];
        }
        vector<int> order;
        int still_requesting = P;
        for (int p = 0; p < P; p++) {
            bool found = 0;
            for (int i = 0; i < P; i++) {
                bool satisfiable = 1;
                if (finished[i]) continue;
                for (int j = 0; j < R; j++) {
                    satisfiable &= (requested_resources[i][j] <= free_resources[j]);
                }
                if (satisfiable) {
                    finished[i] = 1;
                    still_requesting--;
                    for (int j = 0; j < R; j++) {
                        free_resources[j] += held_resources[i][j];
                        held_resources[i][j] = requested_resources[i][j] = 0;
                    }
                    order.push_back(i+1);
                }        
            }
        }
        if (still_requesting == 0) {
            cout << "NO DEADLOCKS OCCURED. PROCESS ORDER:\n";
            for (int x : order) cout << x << (x==order.back() ? '\n' : ' ');
        } else {
            cout << "DEADLOCK OCCURED.\n";
        }
        
    }
    return 0;
}