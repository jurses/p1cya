#include "block.hpp"

Block::Block(int width, int height):
	high_(height),
	length_(width)
{}

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