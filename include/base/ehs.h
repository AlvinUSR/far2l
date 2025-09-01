/**
 * @file ehs.h
 * @author Aleksey Vinogradov (aleksey.develop@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-03
 * 
 * Copyright 2025 AVM Research
 * 
 **/

#ifndef TREX_INCLUDE_BASE__EHS_H
#define TREX_INCLUDE_BASE__EHS_H

#include <exception>
#include <system_error>
#include <expected>
#include <source_location>
#include <types.h>

#ifdef __win__
    #define last_error GetLastError()
#elif __unix__
    #define last_error errno
#endif // __win__

namespace trex {
namespace base {
    using location_t = std::source_location;

    class error_t : public std::error_code {
    public:
        ~error_t() noexcept = default;
        error_t() noexcept = default;

        error_t(std::error_code&& code, location_t&& location) :
        std::error_code{ std::move(code) } {
            m_location.push_back(std::move(location));
        }

        error_t(const std::error_code& code, location_t&& location) :
        std::error_code{ code } {
            m_location.push_back(std::move(location));
        }

        error_t(const std::error_code& code, const char* msg, location_t&& location) :
        std::error_code{ code },
        m_additional_message{ msg } {
            m_location.push_back(std::move(location));
        }

        /**
         * @brief Параметризованный конструктор
         * 
         * @param code Идентификатор (код) ошибки
         * @param msg Дополнительное пользовательское сообщение
         * @param location Место возникновения ошибки
         **/
        error_t(int code, const char* msg, location_t&& location) :
        std::error_code{ code, std::generic_category() },
        m_additional_message{ msg } {
            m_location.push_back(std::move(location));
        }
        
        void add_location(location_t&& location) noexcept {
            m_location.push_back(std::move(location));
        }
    private:
        mutable vector_t<location_t> m_location;
        mutable string_t m_additional_message;
    }; // error_t

    class exception_t : public std::exception {
    private:
        mutable error_t m_error;
    public:
        virtual ~exception_t() noexcept = default;
        exception_t() noexcept = default;
        explicit exception_t(error_t&& error) noexcept :
        m_error{ std::move(error) } {} 

        const char* what() const noexcept override {
            return nullptr;
        }

        constexpr error_t& error() const noexcept {
            return m_error;
        }
    }; // exception_t

    template <typename Type, typename Error = error_t>
    using result_t = std::expected<Type, Error>;

    constexpr void add_debug_item(error_t& err, location_t&& location) {
        err.add_location(std::move(location));
    }

    constexpr void add_debug_item(const exception_t& ex, location_t&& location) {
        add_debug_item(ex.error(), std::move(location));
    }
} // namespace base
} // namespace trex

#endif // TREX_INCLUDE_BASE__EHS_H