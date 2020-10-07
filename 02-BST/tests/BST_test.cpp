#include <algorithm>
#include <iterator>
#include <vector>
#include <random>

#include "BST.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

template <typename T>
void is_BST(std::unique_ptr<TreeNode<T>> &t) {
    if (t) {
        auto ref = t->element;
        if (t->left)
            REQUIRE(t->left->element < ref);
        if (t->right)
            REQUIRE(t->right->element > ref);
 
        is_BST(t->left);
        is_BST(t->right);
    }

}

TEST_CASE("BST insert test", "[BST]") {

    BST<int> bt; 

    std::vector<int> v;
    v.resize(10000);
    std::generate(v.begin(), v.end(), std::rand);
    std::sort(v.begin(), v.end());
    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end()); 
    std::random_shuffle(v.begin(), v.end());

    for (auto ele: v) {
        REQUIRE(bt.insert(ele));
        REQUIRE(!bt.insert(ele));
    }
    
    is_BST(bt.root);

}


TEST_CASE("BST search test", "[BST]") {

    BST<int> bt; 

    std::vector<int> v;
    v.resize(10000);
    std::generate(v.begin(), v.end(), std::rand);
    std::sort(v.begin(), v.end());
    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end()); 
    std::random_shuffle(v.begin(), v.end());
 
    for (auto ele: v) {
        REQUIRE(!bt.search(ele));
        bt.insert(ele);
        REQUIRE(bt.search(ele));
    }

    is_BST(bt.root);

}


TEST_CASE("BST remove test", "[BST]") {

    BST<int> bt; 
 
    std::vector<int> v;
    v.resize(10000);
    std::generate(v.begin(), v.end(), std::rand);
    std::sort(v.begin(), v.end());
    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end()); 
    std::random_shuffle(v.begin(), v.end());

    for (auto ele: v) 
        bt.insert(ele);

    auto x = std::vector<int>(v.begin(), v.begin() + std::distance(v.begin(), v.end()) / 2);
    
    for (auto ele: x) {
        REQUIRE(bt.remove(ele));
        REQUIRE(!bt.remove(ele));
    }

    is_BST(bt.root);

}