#include <bits/stdc++.h>

using namespace std;

using namespace chrono;

high_resolution_clock::time_point tBegin, tEnd;
duration<double> exec_time;

#define int int64_t
#define sz(x) (int)x.size()
#define MASK(i) ((1LL) << (i))
#define all(x) x.begin(), x.end()
#define BIT(x, i) ((x) >> (i) & (1LL))
#define dbg(...) cerr << "#" << __LINE__ << ":[" << #__VA_ARGS__ \
<< "] = [" ,DBG(__VA_ARGS__)

string to_string(const string& s) { return '"' + s + '"'; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
        cerr << to_string(h); if(sizeof...(t)) cerr << ", "; DBG(t...);
}

template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b) : 0); }
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b) : 0); }

const int MAXN = 1e6 + 6;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int BASE = 331;

int n, m, Hash[MAXN], pw[MAXN];
string a, b;

int get(int l, int r) {
	return (Hash[r] - Hash[l - 1] * pw[r - l + 1] + MOD * MOD) % MOD;
}

void solve() {
	cin >> a >> b;
	n = sz(a), m = sz(b);
	if (m > n) return;
	a = " " + a, b = " " + b;
	
	tBegin = high_resolution_clock::now();
	
	pw[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * BASE % MOD;
	
	int code = 0;
	for (int i = 1; i <= m; i++) code = (code * BASE + b[i]) % MOD;
	for (int i = 1; i <= n; i++) Hash[i] = (Hash[i - 1] * BASE + a[i]) % MOD;
	
	for (int i = m; i <= n; i++) if (get(i - m + 1, i) == code) cout << i - m + 1 << ' ';
	
	tEnd = high_resolution_clock::now();
    
	exec_time = duration_cast<duration<double>>(tEnd - tBegin);
    
    cout << (int)1000 * exec_time.count();
}

#define TASK ""
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(TASK".inp", "r", stdin);
    //freopen(TASK".out", "w", stdout);

    int ntest = 1;
    //cin >> ntest;
    while (ntest--) solve();

    return 0;
}
//612

