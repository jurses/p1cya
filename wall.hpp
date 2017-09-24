#include <vector>
#include "block.hpp"
#include "row.hpp"

typedef std::vector<Block> row_T;
typedef std::vector<row_T> vRows_T;

class Wall{
private:
	int length_;
	int high_;
	vRows_T allRows_;	// todas las filas posibles
	std::vector<vRows_T> allWalls_;	// vector de todos los muros posibles
	void obtainAllWalls(int);
	bool checkJoints(vRows_T&, int);	// un muro y la altura
public:
	Wall(int, int);
	void obtainAllWalls(void);
};