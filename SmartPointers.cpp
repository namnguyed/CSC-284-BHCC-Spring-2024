#include <iostream>
#include <memory>
using namespace std;

// Function that modifies the value pointed to by a raw pointer
void modifyRawPointer(int* ptr) {
    if (ptr) {
        *ptr = 1;
    }
}

// Function that modifies the value pointed to by a unique pointer
void modifyUniquePointer(unique_ptr<int>& ptr) {
    if (ptr) {
        *ptr = 2;
    }
}

int main() {
    // Raw pointer
    int* rawPtr = new int(5);
    modifyRawPointer(rawPtr);
    cout << "Raw pointer value: " << *rawPtr << endl;
    delete rawPtr; // Manually deleting the raw pointer

    // Unique pointer
    unique_ptr<int> uniquePtr = make_unique<int>(5);
    modifyUniquePointer(uniquePtr);
    cout << "Unique pointer value: " << *uniquePtr << endl;
    // No need to manually delete, it will be deleted automatically

    return 0;
}
