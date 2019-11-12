#include <iostream>
#include <string>
#include "bank.h"
#include <chrono>


int main()
{
	int antal = 100000;
	auto storage = new VectorAccountStorage();
	Bank b(storage);
	
	chrono::high_resolution_clock::time_point t1;
	chrono::high_resolution_clock::time_point t2;

	cout << "Starting inserts\n" << endl;
	t1 = chrono::high_resolution_clock::now();
	for (int i = 0; i < antal; i++)
	{
		b.AddAccount(to_string(i));
	}
	t2 = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	cout << "Insert tog " << duration << " milliseconds\n";


	string kontonummer;
	while (1)
	{
		std::cout << "Ange kontonummer:>";
		std::cin >> kontonummer;
		t1 = chrono::high_resolution_clock::now();
		Account* acc = b.GetAccount(kontonummer);
		t2 = chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
		std::cout << "Konto hittades ";
		if (acc == nullptr) std::cout << " inte ";
		std::cout << ". Tog " << duration << " millisekunder " << std::endl;
	}


}
