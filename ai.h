#ifndef __AI_H__
#define __AI_H__

//---------------------------- Artificial Inteligence --------------------
// It combines the files responsible for artificial inteligence
//------------------------------------------------------------------------
// Polish team is working on this file
// Included libraries

// Included files
#include "levels_level.h"
#include "ai_easy.h"
#include "ai_medium.h"
#include "ai_hard.h"
#include <stdbool.h>

void test_ai(); // function for agreagate testing
float min_angle(unit local_bot);
float find_random(int min_ang, int max_ang);
bool raycast(unit from, int angle,  int map_layout[MAX_X][MAX_Y]);
void ai(unit local_bot, int map_layout[MAX_X][MAX_Y]);



#endif // __AI_H__
