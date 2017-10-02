#include <iostream>
#include <fstream>
#include <sstream>
#include "LLDeque.h"

void processPerson (LLDeque& p, int counter);
int comparePeople (LLDeque& p1, LLDeque& p2);

int main (int argc, char* argv[]){

	if(argc != 2){
		std::cerr << "Error! Please include an input file." << std::endl;
		return -1; 
	}

	std::ifstream infile(argv[1]);

	if(!infile.is_open() || infile.fail()){
		std::cerr << "Error! Problem opening file." << std::endl;
		return -1;
	}

	LLDeque p1;
	LLDeque p2;
	int p1_counter = 0;
	int p2_counter = 0;

	int per;
	char dir;
	while(!infile.fail()){
		std::string line;
		getline(infile, line);
		std::stringstream ss(line);

		ss >> per >> dir;

		if(per == 1){
			p1.pushback(dir);
			p1_counter++;
		}
		else {
			p2.pushback(dir);
			p2_counter++;
		}
	}
	
	if(per == 1){
		p1.popback();
		p1_counter--;
	}
	else {
		p2.popback();
		p2_counter--;
	}

	processPerson(p1, p1_counter);
	processPerson(p2, p2_counter);

	int ans = comparePeople(p1, p2);

	std::cout << ans << std::endl;

	return 0;
}

void processPerson (LLDeque& p, int counter) {
		if(counter < 2){
			return;
		}

		for(int i=0; i<counter-2; i++){
			char one = p.getfront();
			p.popfront();
			char two = p.getfront();
			p.popfront();

			if((one == 'N' && two == 'S') || (one == 'S' && two == 'N') ||
				(one == 'E' && two == 'W') || (one == 'W' && two == 'E')){
				continue;
			}
			else {
				p.pushback(one);
				p.pushfront(two);
			}
		}
		char one = p.getfront();
		char two = p.getback();
		p.popfront();
		if((one == 'N' && two == 'S') || (one == 'S' && two == 'N') ||
				(one == 'E' && two == 'W') || (one == 'W' && two == 'E')){
			p.popback();
		}
		else {
			p.pushback(one);
		}
}

int comparePeople (LLDeque& p1, LLDeque& p2) {
	int p1Count = 0;
	int p2Count = 0;
	LLDeque stor1;
	LLDeque stor2;
	while(!p1.isempty()){
		char c = p1.getfront();
		p1.popfront();
		stor1.pushback(c);
		p1Count++;
	}
	while(!p2.isempty()){
		char c = p2.getfront();
		p2.popfront();
		stor2.pushback(c);
		p2Count++;
	}

	if(p1Count == p2Count){
		bool areSame = true;
		while(!stor1.isempty()){
			char c = stor1.getfront();
			stor1.popfront();
			char c2 = stor2.getfront();
			stor2.popfront();

			if(c != c2){
				areSame = false;
				break;
			}
		}
		if(areSame){
			return 0;
		}
	}

	return (p1Count + p2Count);
}