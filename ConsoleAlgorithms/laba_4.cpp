#include "laba_4.h"










void l4task1()
{

	list<std::string> str;
	str.start = new leaf<std::string>("str1");

	str.pushBack("str2");
	str.pushPtr(str.start, "str2.1");
	str.print();
	delete str.emplase(str.start);
	str.print();





}



























