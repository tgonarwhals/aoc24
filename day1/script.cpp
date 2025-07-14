#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	std::ifstream input("input.txt");
	std::string line;

	std::string list1[1000];
	int list1i[1000];
	vector<int> list1v;

	std::string list2[1000];
	int list2i[1000];
	vector<int> list2v;

	int i = 0;
	while (std::getline(input, line))
	{
		line.erase(5, 3);
		for (int j = 0; j < 5; j++) {
			list1[i].append(line, j, 1);
			list2[i].append(line, j+5, 1);
			//std::cout << line[j] << " " << line[j+5] << std::endl;
		}
		list1i[i] = std::stoi(list1[i]);
		list2i[i] = std::stoi(list2[i]);
		i++;
	}
	
	for (i = 0; i < 1000; i++) {
		list1v.push_back(list1i[i]);
		list2v.push_back(list2i[i]);
	}

	sort (list1v.begin(), list1v.end());
	sort (list2v.begin(), list2v.end());

	/*
	
	PART ONE ---------

	int sum = 0;
	for (i = 0; i < 1000; i++) {
		int dist = abs(list1v[i] - list2v[i]);
		sum += dist;
	}
	
	PART ONE ---------

	*/
	int score = 0;
	for (i = 0; i < 1000; i++) {
		int count = 0;
		for (int j = 0; j < 1000; j++) {
			if (list1v[i] == list2v[j]) {
				count++;
			}
		}
		score += list1v[i] * count;
	}

	/*for (i = 0; i < 1000; i++){
		std::cout << list1v[i] << " " << list2v[i] << std::endl;
	}*/

	std::cout << score << "!" << std::endl;
	return 0;
}