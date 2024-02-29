#include "buffer.h"

int main(){
    buffer_t buffer;
    slot_t slot = {10};

    buffer_init(&buffer, 10);
    buffer_insert(&buffer, &slot);
    slot.value +=10;
    buffer_insert(&buffer, &slot);
    buffer_dump(&buffer);
    buffer_remove(&buffer, &slot);
    buffer_dump(&buffer);
    

    buffer_detroy(&buffer);

    return 0;

}

