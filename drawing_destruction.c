//---------------------------- Draw destructions -------------------------
// Drawing destructions
// NUNO VALENTE
// PORTUGUESE TEAM
//------------------------------------------------------------------------

#include "drawing_destruction.h"


extern int map_layout [MAX_X][MAX_Y];


void test_drawing_destruction(int map_layout [MAX_X][MAX_Y])
{
    //create_explosion(map_layout,); //Draws the explosion
    create_destruction(map_layout); //Draws the destruction
}

void create_destruction(int map_layout [MAX_X][MAX_Y])
{
    int x, y;
    int breaks_loop = 0;


    for (x = 0; x < MAX_X; x++)
    {
        for (y = 0; y < MAX_Y; y++)
        {
            if (map_layout[x][y] == 50 && map_layout[x][y-1] == 1) //This means this is the final position of the player projectile, as below it there is ground, so it hits the ground
            {
                map_layout[x][y] = 0;

                if ((x - 1) >= 0)
                {
                    map_layout[x-1][y] = 0;
                }

                if ((x + 1) <= MAX_X)
                {
                     map_layout[x+1][y] = 0;
                }

                if ((y + 1) <= MAX_Y)
                {
                    map_layout[x][y+1] = 0;
                }

                if ((x - 1) >= 0 && (y + 1) <= MAX_Y)
                {
                    map_layout[x-1][y+1] = 0;
                }

                if ((x + 1) <= MAX_X && (y + 1) <= MAX_Y)
                {
                    map_layout[x+1][y+1] = 0;
                }
                //The code above restores the explosion to empty


                if ((y - 1) >= 0)
                {
                    map_layout[x][y-1] = 0;
                }

                if ((x - 1) >= 0 && (y - 1) >= 0)
                {
                    map_layout[x-1][y-1] = 0;
                }

                if ((x + 1) <= MAX_X && (y - 1) >= 0)
                {
                    map_layout[x+1][y-1] = 0;
                }

                if ((y - 2) >= 0)
                {
                    map_layout[x][y-2] = 0;
                }

                if ((x - 1) >= 0 && (y - 2) >= 0)
                {
                    map_layout[x-1][y-2] = 0;
                }

                if ((x + 1) <= MAX_X && (y - 2) >= 0)
                {
                    map_layout[x+1][y-2] = 0;
                }

                y = MAX_Y;
                breaks_loop = 1;

                //The code above destroys terrain
            }
            else if (map_layout[x][y] == 60 && map_layout[x][y-1] == 1) //This means this is the final position of the enemy projectile, as below it there is ground, so it hits the ground
            {
                map_layout[x][y] = 0;

                if ((x - 1) >= 0)
                {
                    map_layout[x-1][y] = 0;
                }

                if ((x + 1) <= MAX_X)
                {
                     map_layout[x+1][y] = 0;
                }

                if ((y + 1) <= MAX_Y)
                {
                    map_layout[x][y+1] = 0;
                }

                if ((x - 1) >= 0 && (y + 1) <= MAX_Y)
                {
                    map_layout[x-1][y+1] = 0;
                }

                if ((x + 1) <= MAX_X && (y + 1) <= MAX_Y)
                {
                    map_layout[x+1][y+1] = 0;
                }
                //The code above restores the explosion to empty


                if ((y - 1) >= 0)
                {
                    map_layout[x][y-1] = 0;
                }

                if ((x - 1) >= 0 && (y - 1) >= 0)
                {
                    map_layout[x-1][y-1] = 0;
                }

                if ((x + 1) <= MAX_X && (y - 1) >= 0)
                {
                    map_layout[x+1][y-1] = 0;
                }

                if ((y - 2) >= 0)
                {
                    map_layout[x][y-2] = 0;
                }

                if ((x - 1) >= 0 && (y - 2) >= 0)
                {
                    map_layout[x-1][y-2] = 0;
                }

                if ((x + 1) <= MAX_X && (y - 2) >= 0)
                {
                    map_layout[x+1][y-2] = 0;
                }

                y = MAX_Y;
                breaks_loop = 1;

                //The code above destroys terrain
            }

            if (breaks_loop == 1)
            {
                x = MAX_X;
            }
        }
    }
}

void create_explosion(int map_layout[MAX_X][MAX_Y],missile_data *m,int i)
{
    int x_pos = (int)m->x_vector_coordinate[i];
    int y_pos = (int)m->y_vector_coordinate[i];
    map_layout[x_pos][y_pos] = 0;
    gotoxy(x_pos,79 - y_pos);
    printf(" ");
    map_layout[x_pos +1][y_pos] = 0;
    gotoxy(x_pos+1,79 - y_pos);
    printf(" ");
    map_layout[x_pos-1][y_pos] = 0;
    gotoxy(x_pos-1,79 - y_pos);
    printf(" ");
    map_layout[x_pos][y_pos+1] = 0;
    gotoxy(x_pos,79 - y_pos - 1);
    printf(" ");
    map_layout[x_pos][y_pos-1] = 0;
    gotoxy(x_pos,79 - y_pos +1);
    printf(" ");

}
