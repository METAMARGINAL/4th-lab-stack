#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty.");
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    T& peek() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty.");
        }
        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};

void find_bracket_pairs(const string& text) {
    Stack<int> stack; // Стек для хранения индексов открывающих скобок
    pair<int, int> pairs[1000]; // Массив для хранения пар (позиции открывающих и закрывающих скобок)
    int pair_count = 0; // Счетчик количества пар

    // Проходим по строке
    for (int i = 0; i < text.length(); ++i) {
        if (text[i] == '(') {
            // Если открывающая скобка, добавляем её индекс в стек
            stack.push(i);
        }
        else if (text[i] == ')') {
            // Если закрывающая скобка, извлекаем индекс открывающей скобки из стека
            int opening_index = stack.peek();
            stack.pop();
            pairs[pair_count++] = { opening_index + 1, i + 1 }; // Сохраняем пару с 1-базированными индексами
        }
    }

    sort(pairs, pairs + pair_count);


    for (int i = 0; i < pair_count; ++i) {
        cout << pairs[i].first << " " << pairs[i].second << endl;
    }
}