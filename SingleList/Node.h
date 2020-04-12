#pragma once

template<class T>
struct Node {

	//Node() :val(T()), next(nullptr) {};
	Node(T val = T(),Node* node = nullptr) :val(val), next(node) {};
	Node* next;
	T val;
};