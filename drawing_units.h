#ifndef __DRAWING_UNITS_H__
#define __DRAWING_UNITS_H__

//---------------------------- Draw units --------------------------------
// Drawing units
//------------------------------------------------------------------------
#include <math.h>
#include "maps_create.h" // including this library to have MAX_X, MAX_Y and time.h
#define PLAYER 3  //Sorry for that temporary change, but in text mode we need another char than 10 (it bad looks with ground (1);
#define ENEMY 2
#define DISTANCE 20 // minimum distance between player and enemy

typedef struct
{
    int x, y;
} tCoordinates;

void test_drawing_units(int map_layout[MAX_X][MAX_Y]);
void drawing_units(int map_layout[MAX_X][MAX_Y]);
tCoordinates position (int map_layout[MAX_X][MAX_Y]);

#endif // __DRAWING_UNITS_H__
