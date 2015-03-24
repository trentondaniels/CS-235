/*
 * BST.cpp
 *
 *  Created on: Mar 23, 2015
 *      Author: Jason
 */

#include "BST.h"

namespace std {

BST::BST() {
	size = 0;
	rootNode = NULL;
}

bool BST::add(int data) {
	if (size == 0) {
		rootNode = new Node(NULL, data);
		size = 1;
		return true;
	} else {
		return insert(data, rootNode);
	}
}

NodeInterface* BST::getRootNode() {
	return rootNode;
}

void BST::deleteChild(Node* currentNode) {
	if (currentNode->getParent() != NULL) {
		if (currentNode == currentNode->getParent()->getLeftChild()) {
			currentNode->getParent()->setLeftChild(NULL);
		} else if (currentNode == currentNode->getParent()->getRightChild()) {
			currentNode->getParent()->setRightChild(NULL);
		}else{
			//cout << "Error with parent/child pointer";
		}
	}
	delete currentNode;
	size--;
	if (size == 0) {
		rootNode = NULL;
	}
}

void BST::replaceParent(Node* currentNode, Node* childNode) {
	if (childNode != NULL) {
		childNode->setParent(currentNode->getParent());
	}
}

bool BST::insert(int data_in, Node* currentNode) {

	////cout << "Adding "<< data_in << " to the tree" << endl;
	if (currentNode->getData() == data_in) {
		return false;
	} else if (data_in < currentNode->getData()) {
		if (currentNode->getLeftChild() == NULL) {
			currentNode->setLeftChild(new Node(currentNode, data_in));
			size++;
			return true;
		} else {
			return insert(data_in, currentNode->getLeftChild());
		}
	} else if (data_in > currentNode->getData()) {
		if (currentNode->getRightChild() == NULL) {
			currentNode->setRightChild(new Node(currentNode, data_in));
			size++;
			return true;
		} else {
			return insert(data_in, currentNode->getRightChild());
		}
	} else {
		return false;
	}
}

bool BST::remove(int data) {
	//cout << "Removing: " << data << "...";
	if (rootNode == NULL) {
		//cout << "Root is NULL. Returng false" << endl;
		return false;
	} else {
		return removeFromNode(data, rootNode);
	}
}

bool BST::removeFromNode(int data_in, Node* currentNode) {
	if (data_in == currentNode->getData()) {
		//cout << "Member:" << data_in << " found...";
		if (currentNode->getLeftChild() == NULL
				&& currentNode->getRightChild() == NULL) {
			//cout << "Member:" << data_in << " has no children. Deleteing...";
			deleteChild(currentNode);
			return true;
		} else if (currentNode->getLeftChild() == NULL
				&& currentNode->getRightChild() != NULL) {
			if (currentNode->getParent() != NULL) {
				if (currentNode == currentNode->getParent()->getLeftChild()) {
					currentNode->getParent()->setLeftChild(
							currentNode->getRightChild());
				} else {
					currentNode->getParent()->setRightChild(
							currentNode->getRightChild());
				}
			}
			currentNode->getRightChild()->setParent(currentNode->getParent());
			if(rootNode == currentNode){
							rootNode = currentNode->getRightChild();
						}
			delete currentNode;
			size--;
			return true;
		} else if (currentNode->getLeftChild() != NULL
				&& currentNode->getRightChild() == NULL) {
			if (currentNode->getParent() != NULL) {
				if (currentNode == currentNode->getParent()->getLeftChild()) {
					currentNode->getParent()->setLeftChild(
							currentNode->getLeftChild());
				} else {
					currentNode->getParent()->setRightChild(
							currentNode->getLeftChild());
				}
			}
			currentNode->getLeftChild()->setParent(currentNode->getParent());
			if(rootNode == currentNode){
				rootNode = currentNode->getLeftChild();
			}
			delete currentNode;
			size--;
			return true;
		} else {
			Node* temp = currentNode->getLeftChild();
			int depth = 0;
			while (temp->getRightChild() != NULL) {
				temp = temp->getRightChild();
				depth += 1;
			}
			currentNode->setData(temp->getData());
			if (temp->getLeftChild() != NULL) {
				temp->getLeftChild()->setParent(temp->getParent());
				if (depth > 0) {
					temp->getParent()->setRightChild(temp->getLeftChild());
				} else {
					temp->getParent()->setLeftChild(temp->getLeftChild());
				}

			} else {
				if (depth > 0) {
					temp->getParent()->setRightChild(NULL);
				} else {
					temp->getParent()->setLeftChild(NULL);
				}
			}
			delete temp;
			size--;
			return true;
		}
	} else if (data_in < currentNode->getData()) {
		//cout << " L ";
		return removeFromNode(data_in, currentNode->getLeftChild());
	} else if (data_in > currentNode->getData()) {
		//cout << " R ";
		return removeFromNode(data_in, currentNode->getRightChild());
	} else {
		//cout << "Unkonwn Error" << endl;
		return false;
	}
}

void BST::clearNode(Node* currentNode) {
	if (currentNode != NULL) {
		clearNode(currentNode->getLeftChild());
		clearNode(currentNode->getRightChild());
		delete currentNode;
		size--;
	}
}

void BST::clear() {
	//cout << "Clearing tree...";
	clearNode(rootNode);
	rootNode = NULL;
	//cout << "Size = " << size << endl;
}

BST::~BST() {
	clear();
}

} /* namespace std */
