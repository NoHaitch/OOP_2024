// hewan.h
#include <iostream>

using namespace std;

#ifndef HEWAN_H
#define HEWAN_H

class Hewan {
    protected: 
        string name;
    public:
        Hewan(string nm) : name(nm) {}
        ~Hewan() { 
            cout << "Hewan mati " << name << endl;
            }
        virtual void print() {
            cout << "Hewan ini namanya " << name << endl;
        }
};

class Kucing : public Hewan {
    public:
        Kucing(string nm) : Hewan(nm) {};
        virtual ~Kucing() {
            cout << "Kucing mati " << name << endl;
        }
};

class Anjing : public Hewan {
    public:
        Anjing(string nm) : Hewan(nm) {};
        ~Anjing() {
            cout << "Anjing mati " << name << endl;
        }
        void print() {
            cout << "Anjing ini namanya " << name << endl;
        }
};

class KucingAnggora : public Kucing {
	protected:
		string pemilik;
    public:
		KucingAnggora(string nm, string milik) : Kucing(nm), pemilik(milik) {}
        ~KucingAnggora() {
            cout << "Kucing anggora mati " << name << endl;
        }
		void print() {
            cout << "Kucing anggora ini namanya " << name << ". Pemiliknya adalah " << pemilik << endl;
        }
};

class AnjingBulldog : public Anjing {
	protected:
		string pemilik;
    public:
		AnjingBulldog(string nm, string milik) : Anjing(nm), pemilik(milik) {}
        ~AnjingBulldog() {
            cout << "Anjing bulldog mati " << name << endl;
        }
        void print() {
            cout << "Anjing bulldog ini namanya " << name << ". Pemiliknya adalah " << pemilik << endl;
        }
};

#endif