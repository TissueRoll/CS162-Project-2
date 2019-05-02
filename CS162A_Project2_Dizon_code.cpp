#include <bits/stdc++.h>
using namespace std;

const int N = 10001;

int free_resources[N], held_resources[N][N], requested_resources[N][N];
bool finished[N];

int main() {
    int T, P, R; 
    cin >> T;
    for (int t = 1; t <= T; t++) {
        // reset data
        {
            memset(free_resources, 0, sizeof free_resources);
            memset(held_resources, 0, sizeof held_resources);
            memset(requested_resources, 0, sizeof requested_resources);
            memset(finished, 0, sizeof finished);
        }
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
        // banker's algo
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
            cout << "NO DEADLOCKS OCCURED.\n";
        } else {
            cout << "DEADLOCK OCCURED.\n";
            vector<int> unfinished_processes;
            for (int i = 0; i < P; i++) 
                if (not finished[i]) 
                    unfinished_processes.push_back(i);
            
            cout << "DEADLOCKED PROCESSES:\n";
            int most_progressed_process = -1;
            int most_progressed_process_value = -1;
            for (int x : unfinished_processes) {
                cout << x+1 << (x==unfinished_processes.back() ? '\n' : ' ');
                int temp_value = 0;
                for (int i = 0; i < R; i++) temp_value += held_resources[x][i];
                if (temp_value > most_progressed_process_value) {
                    most_progressed_process = x;
                    most_progressed_process_value = temp_value;
                }
            }
            cout << "DEADLOCK STRATEGY: DEADLOCK RECOVERY.\n";
            cout << "TERMINATED ALL BUT THE ONE WITH MOST RESOURCES HELD. RUNNING PROCESSES BY PROCESS ID.\n";
            order.push_back(most_progressed_process+1);
            for (int u : unfinished_processes) 
                if (u != most_progressed_process) 
                    order.push_back(u+1);
            
        }
        cout << "PROCESS ORDER:\n";
        for (int x : order) cout << x << (x==order.back() ? '\n' : ' ');
        
    }
    return 0;
}