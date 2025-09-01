/**
 * @file cmd_line.h
 * @author Aleksey Vinogradov (aleksey.develop@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-16
 * 
 * Copyright 2024 AVM Research
 * 
 **/
#ifndef TREX_INCLUDE_HELPERS__CMD_LINE_PARSER_H
#define TREX_INCLUDE_HELPERS__CMD_LINE_PARSER_H

#include <afsm/fsm.hpp>
#include <base.h>

namespace trex {
namespace helpers {
    using arg_long_name = string_view_t;
    using arg_short_name = string_view_t;

    struct cmd_arg_base {
        const arg_long_name long_name;
        const arg_short_name short_name;

        cmd_arg_base(arg_long_name ln, arg_short_name sn) noexcept :
        long_name{ ln },
        short_name{ sn } {}
    }; // cmd_arg_base

    template <typename Type>
    struct cmd_arg : cmd_arg_base {
        Type value;

        cmd_arg(arg_long_name ln, arg_short_name sn, Type v = {}) :
        cmd_arg_base{ ln, sn },
        value{ std::move(v) } {}
    }; // cmd_arg

    template <typename... Args>
    requires ((std::derived_from<Args, cmd_arg_base> && ...))
    using cmd_args = tuple_t<Args...>;

    class cmd_line_parser {
    public:
        ~cmd_line_parser() noexcept = default;
        cmd_line_parser() noexcept = default;        
    private:
        struct arg {};

        struct fsm_def : afsm::def::state_machine<fsm_def> {
            /***** States *****/
            struct initial : state<initial>{};
            struct final : state<final>{};

            using initial_state = initial;

            /***** Transitions table *****/
            using transitions = transition_table<
                tr<initial_state, arg, final, none, none>
            >;
        }; // fsm_def

        using fsm = afsm::state_machine<fsm_def>;
    private:
        fsm m_fsm;
    }; // cmd_line_parser
} // namespace helpers
} // namespace trex

#endif // TREX_INCLUDE_HELPERS__CMD_LINE_PARSER_H