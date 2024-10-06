#include<iostream>
#include<string>
#include <time.h>
#include <cstdlib>

using namespace std;

class Player {
    string name;
public:
    void namefix(string a);
    string nameget() { return name; };
};

void Player::namefix(string a) {
    name = a;
}

class GamblingGame {
    Player* p = new Player[2];
public:
    GamblingGame();
    void namefix2();
    string random(string n);
    void start();
    ~GamblingGame() { delete[] p; }
};

GamblingGame::GamblingGame() {
    cout << "***** 갬블링 게임을 시작합니다. *****\n";
    srand((unsigned)time(NULL));
}

void GamblingGame::namefix2() {
    string name;

    cout << "첫번째 선수 이름>>";

    cin >> name;
    p[0].namefix(name);

    cout << "두번째 선수 이름>>";

    cin >> name;
    p[1].namefix(name);
}

string GamblingGame::random(string n) {
    int r[3];

    cout << "\t\t";

    for (int i = 0; i < 3; i++) {
        r[i] = rand() % 3;
        cout << r[i] << "\t";
    }

    if (r[0] == r[1] && r[0] == r[2]) {
        n += "님 승리!!";
        return n;
    } else {
        return "아쉽군요!\n";
    }
}

void GamblingGame::start() {
    string n;
    int i = 0;
    while (true) {
        string m;

        cout << p[i % 2].nameget() << ":<Enter>\n";

        getline(cin, n);

        m = p[i % 2].nameget();

        n = random(n);

        if (n == "님 승리!!") {
            cout << m + n;
            break;
        } else {
            cout << n;
        }

        i++;
    }
}

int main() {
    GamblingGame GG;
    GG.namefix2();
    GG.start();
}
