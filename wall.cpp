#include "wall.hpp"

typedef std::vector<Block> row_T;
typedef std::vector<row_T> vRows_T;

Wall::Wall(int length, int high):
	length_(length),
	high_(high)
{
	Row A(length_);
	allRows_ = A.obtainAllRows();
}
// allWalls_ es un vector de muros, o sea muro[i]; i = 0, 1, 2, 3...
void Wall::insertRowInWall(vRows_T& tempWall, int level){
	if(level <= high)
		for(int i = 0; i < allRows_.size(); i++){
			tempWall.push_back(allRows_[i]);
			if(checkJoints(tempWall, level))	// compruebo que no hay empates
				allWalls_.pop_back();	// no es una buena fila
			if(level + 1 <= high_)	// si el siguiente nivel sigue en el límite
				insertRowInWall(level + 1);	// a hacer otro muro
		}
	if (level == high)	// llegamos al final
		allWalls_.push_back(tempWall)
}

// tempWall es un vector de filas, o sea *un* muro
void Wall::obtainAllWalls(void){
	vRows_T tempWall;
	for(int i = 0; i < allRows_.size(); i++){
		insertRowInWall(tempWall, 1);
	}
}

bool Wall::checkJoints(vRows_T& tempWall, int level){
	if(level == 1)
		return false;
	
	int accumulator1 = 0, accumulator2;

	for(int i=0; i<tempWall[level - 1].size(); i++){	//
		accumulator2 = 0;
		accumulator1 = tempWall[level - 1][i].getLength();
		for(int j=0; j<tempWall[level - 2].size(); j++){x
			accumulator2 += tempWall[level - 2][j].getLength();
			if(accumulator1 == accumulator2)
				return true;
		}
	}

	return false;
}