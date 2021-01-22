

#include <iostream>
#include <sys/timeb.h>

int main()
{
	int startTime, endTime, fizz, buzz, fizzbuzz;
	timeb timeVar;

	fizz = 0;
	buzz = 0;
	fizzbuzz = 0;

	ftime(&timeVar);
	startTime = timeVar.millitm + (timeVar.time & 0xfffff) * 1000;

	for (int i = 1; i <= 1000000000; i++) {
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
	}

	ftime(&timeVar);
	endTime = timeVar.millitm + (timeVar.time & 0xfffff) * 1000;

	std::cout << "fizz : " << fizz << ", buzz : " << buzz << "fizzbuzz : " << fizzbuzz << " -- duration : " << (endTime - startTime);

	return 0;
}
