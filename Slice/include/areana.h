#include <assert.h>
#include <iostream>

struct Arena {
	size_t capacity = 0;
	size_t size = 0;
	uint8_t* data = nullptr;
};

void InitArena(Arena* const arena, const size_t capacity) {
	arena->data = (uint8_t*)malloc(sizeof(arena->data) * capacity);
	if (arena->data) {
		arena->capacity = capacity;
		arena->size = 0;
	}
}

template<typename T>
T* Allocate(Arena* const arena, const size_t size) {
	T* outPtr = nullptr;

	// Arena doesnt have extra size
	//if (!(arena->size + size <= arena->capacity)) { return outPtr; }
	assert ((arena->size + size <= arena->capacity));

	outPtr = (T*)(arena->data + ((sizeof(arena->data) * arena->size)));

	arena->size += size;

	return outPtr;
}

// Reset the size of the arena
void Reset(Arena* const arena) {
	arena->size = 0;
}

void Free(Arena* const arena) {
	free(arena->data);
	arena->capacity = 0;
	arena->size = 0;
}

void PrintArena(const Arena* const arena)
{
	uint8_t* NextData = (arena->data + ((sizeof(arena->data) * arena->size)));

	std::cout << "Arena.size = " << arena->size <<
		"\n Arena.capacity = " << arena->capacity <<
		"\n Arena.data = " << (void*)arena->data << 
		"\n Arena.NextData = " << (void*)NextData << std::endl;
}