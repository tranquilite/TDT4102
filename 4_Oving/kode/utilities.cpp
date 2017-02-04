int incrementByNumTimesValue(int startValue, int increment, int numTimes) {
    for(int i=0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

int incrementByNumTimesValue2(int *startValue, int increment, int numTimes) {
    for(int i=0; i < numTimes; i++) {
        *startValue += increment;
    }
    return *startValue;
}
