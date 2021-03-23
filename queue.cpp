#include "queue.h"

struct Node {
  int key;
  Node* next;
};



Queue::Queue() {  

    this->front_ = this->back_ = new Node{0, nullptr};   
    this->count_ = 0; 
}


void Queue::push(int k) {

    this->back_->next = new Node{k, nullptr};
    this->back_ = this->back_->next;
    ++(this->count_);
}


void Queue::pop() {

    if( !this->count_) throw EmptyException();

    Node* aux = this->front_;
    this->front_ = this->front_->next;
    delete(aux);
    --(this->count_);
}


int Queue::front() const {

    if( !this->count_) throw EmptyException();

    return this->front_->next->key;
}


int Queue::back() const {

    if( !this->count_) throw EmptyException();  

    return this->back_->key;
}


int Queue::count() const {

  return this->count_;
}
