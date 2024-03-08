#include <stdio.h>


/**
 * Exchange the values in two locations
 * \param p A pointer to one value
 * \param q A pointer to another value
 * \post The values at p and q have been exchanged
 */
void exchange(double* p, double* q) {
    double temptp, temptq;
    temptp = *p;
    temptq = *q;
    *p = temptq;
    *q = temptp;
}

int main(void) {
    double p=543.21, q=123.45;
    exchange(&p,&q);
    printf("%lf, %lf\n", p, q);
}

