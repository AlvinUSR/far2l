/**
 * @file meta.h
 * @author Aleksey Vinogradov (aleksey.develop@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-13
 * 
 * Copyright 2024 AVM Research
 * 
 **/
#ifndef TREX_INCLUDE__META_H
#define TREX_INCLUDE__META_H

#include <tuple>
#include <concepts>
#include <type_traits>

namespace trex {
namespace meta {

    /********** Проверка, является ли тип Type специализацией std::tuple **********/
    template <typename Type>
    struct is_tuple : std::false_type {};

    template <typename... Args>
    struct is_tuple<std::tuple<Args...>> : std::true_type {};

    template <typename Type>
    concept is_tuple_v = is_tuple<Type>::value;
} // namespace meta
} // namespace trex

#endif // TREX_INCLUDE__META_H