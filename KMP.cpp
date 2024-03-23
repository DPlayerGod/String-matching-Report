#include <bits/stdc++.h>

using namespace std;

using namespace chrono;

high_resolution_clock::time_point tBegin, tEnd;
duration<double> exec_time;

#define sz(x) (int)x.size()
#define MASK(i) ((1LL) << (i))
#define all(x) x.begin(), x.end()
#define BIT(x, i) ((x) >> (i) & (1LL))

const int MAXN = 1e6 + 6;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int kmp[MAXN];
string s1, s2;

#define TASK ""
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> s1 >> s2;

    int l1 = sz(s1), l2 = sz(s2);
    
    tBegin = high_resolution_clock::now();

    kmp[0] = -1;
    for (int i = 1; i <= l2; i++) {
        kmp[i] = 0;
        for (int j = kmp[i - 1]; j != -1; j = kmp[j]) {
                if (s2[j] == s2[i - 1]) {
                    kmp[i] = j + 1;
                    break;
                }
        }
    }

    int u = 0;
    for(int i = 1; i <= l1; i++) {
        while (u != 0 && s2[u] != s1[i - 1]) u = kmp[u];
        if (s2[u] == s1[i - 1]) u++;
        if (u == l2) {
            u = kmp[u];
            cout << i - l2 + 1 << " ";
        }
    }
    
    tEnd = high_resolution_clock::now();
    
	exec_time = duration_cast<duration<double>>(tEnd - tBegin);
    
    cout << (int)1000 * exec_time.count();

    return 0;
}

