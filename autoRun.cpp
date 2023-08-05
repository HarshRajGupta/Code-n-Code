#include <iostream>
#include <thread>

void childFunction() {
    std::cout << "Child thread: ID = " << std::this_thread::get_id() << std::endl;
}

int main() {
    std::cout << "Parent thread: ID = " << std::this_thread::get_id() << std::endl;

    std::thread childThread(childFunction); // Create a new child thread

    childThread.join(); // Wait for the child thread to finish

    return 0;
}
