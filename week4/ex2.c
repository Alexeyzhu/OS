//
// Created by alexey on 12.09.18.
//

#include <unistd.h>

int main() {
    for (int i = 0; i < 5; ++i) {
        fork();
    }

    sleep(10);

    return 0;
}
