#include <iostream>
using namespace std;

class Trees {
  public:
		int age;
		string group;
		int hight;
		
	};
	
class Flowers {
  public:
		string colour;
		string group;
		int flakes;
	};
	
class Garden {
  public:
	  string WhatTree;
	  string WhatFlower;
};


int main() {
	Trees MyTree;
	MyTree.age = 43;
	MyTree.group = "Spruce";
	MyTree.hight = 22;
	
	Flowers MyFlower;
	MyFlower.colour = "Red";
	MyFlower.group = "Rose";
	MyFlower.flakes = 7;
	return 0;
	
	Garden MyGarden;
	
}
