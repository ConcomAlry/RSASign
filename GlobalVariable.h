#pragma once
#include <random>
#pragma warning (disable : 2020)

#define SAMPLE_COUNT 3          // Кол-во перемножаемых простых чисел при получении большого простого числа
#define PRIME_COUNT 10          // Кол-во генерируемых простых чисел для получения одного большого простого числа
#define DEPTH_COUNT 8			// Кол-во десятичных знаков генерируемых простых чисел
#define LOWER_BOUND 100			// Нижняя граница диапазона генерации U
#define UPPER_BOUND 200			// Верхняя граница диапазона генерации  U

extern std::random_device rd;

