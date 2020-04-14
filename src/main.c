/* 
The MIT License (MIT)

Copyright (c) 2020 Anna Brondin and Marcus Nordström

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "StepCountingAlgo.h"
#define PATH "/home/mackan240/Documents/Step-counting-algo-test/DataSet/optimisation/data/_Patient_2/accelerometer.csv"
int main(int argc, char *argv[])
{
    initAlgo();
    char *line = NULL;
    size_t len = 0;
    size_t read;
    FILE *fp = fopen(PATH, "r");
    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    clock_t startTime = clock();
    while ((read = getline(&line, &len, fp)) != -1) {
        long time = strtol(strtok(line, ","), NULL, 10);
        strtok(NULL, ",");
        long x = (long) (strtof(strtok(NULL, ","), NULL) * 100000000);
        long y = (long) (strtof(strtok(NULL, ","), NULL) * 100000000);
        long z = (long) (strtof(strtok(NULL, ","), NULL) * 100000000);
        //printf("%ld,%f,%f,%f\n",time,x,y,z);
        processSample(time, x, y, z);
    }
    clock_t endTime = clock();
    printf("steps=%i\nt=%fs\n", getSteps(), ((float)(endTime - startTime))/10000000);
    fclose(fp);
    if (line)
        free(line);
}