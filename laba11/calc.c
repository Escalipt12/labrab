#include "calc.h"
#include <stdarg.h>
#include <float.h>

double sum(int count, ...) {
    va_list args;
    va_start(args, count);
    double s = 0;
    while(count--) s += va_arg(args, double);
    va_end(args);
    return s;
}

double max(int count, ...) {
    va_list args;
    va_start(args, count);
    double m = -DBL_MAX;
    while(count--) {
        double val = va_arg(args, double);
        if(val > m) m = val;
    }
    va_end(args);
    return m;
}

double min(int count, ...) {
    va_list args;
    va_start(args, count);
    double m = DBL_MAX;
    while(count--) {
        double val = va_arg(args, double);
        if(val < m) m = val;
    }
    va_end(args);
    return m;
}

double avg(int count, ...) {
    if(count <= 0) return 0;
    double total = 0;
    va_list args;
    va_start(args, count);
    int temp = count;
    while(temp--) {
        total += va_arg(args, double);
    }
    va_end(args);
    return total / count;
} 