#include <stdio.h>
#include <math.h>

int main() {
    double mass = 40.0;  // Mass of the bowling ball 
    double radius = 0.10;  // Radius of the bowling ball 
    double linearVelocity = 4.0;  // Linear velocity 
    double momentOfInertia = 1.6e2;  // Moment of inertia 

    // Calculate the kinetic energy
    double kineticEnergy = 0.5 * mass * pow(linearVelocity, 2);

    
    double potentialEnergy = 0.0;

   
    double totalEnergy = kineticEnergy + potentialEnergy;

   printf( "The total energy of the bowling ball is: %fJoules" ,totalEnergy );

    return 0;
}
