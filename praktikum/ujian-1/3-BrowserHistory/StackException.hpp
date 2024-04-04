#ifndef SEXCEPTION_HPP
#define SEXCEPTION_HPP

#include <exception>
using namespace std;

class HistoryBackStackEmptyException : public exception  {
	const char* what() const throw() {
		return "Stack history back kosong";
	}
};

class HistoryForwardStackEmptyException : public exception  {
	const char* what() const throw() {
		return "Stack history forward kosong";
	}
};

class IndexNotValidException : public exception  {
	const char* what() const throw() {
		return "Indeks pada stack tidak valid";
	}
};
#endif