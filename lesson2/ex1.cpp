#include <iostream>
using namespace std;

class Lamp{
	private:
			bool light;
			float price;
	public:
			Lamp() { this->light = false; this->price = 0.0f; }
			Lamp(float pr) { this->light = false; this->price = pr; }
			Lamp(int pr) { this->light = false; this->price = pr; }
			Lamp(bool lx) { this->light = lx; this->price = 0.0f; }
			Lamp(bool lx, float pr) { this->light = lx; this->price = pr; }
};

class Shovel{
	private:
			float lenght;
};

void dig();
void shorthen();

int main() {
	Lamp Lamp1(true);
	return 0;
}
