#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "omp.h"
#define BUFFER_LENGTH 1024 * 10

int main(int argc, char **argv){
    // Allocates threads
    int t = atoi(argv[1]);
    omp_set_num_threads(t);
    
    // Gets file size
    FILE *a = fopen(argv[2], "r");
    fseeko64(a, 0, SEEK_END);
    unsigned long long size = ftello64(a);
    fclose(a);

    // Starts recording time
    unsigned long occurrences = 0;
    double time = omp_get_wtime();
    #pragma omp parallel
    {
        // Opens file and allocate buffer
        FILE *f = fopen(argv[2], "r");
        char buffer[BUFFER_LENGTH + 1];
        
        unsigned long long i;
        int j, k = 0, l = strlen(argv[3]) - 1;
        #pragma omp for schedule(dynamic) reduction(+:occurrences)
        for(i = 0; i < size; i += sizeof buffer){
            // Gets new bytes
            fseeko64(f, i, SEEK_SET);
            fgets(buffer, sizeof buffer, f);
            // Reads each buffer
            for(j = 0; j < sizeof buffer; j++){
                //if(buffer[j] == '\0') break;
                if(buffer[j] == argv[3][k]){
                    // If the loop is about to finish
                    // and the buffer has part of a 
                    // possible occurrence, load more bytes.
                    if(j == sizeof buffer - 1){
                        // Gets new bytes
                        fgets(buffer, l - k, f);
                        j = -1;
                    }
                    if(k == l) {
                        // Increments occurrence
                        occurrences++;
                        k = 0;
                    }
                    else k++;
                } else k = 0;
            }
        }
        fclose(f);
    }
    // Gets the time difference
    time = omp_get_wtime() - time;
    printf("Occurrences: %i, Time: %lf", occurrences, time);
}