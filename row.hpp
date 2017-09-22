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
	void obtainAllRows(std::vector<Block>&, Block&);
public:
	Row(int);	// max of length
	void obtainAllRows(void);
};

#endif	// ROW_H_