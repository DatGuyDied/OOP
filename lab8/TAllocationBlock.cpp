#include "TAllocationBlock.h"
#include <iostream>

TAllocationBlock::TAllocationBlock(size_t size, size_t count) : size(size), count(count)
{
  used_blocks = (char*)malloc(size * count);
  free_blocks = (void**)malloc(sizeof(void*) * count);
  for (size_t i = 0; i < count; i++) {
    free_blocks[i] = used_blocks + i * size;
  }
  free_count = count;
  max_count = count;
}

void *TAllocationBlock::reallocate() {
  void *result = nullptr;
  max_count = max_count * 2;
  used_blocks = (char*)malloc(size * max_count);
  free_blocks = (void**)malloc(sizeof(void*) * max_count);
  for (size_t i = 0; i < max_count; i++) {
    free_blocks[i] = used_blocks + i * size;
  }
  free_count = max_count / 2;
  return result;
}

void *TAllocationBlock::allocate() {
  void *result = nullptr;
  if (free_count > 0) {
    result = free_blocks[free_count - 1];
    free_count--;
  }
  return result;
}

void TAllocationBlock::deallocate(void *pointer) {
  free_blocks[free_count] = pointer;
  free_count++;
}

bool TAllocationBlock::has_free_blocks() {
  return free_count > 0;
}

TAllocationBlock::~TAllocationBlock()
{
  delete free_blocks;
  delete used_blocks;
}
