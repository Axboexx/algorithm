
#include "lighting_problem.h"
#include<ctime>


int main() {
    int epoch = 10000;
    srand(time(nullptr));
    point p[12];
    point min_e, max_e;
    double emax = 0;
    double emin = 9999;
    double u;
    double max_u = 0;

    for (int i = 0; i < 12; ++i) {
        p[i].x = rand() % L;
        p[i].y = rand() % W;
    }
    print_point(p);
    for (int i = 0; i < epoch; ++i) {
        u = calculate_U(p, emin, emax, min_e, max_e);
        max_u = u > max_u ? u : max_u;
        adjustment_p(p, min_e, max_e);
    }
    print_point(p);
    cout << u << endl;
    cout << max_u << endl;
}
