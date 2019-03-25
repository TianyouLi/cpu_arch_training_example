#include <stdio.h>
#include <stdint.h>

inline void baseline() {
	int64_t src = 0;
	int64_t dst = 1;
	asm (
			 "movq $0x39d8c008aa49, %0    \n"
			 "movq $0x39d8c008ab39, %1    \n"
			 "cmpq %0, %1                \n"
			 "jz done                    \n"
			 "movq $0x39d8c008ab89, %1    \n"
			 "cmpq %0, %1                \n"
			 "jz done                    \n"
			 "movq $0x39d8c008aa49, %1    \n"
			 "cmpq %0, %1                \n"
			 "jz done                    \n"
			 "done:                      \n"
			 : 
			 : "r" (src), "r" (dst)
  );
}

inline void optimized() {
	int32_t src = 0;
	int32_t dst = 1;
	asm (
	 		 "movl $0x000039d8, %0       \n"
	 		 "cmpl $0x000039d8, %0       \n"
			 "jnz done                   \n"
			 "movl $0xc008aa49, %1       \n"
			 "cmpl $0xc008ab39, %1       \n"
			 "jz done                    \n"
			 "cmpl $0xc008ab89, %1       \n"
			 "jz done                    \n"
			 "cmpl $0xc008aa49, %1       \n"
			 "jz done                    \n"
	 "done:                          \n"
			 : 
			 : "r" (src), "r" (dst)
  );
}


#define NUM_OF_ITER  10000000000

int main(int argc, char* argv[])
{
	for (int64_t i = 0 ; i < NUM_OF_ITER; i++) {
#if defined(CMP_OPT)
		optimized();
#else
		baseline();
#endif
	}
}
