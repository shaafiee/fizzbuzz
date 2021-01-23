
#include <Windows.h>
#include <iostream>
//#include <processthreadsapi.h>
//#include <sys/timeb.h>
#include <chrono>
#include <tchar.h>
#include <strsafe.h>


#define BUF_SIZE 512

DWORD WINAPI fizz(LPVOID lpParam);
DWORD WINAPI buzz(LPVOID lpParam);
DWORD WINAPI fizzbuzz(LPVOID lpParam);


int main()
{
	//int startTime, endTime;
	//int fizz, buzz, fizzbuzz;
	//timeb timeVar;

	//fizz = 0;
	//buzz = 0;
	//fizzbuzz = 0;
	
	//SYSTEM_INFO sysinfo;
	//GetSystemInfo(&sysinfo);
	//std::cout << sysinfo.dwNumberOfProcessors << "\n";



	//ftime(&timeVar);
	//startTime = timeVar.millitm + (timeVar.time & 0xfffff) * 1000;
	auto startTime = std::chrono::high_resolution_clock::now();

	/*for (int i = 1; i <= 100; i++) {
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
	}*/

	//ftime(&timeVar);
	//endTime = timeVar.millitm + (timeVar.time & 0xfffff) * 1000;


	DWORD dwThreadIdArray[3];
	HANDLE hThreadArray[3];
	int maxCount = 1000000000;

	hThreadArray[0] = CreateThread(NULL, 0, fizz, &maxCount, 0, &dwThreadIdArray[0]);
	hThreadArray[1] = CreateThread(NULL, 0, buzz, &maxCount, 0, &dwThreadIdArray[1]);
	hThreadArray[2] = CreateThread(NULL, 0, fizzbuzz, &maxCount, 0, &dwThreadIdArray[2]);

	WaitForMultipleObjects(3, hThreadArray, TRUE, INFINITE);

	for (int i = 0; i < 3; i++) {
		CloseHandle(hThreadArray[i]);
	}

	auto endTime = std::chrono::high_resolution_clock::now();
	auto totalTime = endTime - startTime;

	//std::cout << "fizz : " << fizz << ", buzz : " << buzz << ", fizzbuzz : " << fizzbuzz << " -- duration : " << (endTime - startTime) << "ms";
	//std::cout << "fizz : " << fizz << ", buzz : " << buzz << ", fizzbuzz : " << fizzbuzz << " -- duration : " << (totalTime / std::chrono::nanoseconds(1)) << "nanoseconds";
	std::cout << "\nduration : " << (totalTime / std::chrono::microseconds(1)) << "microseconds\n";

	return 0;
}

DWORD WINAPI fizz(LPVOID lpParam) {
	HANDLE hStdout;

	TCHAR msgBuf[BUF_SIZE];
	size_t cchStringSize;
	DWORD dwChars;

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdout == INVALID_HANDLE_VALUE)
		return 1;

	int count = 0;

	for (int i = 1; i <= 1000000000; i++) {
		if (i % 3 == 0 && i % 5 != 0) {
			count++;
		}
	}

	StringCchPrintf(msgBuf, BUF_SIZE, TEXT("fizzes = %d\n"), count);

	StringCchLength(msgBuf, BUF_SIZE, &cchStringSize);
	WriteConsole(hStdout, msgBuf, (DWORD)cchStringSize, &dwChars, NULL);

	return 0;
}

DWORD WINAPI buzz(LPVOID lpParam) {
	HANDLE hStdout;

	TCHAR msgBuf[BUF_SIZE];
	size_t cchStringSize;
	DWORD dwChars;

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdout == INVALID_HANDLE_VALUE)
		return 1;

	int count = 0;

	for (int i = 1; i <= 1000000000; i++) {
		if (i % 5 == 0 && i % 3 != 0) {
			count++;
		}
	}

	StringCchPrintf(msgBuf, BUF_SIZE, TEXT("buzzes = %d\n"), count);

	StringCchLength(msgBuf, BUF_SIZE, &cchStringSize);
	WriteConsole(hStdout, msgBuf, (DWORD)cchStringSize, &dwChars, NULL);

	return 0;
}

DWORD WINAPI fizzbuzz(LPVOID lpParam) {
	HANDLE hStdout;

	TCHAR msgBuf[BUF_SIZE];
	size_t cchStringSize;
	DWORD dwChars;

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdout == INVALID_HANDLE_VALUE)
		return 1;

	int count = 0;

	for (int i = 1; i <= 1000000000; i++) {
		if (i % 3 == 0 && i % 5 == 0) {
			count++;
		}
	}

	StringCchPrintf(msgBuf, BUF_SIZE, TEXT("fizzbuzzes = %d\n"), count);

	StringCchLength(msgBuf, BUF_SIZE, &cchStringSize);
	WriteConsole(hStdout, msgBuf, (DWORD)cchStringSize, &dwChars, NULL);

	return 0;
}