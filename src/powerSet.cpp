#include <vector>

typedef std::vector<int> IntVector;
typedef std::vector<IntVector> IntVectorVector;

IntVector getPermutation(uint32_t i, IntVector const &set) {
    IntVector permutation;
    for (uint32_t j = 0; j < set.size(); j++) {
        if (i & (1 << j)) {
            permutation.push_back(set[j]);
        }
    }
    return permutation;
}

IntVectorVector powerset(IntVector const &set) {
    IntVectorVector ivv;
    uint32_t powerSetSize = pow(2, set.size());

    for (uint32_t i = 0; i < powerSetSize; i ++) {
        ivv.push_back(getPermutation(i, set));
    }
    return ivv;
}
