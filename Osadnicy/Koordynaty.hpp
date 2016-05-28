#pragma once

struct Koordynaty {
	int x;
	int y;
	bool operator==(const Koordynaty & k2) {
		if (this->x == k2.x && this->y == k2.y) { return true; }
		else { return false; }
	}
};