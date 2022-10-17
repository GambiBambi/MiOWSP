#include <iostream>
#include <vector>

using namespace std;

float x(int n, float a[], float t[], int M) {
    switch (n) {
    case 0: {
        return 1;
        break;
    }
    case 1: {
        return a[0] * t[0];
        break;
    }
    default: {
        return P;
    }
    }
}

float P(int n, float a[], float t[], int M, int V) {
    if(n < 0) {
        return 0;
    }
    if(n == 0){
        float t = 0;
        for (int i = 0; i <= V; i++) {
            t += x(i, a, t, M);
        }
        return 1/t;
    }
    float Pt = 0;
    for (int i = 1; i <= M; i++) {
        Pt+= a[i]*t[i]*P(i - t[i], a, t, M, V);
    }
    return Pt/n;
}

float b(int n, float a[], float t[], int M, int V) {
    if (n >= 0) {
        return P(n, a, t, M, V) + b(n - 1, a, t, M, V);
    }
    else {
        return 0;
    }
}

int main() {
    vector<float> a, t;
    int M;
    int V;

    cout << "Podaj parametry a: " << endl;
    for (int i = 0; i < M; i++) {
        cout << i+1 << ": ";
        cin >> a[i];
        cout << endl;
    }
    cout << "Podaj parametry t: " << endl;
    for (int i = 0; i < M; i++) {
        cout << i+1 << ": ";
        cin >> t[i];
        cout << endl;
    }

    cin >> M;
    cin >> V;

    cout << b(V, a, t, M, V);


    return 0;
}
