/**
 * @file json.h
 * @author Aleksey Vinogradov (aleksey.develop@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-12
 * 
 * Copyright 2024 AVM Research
 * 
 **/
#ifndef TREX_LIB_JSON__JSON_H
#define TREX_LIB_JSON__JSON_H

#include <string>
#include "json.hpp"

namespace nlohmann {
    enum class json_error {
        parse_error_101 = 101,
        parse_error_102 = 102,
        parse_error_103 = 103,
        parse_error_104 = 104,
        parse_error_105 = 105,
        parse_error_106 = 106,
        parse_error_107 = 107,
        parse_error_108 = 108,
        parse_error_109 = 109,
        parse_error_110 = 110,
        parse_error_112 = 112,
        parse_error_113 = 113,
        parse_error_114 = 114,
        invalid_iterator_201 = 201,
        invalid_iterator_202 = 202,
        invalid_iterator_203 = 203,
        invalid_iterator_204 = 204,
        invalid_iterator_205 = 205,
        invalid_iterator_206 = 206,
        invalid_iterator_207 = 207,
        invalid_iterator_208 = 208,
        invalid_iterator_209 = 209,
        invalid_iterator_210 = 210,
        invalid_iterator_211 = 211,
        invalid_iterator_212 = 212,
        invalid_iterator_213 = 213,
        invalid_iterator_214 = 214,
        type_error_301 = 301,
        type_error_302 = 302,
        type_error_303 = 303,
        type_error_304 = 304,
        type_error_305 = 305,
        type_error_306 = 306,
        type_error_307 = 307,
        type_error_308 = 308,
        type_error_309 = 309,
        type_error_310 = 310,
        type_error_311 = 311,
        type_error_312 = 312,
        type_error_313 = 313,
        type_error_314 = 314,
        type_error_315 = 315,
        type_error_316 = 316,
        type_error_317 = 317,
        out_of_range_401 = 401,
        out_of_range_402 = 402,
        out_of_range_403 = 403,
        out_of_range_404 = 404,
        out_of_range_405 = 405,
        out_of_range_406 = 406,
        out_of_range_407 = 407,
        out_of_range_408 = 408,
        out_of_range_409 = 409,
        over_error_501 = 501
    }; // json_error

    class json_error_category_impl : public std::error_category {
    public:
        virtual const char* name() const noexcept override { return "JSON error"; }

        virtual std::string message(int ev) const override {
            switch(static_cast<json_error>(ev)) {
            case json_error::parse_error_101: 
            case json_error::parse_error_102: 
            case json_error::parse_error_103: 
            case json_error::parse_error_104: 
            case json_error::parse_error_105:
            case json_error::parse_error_106:
            case json_error::parse_error_107:
            case json_error::parse_error_108:
            case json_error::parse_error_109:   
            case json_error::parse_error_110:
            case json_error::parse_error_112:
            case json_error::parse_error_113:
            case json_error::parse_error_114: return "JSON: Ошибка парсинга";
            case json_error::invalid_iterator_201:
            case json_error::invalid_iterator_202:
            case json_error::invalid_iterator_203:
            case json_error::invalid_iterator_204:
            case json_error::invalid_iterator_205:
            case json_error::invalid_iterator_206:
            case json_error::invalid_iterator_207:
            case json_error::invalid_iterator_208:
            case json_error::invalid_iterator_209:
            case json_error::invalid_iterator_210:
            case json_error::invalid_iterator_211:
            case json_error::invalid_iterator_212:
            case json_error::invalid_iterator_213:
            case json_error::invalid_iterator_214: return "JOSN: Ошибка итератора";
            case json_error::type_error_301:
            case json_error::type_error_302:
            case json_error::type_error_303:
            case json_error::type_error_304:
            case json_error::type_error_305:
            case json_error::type_error_306:
            case json_error::type_error_307:
            case json_error::type_error_308:
            case json_error::type_error_309:
            case json_error::type_error_310:
            case json_error::type_error_311:
            case json_error::type_error_312:
            case json_error::type_error_313:
            case json_error::type_error_314:
            case json_error::type_error_315:
            case json_error::type_error_316:
            case json_error::type_error_317: return "JSON: Ошибка типа";
            case json_error::out_of_range_401:
            case json_error::out_of_range_402:
            case json_error::out_of_range_403:
            case json_error::out_of_range_404:
            case json_error::out_of_range_405:
            case json_error::out_of_range_406:
            case json_error::out_of_range_407:
            case json_error::out_of_range_408:
            case json_error::out_of_range_409: return "JSON: Выход за пределы диапазона";
            case json_error::over_error_501: return "JSON: Ошибка"; 
            }
            return "Неизвестная ошибка JSON";
        }
    }; // json_error_category_impl

    const std::error_category& json_error_category() {
        static json_error_category_impl instance;
        return instance;
    }

    std::error_code make_error_code(json_error e) {
        return std::error_code(static_cast<int>(e), json_error_category());
    }

    std::error_code make_error_code(int code) {
        return make_error_code(static_cast<json_error>(code));
    }

    std::error_condition make_error_condition(json_error e) {
        return std::error_condition(static_cast<int>(e), json_error_category());
    }
} // nlohmann

namespace std
{
    template<>
    struct is_error_code_enum<nlohmann::json_error> : public true_type {};
}

#endif // TREX_LIB_JSON__JSON_H