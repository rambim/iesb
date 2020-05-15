#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "omp.h"
#define BUFFER_SIZE 100

int searchInFile(char *filename, char *string, int num_threads) {
  FILE *f = fopen(filename, "r");
  if(f == NULL) return -1;

  fseeko64(f, 0, SEEK_END);
  long long int fileSize = ftello64(f);
  fclose(f);

  long long int k = 0;
  long long int occurrences = 0;
  double t1, t2;

  t1 = omp_get_wtime();
  #pragma omp parallel
  {
    int i = 0, j = 0;
    char buffer[BUFFER_SIZE + 1];
    int thread_num = omp_get_thread_num();
    FILE *file = fopen(filename, "r");

    #pragma omp for reduction(+:occurrences) schedule(dynamic)
    for(k = 0; k < fileSize; k += BUFFER_SIZE) {
      if(num_threads > 1) {
        fseeko64(file, k, SEEK_SET);
      }
      fgets(buffer, sizeof(buffer), file);

      int end_search = 0;
      for(i = 0; i < strlen(buffer); i++) {
        if(buffer[i] == string[j]) {
          if(j == strlen(string) - 1) {
            j = 0;
            occurrences++;
            if(end_search == 1) break;
          } else {
            if(i == strlen(buffer) - 1 && num_threads > 1) {
              if(k + BUFFER_SIZE < fileSize) {
                fgets(buffer, strlen(string) - j + 1, file);
                i = -1;
                end_search = 1;
              } else break;
            }
            j++;
          }

        }
        else {
          j = 0;
          if(end_search == 1) break;
        }
      }
    }

    fclose(file);
  }
  t2 = omp_get_wtime();

  printf("Done in: %lf seconds\n", t2-t1);
  return occurrences;
}

int main(int argc, char *argv[]) {
  int result;
  int num_threads = atoi(argv[1]);
  char *filename = argv[2];
  char *string = argv[3];
  omp_set_num_threads(num_threads);
  result = searchInFile(filename, string, num_threads);
  if(result == -1) {
    printf("File not found :(\n");
  }
  printf("Occurrences: %i\n", result);
  return(0);
}