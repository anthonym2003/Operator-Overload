#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Budgie {
    public:
        Budgie(string name);
        Budgie operator+(const Budgie &budge) const;
        Budgie operator-(const Budgie &budge) const;
        Budgie operator+(const int &numero) const;
        friend ostream& operator<<(ostream&, const Budgie &b);
        bool operator==(const Budgie &b) const;
        string sentence();
        void add(Budgie b);
    private:
        vector<int> nums;    
        string _name;
};

bool Budgie::operator==(const Budgie &b) const {
    return (_name == b._name);
}

ostream& operator<<(ostream& os, const Budgie &b) {
    os << b._name;
    return os;
}

Budgie operator+(const int &numero, const Budgie &budge) {
    return budge + numero;
}

Budgie Budgie::operator+(const Budgie &budge) const {
    Budgie b("Cage");
    b.nums[0] = nums[0] + budge.nums[0];
    b.nums[1] = nums[1] + budge.nums[1];
    return b;
}

Budgie Budgie::operator-(const Budgie &budge) const {
    Budgie b("Cage");
    b.nums[0] = nums[0] - budge.nums[0];
    b.nums[1] = nums[1] - budge.nums[1];
    return b;
}

Budgie Budgie::operator+(const int &numero) const {
    Budgie b("Cage");
    b.nums[0] = nums[0] + numero;
    b.nums[1] = nums[1] + 2 * numero;
    return b;
}

Budgie::Budgie(string name) {
    _name = name;
    nums.push_back(1);
    nums.push_back(2);
}

string Budgie::sentence() {
    stringstream ss;
    ss << "This fat bird is called " << _name;
    ss << ". His cage has " << nums[0] << " budgies";
    ss << " and " << nums[1] << " wings.\n";
    return ss.str();
}

void Budgie::add(Budgie b) {
    nums[0] += b.nums[0];
    nums[1] += b.nums[1];
}

int main() {
    Budgie birb("Budgie");
    cout << birb.sentence();
    Budgie birb1("Budgie");
    birb.add(birb1);
    cout << birb.sentence();
    Budgie green("Birb");
    cout << green;
    cout << (birb == birb1);

    int x = 5;
    int counter = 0;
    if (x == 5) counter += 9;
    cout << endl;
    cout << counter << endl;
}