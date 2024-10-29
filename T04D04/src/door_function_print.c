#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 42
#define HEIGHT 21

void plot_function(double (*func)(double), double xmin, double xmax,
                   double ymin, double ymax, char graph[HEIGHT][WIDTH]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      graph[i][j] = ' ';
    }
  }

  for (int x = 0; x < WIDTH; x++) {
    double real_x = xmin + (xmax - xmin) * x / (WIDTH - 1);
    double real_y = func(real_x);

    if (real_y >= ymin && real_y <= ymax) {
      int y = HEIGHT - 1 - (real_y - ymin) * (HEIGHT - 1) / (ymax - ymin);
      graph[y][x] = '*';
    }
  }
}

double verzier(double x) { return 1.0 / (1.0 + x * x); }

double lemniscate(double x) {
  double temp = sqrt(sqrt(1 + 4 * x * x) - x * x - 1);
  return isnan(temp) ? NAN : temp;
}

double hyperbola(double x) { return x != 0 ? 1.0 / (x * x) : NAN; }

void print_graph(char graph[HEIGHT][WIDTH]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", graph[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  char graph[HEIGHT][WIDTH];

  // Верзьера Аньези
  plot_function(verzier, -M_PI, M_PI, 0, 1, graph);
  printf("Verzier of Agnese:\n");
  print_graph(graph);

  // Лемниската Бернулли (с полным использованием диапазона Y)
  plot_function(lemniscate, -M_PI, M_PI, 0, 1, graph);
  printf("Lemniscate of Bernoulli:\n");
  print_graph(graph);

  // Квадратичная гипербола
  plot_function(hyperbola, -M_PI, M_PI, 0, 1, graph);
  printf("Quadratic Hyperbola:\n");
  print_graph(graph);

  return 0;
}
