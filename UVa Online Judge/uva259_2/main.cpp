#include <algorithm>
#include <cstring>
#include <cstdio>
#include <limits>
#include <queue>
using namespace std;

#define N 39
int cap[N][N], parent[N], s = 37, t = 38;

bool bfs() {
    queue<int> q;
    q.push(s);
    memset(parent, -1, sizeof parent);
    parent[s] = s;
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (u == t)
            return true;
        for (int v = 0; v < N; ++v)
            if (parent[v] == -1 && cap[u][v] > 0)
                parent[v] = u, q.push(v);
    }
    return false;
}

int maxFlow() {
    int mf = 0, f, v;
    while (bfs()) {
        // min
        v = t;
        f = numeric_limits<int>::max();
        while (parent[v] != v)
            f = min(f, cap[parent[v]][v]), v = parent[v];
        // update
        v = t;
        mf += f;
        while (parent[v] != v)
            cap[parent[v]][v] -= f, cap[v][parent[v]] += f, v = parent[v];
    }
    return mf;
}

int main() {
    char line[1024], *c, nProg = 1, mf;
    while (true) {
        // init
        memset(cap, 0, sizeof cap);
        for (int i = 0; i < 10; ++i)
            cap[i][t] = 1;
        // input
        nProg = 0;
        while (gets(line) && line[0]) {
            nProg += (cap[s][line[0] - 'A' + 10] = line[1] - '0');
            c = &line[3];
            while (*c != ';')
                cap[line[0] - 'A' + 10][*c - '0'] = 1, ++c;
        }
        // output
        if (!nProg)
            break;
        mf = maxFlow();
        if (mf == nProg)
            for (int i = 0; i < 10; ++i) {
                int j;
                for (j = 0; j < 26; ++j)
                    if (cap[i][j + 10])
                        break;
                printf("%c", j == 26 ? '_' : j + 'A');
            }
        else
            printf("!");
        printf("\n");
    }
    return 0;
}
