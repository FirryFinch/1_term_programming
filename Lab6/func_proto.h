typedef double (*TPF)(double);
struct I_print;
double f1 (double);
double f2 (double);
double f3 (double);
double f4 (double);
void PrintTabl (I_print, int);
double IntRect (TPF, double, double, double, int*);
double IntTrap (TPF, double, double, double, int*);