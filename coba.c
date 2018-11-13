#include <stdio.h>
#include "engis.h"
#include "matriks.h"

int main() {

	MATRIKS M;

	MakeMATRIKS(8,8, &M);

	Loadku(&M, 3);
	PrintDenah(&M);
	return 0;

	
}