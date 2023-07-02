#include "../include/ordered_linked_list.h"

OrderedLinkedList::OrderedLinkedList() {
    root = new LinkNode();
    root->val = -1;
    root->next = nullptr;
    size = 0;
}

OrderedLinkedList::~OrderedLinkedList() {
    LinkNode* currentNode = root->next;
    while(currentNode != nullptr) {
        LinkNode* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }

    delete root;
}

/**
 * @brief Adds a node with the given value to the ordered list
 *
 * @param val Value to Add
 */
void OrderedLinkedList::add(int val) {
    LinkNode* newNode = new LinkNode();
    newNode->val = val;
    newNode->next = nullptr;

    LinkNode* currentNode = root;

    while(currentNode->next != nullptr) {
        // Found ordered place for new node
        if(currentNode->next->val > newNode->val) {
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            size++;
            return;
        }

        currentNode = currentNode->next;

    }
    currentNode->next = newNode;
    size++;
}

/**
 * @brief Removes the node at the given index
 *
 * @param index Index of node to remove
 * @return false for invalid index true otherwise
 */
bool OrderedLinkedList::remove(int index) {
    if(index >= size || index < 0) {
      return false;
    }

    LinkNode* currentNode = root;

    for(int i = 0; i < index; i++) {
        currentNode = currentNode->next;
    }

    LinkNode* nodeToRemove = currentNode->next;
    currentNode->next = nodeToRemove->next;

    delete nodeToRemove;
    size--;

    return true;
}

