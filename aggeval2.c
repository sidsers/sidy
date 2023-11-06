#include <stdio.h>
#include <math.h>


int main() {
    double m1 = -6.5;  // Mass a
    double v1 = 2.2;  // Velocity a
    double r1 = 1.5;  // Radius a

    double m2 = 3.1;  // Mass b
    double v2 = 3.6;  // Velocity b
    double r2 = 2.8;  // Radius b

    // Calculate the total angular momentum
    double totalAngularMomentum = m1 * v1 * r1 + m2 * v2 * r2;

    // Convert the angular momentum 
    double conAngularMomentum = totalAngularMomentum;

    // Print the result
    printf( "The total angular momentum is:%f kgm^2/s", conAngularMomentum) ;

    return 0;
}