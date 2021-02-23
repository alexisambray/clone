#include <stdio.h>

typedef struct {
  float x, y;
} Point;

Point getCoordinates(void);

int main() {
  printf("Enter Cadence's coordinates (x, y).\n");
  Point cadenceCoords = getCoordinates();
  printf("Enter the clone's coordinates (x, y).\n");
  Point cloneCoords = getCoordinates();
 
  return 0;
}

Point getCoordinates(void) {
  Point point;
  printf("Enter x coordinate: ");
  scanf("%f", &point.x);
  printf("Enter y coordinate: ");
  scanf("%f", &point.y);

  return point;
}