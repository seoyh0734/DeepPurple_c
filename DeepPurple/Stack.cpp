#include "Stack.h"

	Snode::Snode(char* tmp_str) {
		str = tmp_str;
	};
	Snode::Snode() {};

	char* Snode::get_str() {
		return this->str;
	};



	Snode* Snode::get_next() {
		return nextNode;
	};
	Snode* Snode::get_back() {
		return backNode;
	};
	void Snode::set_back(Snode* back) {
		backNode = back;
	};
	void Snode::set_next(Snode* next) {
		nextNode = next;
	};
	void Snode::set_str(char* tmp_str) {
		str = tmp_str;
	};

	Stack::Stack() {
		top = 0;
		last = new Snode;
	};
	void Stack::push(char* tmp) {
		last->set_str(tmp);
		Snode* tmpNode = last;
		last = last->get_next();
		last = new Snode;
		last->set_back(tmpNode);
		tmpNode->set_next(last);
		top++;
	};
	char* Stack::pop() {
		if (top == 0) {
			return "empty";
		}
		char * tmp = "asd";
		last = last->get_back();
		tmp = last->get_str();
		top--;
		delete last->get_next();
		return  tmp;
	};
	bool Stack::is_empty() {
		if (top == 0)
			return true;
		else
			return false;
	};
