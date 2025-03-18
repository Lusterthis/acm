#include <bits/stdc++.h>
using namespace std;

// 判断某一行的 mask 是否没有相邻国王(如 0110 表示同一行的相邻列冲突)
bool validMask(int mask, int N) {
    // 若 mask & (mask << 1) != 0，则说明有相邻位都放置国王了
    // 注意这里的移位要在合适的范围内
    // 例如对 N=3, mask 最多只需要考虑 3 位
    if ((mask & (mask << 1)) != 0) return false;
    // 同理，(mask & (mask >> 1)) 也可以检查，但一般只需要一次方向就够
    // 确保 mask 不会越界即可
    return true;
}

// 判断相邻行之间，mask1 与 mask2 是否互不冲突
// 两行的国王不能在上下(同列)或对角(列差1)的位置同时出现
bool noConflict(int mask1, int mask2, int N) {
    // 1. 垂直冲突: 同列上同时有国王
    if (mask1 & mask2) return false;
    // 2. 对角冲突: 左斜对角/右斜对角
    //   - 左斜： mask1 & (mask2 << 1)
    //   - 右斜： mask1 & (mask2 >> 1)
    // 注意左右移时防止越界，可以先不做特别处理，只要保证后续在判定时不出负移位即可
    if ((mask1 & (mask2 << 1)) != 0) return false;
    if ((mask1 & (mask2 >> 1)) != 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    // 预处理所有可能的行状态(0 ~ (1 << N) - 1)
    // 只保留那些 “同一行合法” 的状态
    vector<int> validStates;
    for (int mask = 0; mask < (1 << N); mask++) {
        if (validMask(mask, N)) {
            validStates.push_back(mask);
        }
    }

    // dp[r][mask][k]: 考虑到第 r 行(1-based)，该行采用状态 mask(即在哪些列放国王)，
    // 放置的国王总数为 k 时的方案数
    // 最大 r = N，mask 最多 2^N，k 最多 N*N
    static long long dp[15][1 << 9][90]; // 根据题目 N<=9, K<=81

    // 初始化: 第0行没有放任何东西，所以 dp[0][mask][0] = 1 (仅当 mask=0时才算数)
    // 为了简单，我们可以在循环里做也可以手动置 dp[0][0][0] = 1
    dp[0][0][0] = 1;

    // 开始逐行计算
    for (int r = 1; r <= N; r++) {
        // 枚举当前行可用的所有合法 mask
        for (int m : validStates) {
            // 当前行这个 mask 上的国王数量
            int cnt = __builtin_popcount(m);

            // 枚举上一行的所有合法状态
            for (int pm : validStates) {
                // 判断与上一行是否冲突
                if (!noConflict(pm, m, N)) continue;

                // 枚举 k' (上一次已经放置的国王数)
                for (int kPrev = 0; kPrev + cnt <= K; kPrev++) {
                    long long ways = dp[r-1][pm][kPrev];
                    if (ways > 0) {
                        dp[r][m][kPrev + cnt] += ways;
                    }
                }
            }
        }
    }

    // 最后，累加第 N 行所有 mask，使得放置的国王总数 = K 的方案数
    long long ans = 0;
    for (int m : validStates) {
        ans += dp[N][m][K];
    }

    cout << ans << "\n";
    return 0;
}




















#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int mpf[N];
vector<int>primes;
int EulerSieve = []{
    for(int i=2;i<N;++i){
        if(!mpf[i]){
            mpf[i]=i;
            primes.push_back(i);
        }
        for(int p:primes){
            if(p>mpf[i]||p*i>=N)break;
            mpf[p*i]=p;
        }

    }
    return 0;
}();
int findMaxGCD(vector<int> &nums) {
    int max_num = *max_element(nums.begin(), nums.end());
    // 统计每个数的出现次数
    vector<int> freq(max_num + 1, 0);
    for(auto num : nums) {
        freq[num]++;
    }
    // 从最大数开始向下寻找
    for(int i = max_num; i >=1; i--){
        int count =0;
        for(int j = i; j <= max_num; j +=i){
            count += freq[j];
            if(count >=2){
                return i;
            }
        }
    }
    return 1; // 最小的GCD
}

void solve(){
    
    string line;
    getline(cin,line);
    vector<int>nums;
    int num;
    stringstream ss(line);
     while(ss >> num){
            nums.push_back(num);
        }
        cout << findMaxGCD(nums) << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    cin.ignore();
    while(t--){
        solve();
    }

   

    return 0;
}