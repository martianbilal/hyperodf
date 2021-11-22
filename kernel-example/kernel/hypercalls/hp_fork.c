#include <hypercalls/hp_fork.h>
#include <mm/translate.h>

int hp_fork(uint64_t paddr) {
  return hypercall(NR_HP_fork, (uint32_t) paddr);
}
