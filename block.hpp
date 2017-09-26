# ifndef BLOCK_H_
# define BLOCK_H_

#include <cstring>

class Block{
private:
	int length_;
	int high_;
	char stringBlock_[100];
public:
	Block(int, int);	// recibe el ancho y la altura
	Block(const Block&);	// constructor de copia
	int getLength(void);	// recibe el ancho del bloque
	bool operator <(const Block&);
	const char* showBlock(void);
};

#endif	// BLOCK_H_