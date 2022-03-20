#include <iostream>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

queue<PII> q;

int main() {
    q.emplace(1, 2);
    q.emplace(3, 4);
    
    PII t = q.front();
    
    cout << q.size() << endl;
    cout << t.first << endl;
    
    return 0;
}