#include <bits/stdc++.h>

using namespace std;

ifstream fin("walsh.in");
ofstream fout("walsh.out");

int n, k, x, y;
// O(n * log n)
int main() {
    fin >> n >> k;
    for (int i = 0; i < k; ++i) {
        fin >> x >> y;
        // acest boolean il folosesc pentru a
        // verifica cand ma aflu in cadranul 4
        bool ok = 0;
        // decrementez valorile mele
        --x;
        --y;
        int z = n;
        while (z > 2) {
            // vad in ce cadran din cele 4 ma aflu
            // si realizez operatiile necesare
            // iar la final afisez
            if (x < z / 2) {
                if (y < z / 2) {
                    z /= 2;
                } else {
                    y -= z / 2;
                    z /= 2;
                }
            } else {
                if (y < z / 2) {
                    x -= z / 2;
                    z /= 2;
                } else {
                    x -= z / 2;
                    y -= z / 2;
                    z /= 2;
                    ok = !ok;
                }
            }
        }
        fout << (ok ^ (x & y)) << endl;
    }
    return 0;
}
