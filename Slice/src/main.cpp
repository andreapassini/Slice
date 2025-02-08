#include <iostream>
#include <assert.h>

#include "../include/areana.h"

int main()
{
	Arena arena;
	InitArena(&arena, 1'000);

	uint8_t* ptr1 = Allocate<uint8_t>(&arena, 123);
	PrintArena(&arena);
	uint8_t* ptr2 = Allocate<uint8_t>(&arena, 123);
	PrintArena(&arena);
	uint8_t* ptr3 = Allocate<uint8_t>(&arena, 123);
	PrintArena(&arena);

	Free(&arena);
	PrintArena(&arena);

	std::cout << "Hello" << std::endl;

	return 0;
}