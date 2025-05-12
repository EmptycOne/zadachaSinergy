#include <gtest/gtest.h>

// Предположим, что эти классы объявлены в соответствующих заголовочных файлах
#include "queue.h"
#include "heap.h"
#include "binary_tree.h"

// Тесты для класса Queue
class QueueTest : public ::testing::Test {
protected:
    // Можно объявить здесь объекты очереди для использования в тестах
    Queue<int> q;
};

TEST_F(QueueTest, PushAndPopSingleElement) {
    q.push(42);
    EXPECT_FALSE(q.empty());
    int value = q.pop();
    EXPECT_EQ(value, 42);
    EXPECT_TRUE(q.empty());
}

TEST_F(QueueTest, MultipleElementsOrder) {
    q.push(1);
    q.push(2);
    q.push(3);
    EXPECT_EQ(q.pop(), 1);
    EXPECT_EQ(q.pop(), 2);
    EXPECT_EQ(q.pop(), 3);
}

TEST_F(QueueTest, PopFromEmpty) {
    // Предположим, что pop из пустой очереди возвращает исключение или специальное значение
    // В зависимости от реализации тестируемого класса
    EXPECT_THROW(q.pop(), std::out_of_range);
}

// Тесты для класса Heap
class HeapTest : public ::testing::Test {
protected:
    Heap<int> h;
};

TEST_F(HeapTest, PushAndPopSingleElement) {
    h.push(10);
    EXPECT_FALSE(h.empty());
    int val = h.pop();
    EXPECT_EQ(val, 10);
    EXPECT_TRUE(h.empty());
}

TEST_F(HeapTest, MultipleElementsOrder) {
    h.push(5);
    h.push(3);
    h.push(8);
    
    int first = h.pop(); // должен быть минимальным элементом (если min-heap)
    int second = h.pop();
    int third = h.pop();

    EXPECT_LE(first, second);
    EXPECT_LE(second, third);
}

TEST_F(HeapTest, PopFromEmpty) {
    // Аналогично с очередью
    EXPECT_THROW(h.pop(), std::out_of_range);
}

// Тесты для класса BinaryTree
class BinaryTreeTest : public ::testing::Test {
protected:
    BinaryTree<int> tree;
};

TEST_F(BinaryTreeTest, InsertAndSearchExisting) {
    tree.push(15);
    tree.push(10);
    tree.push(20);

    EXPECT_TRUE(tree.search(15));
    EXPECT_TRUE(tree.search(10));
    EXPECT_TRUE(tree.search(20));
}

TEST_F(BinaryTreeTest, SearchNonExisting) {
    tree.push(5);
    tree.push(7);

    EXPECT_FALSE(tree.search(10));
}

TEST_F(BinaryTreeTest, PopAndInsert) {
    tree.push(30);
    
    int val = tree.pop(); // предполагается, что pop возвращает корень или минимальный/максимальный элемент
    // В зависимости от реализации дерева
    // Например:
    // EXPECT_EQ(val, 30);

    // После удаления можно вставлять новые элементы
}

// Основная функция для запуска всех тестов
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
