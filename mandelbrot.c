#include <stdio.h>

#define WIDTH 80
#define HEIGHT 24
#define MAX_ITER 100

void drawMandelbrot() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;

            double realTemp = real;
            double imagTemp = imag;

            int iter = 0;

            while (iter < MAX_ITER) {
                double realSquared = real * real - imag * imag;
                double imagSquared = 2 * real * imag;

                real = realSquared + realTemp;
                imag = imagSquared + imagTemp;

                if ((real * real + imag * imag) > 4) {
                    break;
                }

                iter++;
            }

            if (iter == MAX_ITER) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    drawMandelbrot();

    return 0;
}

