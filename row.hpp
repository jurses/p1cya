#ifndef ROW_H_
#define ROW_H_

#include <vector>
#include <set>
#include <iterator>
#include "block.hpp"

class Row{
private:
	int length_;
	std::vector<std::vector<Block>>	vectorBlock_;
	
public:
	Row(int);	// max of length
	const std::vector<std::vector<Block>> obtainAllRows(void);
};

#endif	// ROW_H_