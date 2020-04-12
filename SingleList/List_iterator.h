#pragma once
#include"Iterator.h"

template <class T>
class List_iterator : public Iterator<T> {

public:
	//typedef List_iterator<T> iterator;

	
	List_iterator(Node<T>* container = nullptr);
	List_iterator(const List_iterator& obj);

	T& operator*();  // dereferencing operator
	List_iterator<T>& operator=(const List_iterator<T>& obj);
	bool operator==(const List_iterator<T>& obj) const;
	bool operator!=(const List_iterator<T>& obj) const;
	List_iterator<T>& operator++();
	List_iterator<T> operator++(int);

//private:
	Node<T>* current_node;

};


template <class T>
List_iterator<T>::List_iterator(Node<T>* container):current_node(container) {}

template <class T>
List_iterator<T>::List_iterator(const List_iterator& obj) {
	current_node = obj.current_node;
}

template<class T>
T& List_iterator<T>::operator*() {
		return *current_node;
}

template<class T>
List_iterator<T>& List_iterator<T>::operator++() {
	
	current_node = current_node->next;

	return *new List_iterator<T>(current_node);
}

template<class T>
List_iterator<T> List_iterator<T>::operator++(int n) {
	List_iterator<T>* temp = new List_iterator<T>(current_node);
	current_node = current_node->next;
	//List_iterator<T>* temp = new List_iterator<T>();
	return  *temp;
}

template<class T>
List_iterator<T>& List_iterator<T>::operator=(const List_iterator<T>& obj) {

	obj.current_node = current_node;

	return &obj.current_node;
}

template<class T>
bool List_iterator<T>::operator==(const List_iterator<T>& obj) const {
	if (current_node == obj.current_node)
		return true;
	return false;
}

template<class T>
bool List_iterator<T>::operator!=(const List_iterator<T>& obj) const {
	if (current_node == obj.current_node)
		return false;
	return true;
}