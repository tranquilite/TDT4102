#include<ctime>
#include<cstdlib>

int randomWithLimits(int lower, int upper) {
    int rekkevidde_diff = (upper - lower);
    srand(time(0));
    return ((rand() % rekkevidde_diff)+lower);
}

// case: hvis rand() % rekkevidde_diff == 0, når den aldri upper.
// Legg til +1 for å .. jeg vet ikke.. ikke fucke opp livet
