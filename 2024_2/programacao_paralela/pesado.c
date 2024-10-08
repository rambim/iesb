#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000

// Função para calcular o conjunto de Mandelbrot
int mandelbrot(double complex c) {
    double complex z = 0;
    int iter;
    for (iter = 0; iter < MAX_ITER; iter++) {
        if (creal(z) * creal(z) + cimag(z) * cimag(z) > 4.0)
            return iter;
        z = z * z + c;
    }
    return iter;
}

// Função para gerar a imagem do conjunto de Mandelbrot
void generate_mandelbrot_image(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Não foi possível abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    double re_min = -2.0, re_max = 1.0;
    double im_min = -1.0, im_max = 1.0;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double re = re_min + (re_max - re_min) * x / (WIDTH - 1);
            double im = im_min + (im_max - im_min) * y / (HEIGHT - 1);
            double complex c = re + im * I;
            int value = mandelbrot(c);
            int color = (value == MAX_ITER) ? 0 : (value * 255) / MAX_ITER;
            fprintf(file, "%d %d %d ", color, color, color);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    clock_t start = clock();
    generate_mandelbrot_image("mandelbrot.ppm");
    clock_t end = clock();

    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Tempo para gerar a imagem do conjunto de Mandelbrot: %f segundos\n", time_taken);

    return 0;
}
