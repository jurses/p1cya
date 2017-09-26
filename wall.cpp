#include "wall.hpp"
#include <iostream>

typedef std::vector<Block> row_T;
typedef std::vector<row_T> vRows_T;
typedef std::vector<vRows_T> vWalls_T;

Wall::Wall(int length, int high):
	length_(length),
	high_(high)
{
	Row A(length_);
	A.showRows();
	allRows_ = A.obtainAllRows();
	//A.showRows();
}
// allWalls_ es un vector de muros, o sea muro[i]; i = 0, 1, 2, 3...
void Wall::insertRowInWall(vRows_T& tempWall, int level){
	for(vRows_T::iterator it = allRows_.begin(); it != allRows_.end(); it++){
		std::cout << "Añadimos otra fila al muro de tamaño " << tempWall.size() << std::endl;
		showRow(*it);
		tempWall.push_back(*it);	// metemos un muro
		if(checkJoints(tempWall, level)){	// comprobamos
			tempWall.pop_back();	// si está mal lo quitamos
			std::cout << "Fila Mala, se quita" << std::endl;
		}
		else{
			if(tempWall.size() == high_){	// tiene la altura correcta
				allWalls_.push_back(tempWall);	// lo añadimos al vector de muros allWalls_
				std::cout << "Muro bueno +1" << std::endl;
			}
			else if(tempWall.size() < high_){	// es pequeño aún, se le puede poner otra fila
				std::cout << "Muro pequeño" << std::endl;
				insertRowInWall(tempWall, level + 1);	// mandamos a otra fila
			}
			
			if(!tempWall.empty()){	// si no está vacío
				std::cout << "Quitamos" << std::endl;
				showRow(tempWall.front());
				tempWall.pop_back();	// quitar el que pusimos
			}
		}
	}
}

// tempWall es un vector de filas, o sea *un* muro
void Wall::obtainAllWalls(void){
	vRows_T tempWall;
	insertRowInWall(tempWall, 1);
}

bool Wall::checkJoints(vRows_T& tempWall, int level){
	if(level == 1)
		return false;

	int acumulator1 = 0, acumulator2 = 0;

	for(int i = 0; i < tempWall[level - 1].size(); i++){
		acumulator1 += tempWall[level - 1][i].getLength();
		acumulator2 = 0;
		for(int j = 0; j < tempWall[level - 2].size(); j++){
			acumulator2 += tempWall[level - 2][j].getLength();
			if(acumulator1 == acumulator2 && (acumulator1 != length_ || acumulator2 != length_))	// comprobamos que el empate no coincida y no sea el del final
				return true;
		}
	}


	return false;
}

std::ostream& Wall::showWalls(std::ostream& os){
	for(vWalls_T::iterator it1 = allWalls_.begin(); it1 != allWalls_.end() ; it1++){	// vector de muro = muros
		os << std::endl;
		os << "__________Siguiente muro____" << std::endl;
		for(vRows_T::iterator it2 = it1->begin(); it2 != it1->end(); it2++){	// vector de fila = muro
			for(row_T::iterator it3 = it2->begin(); it3 != it2->end(); it3++){	// vector bloques	= fila
				os << it3->showBlock() << '|';
			}
		}
	}
	return os;
}

void Wall::showRow(row_T& row){
	for(row_T::iterator it2 = row.begin(); it2 != row.end(); it2++)
		std::cout << it2->getLength() << " ";
	
	std::cout << std::endl;
}