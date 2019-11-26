#include <iostream>
#include <string>
#include "bank.h"
#include <chrono>
#include <map>

using namespace std;

int main()
{
	map<string, int> lag;

	lag["Djurgården"] = 34;
	lag["Örebro"] = 22;
	if (lag["Örebro"] > 20)
	{
		cout << "Ojsan";
	}

	int antal = 500000;
	auto storage = new FileAccountStorage();
	
	
	Bank b(storage);
	
	chrono::high_resolution_clock::time_point start;
	chrono::high_resolution_clock::time_point slut;

	cout << "Starting inserts\n" << endl;
	start = chrono::high_resolution_clock::now();
	//for (int i = 0; i < antal; i++)
	//{
	//	b.AddAccount(to_string(i));
	//}
	slut = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<std::chrono::milliseconds>(slut - start).count();
	cout << "Insert tog " << duration << " milliseconds\n";


	string kontonummer;
	while (1)
	{
		std::cout << "Ange kontonummer:>";
		std::cin >> kontonummer;
		start = chrono::high_resolution_clock::now();
		Account* acc = b.GetAccount(kontonummer);
		slut = chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(slut - start).count();
		std::cout << "Konto hittades ";
		if (acc == nullptr) std::cout << " inte ";
		std::cout << ". Tog " << duration << " millisekunder " << std::endl;
	}


}
