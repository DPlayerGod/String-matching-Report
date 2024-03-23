#include "testlib.h"

#include <bits/stdc++.h>
#define ll long long
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

const int N = 1e5 + 5;
const int Sz = 1e6;
const int Lim = 2e3;
int b[N], n, m, t, par[N];

int Rand(int l, int h) {
    return rd() % (h - l + 1) + l;
}

struct Dsu {
	int root(int u) {
		return par[u] < 0 ? u : par[u] = root(par[u]);
	}

	bool merge(int u, int v) {
		u = root(u), v = root(v);
		if (u == v) return false;
		if (par[u] > par[v]) swap(u, v);
		par[u] += par[v];
		par[v] = u;
		return true;
	}
};

int main(int argc, char* argv[]) {
   	registerGen(argc, argv, 1);
   	int g1 = argc >= 2 ? stoll(argv[1],nullptr,10) : 10;
   	int g2 = argc >= 3 ? stoll(argv[2],nullptr,10) : g2;

	if (g2 == 1) {
		for (int i = 1; i <= 1000000; i++) cout << 'a';
		cout << '\n';
		for (int i = 1; i <= 20; i++) cout << 'a';
 	}
 	else if (g2 == 2) {
 		for (int i = 1; i <= 1000000; i++) cout << 'b';
 		cout << '\n';
		for (int i = 1; i <= 20; i++) cout << 'a';	 
	}
	else {
		for (int i = 1; i <= 1000000; i++) cout << (char)('a' + Rand(0, 3));
		cout << '\n';
		int lim = Rand(1, 20);
		for (int i = 1; i <= lim; i++) cout << (char)('a' + Rand(0, 3));
	}
	
}
