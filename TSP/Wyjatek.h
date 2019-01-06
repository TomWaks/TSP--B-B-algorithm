#include <iostream>
#include <exception>

using namespace std;

class Wyjatek: public exception{
    string error;
public:
	Wyjatek(string err="brak")
	{
       error = err;
	}

	virtual ~Wyjatek() throw() {} // destruktor nie rzuci zadnego wyjatku

    const char* what()  const throw()
    {
        return error.c_str(); // konwert na ciag znakow
    }
};
