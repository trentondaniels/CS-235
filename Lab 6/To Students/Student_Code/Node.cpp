/*
 * Node.cpp
 *
 *  Created on: Mar 23, 2015
 *      Author: Jason
 */

#include "Node.h"

namespace std {

Node::Node() {
	parent = NULL;
	rightChild = NULL;
	leftChild = NULL;
	data = 0;
}

Node::Node(Node* parent, int data_in) {
	this->parent = parent;
	this->data = data_in;
	rightChild = NULL;
	leftChild = NULL;
}

int Node::getData() {
	return data;
}

Node* Node::getLeftChild(){
	return leftChild;
}

Node* Node::getRightChild(){
	return rightChild;
}

Node* Node::getParent(){
	return parent;
}

void Node::setData(int data_in){
	data = data_in;
}

void Node::setLeftChild(Node* node_in){
	leftChild = node_in;
}

void Node::setRightChild(Node* node_in){
	rightChild = node_in;
}

void Node::setParent(Node* node_in){
	parent = node_in;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
