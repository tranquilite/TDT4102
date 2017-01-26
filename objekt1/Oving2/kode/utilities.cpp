#include<cstdlib>
#include<ctime>

int randomWithLimits(int lower, int upper) {
    //Tick tock goes the clock
    //and what now shall we play?
    int rekkevidde_diff = (upper - lower);
    srand(time(0));
    // + 1.
    return ( (rand() % rekkevidde_diff) + lower);
    //Tick tock goes the clock
    //Even for the doctor
}
