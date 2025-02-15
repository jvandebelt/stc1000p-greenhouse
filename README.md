Introduction
==========

See the main README on the master branch for full details on the STC\-1000 and the stc1000p code created by Mats Staffansson. The stc controller can monitor temperature such as the temperature of an aquarium or a brewing vessel, and can keep the temperature within a desired range through the use of heating and cooling equipment.

The greenhouse branch adapts the code to use the STC\-1000 as a controller for a heated bench for seedlings and plants and adds additional features on top of the existing features created by Mats and others. The main extra feature is adapting the temperature profiles to a day/night cycle with different temperatures for day, night and transition periods in between. Setting a lower temperature at night is actually advantageous to plant growth and health, and will also save electricity as heated benches can cost quite a bit to run. 

Another feature added is to increase or decrease day length (and corresponding night length) tracking the natural light. Each day will be 3 minutes longer or shorter which roughly keeps up with daylight change at 52 degrees latitude. I am still testing how well the program keeps up with the natural sunrise but this experiment is ongoing.

How to use
==========

See [this video](http://youtu.be/u95BEq3bk7Q) 
and [this video](http://youtu.be/nZst7ETP-w8) on general use of the stc1000p and on setting up temperature profiles. The greenhouse code enabeles profiles to be repeated up to 999 times. By setting the profiles to be 24 hours, we can set a day and night temperature which is then repeated. 

To use the heated bench day/night function, ramping should be enabled and only 5 setpoints used (marked as * below). The ramp is 2 hours of twilight in morning and evening. Profiles should look like this:

\*-----day-----\*&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\*<br>   		
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\\	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\/<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\\ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\/<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\*-----night-----\*
						
Only five profiles are possible instead of ten due to reduced memory. The default profiles are as follows:
 
* Pr0: Normal (20 and 12 degrees) day/night cycle Jan 14 till end May - 8 hrs 1 mins daylight to start
 
* Pr1: Cooler (18 and 12 degrees) day/night cycle Jan 14 till end May
 
* Pr2: Normal day/night cycle Feb 4 till May 31 - 9 hrs 9 mins daylight to start
 
* Pr3: Heat-loving plants (24 and 12 degrees) Feb 21 till end May - 10 hrs 15 mins daylight to start
 
* Pr4: Overwintering crops Sep 18 to Nov 18 - 12 hrs 31 mins daylight to start and reduce daylight
		


 
