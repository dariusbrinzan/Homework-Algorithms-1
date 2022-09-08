#include<bits/stdc++.h>

using namespace std;

ifstream fin("statistics.in");
ofstream fout("statistics.out");

// constanta care imi returneaza numarul de litere
const int ALPHABETSIZE = 'z' - 'a' + 1;
// O (n * log n)
int main() {
	int n;
	fin >> n;
	vector<int> v[ALPHABETSIZE];
	for(int i = 0; i < n; ++i) {
		string word;
		fin >> word;
		int size = word.size();
		// imi construiesc un map pentru fiecare litera
		map<char, int> m;
		// iau fiecare aparitie in parte a fiecarui cuvant
		for(int j = 0; word[j]; ++j) {
			++m[word[j]];
		}
		// adaug in array-ul meu
		for(int j = 0; j < ALPHABETSIZE; ++j) {
		  v[j].push_back(2 * m[j + 'a'] - size);
		}
	}
	int result = 0;
	for(int i = 0; i < ALPHABETSIZE; ++i) {
		int sum = 0;
		int count = 0;
		// sortez crescator vectorul meu
		sort(v[i].begin(), v[i].end());
		for(int j = n - 1; j >= 0; --j) {
			// iar daca suma este mai mare ca 0, adaug
			// in suma si mi cresc count-ul care la final
			// o sa mi dea numarul de cuvinte care imi
			// satisfac cerinta
			if(sum + v[i][j] > 0) {
				sum += v[i][j];
				++count;
			}
		}
		// retin in result, rezultatul
		result = max(result, count);
	}
	fout << result << endl;
	return 0;
}
