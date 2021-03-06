//---------------------------- New game ----------------------------------
// Start new game
//------------------------------------------------------------------------

#include "menu_new_game.h"
#include "levels_level.h"
#include "drawing_units.h"
#include "unit.h"
#include <conio.h>
#include <stdio.h>
#include <stdbool.h>
#include "shot.h"
#include "ai.h"

#define PI 3.14159265

int screen_bufor [MAX_X][MAX_Y];

int angle_points[3][2];
bool first_angle = true;
float angle_drawing_distanse = 5;

void game_loop(int map_layout [MAX_X][MAX_Y])
{
    system("cls");

    CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize=1;
	CurInfo.bVisible=FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);

    unit_func();
    int queue = 1; //1 - Player, 2 - Bot
    int max_players = 2;
    int key_pressed;
    int player_angle = 0;
    int player_power = 100;
    bool first_frame = 1; // thanks to this bool, map, draws only once
    bool quit = false;
    bool playerTurn = 1; // it should be an option to choose - who will begin the game - player or ai?


    test_drawing_units(map_layout);

    while(player.hp > 0 && bot.hp > 0)
    {
        //Main game loop :)
        //system("cls");
        if(quit == false && first_frame == 1)
        {
        test_drawing_map(map_layout);
        first_frame = 0;
        printf("\n\n");
        }


        while(playerTurn)
        {
            if(quit == true)break;
            //Player move

                if(quit == true)break;
                //Choose power and angle
                gotoxy(0,80);
                printf("Angle = %d", player_angle);
                printf("\t\tPower = %d", player_power);
                printf("\t\tWind = %d", (int)wind_speed);
                printf("\t\tPoints = %d", player.points);

                //Drawing angle tray
                if(first_angle == true)
                {
                    int i;
                    for(i = 0; i < 3; i++)
                    {
                         angle_points[i][0] = player.x + (int)angle_drawing_distanse*(i+1)*cos(player_angle * PI / 180.0 );
                         angle_points[i][1] = 79 - (player.y + (int)angle_drawing_distanse*(i+1)*sin(player_angle * PI / 180.0 ));
                         if((angle_points[i][0] >=0)&&(angle_points[i][0] < MAX_X) && (angle_points[i][1] >=0) && (angle_points[i][1] < MAX_Y))
                         {
                         gotoxy(angle_points[i][0],angle_points[i][1]);
                         printf(".");
                         }
                    }
                    first_angle = false;

                }
                else
                {
                    int i;
                    for(i = 0; i < 3; i++)
                    {
                        if((angle_points[i][0] >=0)&&(angle_points[i][0] < MAX_X) && (angle_points[i][1] >=0) && (angle_points[i][1] < MAX_Y))
                         {


                         int xxx = map_layout[angle_points[i][0]][79-angle_points[i][1]];
                         gotoxy(angle_points[i][0],angle_points[i][1]);
                         switch(xxx){
                            case 0: printf(" "); break;
                            case 1: printf("1"); break;
//                            default: printf(" "); break;
                         }

                         }

                    }


                    for(i = 0; i < 3; i++)
                    {
                       angle_points[i][0] = player.x + (int)angle_drawing_distanse*(i+1)*cos(player_angle * PI / 180.0 );
                       angle_points[i][1] = 79 - (player.y + (int)angle_drawing_distanse*(i+1)*sin(player_angle * PI / 180.0 ));
                       if((angle_points[i][0] >=0)&&(angle_points[i][0] < MAX_X) && (angle_points[i][1] >=0) && (angle_points[i][1] < MAX_Y))
                       {
                         gotoxy(angle_points[i][0],angle_points[i][1]);
                         printf(".");
                         }
                    }
                }
                //------------------

                key_pressed = getch();
                if(key_pressed == 27)quit = true;
                if(key_pressed == 13)
                {
                    missile_data *missile;
                    missile = initializeMissile(player.x, player.y);
                    playerShot(missile, player_power, player_angle, map_layout);
                    playerTurn = false;
                }
                else switch(getch()){
                        case 72:
                        if(player_angle < 180)player_angle = player_angle + 1;
                        break;

                        case 75:
                        if(player_power > 0)player_power = player_power - 1;
                        break;

                        case 77:
                        if(player_power < 200)player_power = player_power + 1;
                        break;

                        case 80:
                        if(player_angle > 0)player_angle = player_angle - 1;
                        break;
                }
        }
        //-----------------------------------end of player's turn
        ai(bot, map_layout); // chain of few functions, which ends with calling function playerShot()

        //------------------------------------end of bots' turn
    if(selected_level.level_wind == WIND_VARIABLE)wind_speed = random_wind(); //Generate new wind force
    Sleep(1000);
    playerTurn = true;

    }//end of main loop

    system("cls");
    if(player.hp > 0)
    {
        //Inform about victory

        //--------------------

        //Back to menu

        //------------
    }

    else if(bot.hp > 0 || key_pressed == 27)
    {
        //Inform about defeat

        //--------------------

        getch();

        //Back to menu

            system("cls");
            test_menu(map_layout);

        //------------
    }
}
