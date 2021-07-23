# DDK_mouse_cursor
* The cursor moves and clicks on its own.
* 7/18 mouse_move.c implements recording of moving.
  * Type 's' to record and type 'c' to stop recording.
  * Type 'e' to execute.
  * It can record 60s (6000/100), but you can change it.
  * Next time, I will add click function and change it to a structure.
* 7/23 Add click function.
  * Some bugs were fixed, and it works well.
* To be more convenient, I will use txt file to record the moving and clicking instead of array.
  * MOV x y 100(ms)
  * CLK x y 100(ms)
  * ... 
* I hope one day this project could be Selenium-like.


# Platform
* Windows
* Dev C

# Language 
* C/C++

# References
* https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-mouse_event
