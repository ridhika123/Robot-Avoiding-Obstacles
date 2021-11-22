/*

> Avoid obstacles
> If it does a turn twice, it should beep and spin
> Dance (3times) every 10 seconds 
> at least one if; 1 switch or another if; 3 loops (1 for, 1 while)
> needs a print message each acion

 */

/* 
Avoiding obstacles: 
- Sensors detect obstacles 3 times each
- If not right, if left, turn right
- If not left, if right, turn left
- If not right, if not left, move forward
- If right, if left, turn around
- After action, go back to sensors 

 */

#include <stdio.h>
#include <MyroC.h>
#include <unistd.h>

/* Precoedure to */
/* Pre-conditions: 
* Post-conditions:
*/

void
robot_dance (int i)
{
  while (i % 10 == 0)
    {for (int j = 1; j < 4; j++)
        {
          rForward (0.5, 0.5);
          rForward (0.5, 0.5);
          rTurnRight (0.5, 0.5);
          rTurnLeft (0.5, 0.5);
          rBackward (0.5, 0.5);
          rBackward (0.5, 0.5);
        }
      break;}
 }


/* Precoedure to */
/* Pre-conditions: 
* Post-conditions:
*/

char
robot_avoiding_obstacles (void)
{
int leftIR  = rGetIRTxt ("left", 3);
int rightIR = rGetIRTxt ("right", 3);
char movement_of_robot_char; 
 
if (leftIR && !rightIR)
  {rTurnLeft(0.3, 0.5);
  movement_of_robot_char = 'l';}
else if (!leftIR && rightIR)
  {rTurnRight(0.3, 0.5);
  movement_of_robot_char = 'r';}
else if (!leftIR && !rightIR)
  {rBackward(0.3, 0.5);
  movement_of_robot_char = 'x';}
else if (leftIR && rightIR)
  {rForward(0.3, 0.5);
  movement_of_robot_char = 'x';}

return movement_of_robot_char;
 }

int
main (void)
{
rConnect ("/dev/rfcomm0");
 
for (int i = 1; 1; i++)
{
  char movement_tracker_1, movement_tracker_2;
   
  if (i % 2 == 1) /* If i is odd, assigns the movement of the robot to movement_tracker_1. */
    movement_tracker_1 = robot_avoiding_obstacles();
  else /* If i is even, assigns the movement of the robot to movement_tracker_2. */
    movement_tracker_2 = robot_avoiding_obstacles();

  if ((movement_tracker_1 == movement_tracker_2) && (movement_tracker_1 != 'x')) /* Compares the current movement to the previous movement. */
    {
      rBeep(1, 5000);
      rMotors (1, 0.02); //turn clockwise, won't stop until received new order
      sleep(5);
    }
     
   robot_dance(i); /* Robot performs dance routine 3 times. */
}
 
rDisconnect ();

return 0;
}
