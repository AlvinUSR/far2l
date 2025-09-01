/**
 * @file process.h
 * @author Aleksey Vinogradov (aleksey.develop@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-03
 * 
 * Copyright 2024 AVM Research
 * 
 **/
#ifndef TREX_INCLUDE_BASE__PROCESS_H
#define TREX_INCLUDE_BASE__PROCESS_H

#include <afsm/fsm.hpp>
#include <base.h>
#include <base/tags.h>
#include <helpers/cmd_line_parser.h>
#include <sm/settings.h>

namespace trex {
namespace base {
    using none = afsm::none;

    class iprocess {
    public:
        
    };

    /**
     * @brief Описсание функционала процесса
     * 
     * @tparam Proc Пользовательский процесс
     * @tparam EVS Система событий
     * @tparam CCS Система коммуникации между компонентами
     * @tparam SMS Менеджер настроек
     * @tparam Logger Система логирования
     **/
    template <typename Proc, typename SM = tags::sm, typename EVS = tags::evs, typename CCS = tags::ccs, typename Logger = tags::logger>
    requires (
        std::derived_from<Proc, iprocess>
    )
    class process : public Proc, public EVS, public CCS, public SM, public Logger {
    public:
        using proc_type     = Proc;
        using evs_type      = EVS;
        using ccs_type      = CCS;
        using sm_type       = SM;
        using logger_type   = Logger;
        using type          = process<proc_type, evs_type, ccs_type, sm_type, logger_type>;
    public:
        /*
        1. Инициализация менеджера настроек (чтение, парсинг, применение)
            - Если местоположение и название файла настроек изменено, то указывается аргумент командной строки <settings=path_to_file/file_name.json>
        2. Инициализация системы событий (инициализация SELECT, POLL, EPOLL, в зависимости от того, что выбрано, инициализация и запуск пула потоков)
        3. Инициализация системы коммуникации между компонентами ()
        4. Инициализация системы логирования
        !!! Все компоненты инициализируются, если они переданы в качестве параметров шаблона
        5. Инициализация и запуск служб
        */

        virtual ~process() noexcept {

        }

        process() noexcept = default;

        process(int argc, char** argv) {
            try {
                init(argc, argv);
            }
            catch(const exception_t& ex) {
                add_debug_item(ex, location_t::current());
                throw ex;
            }
        }

        constexpr void init(int argc, char** /*argv*/) {
            /**
             * @brief Парсинг аргументов командной строки
             * 
             * Если 
             * - есть аргументы командной строки
             **/
            if(argc > 1) { // первый аргумент - это местоположение исполняемого файла процесса
                
            }


            /**
             * @brief Менеджер настроек задан. Можно инициализировать
             * 
             **/
            if constexpr (!std::is_same_v<sm_type, tags::sm>) {

            }

            /**
             * @brief Система событий задана. Можно инициализировать
             * 
             **/
            if constexpr (!std::is_same_v<evs_type, tags::evs>) {

            }

            /**
             * @brief Система коммуникации между компонентами можно инициализировать
             * 
             **/
            if constexpr (!std::is_same_v<ccs_type, tags::ccs>) {

            }

            /**
             * @brief Система логирования задана. Можно инициализировать
             * 
             **/
            if constexpr (!std::is_same_v<logger_type, tags::logger>) {

            }
        }

        constexpr void deinit() {

        }

        constexpr void run() {

        }

        constexpr void stop() {

        }
    protected:
        helpers::cmd_line_parser m_cmd_line_parser{};
        sm_type m_sm;
    }; // process
} // namespace base
} // namespace trex

#endif // TREX_INCLUDE_BASE__PROCESS_H