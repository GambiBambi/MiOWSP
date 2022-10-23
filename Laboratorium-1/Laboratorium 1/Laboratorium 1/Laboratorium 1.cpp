#include <iostream>
#include <vector>

using namespace std;

float x(int n, vector<float> a, vector<float> t) {
    switch (n) {
    case 0: {
        return 1;
        break;
    }
    case 1: {
        return a[0] * t[0];
        break;
    }
    case 2: {
        return ((t[1] * a[1]) + (t[0] * t[0] * a[0] * a[0])) / 2;
        break;
    }
    case 3: {
        return (((t[0] * t[1] * t[1] + t[1]) * a[0] * a[1])/6) + ((t[0] * t[0] * t[0] * a[0] * a[0] * a[0]) / 6);
    }
    default: {
        return (t[1] * a[1] * x(n - 2, a, t)) + (t[0] * a[0] * x(n - 1, a, t));
        break;
    }
    }
}

float P(int n, vector <float> a, vector<float> t, int M, int V) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        float temp = 0;
        for (int i = 0; i <= V; i++) {
            temp += x(i, a, t);
        }
        return 1 / temp;
    }
    float Pt = x(n, a, t) * P(0, a, t, M, V);

    return Pt;
}

float b(int n,  vector<float> a, vector <float> t, int M, int V) {
    if (n >= 0) {
        float Pn = 0;
        for (int i = n; i <= V; i++) {
            Pn += P(i, a, t, M, V);
        }
        return Pn;
    }
    else {
        return 0;
    }
}

int main() {
    vector<float> a, t;
    int M;
    int V;
    float at, tt;

    cout << "Podaj wartosc M: ";
    cin >> M;
    cout << "Podaj wartosc V: ";
    cin >> V;

    cout << "Podaj parametry a: " << endl;
    for (int i = 0; i < M; i++) {
        cout << "a" << i + 1 << ": ";
        cin >> at;
        a.push_back(at);
    }
    cout << "Podaj parametry t: " << endl;
    for (int i = 0; i < M; i++) {
        cout << "t" << i + 1 << ": ";
        cin >> tt;
        t.push_back(tt);
    }
    cout << "Wartosci x: " << endl;
    for (int i = 0; i <= V; i++) {
        cout << "x" << i << " = " << x(i, a, t) << endl;
    }
    cout << "Wartosci prawdopodobienstwa znalezienia wiazki doskonalej w stanie zajetosci kanalow: " << endl;
    for (int i = 0; i <= V; i++) {
        cout << "P" << i << " = " << P(i, a, t, M, V) << endl;
    }
    int nActual;
    int n = 1;
    nActual = V - t[n-1] + 1;
    cout << "Prawdopodobienstwo blokady:" << endl;
    cout << "b(" << n << ") = " << b(nActual, a, t, M, V) << endl;
    n = 2;
    nActual = V - t[n-1] + 1;
    cout << "b(" << n << ") = " << b(nActual, a, t, M, V);


    return 0;
}
