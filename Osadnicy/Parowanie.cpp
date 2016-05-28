#include "Parowanie.hpp"

Koordynaty Parowanie::osadaDlaDrogi_1(const Koordynaty & kDrogi)
{
	int n = kDrogi.x;
	int m = kDrogi.y;
	Koordynaty nowe;
	nowe.x = n % 2 + n / 2;
	nowe.y = (n % 2) ? m : (2*m - 1) + !(n % 4);
	return nowe;

}

Koordynaty Parowanie::osadaDlaDrogi_2(const Koordynaty & kDrogi)
{
	int n = kDrogi.x;
	int m = kDrogi.y;
	Koordynaty nowe;
	nowe.x = n % 2 + n / 2 + !(n % 2);
	nowe.y = (n % 2) ? (m + 1) : (2*m - 1) + !(n % 4);
	return nowe;
}

int Parowanie::orientacjaDlaDrogi(const Koordynaty & kDrogi)
{
	int n = kDrogi.x;
	int m = kDrogi.y;
	return (n % 2) ? ((m % 2) ? 330 : 30) : 90;
}

Koordynaty Parowanie::poleDlaOsady_1(const Koordynaty & kOsady)
{
	int n = kOsady.x;
	int m = kOsady.y;
	Koordynaty nowe;
	nowe.x = n - 1;
	nowe.y = (m - (n % 2)) / 2;
	return nowe;
}

Koordynaty Parowanie::poleDlaOsady_2(const Koordynaty & kOsady)
{
	int n = kOsady.x;
	int m = kOsady.y;
	Koordynaty nowe;
	nowe.x = (n % 2) ? n - !(m % 2) : n - (m % 2);
	nowe.y = (n % 2) ? m / 2 : ((m % 2) ? (m + 1) / 2 : m / 2 - 1);
	return nowe;
}

Koordynaty Parowanie::poleDlaOsady_3(const Koordynaty & kOsady)
{
	int n = kOsady.x;
	int m = kOsady.y;
	Koordynaty nowe;
	nowe.x = n;
	nowe.y = (n % 2) ? ((m % 2) ? (m + 1) / 2 : m / 2) : m / 2;
	return nowe;
}
