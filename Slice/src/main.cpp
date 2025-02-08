#include <iostream>

#include "../include/areana.h"

int main()
{
	Arena*  arena = (Arena*)malloc(sizeof(Arena));
	InitArena(arena, 1'000);

	uint8_t* ptr1 = Allocate<uint8_t>(arena, 1200);
	PrintArena(arena);
	std::cout << "\n" << std::endl;

	uint8_t* ptr2 = Allocate<uint8_t>(arena, 1000);
	PrintArena(arena);
	std::cout << "\n" << std::endl;

	uint8_t* ptr3 = Allocate<uint8_t>(arena, 1000);
	PrintArena(arena);
	std::cout << "\n" << std::endl;

	uint8_t* ptr4 = Allocate<uint8_t>(arena, 1000);
	PrintArena(arena);
	std::cout << "\n" << std::endl;

	uint8_t* ptr5 = Allocate<uint8_t>(arena, 1000);
	PrintArena(arena);
	std::cout << "\n" << std::endl;

	uint8_t* ptr6 = Allocate<uint8_t>(arena, 2000);
	PrintArena(arena);
	std::cout << "\n" << std::endl;

	std::cout << "\n Resetting" << std::endl;
	Reset(arena);
	PrintArena(arena);
	std::cout << "\n" << std::endl;

	std::cout << "\n Freeing" << std::endl;
	Free(arena);
	PrintArena(arena);
	std::cout << "\n" << std::endl;

	ptr1 = nullptr;
	ptr2 = nullptr;
	ptr3 = nullptr;
	ptr4 = nullptr;
	ptr5 = nullptr;
	ptr6 = nullptr;

	std::cout << "The end" << std::endl;

	return 0;
}