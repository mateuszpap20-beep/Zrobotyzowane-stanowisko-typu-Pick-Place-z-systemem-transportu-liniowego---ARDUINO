#include "arm.h"
#include <math.h>



#define RAD_TO_DEG (180 / M_PI)
#define DEG_TO_RAD (M_PI / 180)



Arm::Arm() {
	this->pos.x = START_POS_X;
	this->pos.y = START_POS_Y;
	this->pos.z = START_POS_Z;

	this->gripper = new Servo;
}


void Arm::init() {
	this->gripper->attach(GRIPPER_PIN);
	
	Right.attach(RIGHT_PIN);
	Left.attach(LEFT_PIN);
	Bottom.attach(BOTTOM_PIN);

	this->gripperClose();
	Bottom.write(90);
	Right.write(0);
	Left.write(120);
}



// for gripper

void Arm::gripperOpen() {
	this->gripper->write(GRIPPER_MAX);
}

void Arm::gripperClose() {
	this->gripper->write(GRIPPER_MIN);
}




// IK

/*

y
^
|
|    / P ( x, y )				=> atan2 (x, y) * RAD_TO_DEG;
|   /							=> l^2 = x^2 + y^2
|  / <-- l
| /
|/
-------------------> x




z                        /
^                     /  /
|                   /   /
|                /     / a2
|       c --> /       /
|           /       /
|        /        / 
|     /       ----
|   /      ----
| /   ---- a1
|/---
|-
---------------------------> l

*/

bool Arm::solve() {


	double x = this->pos.x;
	double y = this->pos.y;
	double z = this->pos.z;



	double alpha = atan2(y, x) * RAD_TO_DEG;
	double l = sqrt(x * x + y * y);


	double c = sqrt(z * z + l * l);
	double phi = atan(z / l) * RAD_TO_DEG;

	double triangle_alpha = acos((a1 * a1 + c * c - a2 * a2) / (2 * a1 * c)) * RAD_TO_DEG;
	double triangle_gamma = acos((a1 * a1 + a2 * a2 - c * c) / (2 * a1 * a2)) * RAD_TO_DEG;


	double betha = phi + triangle_alpha;
	double gamma = 180 - triangle_gamma;



	alpha = 90 + alpha;
	betha = 180 - betha;
	gamma = 180 - gamma;



	double tmp_check_table[3] = { alpha, betha, gamma };

	for (uint8_t i = 0; i < sizeof(tmp_check_table) / sizeof(double); i++)
		if (tmp_check_table[i] != tmp_check_table[i])
			return false;



	joint[0].angle.raw_angle = alpha;
	joint[0].angle.angle = round(alpha);

	joint[1].angle.raw_angle = betha;
	joint[1].angle.angle = round(betha);

	joint[2].angle.raw_angle = gamma;
	joint[2].angle.angle = round(gamma);


	return true;
}





void Arm::setPoint(Pos_3d pos) {
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	this->pos.z = pos.z;
}



void Arm::move() {
	Bottom.write(joint[0].angle.angle);
	Right.write(joint[1].angle.angle);
	Left.write(joint[2].angle.angle);
}
