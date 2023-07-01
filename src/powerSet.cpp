#include <vector>

typedef std::vector<int32_t> IntVector;
typedef std::vector<IntVector> IntVectorVector;

IntVector getPermutation(int32_t i, IntVector const &set) {
    IntVector permutation;
    for (int32_t j = 0; j < set.size(); j++) {
        if (i & (1 << j)) {
            permutation.push_back(set[j]);
        }
    }
    return permutation;
}

IntVectorVector powerset(IntVector const &set) {
    IntVectorVector ivv;
    int32_t powerSetSize =  1 << set.size();
    for (int32_t i = 0; i < powerSetSize; i ++) {
        ivv.push_back(getPermutation(i, set));
    }
    return ivv;
}
