/* set-up for partial termination -- needs tarjan's articulation points and cut vertices
vector<int> adj[n]; // directed graph
// getting the graph in O(n^2)
for (int i1 = 0; i1 < still_requesting; i1++) {
    for (int i2 = 0; i2 < still_requesting; i2++) {
        if (i1 == i2) continue;
        bool i1_holding_more = 1, i2_holding_more = 1;
        for (int j = 0; j < R; j++) {
            if (free_resources[j]+held_resources[i1][j] >= requested_resources[i2][j]) {
                i1_holding_more &= 1;
                i2_holding_more &= 0;
            }
            if (free_resources[j]+held_resources[i2][j] >= requested_resources[i1][j]) {
                i1_holding_more &= 0;
                i2_holding_more &= 1;
            }
        }
        if (not i2_holding_more)
            adj[i1].push_back(i2);
        if (not i1_holding_more) 
            adj[i2].push_back(i1);
    }
}
*/