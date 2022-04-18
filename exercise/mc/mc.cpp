#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <unordered_map>
#include <sstream>
#include <fstream>
#define name first
#define num second

using namespace std;

typedef stringstream ss;

void itoa();
void show();
void show_no_endl();
void slow_show();
int get_int();
void sleep();

void bei_bao();
void info();
void kan_shu();
void wa_kuang();
void shao_kuang();
void he_cheng();
void sell();
void buy();
void start();
void hall();

unordered_map<string, int> bao;
int money;

string itoa(int x) {
    ss stream;
    stream << x;
    string res;
    stream >> res;
    return res;
}

void show(string s) {
    printf("%s\n", s);
}

void show_no_endl(string s) {
    printf("%s", s);
}

void slow_show(string s) {
    for (auto item : s) {
        printf("%c", item);
        sleep(120);
    }
    puts("");
}

int get_int() {
    int x;
    scanf("%d", &x);
    return x;
}

void sleep(int x) {
    auto c = clock();
    while ((int)clock - c < x);
}

void bei_bao() {
    show("正在打开背包……");
    for (auto item : bao) {
        show_no_endl(item.name);
        show_no_endl(':');
        show(itoa(item.num))
    }
    show("正在回到首页……");
}

void info(bool f) {
    ifstream fin("C:\_ray\dev\learn-cpp");
    string tmp;
    fin >> tmp;
    show(tmp);
    fin >> tmp;
    show(tmp);
}

void kan_shu() {
    slow_show("正在奔向林场……");
    show("开始砍树……");
    while (true) {
        show("你要砍几棵树？一棵树可以砍出3至6块木头。");
        show("0是回到主页。");
        int n = get_int()；
        if (n) {
            int ans = 0;
            for (int i = 0; i < n; i ++ ) {
                srand(time(NULL));
                ans += rand() % 4 + 3;
                sleep(1500);
                show("不要急……")；
            }
            show_no_endl("你砍出了");
            show_no_endl(itoa(ans));
            show("块木头(wood)")；
            bao["wood"] += ans;
        } else {
            break;
        }
    }
    show("正在回到首页……");
}

void wa_kuang() {
    slow_show("正在奔向矿洞……");
    show("到了， 挺近的呢。");
    while (true) {
        show("0回到主页1继续挖");
        int n = get_int()；
        if (n) {
            int rock = 0;
            int coal = 0;
            int iron = 0;
            int gold = 0;
            int diamond = 0;
            for (int i = 0; i < 10; i ++ ) {
                srand(time(NULL));
                int r = rand() % 100 + 1;
                srand(time(NULL));
                int num = rand() % 8 + 1;
                show("不要急……");
                sleep(3500);
                if (r <= 40) rock += num;
                else if (r <= 70) coal += num;
                else if (r <= 90) iron += num;
                else if (r <= 97) gold += num;
                else diamond += num; 
            }
            show_no_endl("你挖到的石头(rock)、煤矿(coal)、铁矿(iron)、金矿(gold)、钻石(diamond)");
            show_no_endl("分别有：");
            show_no_endl(itoa(rock));
            show_no_endl("、");
            show_no_endl(itoa(coal));
            show_no_endl("、");
            show_no_endl(itoa(iron));
            show_no_endl("、");
            show_no_endl(itoa(gold));
            show_no_endl("、");
            show_no_endl(itoa(diamond));
            show("块");
            bao["rock"] += rock;
            bao["coal"] += coal;
            bao["iron"] += iron;
            bao["gold"] += gold;
            bao["diamond"] += diamond;
        } else {
            break;
        }
    }
    show("正在回到首页……");
}

void shao_kuang() {
    slow_show("正在奔向冶炼场……");
    show("到了， 挺近的呢。");
    while (true) {
        show("你要烧什么矿？");
        show("0退出1铁2金");
        int x = get_int();
        if (x) {
            show("烧几个？");
            int y = get_int();
            if (bao["coal"] >= y) {
                bao["coal"] -= y;
                switch (x) {
                    case 1:
                        if (bao["iron"] >= y) {
                            bao["iron"] -= y;
                            show("开始烧矿……")
                            sleep(y * 1200);
                            bao["iron_ingot"] += y + rand() % int(y / 3) + 1;
                        } else {
                            s
                        }
                }
            }
        }
    }
}