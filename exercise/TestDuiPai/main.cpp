#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    for (int T = 1; T <= 100; T ++ ) {
        system("C:\\temp\\TestDuiPai\\ri.exe");
        double st = clock();
        system("C:\\temp\\TestDuiPai\\sol.exe");
        double ed = clock();
        system("C:\\temp\\TestDuiPai\\bf.exe");
        if (system("fc C:\\temp\\TestDuiPai\\data.out C:\\temp\\TestDuiPai\\data.ans")) {
            printf("WA, Case #%d\n", T);
            return 0;
        } else {
            printf("AC, Case #%d, %.0lfms\n", T, ed-st);
        }
    }
    system("cls");
    return 0;
}