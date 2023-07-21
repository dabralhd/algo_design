#include "test_cases.hpp"
#include "singly_linked_list.hpp"
#include <stdint.h>

using namespace std;

void create_and_traverse_list_of_int32_t() {
    SinglyLinkedList<uint32_t> list;
    for(uint32_t i=0; i<10; i++)
        list.insert_before(i);

    list.traverse();
}

int main() {
    create_and_traverse_list_of_int32_t();
    return 0;
}
