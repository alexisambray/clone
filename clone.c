#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
  float x, y;
} Point;

typedef enum {
  UP = 'U',
  DOWN = 'D',
  LEFT = 'L',
  RIGHT = 'R',
  STOP = 'S'
} Movement;

Point getCoordinates(void);
Movement moveCadence(Point* cadenceCoords, Point* cloneCoords);
void displayCoordinates(Point point);
float getDistance(Point point1, Point point2);
bool isSafe(float distance);
void displaySafeOrNot(bool safe);

int main() {
  printf("Enter Cadence's coordinates (x, y).\n");
  Point cadenceCoords = getCoordinates();
  printf("Enter the clone's coordinates (x, y).\n");
  Point cloneCoords = getCoordinates();

  Movement movement;
  do {
    movement = moveCadence(&cadenceCoords, &cloneCoords);
  } while (movement != STOP);

  printf("Cadence's location: ");
  displayCoordinates(cadenceCoords);
  printf("Clones's location: ");
  displayCoordinates(cloneCoords);

  float distance = getDistance(cadenceCoords, cloneCoords);
  printf("Distance between Cadence and the clone is: %.2f", distance);
  displaySafeOrNot(isSafe(distance));

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

Movement moveCadence(Point* cadenceCoords, Point* cloneCoords) {
  Movement movement;

  printf(
      "What direction do you want Cadence to move to? [U, D, L, R. Input S "
      "to "
      "stop]: ");
  scanf(" %c", &movement);
  switch (toupper(movement)) {
    case UP:
      (cadenceCoords->y)++;
      (cloneCoords->y)--;
      break;
    case DOWN:
      (cadenceCoords->y)--;
      (cloneCoords->y)++;
      break;
    case LEFT:
      (cadenceCoords->x)--;
      (cloneCoords->x)++;
      break;
    case RIGHT:
      (cadenceCoords->x)++;
      (cloneCoords->x)--;
      break;
    default:
      movement = STOP;
  }
  return movement;
}

void displayCoordinates(Point point) {
  printf("(%.2f, %.2f)\n", point.x, point.y);
}

// Cadence (X1, Y1)  Clone (X2, Y2)
// d = sqrt (X2 - X1)^2 + (Y2 - Y1)^2
float getDistance(Point point1, Point point2) {
  return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}

// Returns true if Cadence is safe
bool isSafe(float distance) {
  return distance >= 10;
}

void displaySafeOrNot(bool safe) {
  if (safe) {
    printf("Cadence is NOT SAFE! We can't stop yet!\n");
  } else {
    printf("Cadence is safe now! We can stop.\n");
  }
}
