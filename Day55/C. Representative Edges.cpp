/*
Platform :- Codeforces
Contest :- Good Bye 2021
Approach :- Note that if the array is good ak+2−ak+1=ak+1−ak. In other words, the array form an arithmetic progression.

            We can either fix an arbitrary element and set all other elements equal to it (giving us the lower bound n−1 on the answer).

            Or, to solve the remaining case, we can fix any two elements that are in the answer, derive the formula for an arbitrary element
            of the arithmetic progression, and check the number of elements that we have to change.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <iomanip>
#include <map>
#include <stack>
#include <set>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <stdio.h>
#include <memory.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <bitset>
#include <random>
#include <chrono>

#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sqr(a) (a)*(a)

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9 + 7;
const int inf = 1e9;
const ll biginf = 2e18;
const ld pi = acosl(-1);
const ld eps = 1e-9;
const int maxn = 101;
const ll negative_inf = -1e18;
const int alph_size = 26;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (n < 3) {
        cout << "0\n";
        return;
    }
    int minn = inf;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ld d = (ld)(v[j] - v[i]) / (ld)(j - i);
            int res = 0;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) {
                    continue;
                }
                if ((ld)v[k] != (ld)v[i] + (ld)(k - i) * d) {
                    res++;
                }
            }
            minn = min(minn, res);
        }
    }
    cout << minn << "\n";
}

void multisolve() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("destroy.in", "r", stdin);
    //freopen("destroy.out", "w", stdout);
    multisolve();
}
