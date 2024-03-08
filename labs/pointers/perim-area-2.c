/* program to compute the perimeter and area of a rectangle */

#include <stdio.h>

// compute the perimeter and area of a rectangle, given the lengths of the two sides
void compute(double side1, double side2, double* perimeter, double* area) {
  double lengthPlusWidth = side1 + side2;
  *perimeter = 2.0 * lengthPlusWidth;
  *area = side1 * side2;
  printf("parameter side1:  location: %p, value: %lf\n", &side1, side1);
  printf("parameter side2:  location: %p, value: %lfn", &side2, side2);
  printf("local lengthPlusWidth:  location: %p, lengthPlusWidth: %lf\n",
        &lengthPlusWidth, lengthPlusWidth);
  printf("parameter:  location: %p, value: %p, point to: %lf\n", &perimeter, perimeter, *perimeter);
  printf("area:  location: %p, value: %p, point to: %lf\n", &area, area, *area);
}


// demonstrate pointer passing by calling compute and displaying results
int main() {
 
  // declare variables
  double length = 5.0;
  double width  = 7.0;

  // print header
  printf ("working with a rectangle of width %lf and length %lf\n", width, length);

  // compute desired quantities
  double perimeter;
  double area;
  compute(length, width, &perimeter, &area);

  // print results
  printf("rectangle length:  location: %p, value: %lf\n", &length, length);
  printf("rectangle width:   location: %p, value: %lf\n", &width, width);
  printf("rectangle perim:   location: %p, value: %lf\n", &perimeter, perimeter);
  printf("rectangle area:    location: %p, value: %lf\n", &area, area);
  return 0;
}
