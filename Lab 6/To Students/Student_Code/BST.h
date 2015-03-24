/*
 * BST.h
 *
 *  Created on: Mar 23, 2015
 *      Author: Jason
 */

#ifndef TO_STUDENTS_STUDENT_CODE_BST_H_
#define TO_STUDENTS_STUDENT_CODE_BST_H_

#include "BSTInterface.h"
#include "Node.h"

namespace std {

class BST: public BSTInterface {
public:
	BST();
	virtual ~BST();

	NodeInterface * getRootNode();
	bool add(int data);
	bool remove(int data);
	void clear();

	bool insert(int data_in, Node* currentNode);
	bool removeFromNode(int data_in, Node* currentNode);
	void replaceParent(Node* currentNode, Node* childNode);
	void clearNode(Node* currentNode);
	void deleteChild(Node* currentNode);

private:
	Node *rootNode;
	int size;
};

} /* namespace std */

#endif /* TO_STUDENTS_STUDENT_CODE_BST_H_ */
