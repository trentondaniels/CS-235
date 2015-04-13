/*
 * AVL.cpp
 *
 *  Created on: Apr 12, 2015
 *      Author: Jason
 */

#include "AVL.h"

namespace std {

AVL::AVL() {
	size = 0;

}

AVL::~AVL() {
	// TODO Auto-generated destructor stub
}

NodeInterface *AVL::getRootNode() {
	return rootNode;
}

bool AVL::insert(int data_in, Node* currentNode) {
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

void AVL::balanceNode(Node* currentNode) {

}

bool AVL::add(int data) {
	if (size == 0) {
		rootNode = new Node(NULL, data);
		size = 1;
		return true;
	} else {
		if (insert(data, rootNode)) {
			if (isBalanced(rootNode)) {
				return true;
			}
			balanceNode(rootNode);
			return true;
		} else {
			return false;
		}
	}
}

void AVL::deleteChild(Node* currentNode) {
	if (currentNode->getParent() != NULL) {
		if (currentNode == currentNode->getParent()->getLeftChild()) {
			currentNode->getParent()->setLeftChild(NULL);
		} else if (currentNode == currentNode->getParent()->getRightChild()) {
			currentNode->getParent()->setRightChild(NULL);
		} else {
			//cout << "Error with parent/child pointer";
		}
	}
	delete currentNode;
	size--;
	if (size == 0) {
		rootNode = NULL;
	}
}

bool AVL::remove(int data) {
	if (rootNode == NULL) {
		return false;
	} else {
		if (removeFromNode(data, rootNode)) {
			if (isBalanced(rootNode)) {
				return true;
			}
			balanceNode(rootNode);
			return true;
		} else {
			return false;
		}
	}
}

bool AVL::removeFromNode(int data_in, Node* currentNode) {
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
			if (rootNode == currentNode) {
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
			if (rootNode == currentNode) {
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

bool AVL::isBalanced(Node* currentNode) {
	if (currentNode->getLeftChild() != NULL
			&& currentNode->getRightChild() != NULL) {
		return (isBalanced(currentNode->getLeftChild())
				&& isBalanced(currentNode->getRightChild()));
	} else if (currentNode->getLeftChild() == NULL
			&& currentNode->getRightChild() == NULL) {
		return true;
	} else {
		return false;
	}
}

void AVL::clearNode(Node* currentNode) {
	if (currentNode != NULL) {
		clearNode(currentNode->getLeftChild());
		clearNode(currentNode->getRightChild());
		delete currentNode;
		size--;
	}
}

void AVL::clear() {
	clearNode(rootNode);
	rootNode = NULL;
}

} /* namespace std */
