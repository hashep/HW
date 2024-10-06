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
    cout << "***** ���� ������ �����մϴ�. *****\n";
    srand((unsigned)time(NULL));
}

void GamblingGame::namefix2() {
    string name;

    cout << "ù��° ���� �̸�>>";

    cin >> name;
    p[0].namefix(name);

    cout << "�ι�° ���� �̸�>>";

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
        n += "�� �¸�!!";
        return n;
    } else {
        return "�ƽ�����!\n";
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

        if (n == "�� �¸�!!") {
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
