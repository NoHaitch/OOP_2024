#include "Hewan.h"

int main() {
	Hewan *array_hewan[3];
	Hewan a("a");
	Kucing b("b");
	Anjing c("c");
	array_hewan[0] = &a;
	array_hewan[1] = &b;
	array_hewan[2] = &c;
	
	for(int i=0;i<3;i++) {
		array_hewan[i]->print(); //Keluaran = "[Makhluk] ini namanya [nama]\n"
	}
	array_hewan[1] = &c;
	array_hewan[1]->print();
	Kucing *d = new KucingAnggora("d","1");
	Anjing *e = new AnjingBulldog("e","2");;
	d->print();
	e->print();
	KucingAnggora f("f","3");
	AnjingBulldog g("g","4");
	f.print();
	g.print();
	delete e;
	delete d;
	return 0;
}


/*
Hewan ini namanya a{dari fungsi print}
Hewan ini namanya b{dari fungsi print}
Anjing ini namanya c{dari fungsi print}
Anjing ini namanya c{dari fungsi print}
Kucing anggora ini namanya d. Pemiliknya adalah 1{dari fungsi print}
Anjing bulldog ini namanya e. Pemiliknya adalah 2{dari fungsi print}
Kucing anggora ini namanya f. Pemiliknya adalah 3{dari fungsi print}
Anjing bulldog ini namanya g. Pemiliknya adalah 4{dari fungsi print}
Anjing mati e{dari destructor}
Hewan mati e{dari destructor}
Kucing anggora mati d{dari destructor}
Kucing mati d{dari destructor}
Hewan mati d{dari destructor}
Anjing bulldog mati g{dari destructor}
Anjing mati g{dari destructor}
Hewan mati g{dari destructor}
Kucing anggora mati f{dari destructor}
Kucing mati f{dari destructor}
Hewan mati f{dari destructor}
Anjing mati c{dari destructor}
Hewan mati c{dari destructor}
Kucing mati b{dari destructor}
Hewan mati b{dari destructor}
Hewan mati a{dari destructor}
*/