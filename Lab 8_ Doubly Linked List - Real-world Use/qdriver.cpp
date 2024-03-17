#include "q.h"
int main()
{
	hlp2::finder testee("search-space.txt");

	testee.find("The Top Ten Scientific Problems with Biological and Chemical Evolution");
	testee.print();

	testee.find("IDEA Centre website");
	testee.print();

	testee.find("deoxyribonucleic acid");
	testee.print();

	testee.find("evolution is dead");
	testee.print();

	testee.find("Origin-of-life");
	testee.print();

	testee.find("primordial soup");
	testee.find("dna");
	testee.print();
}