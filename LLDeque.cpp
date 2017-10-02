#include "LLDeque.h"

// initializes an empty deque
LLDeque::LLDeque () {
	size = 0;
	head = nullptr;
	tail = nullptr;
}

// deallocates all dynamically allocated memory
LLDeque::~LLDeque () {
	if(head != nullptr){
		while(head != nullptr){
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
}

 // append x at one end of the deque.
void LLDeque::pushback (char x){
	if(size == 0){
		Node* temp = new Node(x);
		tail = temp;
		head = temp;
		size++;
	}
	else if (size == 1){
		Node* temp = new Node(x);
		temp->prev = head;
		head->next = temp;
		tail = temp;
		size++;
	}
	else {
		Node* temp = new Node(x);
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
		size++;
	}
}

/* remove at the same end of the deque.
Does nothing if called on an empty deque. */
void LLDeque::popback () {
	if(size == 0){
		return;
	}
	else if (size == 1){
		Node* temp = head;
		head = nullptr;
		tail = nullptr;
		size--;
		delete temp;
	}
	else {
		Node* temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		size--;
		delete temp;
	}
}

/* returns the element at the same end of the deque.
Returns '\0' if called on an empty deque. */
char LLDeque::getback () {
	if(size == 0){
		return '\0';
	}
	else {
		return tail->data;
	}
}

// "prepend" x at the other end of the queue.
void LLDeque::pushfront (char x) {
	if(size == 0){
		Node* temp = new Node(x);
		head = temp;
		tail = temp;
		size++;
	}
	else if (size == 1){
		Node* temp = new Node(x);
		head = temp;
		head->next = tail;
		tail->prev = head;
		size++;
	}
	else {
		Node* temp = new Node(x);
		head->prev = temp;
		temp->next = head;
		head = temp;
		size++;
	}
}

 /* remove at the other end of the deque.
Does nothing if called on an empty deque. */
void LLDeque::popfront () {
	if(size == 0){
		return;
	}
	else if (size == 1){
		Node* temp = head;
		head = nullptr;
		tail = nullptr;
		size--;
		delete temp;
	}
	else {
		Node* temp = head;
		head = head->next;
		head->prev = nullptr;
		size--;
		delete temp;
	}
}

 /* returns the element at the other end of the deque.
Returns `\0` if called on an empty deque. */
char LLDeque::getfront() {
	if(size == 0){
		return '\0';
	}
	else {
		return head->data;
	}
}

// returns whether the deque is empty.
bool LLDeque::isempty(){
	if(size == 0){
		return true;
	}
	return false;
}