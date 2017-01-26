int increment_by_value_num_times(int start_value, int increment, int num_times) {
    for(int i=0; i < num_times; i++) {
        start_value += increment;
    }
    return start_value;
}

void increment_by_pointer_num_times(int* start_value, int increment, int num_times) {
    for(int i=0; i < num_times; i++) {
        *(start_value) += increment;
    }
}

void swap_numbers(int* augend, int* addend) {
    //Fordi den bare skal bytte om på to variabler.
    //ok, så den enkleste løsningen er temp = a; a = b; b = temp;
    //så det krever +1 variabel. Pass by value krever ytterligere to.
    //så plutselig har du tre sett med verdier løpende rundt her,
    //når alt jeg ville var bytte om på verdien av to variabler.
    *augend = *augend + *addend;
    *addend = *augend - *addend;
    *augend = *augend - *addend;
    //ok, så det er mulig at det er et lite overflowproblem her.
    
}
