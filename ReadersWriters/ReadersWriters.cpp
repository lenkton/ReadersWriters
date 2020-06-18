#include <iostream>
#include <thread>
#include <vector>

#define READERS_NUM 5
#define WRITERS_NUM 2

void writerMain(){}

void readerMain(){
	std::cout << "a";
}

int main()
{
	////threads initialization
	//readers initialization
	std::vector<std::thread> readers;
	for (int i = 0; i < READERS_NUM; i++)
	{
		std::thread t(readerMain);
		readers.push_back(std::move(t));
	}

	//writers initialization
	std::vector<std::thread> writers;
	for (int i = 0; i < WRITERS_NUM; i++)
	{
		std::thread t(readerMain);
		writers.push_back(std::move(t));
	}

	////waiting for threads to finish
	for (auto& a : readers)a.join();
	for (auto& a : writers)a.join();
}
