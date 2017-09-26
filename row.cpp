#include "row.hpp"

typedef std::vector<Block> row_T;

Row::Row(int length):
	length_(length)
{

}

Row::Row(const Row& row){
  length_ = row.length_;
  vectorBlock_ = row.vectorBlock_;
}

void Row::insertBlock(row_T& tempVBlock, const Block& block){
	tempVBlock.push_back(block);
	if(obtSize(tempVBlock) < length_){
		Block A(3, 1);
		Block B(2, 1);
		insertBlock(tempVBlock, A);
		insertBlock(tempVBlock, B);
	}
	else if(obtSize(tempVBlock) == length_)
		vectorBlock_.push_back(tempVBlock);
	tempVBlock.pop_back();
}

const vRows_T Row::obtainAllRows(void){
	std::vector<Block> tempVBlock;
	Block A(3, 1);
	Block B(2, 1);
	insertBlock(tempVBlock, A);
	insertBlock(tempVBlock, B);
	tempVBlock.clear();
	std::cout << vectorBlock_.size() << std::endl;
	return vectorBlock_;
}

int Row::obtSize(row_T& row){
	int size = 0;	// tamaño actual del muro
	for(row_T::iterator it = row.begin(); it != row.end(); it++)
		size += it->getLength();
	
	return size;
}

void Row::showRows(void){
	std::cout << "Filas: " << std::endl;
	for(vRows_T::iterator it1 = vectorBlock_.begin(); it1 != vectorBlock_.end(); it1++){
		std::cout << std::endl;
		for(row_T::iterator it2 = it1->begin(); it2 != it1->end(); it2++)
			std::cout << it2->getLength() << " ";
	}
	std::cout << std::endl;
}

