/*
 * Node.h
 *
 *  Created on: Apr 12, 2015
 *      Author: Jason
 */

#ifndef TO_STUDENTS_STUDENT_CODE_NODE_H_
#define TO_STUDENTS_STUDENT_CODE_NODE_H_

#include "NodeInterface.h"

namespace std {

class Node: public NodeInterface {
public:
	Node();
	Node(Node* parent, int data_in);
	virtual ~Node();
	int getData();
	int getHeight();
	int calculateHeight();

	Node* getLeftChild();
	Node* getRightChild();
	Node* getParent();

	void setLeftChild(Node* node_in);
	void setRightChild(Node* node_in);
	void setParent(Node* node_in);
	void setData(int data_in);

private:
	int data, height;
	Node *parent, *leftChild, *rightChild;

};

} /* namespace std */

#endif /* TO_STUDENTS_STUDENT_CODE_NODE_H_ */
