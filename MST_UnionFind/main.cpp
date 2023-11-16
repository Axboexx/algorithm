#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
struct edge {
    int from, to;
    int dis;
} e[100];

bool cmp(edge a, edge b) {
    return a.dis < b.dis;
}

int node[200];

int father(int x) {
    if (x == node[x])
        return x;
    node[x] = father(node[x]);
    return father(node[x]);
}

int check(int x, int y) {
    if (father(x) == father(y))
        return true;
    return false;
}

void merge(int x, int y) {
    node[x] = father(y);
}

int kruskal() {
    int sum = 0;
    int count = 0;
    int t1, t2;
    for (int i = 1; i <= m; ++i) {
        t1 = e[i].from;
        t2 = e[i].to;
        if (!check(t1, t2)) {
            cout << e[i].dis << " " << e[i].from << " " << e[i].to << endl;
            sum += e[i].dis;
            count++;
            merge(t1, t2);
        }
        if (count == n - 1) {
            return sum;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        node[i] = i;
    }
    int x, y, z;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> z;
        e[i].from = x;
        e[i].to = y;
        e[i].dis = z;
    }
    sort(e + 1, e + m + 1, cmp);
    int re = kruskal();
    cout << re;
    return 0;

}