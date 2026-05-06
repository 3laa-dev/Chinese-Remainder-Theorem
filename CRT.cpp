
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vec) {
    int len = vec.size();
    cout << "[";
    for (int i = 0; i < len; i++)
    {
        cout << vec.at(i);
        if (i == len - 1)
            break;
        cout << ",";
    }
    cout << "]";
}



int modInverse(int a, int  m) {
    a = a % m;
    for (int  x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // ters mod yoksa
}



vector <int> encrypt_CRT(int n, vector<int>mod) {
    vector<int> encrypted;
    for (int i : mod) 
        encrypted.push_back(n % i);
    return encrypted;
    
}

int decrypt_CRT(vector<int> encrypted, vector<int>mod) {
    int M = 1;
    for (int  i: mod)
        M *= i;

    vector<int> Mi;
    for (int i : mod)
        Mi.push_back(M / i);

    vector<int> invMod;
    for (int i = 0; i < mod.size(); i++)
        invMod.push_back(modInverse(Mi.at(i), mod.at(i) ));
    
    int sum = 0;
    for (int i = 0; i < mod.size(); i++)
        sum += (invMod.at(i) * Mi.at(i) * encrypted.at(i));

    return sum%M;

}



int main()
{
}
