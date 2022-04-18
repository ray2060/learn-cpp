<<<<<<< Updated upstream
#include <cstdio>    // freopen
#include <cstring>   // memset
#include <cmath>     // abs, fabs, floor, ceil, pow
#include <iostream>
#include <vector>
#include <algorithm> // min, max, sort, lower_bound, upper_bound
#include <utility>   // swap, pair
#include <typeinfo>
=======
#include <bits/stdc++.h>
>>>>>>> Stashed changes

using namespace std;

const int N = 1e5 + 10;
int n, m;
int s[N];

typedef pair<int, int> PII;
vector<PII> segs;

struct Stu {
    int id;
    int score;
};
Stu students[N];
bool cmp(Stu a, Stu b) {
    return a.score != b.score ? a.score > b.score : a.id < b.id;
}

int main() {
    int a, b;
    a = 410;
    b = 30;
    double c = a / 100.0 * b;
    int d = c;
    
    printf("%.100f\n", c);
    printf("%d\n", d);
    printf("%d\n", (int)(a * b / 100.0));
    //cout << typeid(a).name() << endl;
    //cout << typeid(a * 1.0).name() << endl;
    /*
    cin >> m;
    
    int a, b;
    for (int i = 0; i < m; i ++ ) {
        cin >> a >> b;
        // vector of pairs
    	//segs.emplace_back(a, b);
        // array of structs
        students[i] = {a, b};
    }
    
    //for (auto it = segs.begin(); it < segs.end(); it ++ ){
    //    cout << (*it).first << endl;
    //}
    for (int i = 0; i < m; i ++ ) {
        cout << students[i].id << endl;
    }
<<<<<<< Updated upstream
    */
=======
    
>>>>>>> Stashed changes
    //sort(segs.begin(), segs.end());
    sort(students, students + m, cmp);
    
    //cout << segs[0].first << endl;
    cout << students[0].id << endl;
    
    return 0;
}
