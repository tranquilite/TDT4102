//Note to self: Dette er så utrolig unødvendig.
//Note to self: Spør om jeg kan slippe camelcase.
double acclX();
double acclY();

double velX(double initVelocity, double time);
double velY(double initVelocity, double time);

double posX(double initVelocity, double time);
double posY(double initVelocity, double time);

double flightTime(double initVelocity);

void printTime(double time);

void getUserInput(double* theta, double* absVelocity);

double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

void getVelocityVector(double theta, double absVelocity,
                        double *velocityX, double *velocityY);

double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, double velocityX,
                        double velocityY);
