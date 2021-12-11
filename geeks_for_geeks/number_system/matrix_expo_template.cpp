/**
 * @file matrix_expo_template.cpp
 * @author Soumodipta Bose (sbose2019@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * F(n)=aF(n-1)+bF(n-2)+cF(n-3)
 * |F(n)   |   | a b c |        | F(n-1)|
 * |F(n-1) | = | 1 0 0 |  x     | F(n-2)|
 * |F(n-2) |   | 0 1 0 |        | F(n-3)|
 * 
 * | F(n)   |  =  [ | a b c | ] ^ (n-2)   *  | F(2) |
 * | F(n-1) |     [ | 1 0 0 | ]              | F(1) |
 * | F(n-2) |     [ | 0 1 0 | ]              | F(0) |
 */
#include <bits/stdc++.h>
using namespace std;
