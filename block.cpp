#include "block.hpp"

Block::Block(int width, int height):
	high_(height),
	length_(width)
{}

Block::~Block(){
  //std::cout << "destroy" << std::endl;
}

Block::Block(const Block& b){
	length_ = b.length_;
	high_ = b.high_;
}

int Block::getLength(void){
	return length_;
}

bool Block::operator<(const Block& B){
	return length_ < B.length_;
}

const char* Block::showBlock(void){
	  for(int i=0; i<length_; i++)
	    stringBlock_.push_back('X');
	  return stringBlock_.c_str();
}