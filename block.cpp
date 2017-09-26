#include "block.hpp"

Block::Block(int width, int height):
	high_(height),
	length_(width)
{
	int i=0;
	for(; i<length_; i++)
		stringBlock_[i] = 'X';

	stringBlock_[i] = '\0';
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
	return stringBlock_;
}