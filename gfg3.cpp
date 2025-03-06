#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAX_NUM 100000

typedef long long ll;

vector<int> spf(MAX_NUM + 1);

void sieve() {
    for (int i = 0; i <= MAX_NUM; i++) spf[i] = i;
    for (int i = 2; i * i <= MAX_NUM; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAX_NUM; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}
ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}


map<int, int> factorize(int x) {
    map<int, int> factors;
    while (x != 1) {
        int p = spf[x];
        while (x % p == 0) {
            factors[p]++;
            x /= p;
        }
    }
    return factors;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) m++;
    }
    
    sieve();
    
    int case1 = 0, sum_pq_count = 0;
    unordered_map<int, int> count_p;
    unordered_map<int, vector<int>> S_p;

    for (int x : arr) {
        if (x == 1) continue;
        map<int, int> factors = factorize(x);
        vector<int> primes;
        for (auto &[p, exp] : factors) primes.push_back(p);

        if (primes.size() == 1) {
            int p = primes[0], exp = factors[p];
            if (exp == 1) {
                case1++;
                count_p[p]++;
            }
            S_p[p].push_back(exp);
        } else if (primes.size() == 2) {
            if (factors[primes[0]] == 1 && factors[primes[1]] == 1) sum_pq_count++;
        }
    }

    // Compute case2
    int case2 = 0;
    for (auto &[p, exponents] : S_p) {
        vector<int> dp(3, 0);
        dp[0] = 1;
        for (int k : exponents) {
            for (int s = 2; s >= max(0, 2 - k); s--) {
                dp[s] = (dp[s] + dp[s - k]) % MOD;
            }
            if (k >= 2) dp[2] = (dp[2] + 1) % MOD;
        }
        case2 = (case2 + dp[2]) % MOD;
    }

    // Compute case3
    ll S = case1, T = 0;
    for (auto &[p, cnt] : count_p) {
        T = (T + (ll)cnt * cnt) % MOD;
    }
    ll inv2 = 500000004;
    ll part1 = ((S * S - T) % MOD + MOD) % MOD;
    part1 = (part1 * inv2) % MOD;
    ll case3 = (part1 + sum_pq_count) % MOD;

    ll total = (case1 + case2 + case3) % MOD;
    total = (total * 1LL * power(2, m, MOD)) % MOD;
    cout << total << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}