#pragma once

class Animal {

public:
	Animal();
	void sound();
	void go();
	void eat();
	void sleep();
	void hear(int);
	void speak();
	void setSpeed(int);
	int getSpeed();

private:
	int speed;
	int mem;
	Foot foot;
};