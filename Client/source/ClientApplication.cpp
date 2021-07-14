#include <Onfer.h>
#include "pch.h"

size_t bytesAllocate = 0;
uint32_t AllocateCalls = 0;
uint32_t freeCalls = 0;

void* operator new (size_t size) {

	bytesAllocate += size;
	AllocateCalls++;
	return malloc(size);

}

void* operator new[](size_t size) {

	bytesAllocate += size;
	AllocateCalls++;
	return malloc(size);

}

void operator delete(void* ptr, size_t size) noexcept {

	bytesAllocate -= size;
	freeCalls++;
	free(ptr);
}

void operator delete[](void* ptr) noexcept {

	freeCalls++;
	//bytesAllocate -= size;
	free(ptr);

}

//int main() {
//
//	int* ptr = new int;
//	delete ptr;
//
//	Onfer::Log::info("%d Bytes Allocate", bytesAllocate);
//	Onfer::Log::info("%d Allocate Calls", AllocateCalls);
//	Onfer::Log::info("%d Free Calls", freeCalls);
//
//}

#include <sstream>

int main(int argc, char** argv) {

	Onfer::vec3 a(2, 3, 4);
	Onfer::vec3 b(3, 1, 2);

	Onfer::vec3().cross(a);

	Onfer::Scene* application = new Onfer::Scene();
	application->run();
	delete application;

	Onfer::Log::info("%d Bytes Allocate", bytesAllocate);
	Onfer::Log::info("%d Allocate Calls", AllocateCalls);
	Onfer::Log::info("%d Free Calls", freeCalls);


}
