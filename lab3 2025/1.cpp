#include <iostream>
#include <cstring>

using namespace std;

enum color {red, yellow, green, orange};
void out(bool x);
const char *c[] = {"red", "yellow", "green", "orange"};

class Fruit {
public:
    bool annual;
    bool perennial;
    bool tree;
    bool tropical;
    color clr;
    char name[40];
};

class Apple : public Fruit {
    bool cooking;
    bool crunchy;
    bool eating;
public:
    void seta(const char *n, color c, bool ck, bool crchy, bool e);
    void seta(const char *n, color c, const char* ck, const char* crchy, const char* e);
    void show();
};

class Orange : public Fruit {
    bool juice;
    bool sour;
    bool eating;
public:
    void seto(const char *n, color c, bool j, bool sr, bool e);
    void seto(const char *n, color c, const char* j, const char* sr, const char* e);
    void show();
};

bool True_False(const char* str) {
    return strcmp(str, "yes") == 0;
}

void out(bool x) {
    cout << (x ? "yes" : "no") << "\n";
}

void Apple::seta(const char *n, color c, bool ck, bool crchy, bool e) {
    strncpy(name, n, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
    annual = false;
    perennial = true;
    tree = true;
    tropical = false;
    clr = c;
    cooking = ck;
    crunchy = crchy;
    eating = e;
}

void Apple::seta(const char *n, color c, const char* ck, const char* crchy, const char* e) {
    seta(n, c, True_False(ck), True_False(crchy), True_False(e));
}

void Orange::seto(const char *n, color c, bool j, bool sr, bool e) {
    strncpy(name, n, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
    annual = false;
    perennial = true;
    tree = true;
    tropical = true;
    clr = c;
    juice = j;
    sour = sr;
    eating = e;
}

void Orange::seto(const char *n, color c, const char* j, const char* sr, const char* e) {
    seto(n, c, True_False(j), True_False(sr), True_False(e));
}

void Apple::show() {
    cout << name << " apple is: " << "\n";
    cout << "Annual: "; out(annual);
    cout << "Perennial: "; out(perennial);
    cout << "Tree: "; out(tree);
    cout << "Tropical: "; out(tropical);
    cout << "Color: " << c[clr] << "\n";
    cout << "Good for cooking: "; out(cooking);
    cout << "Crunchy: "; out(crunchy);
    cout << "Good for eating: "; out(eating);
}

void Orange::show() {
    cout << name << " orange is: " << "\n";
    cout << "Annual: "; out(annual);
    cout << "Perennial: "; out(perennial);
    cout << "Tree: "; out(tree);
    cout << "Tropical: "; out(tropical);
    cout << "Color: " << c[clr] << "\n";
    cout << "Good for juice: "; out(juice);
    cout << "Sour: "; out(sour);
    cout << "Good for eating: "; out(eating);
}

int main() {
    Apple a2;
    Orange o2;
    a2.seta("Jonathan", red, "yes", "no", "yes");
    o2.seto("Valencia", orange, "yes", "yes", "no");
    
    a2.show();
    o2.show();
    
    return 0;
}
