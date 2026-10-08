#pragma once
#include <iostream>
#include "Node.h"
#include "List.h"

template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr), size_(0) {}

    void addFront(T* value) override {
        Node<T>* node = new Node<T>(value);
        node->next = head_;
        head_ = node;
        size_++;
    }

    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }

        Node<T>* old = head_;
        head_ = head_->next;
        delete old->data;
        delete old;
        size_--;
    }

    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void addAnywhere(int position, T* value) override {
        if (position < 0 || position > size_) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
        if (position == 0) {
            addFront(value);
            return;
        }

        Node<T>* current = head_;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }

        Node<T>* node = new Node<T>(value);
        node->next = current->next;
        current->next = node;
        size_++;
    }

    void deleteAnywhere(int position) override {
        if (position < 0 || position >= size_) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
        if (position == 0) {
            deleteFront();
            return;
        }

        Node<T>* current = head_;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }

        Node<T>* old = current->next;
        current->next = old->next;
        delete old->data;
        delete old;
        size_--;
    }

    void reverse() override {
        Node<T>* previous = nullptr;
        Node<T>* current = head_;

        while (current != nullptr) {
            Node<T>* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head_ = previous;
    }

    void concat(List<T>* other) override {
        LinkedList<T>* second = dynamic_cast<LinkedList<T>*>(other);
        if (second == nullptr) {
            std::cout << "List types do not match." << std::endl;
            return;
        }
        if (second->head_ == nullptr) {
            return;
        }

        if (head_ == nullptr) {
            head_ = second->head_;
        } else {
            Node<T>* current = head_;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = second->head_;
        }

        size_ += second->size_;
        second->head_ = nullptr;
        second->size_ = 0;
    }

    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* old = head_;
            head_ = head_->next;
            delete old->data;
            delete old;
        }
    }

private:
    Node<T>* head_;
    int size_;
};