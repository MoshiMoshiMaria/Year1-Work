#include <iostream>
#include "Student.h"

int main()
{
	Student banan(2, "Sanjay", 12);
	banan.coutAttr();
	system("pause");
	banan.setId(12);
	banan.setName("roblox");
	banan.setAge(18);
	banan.coutAttr();
	system("pause");
	
	return 0;
}