#pragma once

class Person {

public:
	Person();
	void dance();
	void walk();
	void get();
	void sit();
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
	int mem;
	Foot foot;
	Hand hand;
	Head head;

};