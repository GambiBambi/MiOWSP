#include <iostream>

using namespace std;

float x0() {
    return 1;
}

float x(int n, float a1, float t1, float a2, float t2) {
    switch (n) {
    case 0: {
        return 1;
        break;
    }
    case 1: {
        return a1 * t1;
        break;
    }
    case 2: {
        return ((2 * a2) + (a1 * a1)) / 2;
        break;
    }
    case 3: {
        return (a1 * a2) + ((a1 * a1 * a1) / 6);
        break;
    }
    default: {
        return 0;
    }
    }
}

float P(int n, float a1, float t1, float a2, float t2) {
    if(n == 0){
       return 1 / (x(0, a1, t1, a2, t2));
    }
    else if (n > 0){
        return ((a1 * t1 * P(n - t1, a1, t1, a2, t2)) + (a2 * t2 * P(n - t2, a1, t1, a2, t2)))/n;
    }
    else {
        return 0;
    }
}

float b(int n, float a1, float t1, float a2, float t2) {
    if (n >= 0) {
        return P(n, a1, t1, a2, t2) + b(n - 1, a1, t1, a2, t2);
    }
    else {
        return 0;
    }
}

int main() {
    float a1, a2, t1, t2;
    int M = 2;
    int V;

    cout << "Podaj parametry a: ";
    cin >> a1 >> a2;
    cout << "Podaj parametry t: ";
    cin >> t1 >> t2;

    cin >> V;

    cout << b(V, a1, t1, a2, t2);


    return 0;
}