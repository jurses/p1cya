# ifndef BLOCK_H_
# define BLOCK_H_

class Block{
private:
	int length_;
	int high_;
public:
	Block(int, int);	// recibe el ancho y la altura
	Block(const Block&);	// constructor de copia
	int getLength(void);	// recibe el ancho del bloque
	bool operator <(const Block&);	
};

#endif	// BLOCK_H_