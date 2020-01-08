#pragma once
class ObjectCount
{
public:
	ObjectCount();
	~ObjectCount();
	ObjectCount(const ObjectCount& obj);
	void printCount();
private:
	static int count;

};

