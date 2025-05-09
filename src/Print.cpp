#include <Print.hpp>

void Print::writeTenTimes(char a) {
	for (int i = 1; i <= 10; i++) {
		cout << a;
    }
}

void Print::print(int Board[3][3]) { //Tahtayı ekrana gösterir

	//system("cls");

	char solustkose = 201, yatay = 205, sagustkose = 187, dikey = 186, solayrim = 204, ortaayrim = 206
		, sagayrim = 185, solaltkose = 200, sagaltkose = 188, altayrim = 202, ustayrim = 203, bosluk = 177,
		ustbeyaz = 223, altbeyaz = 220, fulbeyaz = 219;

	char ust{}, alt{}, ful{}, fulbos{};
	char* ustptr = &ust, * altptr = &alt, * fulptr = &ful, * fulbosptr = &fulbos;



	cout << "X" << yatay << yatay; // Üst Kısım
	writeTenTimes(yatay);
	writeTenTimes(yatay);
	writeTenTimes(yatay);
	cout << yatay << yatay << yatay << yatay << yatay << yatay << yatay << yatay << "X";
	cout << endl;


	cout << dikey << solustkose; //Tablonun üst çizgisi
	writeTenTimes(yatay);
	cout << ustayrim;
	writeTenTimes(yatay);
	cout << ustayrim;
	writeTenTimes(yatay);
	cout << sagustkose << "      " << dikey << endl;

	for (int j = 2; j >= 0; j--) { // Tablonun satırları

		cout << dikey;
		for (int i = 0; i <= 2; i++) { // Tablo için 1. pixel satırı
			swapColour(Board[j][i], ustptr, altptr, fulptr, fulbosptr);
			cout << dikey << bosluk << bosluk << alt << ful << ust << ust << ful << alt << bosluk << bosluk;
		}
		cout << dikey << "      " << dikey << endl;
		cout << dikey;
		for (int i = 0; i <= 2; i++) { // Tablo için 2. pixel satırı
			swapColour(Board[j][i], ustptr, altptr, fulptr, fulbosptr);
			cout << dikey << bosluk << bosluk << ful << fulbos << fulbos << fulbos << fulbos << ful << bosluk << bosluk;
		}
		cout << dikey;
		if (j == 2) { // Satır sayısı için 1. pixel satırı
			cout << "  " << altbeyaz << ustbeyaz << ustbeyaz << altbeyaz;
		}
		else if (j == 1) {
			cout << "  " << altbeyaz << ustbeyaz << ustbeyaz << altbeyaz;
		}
		else {
			cout << "   " << altbeyaz << fulbeyaz << " ";
		}
		cout << dikey << endl;
		cout << dikey;
		for (int i = 0; i <= 2; i++) { // Tablo için 3. pixel satırı
			swapColour(Board[j][i], ustptr, altptr, fulptr, fulbosptr);
			cout << dikey << bosluk << bosluk << ust << ful << fulbos << fulbos << ful << ust << bosluk << bosluk;
		}
		cout << dikey;
		if (j == 2) { // Satır sayısı için 2. pixel satırı
			cout << "    " << ustbeyaz << altbeyaz;
		}
		else if (j == 1) {
			cout << "    " << altbeyaz << ustbeyaz;
		}
		else {
			cout << "    " << fulbeyaz << " ";
		}
		cout << dikey << endl;
		cout << dikey;
		for (int i = 0; i <= 2; i++) { // Tablo için 4. pixel satırı
			swapColour(Board[j][i], ustptr, altptr, fulptr, fulbosptr);
			cout << dikey << bosluk << alt << ful << ust << fulbos << fulbos << ust << ful << alt << bosluk;
		}
		cout << dikey;
		if (j == 2) { // Satır sayısı için 3. pixel satırı
			cout << "  " << ustbeyaz << altbeyaz << altbeyaz << ustbeyaz;
		}
		else if (j == 1) {
			cout << "  " << altbeyaz << fulbeyaz << altbeyaz << altbeyaz;
		}
		else {
			cout << "   " << altbeyaz << fulbeyaz << altbeyaz;
		}
		cout << dikey << endl;
		cout << dikey;
		for (int i = 0; i <= 2; i++) { // Tablo için 5. pixel satırı
			swapColour(Board[j][i], ustptr, altptr, fulptr, fulbosptr);
			cout << dikey << bosluk << ful << alt << alt << alt << alt << alt << alt << ful << bosluk;
		}
		cout << dikey << "      " << dikey << endl;

		if (j > 0) { // Tablonun orta çizgileri
			cout << dikey << solayrim;
			writeTenTimes(yatay);
			cout << ortaayrim;
			writeTenTimes(yatay);
			cout << ortaayrim;
			writeTenTimes(yatay);
			cout << sagayrim;
		}
		else { // Tablonun alt çizgisi
			cout << dikey << solaltkose;
			writeTenTimes(yatay);
			cout << altayrim;
			writeTenTimes(yatay);
			cout << altayrim;
			writeTenTimes(yatay);
			cout << sagaltkose;
		}
		cout << "      " << dikey << endl;
	}
	cout << dikey;
	writeTenTimes(32);
	writeTenTimes(32);
	writeTenTimes(32);
	writeTenTimes(32);
	cout << dikey << endl;

	// Sütun sayıları
	cout << dikey << "    " << altbeyaz << ustbeyaz << ustbeyaz << altbeyaz << "        " << fulbeyaz << ustbeyaz
		<< ustbeyaz << altbeyaz << "       " << altbeyaz << ustbeyaz << ustbeyaz << altbeyaz << "         " << dikey << endl;
	cout << dikey << "    " << fulbeyaz << altbeyaz << altbeyaz << fulbeyaz << "        " << fulbeyaz << " " << ustbeyaz
		<< altbeyaz << "       " << fulbeyaz << "            " << dikey << endl;
	cout << dikey << "    " << fulbeyaz << "  " << fulbeyaz << "        " << fulbeyaz << altbeyaz << altbeyaz << ustbeyaz
		<< "       " << ustbeyaz << altbeyaz << altbeyaz << ustbeyaz << "         " << dikey << endl;
	cout << "X" << yatay << yatay; // Alt Kısım
	writeTenTimes(yatay); 
	writeTenTimes(yatay);
	writeTenTimes(yatay);
	cout << yatay << yatay << yatay << yatay << yatay << yatay << yatay << yatay << "X";
	cout << endl << endl;
}



void Print::swapColour(int colour, char* ust, char* alt, char* ful, char* fulbos) {

	if (colour == WHITE) { //Piyon Beyaz ise Karakterler beyaz seçilir
		*ust = 220;
		*alt = 223;
		*ful = 32;
		*fulbos = 219;
	}
	else if (colour == BLACK) { //Piyon Siyah ise Karakterler Siyah seçilir
		*ust = 223;
		*alt = 220;
		*ful = 219;
		*fulbos = 32;
	}
	else if (colour == EMPTY) { //Kare Boş ise Karakterler Boş seçilir
		*ust = 177;
		*alt = 177;
		*ful = 177;
		*fulbos = 177;
	}
}