#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {
    uint64_t expanded = 0;

    for (uint64_t i = 0; i < 64; i++) {
        const uint64_t long_num = 1;
        uint64_t bit = long_num & (input >> i);

        uint64_t shift = i * scale;
        if (shift >= 64) {
            continue;
        }
        expanded |= (bit << shift);

    }

    return expanded;  // replace this with your impl!
}

int main() {
    // test here...
    //test given and test not always passing
    assert(expand(0b0101, 2) == 0b00010001);
    assert(expand(0b1111, 3) == 0b001001001001);
    assert(expand(0b1111, 3) != 0b1111);

    //Test nothing
    assert(expand(0b111, 1) == 0b111);

    //Test truncate
    assert(expand(1 << 32, 2) == 0);


    return 0;
}
