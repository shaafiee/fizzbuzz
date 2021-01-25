
#include <iostream>
#include <chrono>

int main()
{
	int fizz = 0, buzz = 0, fizzbuzz = 0;

	auto startTime = std::chrono::high_resolution_clock::now();

	for (unsigned int i = 1; i <= 4000000000; i++) {
		if (i % 3 == 0) {
			if (i % 5 == 0) {
				fizzbuzz++;
			}
			else {
				fizz++;
			}
		}
		else if (i % 5 == 0) {
			buzz++;
		}
	}

	auto endTime = std::chrono::high_resolution_clock::now();
	auto totalTime = endTime - startTime;

	printf("\t fizz : %d, buzz: %d, fizzbuzz: %d, duration %lld milliseconds\n", fizz, buzz, fizzbuzz, (totalTime / std::chrono::milliseconds(1)));

	return 0;
}
