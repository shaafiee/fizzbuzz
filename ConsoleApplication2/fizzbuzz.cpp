

#include <iostream>
//#include <sys/timeb.h>
#include <chrono>

int main()
{
	//int startTime, endTime;
	int fizz, buzz, fizzbuzz;
	//timeb timeVar;

	fizz = 0;
	buzz = 0;
	fizzbuzz = 0;

	//ftime(&timeVar);
	//startTime = timeVar.millitm + (timeVar.time & 0xfffff) * 1000;
	auto startTime = std::chrono::high_resolution_clock::now();

	for (int i = 1; i <= 100; i++) {
		if (i % 3 == 0) {
			if (i % 5 == 0) {
				fizzbuzz++;
			}
			else {
				fizz++;
			}
		}
		else if (i % 5 == 0) {
			if (i % 3 == 0) {
				fizzbuzz++;
			}
			else {
				buzz++;
			}
		}

		/*
		if (i % 3 == 0 && i % 5 == 0) {
			fizzbuzz++;
		}
		else {
			if (i % 3 == 0) {
				fizz++;
				continue;
			}
			if (i % 5 == 0) {
				buzz++;
			}
		}
		*/

		/*
		if (i % 3 == 0) {
			fizz++;
		}
		else if (i % 5 == 0) {
			buzz++;
		}
		else if (i % 3 == 0 && i % 5 == 0) {
			fizzbuzz++;
		}
		*/
	}

	//ftime(&timeVar);
	//endTime = timeVar.millitm + (timeVar.time & 0xfffff) * 1000;

	auto endTime = std::chrono::high_resolution_clock::now();
	auto totalTime = endTime - startTime;

	//std::cout << "fizz : " << fizz << ", buzz : " << buzz << ", fizzbuzz : " << fizzbuzz << " -- duration : " << (endTime - startTime) << "ms";
	std::cout << "fizz : " << fizz << ", buzz : " << buzz << ", fizzbuzz : " << fizzbuzz << " -- duration : " << (totalTime / std::chrono::nanoseconds(1)) << "nanoseconds";

	return 0;
}
