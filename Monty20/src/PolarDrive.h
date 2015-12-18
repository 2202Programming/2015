/*
 * PolarDrive.h
 *
 *  Created on: Dec 18, 2015
 *      Author: lazar
 */

#ifndef SRC_POLARDRIVE_H_
#define SRC_POLARDRIVE_H_
#include "IControl.h"
#include <vector>

class PolarDrive: public IControl {
protected:
	NewXboxController *xbox;
	RobotDrive* myRobot;
	MultiOutputPID *motorOutput;
	MultiOutputPID *leftOutput;
	MultiOutputPID *rightOutput;
	Talon *talonFR, *talonRR, *talonFL, *talonRL;

	//FrontLeft3 RearLeft4 FrontRight1 RearRight2
	BeastSpeedControl *frontRight, *rearRight, *frontLeft, *rearLeft;
	PIDController *autoRotateController;
	PIDController *leftController;
	PIDController *rightController;

	//MOTOR CHANNELS
	const static int frontLeftChannel = 2;
	const static int rearLeftChannel = 4;
	const static int frontRightChannel = 1;
	const static int rearRightChannel = 3;

	//ENCODERS AND CLIPPERS
	Encoder *frontRightEncoder;
	Encoder *frontLeftEncoder;
	JoystickClipper *stickX;
	JoystickClipper *stickY;
	JoystickClipper *stickTwist;

	float translationSpeedFactor = .5;
	float roatationSpeedFactor = .5;

public:
	PolarDrive();
	virtual ~PolarDrive();

	void TeleopInit();
	void TeleopPeriodic();

private:

	void setMotors();
	void setEncoders();
	void setClippers();

	std::vector getVVector();
	bool setVVector();

	void drive();
	void left(int theta);
	void right(int theta);

	void setLimiters(float forward, float turn);

	void setCreep(bool prick);
	void toggleCreep();
	void getCreep();
};

#endif /* SRC_POLARDRIVE_H_ */
