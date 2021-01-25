
#include <Windows.h>
#include <iostream>

#include <chrono>
#include <tchar.h>
#include <strsafe.h>


#define BUF_SIZE 512

const unsigned int FIZZBUZZMAX = 4000000000;

DWORD WINAPI fizz(LPVOID lpParam);
DWORD WINAPI buzz(LPVOID lpParam);
DWORD WINAPI fizzbuzz(LPVOID lpParam);


int main()
{

	auto startTime = std::chrono::high_resolution_clock::now();

	DWORD dwThreadIdArray[3];
	HANDLE hThreadArray[3];
	int maxCount = 4000000000;

	hThreadArray[0] = CreateThread(NULL, 0, fizz, &maxCount, 0, &dwThreadIdArray[0]);
	hThreadArray[1] = CreateThread(NULL, 0, buzz, &maxCount, 0, &dwThreadIdArray[1]);
	hThreadArray[2] = CreateThread(NULL, 0, fizzbuzz, &maxCount, 0, &dwThreadIdArray[2]);

	WaitForMultipleObjects(3, hThreadArray, TRUE, INFINITE);

	auto endTime = std::chrono::high_resolution_clock::now();
	auto totalTime = endTime - startTime;

	std::cout << "\t duration: " << (totalTime / std::chrono::milliseconds(1));
	
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

	for (int i = 1; i <= FIZZBUZZMAX; i++) {
		if (i % 3 == 0 && i % 5 != 0) {
			count++;
		}
	}

	StringCchPrintf(msgBuf, BUF_SIZE, TEXT("\t fizzes = %d\n"), count);

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

	for (int i = 1; i <= FIZZBUZZMAX; i++) {
		if (i % 5 == 0 && i % 3 != 0) {
			count++;
		}
	}

	StringCchPrintf(msgBuf, BUF_SIZE, TEXT("\t buzzes = %d\n"), count);

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

	for (int i = 1; i <= FIZZBUZZMAX; i++) {
		if (i % 3 == 0 && i % 5 == 0) {
			count++;
		}
	}

	StringCchPrintf(msgBuf, BUF_SIZE, TEXT("\t fizzbuzzes = %d\n"), count);

	StringCchLength(msgBuf, BUF_SIZE, &cchStringSize);
	WriteConsole(hStdout, msgBuf, (DWORD)cchStringSize, &dwChars, NULL);

	return 0;
}