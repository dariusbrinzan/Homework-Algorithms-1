#include <bits/stdc++.h>

using namespace std;

ifstream fin("prinel.in");
ofstream fout("prinel.out");

const int N = 1e3;
const int M = 1e5;

vector<int> dp(M);
vector<vector<int> > divisors(M);
vector<int> moves(M);
vector<int> cost(N);
vector<int> p(N);
vector<int> target(N);

// O(n * log n)
int main() {
    int n, k;
    fin >> n >> k;
    // calculez divizorii cu ciurul lui eratostene
    for (int i = 1; i <= M; ++i) {
		for (int j = i; j <= M; j += i)
			divisors[j].push_back(i);
	}
    // cazul de baza
    // ca sa ajung la 1 am nevoie de 0 moves practic
    moves[1] = 0;
    for (int i = 2; i < M; ++i) {
        moves[i] = 1e6;
    }
    // calculez numarul minim de pasi pentru
    // a ajunge la target-ul mey
    for (int i = 1; i < M; ++i) {
        for (auto u : divisors[i]) {
            int value = i + u;
            if (value < M) {
                moves[value] = min(moves[value], moves[i] + 1);
            }
        }
    }
    int total_cost = 0;
    // citesc target-ul meu si
    // calculez costul aferent acestuia
    for (int i = 1; i <= n; ++i) {
        fin >> target[i];
        cost[i] = moves[target[i]];
        total_cost += cost[i];
    }
    // citesc points-urile
    for (int i = 1; i <= n; ++i) {
        fin >> p[i];
    }
    // exista unele cazuri cand s-ar putea ca
    // total_cost-ul sa fie mai mare decat k-ul meu
    k = min(k, total_cost);
    // am aplicat logica de la rucsac
    for (int i = 0; i <= k; ++i) {
        dp[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = k; j >= cost[i]; --j) {
            dp[j] = max(dp[j], dp[j - cost[i]] + p[i]);
        }
    }
    // al k-lea element este rezultatul cautat de mine
    fout << dp[k] << endl;
    return 0;
}
