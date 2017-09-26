#ifndef ROW_H_
#define ROW_H_

#include <vector>
#include <set>
#include <ostream>
#include "block.hpp"

typedef std::vector<Block> row_T;
typedef std::vector<row_T> vRows_T;

class Row{
private:
	int length_;
	vRows_T	vectorBlock_;
	int obtSize(row_T&);
public:
	Row(int);	// max of length
	const vRows_T obtainAllRows(void);
	void insertBlock(row_T&, Block&);
	void showRows(void);
};

#endif	// ROW_H_