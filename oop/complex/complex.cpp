#include<complex.h>

using namespace std;

inline complex&
__doapl(complex* ths, const complex& r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}