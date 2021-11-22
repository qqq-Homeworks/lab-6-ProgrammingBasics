#include "functions.h"


double f1(double x) {
    return x;
}

double f2(double x) {
    return sin(22 * x);
}

double f3(double x) {
    return pow(x, 4);
}

double f4(double x) {
    return atan(x);
}

double f1ExactValue() {
    return (VAL_B * VAL_B - VAL_A * VAL_A) / 2.0;
}

double f2ExactValue() {
    return (cos(VAL_A * 22.0) - cos(VAL_B * 22.0)) / 22.0;
}

double f3ExactValue() {
    return (VAL_B * VAL_B * VAL_B * VAL_B * VAL_B - VAL_A * VAL_A * VAL_A * VAL_A * VAL_A) / 5.0;
}

double f4ExactValue() {
    return VAL_B * atan((double)VAL_B) - VAL_A * atan((double)VAL_A) - (log(VAL_B * VAL_B + 1) - log(VAL_A * VAL_A + 1)) / 2.0;
}

I_print IntRect(TPF funq, TPFEV exFunq, double eps, char *functionName) {
    I_print result = {};
    result.name = functionName;
    result.i_toch = exFunq();

    double delX = (VAL_B - VAL_A) / 2.0;
    double x;
    double f1, f2, s1, s2;
    int n = 2;
    do {
        x = VAL_A;
        s1 = 0;
        s2 = 0;
        for (int i = 0; i < n - 1; i++) {
            f1 = funq(x);
            f2 = funq(x + delX);
            s1 += std::min(f1, f2) * delX;
            s2 += std::max(f1, f2) * delX;
            x += delX;
        }
        delX /= 2.0;
        n *= 2;
    } while (fabs(s2 - s1) > eps);
    result.i_sum = s2;
    result.n = n;
    return result;
}

I_print IntTrap(TPF funq, TPFEV exFunq, double eps, char *functionName) {
    I_print result = {};
    result.name = functionName;
    result.i_toch = exFunq();
    double delX = (double) VAL_B - VAL_A;
    double x;
    double s1 = ((funq(VAL_A) + funq(VAL_B)) / 2) * (VAL_B - VAL_A), s2 = s1;
    int n = 1;
    do {
        x = VAL_A;
        s1 = s2;
        s2 = 0;
        n *= 2;
        delX /= 2.0;
        for (int i = 0; i < n; i++) {
            s2 += ((funq(x) + funq(x + delX)) / 2.0) * delX;
            x += delX;
        }
    } while (fabs(s2 - s1) > eps);
    result.i_sum = s2;
    result.n = n / 2;

    return result;
}

void printInfoBeforeTable(const char *text, double eps) {
    std::cout << "\t\tТаблица рассчёта интеграла" << std::endl;
    std::cout << "\t от " << VAL_A << " до " << VAL_B << " с точностью до " << std::scientific << eps << ' ' << text << std::endl;
}

void PrintTabl(I_print i_prn[], int k) {
    const int m = 4;
    int wn[m] = {16, 18, 18, 10};
    char title[m][10] = {"Function", "Integral", "IntSum", "N "};
    int size[m];
    for (int i = 0; i < m; i++)
        size[i] = std::strlen(title[i]);

    std::cout << '_' << std::setfill('_');
    for (int j = 0; j < m - 1; j++)
        std::cout << std::setw(wn[j]) << '_';
    std::cout << std::setw(wn[m - 1]) << '_' << std::endl;

    std::cout << '|';
    for (int j = 0; j < m; j++)
        std::cout << std::setw((wn[j] - size[j]) / 2) << std::setfill(' ') << ' ' << title[j]
                  << std::setw((wn[j] - size[j]) / 2) << '|';
    std::cout << std::endl;
    for (int i = 0; i < k; i++) {
        std::cout << '|' << std::fixed;
        for (int j = 0; j < m - 1; j++)
            std::cout << std::setfill('_') << std::setw(wn[j]) << '|';
        std::cout << std::setw(wn[m - 1]) << '|' << std::setfill(' ') << std::endl;

        std::cout << '|' << std::setw((wn[0] - strlen(i_prn[i].name)) / 2) << ' ' << i_prn[i].name
                  << std::setw((wn[0] - strlen(i_prn[i].name)) / 2) << '|';
        std::cout << std::setw(wn[1] - 1) << std::setprecision(10) << i_prn[i].i_toch << '|'
                  << std::setw(wn[2] - 1) << i_prn[i].i_sum << std::setprecision(6) << '|'
                  << std::setw(wn[3] - 1) << i_prn[i].n << '|' << std::endl;
    }

    std::cout << '|' << std::setfill('_');
    for (int j = 0; j < m - 1; j++)
        std::cout << std::setw(wn[j]) << '|';
    std::cout << std::setw(wn[m - 1]) << '|' << std::setfill(' ') << std::endl;
}
