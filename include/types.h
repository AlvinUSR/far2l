/**
 * @file types.h
 * @author Aleksey Vinogradov (aleksey.develop@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-03
 * 
 * Copyright 2025 AVM Research
 * 
 **/
#ifndef TREX_INCLUDE__TYPES_H
#define TREX_INCLUDE__TYPES_H

#ifdef __win__
    #include <windows.h>
#endif // __win__ 

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <memory>

namespace trex {
    using string_t = std::string;
    using string_view_t = std::string_view;

    template <typename Type, typename Allocator = std::allocator<Type>>
    using vector_t = std::vector<Type, Allocator>;

    template <typename... Types>
    using tuple_t = std::tuple<Types...>;

    template <typename Key, typename Value, typename Hash = std::hash<Key>, typename Equal = std::equal_to<Key>, typename Allocator = std::allocator<std::pair<const Key, Value>>>
    using umap_t = std::unordered_map<Key, Value, Hash, Equal, Allocator>;

    template <typename Type>
    using unique_ptr_t = std::unique_ptr<Type>;

    template <typename Type>
    using shared_ptr_t = std::shared_ptr<Type>;
} // namespace trex

#endif // TREX_INCLUDE__TYPES_H