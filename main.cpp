#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

bool quadEquation(double a, double b, double c, double* x1, double* x2) {
    if(a == 0) return false; //função não é quadrática

    double delta = b * b - 4 * a * c;
    if(delta < 0) return false; //não há soluções reais

    double root = sqrt(delta);
    *x1 = (-b - root) / (2 * a);
    *x2 = (-b + root) / (2 * a);
    return true;
}


int main() {
    ifstream inFile("input.txt"); // leitura
    ofstream outFile("output.txt"); // escrita
    double a, b, c, x1, x2;
    int counter = 1;

    while(inFile >> a >> b >> c) { // lê três números por vez e os atribui as variáveis a, b, c.
        outFile << "Equation " << counter++ << ": ";

        if (quadEquation(a, b, c, &x1, &x2)) {
            outFile << "Roots = " << x1 << " and x2: " << x2 << endl;

        }
        else {
            outFile << "No real roots\n";
        }
    }
    inFile.close();
    outFile.close();
    return 0;
}