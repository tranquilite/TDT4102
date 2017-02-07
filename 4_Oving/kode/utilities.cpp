int incrementByNumTimesValue(int startValue, int increment, int numTimes) {
    for(int i=0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

int incrementByNumTimesValue2(int *startValue, int increment, int numTimes) {
    //og vi endrer for det meste at startValue nå derefererer crappet som kom
    //inn som argument, aka adressen av v0 i stacken.
    for(int i=0; i < numTimes; i++) {
        *startValue += increment;
    }
    return *startValue;
}

void swapNumbers(int *etTall, int *toTall) {
    //Pointypointy fordi hvorfor legge mer på stacken når vi allerede har to
    //helt fine rett under som vi kan omrokkere på?
    //Skal bytte på to tall, hva skulle jeg gjort?
    //Returnert et array elns? Typen sier også noe om hva en funksjon gjør,
    //og dette er et rent predikat, ikke et objekt.
    int a = *etTall;
    *etTall = *toTall;
    *toTall = a;
}


