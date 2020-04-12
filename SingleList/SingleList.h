#pragma once

#include<iostream>

#include"List_iterator.h"

template <class T>
class SingleList {
	
	

public:

	SingleList();
	SingleList(const SingleList& obj);
	SingleList(SingleList&& m_obj);
	~SingleList();

	SingleList(const std::initializer_list<T>& obj);

	SingleList<T>& operator=(const SingleList<T>& obj);
	SingleList<T>& operator=(SingleList<T>&& obj);

	bool operator==(const SingleList<T>& obj) const;
	bool operator!=(const SingleList<T>& obj) const;
	
	//SingleList<T>& operator++();
	//SingleList<T> operator++(int);

	bool find(T const& val);
	void insert(List_iterator<T>& itr, T const& val);
	void insert(int const pos, T const& val);
	void push_back(T const& val);
	void push_front(T const& val);
	void pop_back();
	void pop_front();
	const T& front() const;
	const T& back() const;
	void erase(int const pos);
	void erase(List_iterator<T>& itr);
	bool isEmpty() const;
	unsigned size() const;

	typedef List_iterator<T> iterator;
	//friend class iterator;
	iterator begin() const;
	iterator end() const;
private:
	Node<T>* head;
	Node<T>* tail;
	unsigned m_size;
};

//Def Ctor
template <class T>
SingleList<T>::SingleList():head(new Node<T>()), tail(head),m_size(0) {

}

//Copy Ctor
template <class T>
SingleList<T>::SingleList(const SingleList<T>& obj) {
	if (!m_size) {
		//this->head = new Node<T>(obj.val);
		Node<T>* temp = new Node<T>();
		head = temp;
		Node<T>* tempObj = new Node<T>();
		tempObj = obj.head;
		for(int i = 0; i < m_size; ++i)
			temp = new Node<T>(tempObj->val,tempObj->next);
		tail = temp;
	}
}

template <class T>
SingleList<T>::SingleList(SingleList<T>&& obj) {
	head = std::move(obj.head);
	tail = std::move(obj.tail);
	m_size = std::move(obj.m_size);

	return *this;
}

//Dtor
template <class T>
SingleList<T>::~SingleList() {
	if (head != nullptr) {
		delete head;
		head = nullptr;
	}
}

//initializer_list<T>
template <class T>
SingleList<T>::SingleList(const std::initializer_list<T>& obj) :head(new Node<T>()), tail(head) {

	const T* ptr = obj.begin();
	head = tail = new Node<T>(*ptr);
	
	m_size = obj.size();

	for (int i = 1; i < obj.size(); ++i) 
		tail = tail->next = new Node<T>(*++ptr);
}

//copy operator=
template <class T>
SingleList<T>& SingleList<T>::operator=(const SingleList<T>& obj) {
	if (&obj == this)
		return *this;
	Node<T>* temp = obj.head;
	push_front(temp);
	for (int i = 1; i < obj.m_m_size; ++i)
		push_back(temp = temp->next);
	return *this;
}

//move operator=
template <class T>
SingleList<T>& SingleList<T>::operator=(SingleList<T>&& obj) {
	
}

//operator==
template <class T>
bool SingleList<T>::operator==(const SingleList<T>& obj) const {
	if (this->m_size != obj.m_size)
		return false;
	Node<T>* temp1 = head;
	Node<T>* temp2 = obj.head;

	if (temp1->val != temp2->val)
		return false;

	for (int i = 1; i < m_size; ++i) {
		temp1 = temp1->next;
		temp2 = temp2->next;
		if (temp1->val != temp2->val)
			return false;
	}
	return true;
}

//operator!=
template <class T>
bool SingleList<T>::operator!=(const SingleList<T>& obj) const {
	if (this->m_size != obj.m_size)
		return true;
	Node<T>* temp1 = head;
	Node<T>* temp2 = obj.head;

	if (temp1->val != temp2->val)
		return true;

	for (int i = 0; i < m_size; ++i) {
		temp1 = temp1->next;
		temp2 = temp2->next;
		if (temp1->val != temp2->val)
			return true;
	}
	return false;
}

//find element in list
template<class T>
bool SingleList<T>::find(T const& val) {
	Node<T>* temp = head;
	
	for (int i = 0; i < size; ++i) {
		if (temp->val == val)
			return true;
		temp = temp->next;
	}
	return false;
}

