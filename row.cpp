#include "row.hpp"

Row::Row(int length):
	length_(length)
{

}

void Row::insertBlock(std::vector<Block>& tempVBlock, Block& block){
	int size = 0;	// tamaño actual del muro
	for(std::iterator it = tempVBlock.begin(); it != tempVBlock.end(); it++)
		size += it->getLength();

	if(size + block.getLength() > length_)	// nos pasamos de tamaño
		return;	// no se inserta y salimos desde aquí
	else if(size == length_)
		vectorBlock_.push_back(tempVBlock);	// es una fila posible la añadimos al vector
											// de filas posibles
	else if(size < length_){	// El tamaño es menor que el muro, faltan ladrillos
		tempVBlock.push_back(block);
		insertBlock(tempVBlock, Block(3, 1));
		insertBlock(tempVBlock, Block(2, 1));
	}
	tempVBlock.pop_back();	// sacamos el elemento
}



void Row::obtainAllRows(void){
	std::vector<Block> tempVBlock;
	insertBlock(tempVBlock, Block(3, 1));
	insertBlock(tempVBlock, Block(2, 1));
}