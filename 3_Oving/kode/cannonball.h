double acclY();
double velY(double initVelocityY, double time);
double velX(double initVelocityY, double time);

double posX(double initPosition, double initVelocity, 
            double time);
double posY(double initPosition, double initVelocity, 
            double time);

void printTime(int time);

double flightTime(double initVelocity);

//Del 2 - Gjenbruk av funksjoner
//4 - Implementer funksjoner

void getUserInput(double *theta, double *absVelocity);
double degToRad(double deg);

double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

void getVelocityVector(double theta, double absVelocity,
                        double *velocityX, double velocityY);

double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, double velocityX,
                        double velocityY);

void playTargetPractice();
