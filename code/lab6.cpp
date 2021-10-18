#include "functions.h"

int main() {

    I_print printInfo[printInfoSize];
    double eps = 0.01;
    while (eps > 0.000001) {
        printInfo[0] = IntRect(f1, f1ExactValue, VAL_A, VAL_B, eps, f1Name);
        printInfo[1] = IntRect(f2, f2ExactValue, VAL_A, VAL_B, eps, f2Name);
        printInfo[2] = IntRect(f3, f3ExactValue, VAL_A, VAL_B, eps, f3Name);
        printInfo[3] = IntRect(f4, f4ExactValue, VAL_A, VAL_B, eps, f4Name);
        eps *= 0.1;
        PrintTabl(printInfo, printInfoSize);
    }
    eps = 0.01;
    while (eps > 0.000001) {
        printInfo[0] = IntTrap(f1, f1ExactValue, VAL_A, VAL_B, eps, f1Name);
        printInfo[1] = IntTrap(f2, f2ExactValue, VAL_A, VAL_B, eps, f2Name);
        printInfo[2] = IntTrap(f3, f3ExactValue, VAL_A, VAL_B, eps, f3Name);
        printInfo[3] = IntTrap(f4, f4ExactValue, VAL_A, VAL_B, eps, f4Name);
        eps *= 0.1;
        PrintTabl(printInfo, printInfoSize);
    }

    return 0;
}

//1) вычислить интегралы от а до б для четырёх функций, оформить в виде функции IntRect
// eps = w0.01, 0.001, 0.0001, 0.00001 и 0.000001