/*
 * STC1000+, improved firmware and Arduino based firmware uploader for the STC-1000 dual stage thermostat.
 *
 * Copyright 2014 Mats Staffansson
 *
 * This file is part of STC1000+.
 *
 * STC1000+ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * STC1000+ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with STC1000+.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "stc1000p.h"

#define EEPROM_DEFAULTS(name, led10ch, led1ch, led01ch, type, default_value) \
    default_value,

/* Initial EEPROM data */
__code const int __at(0xF000) eedata[] = {
#if !(defined(OVBSC) || defined(RH))
			// ramping should be enabled and only 5 setpoints used				
			// profile should look like this
			/*
			   -----day-----
							\				  /
							 \			 	 /
							  -----night-----
						
			// Ramp is 2 hours of twilight in morning and evening.
			// JC turn on hotbed Jan week 2 at 18 degrees C
			// Keep hotbed on till end May - 137 days
			*/
			// each day sunrise is 1.5 mins earlier. Therefore total day + night = 1438.5 mins. 
			// Take one min off night duration (so day + night = 1439 mins) and every even night take extra min off
			200, 481, 200, 120, 120, 718, 120, 120, 200, 0, 0, 0, 0, 0, 0, 0, 14, 1, 0, 137, 	// Pr0 (SP0, dh0, ..., SP9, reps) 	// Normal day/night times starting Jan 14 - 8 hrs 1 mins daylight
			180, 481, 180, 120, 100, 718, 100, 120, 180, 0, 0, 0, 0, 0, 0, 0, 14, 1, 0, 137, 	// Pr1 (SP0, dh0, ..., SP9, reps) 	// Cooler day/night times starting Jan 14 - 8 hrs 1 mins daylight
			200, 549, 200, 120, 100, 650, 100, 120, 200, 0, 0, 0, 0, 0, 0, 0, 4,  2, 0, 117, 	// Pr2 (SP0, dh0, ..., SP9, reps) 	// Day/night times starting Feb 4 - 9 hrs 9 mins daylight
			240, 615, 220, 120, 140, 584, 140, 120, 240, 0, 0, 0, 0, 0, 0, 0, 21, 2, 0, 117,	// Pr3 (SP0, dh0, ..., SP9, reps)	// Heat-loving plants starting Feb 21 - 10 hrs 15 mins daylight
			200, 2,   200, 1,   120, 5,   120, 1,   200, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 2,		// test sequence
			//200, 750, 200, 120, 120, 451, 120, 120, 200, 0, 0, 0, 0, 0, 0, 0, 18, 9, 0, 60, 	// Pr4 (SP0, dh0, ..., SP9, reps)	// Overwintering crops: Sep 18 to Nov 18 - start with 12 hrs 31 mins daylight
#endif
			MENU_DATA(EEPROM_DEFAULTS)
};

