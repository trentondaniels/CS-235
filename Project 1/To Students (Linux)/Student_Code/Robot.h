/*
 * Robot.h
 *
 *  Created on: Jan 6, 2015
 *      Author: JasonT
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include "Fighter.h"

class Robot: public Fighter {
public:
	Robot();
	Robot(string info);
	virtual ~Robot();

	void reset();
	void regenerate();
	bool useAbility();
};

#endif /* ROBOT_H_ */
