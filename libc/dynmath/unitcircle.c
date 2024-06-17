#include <dynmath.h>

static const float pi = 3.14159265358979323846f;

void unitcircle(float *x, float *y, float angle) {
    *x = cos(angle);
    *y = sin(angle);
}
