#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstring>

#define EPS_2  0.01
#define EPS_3  0.001
#define EPS_4  0.0001
#define EPS_5  0.00001

#define f1Name "y = x "
#define f2Name "y = sin(22x)"
#define f3Name "y = x^4 "
#define f4Name "y = arctg(x)"

#define printInfoSize 4


typedef double(*TPF)(double);

typedef double(*TPFEV)(double, double);

enum ABValues {
    VAL_A = 0,
    VAL_B = 1
};

struct I_print {                  //данные для печати результатов интегрирования
    char *name;    //название функции
    double i_sum;  //значение интегральной суммы
    double i_toch; //точное значение интеграла
    int n;         //число разбиений области интегрирования, при котором достигнута требуемая точность
};

void PrintTabl(I_print i_prn[], int k);

I_print IntRect(TPF, TPFEV, double, double, double, char *);

I_print IntTrap(TPF, TPFEV, double, double, double, char *);

double f1ExactValue(double, double);

double f2ExactValue(double, double);

double f3ExactValue(double, double);

double f4ExactValue(double, double);

double f1(double);

double f2(double);

double f3(double);

double f4(double);



