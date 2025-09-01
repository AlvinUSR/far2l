/**
 * @file settings.h
 * @author Aleksey Vinogradov (aleksey.develop@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-11
 * 
 * Copyright 2024 AVM Research
 * 
 **/
#ifndef TREX_SRS_TMASTER_INCLUDE__SETTINGS_H
#define TREX_SRS_TMASTER_INCLUDE__SETTINGS_H

#include <base.h>
#include <sm/settings.h>

#include <config.h>

namespace trex {
namespace tmaster {
    constexpr auto def_settings_file_name = "trex.json";

    /**
     * @brief Контейнер настроек мастер процесса
     * 
     **/
    using tmaster_settings = tuple_t<

    >;
} // namespace tmaster
} // namespace trex

#endif // TREX_SRS_TMASTER_INCLUDE__SETTINGS_H