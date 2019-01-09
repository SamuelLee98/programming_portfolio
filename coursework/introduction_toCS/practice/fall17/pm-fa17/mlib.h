#ifndef MLIB_H
#define MLIB_H

//-****************************************************
//-************* DO NOT ALTER THIS FILE ***************
//-**** WE WILL NOT ACCEPT ALTERED SUBMISSIONS ********
//-****************************************************
int** read_mpg(
    const char* filename, 
    int* n);

double convert_speed_time_to_gallons(
    int speed,
    int min,
    int* mpg_array);

#endif
