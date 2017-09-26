#include <iostream>
#include "wall.hpp"

int main(void){
	Wall A(14, 10);
	A.obtainAllWalls();
	A.showWalls(std::cout);
	std::cout << std::endl;
}