#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>
#include <Naming.hpp>
#include <cstdlib>
using namespace std;


class Print {
private:
	// ekrana 10 kere verilen char karakteri yazar (yazım kolaylığı için)
    static void writeTenTimes(char);
	// Karakterleri Siyah ve Beyaz olarak değiştirir (yazım kolaylığı için)
	static void swapColour(int colour, char* ust, char* alt, char* ful, char* fulbos);
public:
    // Tahtayı ekrana gösterir
	static void print(int squares[3][3]);

};

#endif // PRINT_HPP