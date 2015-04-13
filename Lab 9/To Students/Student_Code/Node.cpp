/*
 * Node.cpp
 *
 *  Created on: Apr 12, 2015
 *      Author: Jason
 */

#include "Node.h"

namespace std {

Node::Node() {
	parent = NULL;
	rightChild = NULL;
	leftChild = NULL;
	data = 0;
	height = 0;
	balance = 0;

}

Node::Node(Node* parent, int data_in) {
	this->parent = parent;
	this->data = data_in;
	rightChild = NULL;
	leftChild = NULL;
	height = 0;
	balance = 0;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

void Node::calculateBalance() {
	int leftHeight = 0, rightHeight = 0;
	if(leftChild != NULL){
		leftHeight = leftChild->getHeight();
	}
	if(rightChild != NULL){
		rightHeight = rightChild->getHeight();
	}
	balance = rightHeight - leftHeight;
}

void Node::calculateHeight() {
	int leftHeight = 0, rightHeight = 0;
	if (leftChild != NULL) {
		leftHeight = leftChild->getHeight();
	}
	if (this->rightChild != NULL) {
		rightHeight = rightChild->getHeight();
	}

	if (rightHeight >= leftHeight) {
		height = rightHeight + 1;
	} else {
		height = leftHeight + 1;
	}
}

int Node::getBalance() {
	calculateBalance();
	return balance;
}

int Node::getHeight() {
	calculateHeight();
	return height;
}

int Node::getData() {
	return data;
}

Node* Node::getLeftChild() {
	return leftChild;
}

Node* Node::getRightChild() {
	return rightChild;
}

Node* Node::getParent() {
	return parent;
}

void Node::setData(int data_in) {
	data = data_in;
}

void Node::setLeftChild(Node* node_in) {
	leftChild = node_in;
}

void Node::setRightChild(Node* node_in) {
	rightChild = node_in;
}

void Node::setParent(Node* node_in) {
	parent = node_in;
}

} /* namespace std */
