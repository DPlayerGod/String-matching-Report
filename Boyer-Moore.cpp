#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256


using namespace chrono;

high_resolution_clock::time_point tBegin, tEnd;
duration<double> exec_time;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string txt, pat;
	cin >> txt >> pat;
	
	int m = pat.size();
	int n = txt.size();
	
	tBegin = high_resolution_clock::now();

	int badchar[NO_OF_CHARS];
	
	for (int i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
 
    for (int i = 0; i < m; i++)
        badchar[(int)pat[i]] = i;

	int s = 0; 
	while (s <= (n - m)) {
		int j = m - 1;
		
		while (j >= 0 && pat[j] == txt[s + j]) j--;

		if (j < 0) {
			cout << s + 1 << ' ';
			s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
		}
		else s += max(1, j - badchar[txt[s + j]]);
	}
	
	tEnd = high_resolution_clock::now();
    
	exec_time = duration_cast<duration<double>>(tEnd - tBegin);
    
    cout << (int)1000 * exec_time.count();
	
	return 0;
}


