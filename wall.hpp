#ifndef WALL_H_
#define WALL_H_

#include <vector>
#include "block.hpp"
#include "row.hpp"
#include <ostream>

typedef std::vector<Block> row_T;
typedef std::vector<row_T> vRows_T;
typedef std::vector<vRows_T> vWalls_T;

class Wall{
private:
	int length_;
	int high_;
	vRows_T allRows_;	// todas las filas posibles
	vWalls_T allWalls_;	// vector de todos los muros posibles
	void obtainAllWalls(int);
	void insertRowInWall(vRows_T&, int);
	bool checkJoints(vRows_T&, int);	// un muro y la altura
public:
	Wall(int, int);	// anchura x altura
	void obtainAllWalls(void);
	std::ostream& showWalls(std::ostream&);
	void showRow(row_T&);
};

#endif	// WALL_H_