//insert( iterator, val)
template<class T>
void SingleList<T>::insert(List_iterator<T>&  itr, T const& val) {
	if (m_size == 0) {
		itr.current_node->val = val;
		++m_size;
		return;
	}
	if (itr.current_node == tail) 
		tail = itr.current_node->next = new Node<T>(val, itr.current_node->next);
	else
		itr.current_node->next = new Node<T>(val, itr.current_node->next);
	
	++m_size;
}



//Insert(pos,val)
template <class T>
void SingleList<T>::insert(int const pos, T const& val) {
	
	if (pos < 1)
	{
		std::cout << "position failed, set true pos" << std::endl;
		return;
	}
	if (pos == 1) {
		push_front(val);
		return;
	}
	if (pos == m_size + 1) {
		push_back(val);
		return;
	}
	if (pos > m_size) {
		std::cout << "position failed, set true pos" << std::endl;
		return;
	}
	
		Node<T>* temp_n = new Node<T>();
		Node<T>* temp_p = new Node<T>();

		temp_n = head;
		//temp_p = head;

		for (int i = 1; i < pos; ++i) {
			temp_p = temp_n;
			temp_n = temp_n->next;
		}
		temp_p->next = new Node<T>(val,temp_n);

		++m_size;
		temp_n = nullptr;
		temp_p = nullptr;
}

//push back
template <class T>
void SingleList<T>::push_back(T const& val) {
	if (m_size == 0) 
		tail->val = val;
	else
		tail = tail->next = new Node<T>(val);
	++m_size;
}

//push front
template <class T>
void SingleList<T>::push_front(T const& val) {
	if (m_size == 0) 
		head->val = val;
	else
		head = new Node<T>(val, head);
	++m_size;
}

//pop back
template <class T>
void SingleList<T>::pop_back() {

	Node<T>* temp = tail;
		if (m_size == 0)
			return;
		else if (m_size == 1)
			tail = nullptr;
		else {
			Node<T>* temp = new Node<T>();
			temp = head;
			for(int i = 1; i < m_size-1; ++i)	
				temp = temp->next;
			tail = temp;
			tail->next = nullptr;
		}
		delete temp;
		temp = nullptr;
		--m_size;
}

//pop front
template <class T>
void SingleList<T>::pop_front(){
	Node<T>* temp = head;
	if (m_size == 0)
		return;
	else if (m_size == 1)
		head = nullptr;
	else
		head = head->next;
	delete temp;
	temp = nullptr;
	--m_size;
}

//front retrn first element
template <class T>
const T& SingleList<T>::front() const {
	return head->val;
}

//back return last element
template <class T>
const T& SingleList<T>::back() const {
	return tail->val;
}

//erase(pos)
template <class T>
void SingleList<T>::erase(int const pos) {
	if (pos < 1)
	{
		std::cout << "position failed, set true pos" << std::endl;
		return;
	}
	if (pos == 1) {
		pop_front();
		return;
	}
	if (pos == m_size + 1) {
		pop_back();
		return;
	}
	if (pos > m_size) {
		std::cout << "position failed, set true pos" << std::endl;
		return;
	}

	Node<T>* temp = new Node<T>();

	temp = head;

	for (int i = 1; i < pos-1; ++i) 
		temp = temp->next;
	
	Node<T>* temp1 = new Node<T>();
	temp1 = temp->next;

	temp->next = temp->next->next;

	--m_size;
	delete temp1;
	temp1 = nullptr;
}

//erase (iterator )
template<class T>
void SingleList<T>::erase(List_iterator<T>& itr) {
	if (!m_size)
		return;

	if (head == itr.current_node) {
		head = head->next;
		--m_size;
		return;
	}


	Node<T>* temp = head;

	temp = head;

	int size = m_size;
	while (temp->next != itr.current_node && size--) 
		temp = temp->next;
	if (size == 0)
		return;
		
	Node<T>* temp_current = itr.current_node;
	temp->next = temp->next->next;
	itr.current_node = temp;
	--m_size;
	delete temp_current;
	temp_current = nullptr;
}

//IsEmpty()
template <class T>
bool SingleList<T>::isEmpty() const {
	if (m_size)
		return true;
	return false;
}

//return m_size()
template <class T>
unsigned SingleList<T>::size() const {
	return m_size;
}

//function iterator begin()
template<class T>
typename SingleList<T>::iterator SingleList<T>::begin() const {
	return iterator(head);
}

//function iterator end()
template<class T>
typename SingleList<T>::iterator SingleList<T>::end() const {
	return iterator(tail->next);
}