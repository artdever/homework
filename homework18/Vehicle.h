#pragma once


class Person {

public:
	Person();
	void wait();
	void getup();
	void sleep();
	void go();
	void eat();
	void hear(int);
	void speak();
	void setSpeed(int);
	int getSpeed();

private:
	int speed;
	int wheel;
	int year;
	Rudder rudder;
	Body body;
	Model model;

};