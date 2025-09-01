/**
 * @file tmaster.h
 * @author Aleksey Vinogradov (aleksey.develop@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-03
 * 
 * Copyright 2024 AVM Research
 * 
 **/
#ifndef TREX_SRC_TMASTER_INCLUDE__TMASTER_H
#define TREX_SRS_TMASTER_INCLUDE__TMASTER_H

#include <base/process.h>

#include <settings.h>

namespace trex {
namespace tmaster {

    /**
     * @brief Описание мастер-процесса
     * 
     **/
    class master_process_def : public base::iprocess {
    public:
        using cmd_args = helpers::cmd_args<
            helpers::cmd_arg<string_view_t>,
            helpers::cmd_arg<bool>
        >;
    public:
        ~master_process_def() noexcept = default;
        master_process_def() noexcept = default;
    private:
        cmd_args m_cmd_args{
            { "string", "s", {} },
            { "daemon", "d", false }
        };
    }; // master_process_def

    using master_process = base::process<master_process_def>;
} // namespace tmaster
} // namespace trex

#endif // TREX_SRS_TMASTER_INCLUDE__TMASTER_H