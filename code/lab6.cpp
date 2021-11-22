#include "functions.h"

int main() {

    I_print printInfo[printInfoSize];
    TPF functions[] = {f1,f2,f3,f4};
    TPFEV functionsExactValues [] = {f1ExactValue,f2ExactValue,f3ExactValue,f4ExactValue};
    char* functionsNames[] = {f1Name,f2Name,f3Name,f4Name};

    double eps = 0.01;

    while (eps > 0.000001) {
        for (size_t i = 0; i < printInfoSize; i++)
        {
            printInfo[i] = IntRect(functions[i], functionsExactValues[i], eps, functionsNames[i]);
        }
        eps *= 0.1;
        printInfoBeforeTable(textRect, eps);
        PrintTabl(printInfo, printInfoSize);
    }

    eps = 0.01;
    
    while (eps > 0.000001) {
       for (size_t i = 0; i < printInfoSize; i++)
        {
            printInfo[i] = IntRect(functions[i], functionsExactValues[i], eps, functionsNames[i]);
        }
        eps *= 0.1;
        printInfoBeforeTable(textTrap, eps);
        PrintTabl(printInfo, printInfoSize);
    }
    return 0;
}
