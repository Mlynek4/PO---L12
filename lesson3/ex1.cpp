#include <iostream>
using namespace std;

class Movie{
	private:
			string title;
			string genre;
			int year;
			int length;
	public:
			Movie(string t, string g, int y, int l) { this->title = t; this->genre = g; this->year = y; this->length = l; }
			void changetitle(string t1) { this->title = t1; }
};

int main() {
	Movie Movie1("Se7en", "Thriller", 1995, 127);
	return 0;
}
