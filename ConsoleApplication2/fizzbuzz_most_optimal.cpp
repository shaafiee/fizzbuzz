
#include <iostream>
#include <chrono>

int main()
{
	const int countTo = 1000000000;
	int fizz, buzz, fizzbuzz;

	unsigned char numState;

	fizz = 0;
	buzz = 0;
	fizzbuzz = 0;

	auto startTime = std::chrono::high_resolution_clock::now();

	for (int i = 1; i <= countTo; i++) {
		numState = 0;

		if (i % 3 == 0) {
			numState++;
		}

		if (i % 5 == 0) {
			numState += 3;
		}

		switch (numState) {
			case 0:
				break;
			case 1:
				fizz++;
				break;
			case 3:
				buzz++;
				break;
			case 4:
				fizzbuzz++;
				break;
		}

	}


	auto endTime = std::chrono::high_resolution_clock::now();
	auto totalTime = endTime - startTime;

	printf("fizz : %d, buzz: %d, fizzbuzz: %d, duration %lld nanoseconds\n", fizz, buzz, fizzbuzz, (totalTime / std::chrono::milliseconds(1)));

	return 0;
}
