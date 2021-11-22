# Robot-Avoiding-Obstacles

## Prompt
You will write a program governing robot behavior so that it avoids obstacles. Since one obstacle might be boring, you will also make the robot do something novel when it has been repetitive and dance every so often because life is too short not to.

Working in pairs, you will develop a program that includes these elements:

* The robot should move so as to avoid obstacles in the room.
* If the robot performs the same two turns consecutively (e.g. two right turns), the robot beeps and turns for a second or two (before performing any further movements).
  *  Note: The beep/turn around activity applies only when there are two turns, so going forward or backward twice in a row does not count!
  *  The turning that accompanies a beep should not count as an action.
  *  To accomplish this requirement, you likely will need at least one variable that keeps track of the previous robot activity. This variable is updated after each action. After a turn left or right, this variable can be consulted to determine if the previous action (turn or movement) was the same type of turn.
*  Every ten actions, the robot performs a short dance three times in a row (the dance can just be a few actions).
*  The program contains at least one if statement.
*  The program contains a switch statement or a second if statement.
*  The program contains at least three loops; at least one must be a for loop, and at least one must be a while loop.
*  The program displays an indicative message each time it turns, each time it moves forward or backward, and each time it performs its short dance after ten other actions.

Note: The robot's motion need not be continual; you can interleave short motions with sensing operations.

## Response
The program is [here](https://github.com/ridhika123/Robot-Avoiding-Obstacles/blob/main/avoiding_obstacles.c).
