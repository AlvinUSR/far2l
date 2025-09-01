/**
 * @file settings.h
 * @author Aleksey Vinogradov (aleksey.develop@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-10
 * 
 * Copyright 2024 AVM Research
 * 
 **/
#ifndef TREX_INCLUDE_SM__SETTINGS_H
#define TREX_INCLUDE_SM__SETTINGS_H

#include <helpers/json_parser.h>
#include <base.h>

namespace trex {
    using json_t = nlohmann::json;
namespace sm {
    struct version {
        int major;
        int minor;
        int patch;
    }; // version

    template <typename ProcSettings>
    using process_settings = tuple_t<
        version,        // Версия процесса
        bool,           // Флаг необходимости работы в режиме демона
        ProcSettings    // Контейнер настроек пользовательского процесса
    >;

    template <typename ProcSettings>
    constexpr void to_json(json_t&, const process_settings<ProcSettings>&) {

    }

    template <typename ProcSettings>
    constexpr void from_json(const json_t& json_obj, process_settings<ProcSettings>&) {

    }

    template <typename Container>
    class settings_manager {
    public:
        using container_type = Container;
        using type = settings_manager<container_type>;
    public:
        ~settings_manager() noexcept = default;
        settings_manager() noexcept = default;

        settings_manager(string_t&& path) {
            try {
                apply_settings(std::move(path));
            }
            catch(...) {

            }
        }

        constexpr void apply_settings(string_t&& path) {
            auto _res = m_parser.parse(std::move(path));

            if(!_res) { // Ошибка парсинга файла настроек
                base::add_debug_item(_res.error(), base::location_t::current());
                throw base::exception_t{ std::move(_res.error()) };
            }

            auto _json_obj = _res.value();

            /**
             * @brief Сохранение настроек в контейнере
             * 
             **/
        }
    private:
        container_type m_container;
        helpers::json_parser m_parser;
    }; // settings_manager
} // namespace sm
} // namespace trex

#endif // TREX_INCLUDE_SM__SETTINGS_H