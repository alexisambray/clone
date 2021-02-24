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
float getDistance(Point* cadenceCoords, Point* cloneCoords);
bool isSafe(float getDistance, float distanceResult);

int main() {
  printf("Enter Cadence's coordinates (x, y).\n");
  Point cadenceCoords = getCoordinates();
  printf("Enter the clone's coordinates (x, y).\n");
  Point cloneCoords = getCoordinates();

  Movement movement;
  do {
    movement = moveCadence(&cadenceCoords, &cloneCoords);
  } while (movement != STOP);

  do {
    printf("Cadence's location: ");
    displayCoordinates(cadenceCoords);
    printf("Clones's location: ");
    displayCoordinates(cloneCoords);

    getDistance(&cadenceCoords, &cloneCoords);
  } while (isSafe == false);

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
float getDistance(Point* cadenceCoords, Point* cloneCoords) {
  float distanceOne, distanceTwo, getDistance;
  float powerOne, powerTwo, distanceResult;

  distanceOne = (cloneCoords->x) - (cadenceCoords->x);
  powerOne = pow(distanceOne, 2);
  distanceTwo = (cloneCoords->y) - (cadenceCoords->y);
  powerTwo = pow(distanceTwo, 2);

  getDistance = (powerOne + powerTwo);
  distanceResult = sqrt(getDistance);

  printf("Distance between Cadence and the clone is %.2f\n", distanceResult);

  isSafe(getDistance, distanceResult);

  return 0;
}

// Returns true if Cadence is safe
bool isSafe(float getDistance, float distanceResult) {
  bool isSafe = false;  // initialized as false unless distance is more than 10

  if (distanceResult < 10) {
    printf("Cadence is NOT SAFE! We can't stop yet!\n");
  } else {
    printf("Cadence is safe now! We can stop.\n");
  }
  return isSafe = true;
}