## Use
***
To run the mechanism run these commands sequentially

`rosrun act_pump actp.py`

To run any of the pumps replace command in the rosservice call with any of the pumps.

`rosservice call control_pumps /command`

For example: `rosservice call control_pumps /pump1` will actuate the first pump.

This service call returns success:True once the pumps are actuated without any error

***

## Common Issues
***
* permission denied for a port
  
  Use the following command:
  
  `sudo chmod 666 #port`
  
  Replace #port with whichever port is being used by external mechanisms.
  
* Electronic failures
  
  This might happen sometimes as some of our electronic components are unreliable. We are working on getting it fixed ASAP!
*** 
