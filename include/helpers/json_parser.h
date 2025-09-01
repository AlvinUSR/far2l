/**
 * @file json_parser.h
 * @author Aleksey Vinogradov (aleksey.develop@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-11
 * 
 * Copyright 2024 AVM Research
 * 
 **/
#ifndef TREX_INCLUDE_HELPERS__JSON_PARSER_H
#define TREX_INCLUDE_HELPERS__JSON_PARSER_H

#include <fstream>
#include <sstream>
#include <json/json.h>
#include <base.h>

namespace trex {
    using json_t = nlohmann::json;

namespace helpers {
    class json_parser {
    public:
        ~json_parser() noexcept = default;
        json_parser() noexcept = default;

        constexpr base::result_t<json_t> parse(string_t path) {
            json_t _json_obj;
            std::ifstream _is;
            std::ostringstream _oss;
            string_t _path{ std::move(path) };
            
            try{
                _is.open(path, std::ios::in);
                
                if(!_is) { // ошибка открытия файла настроек
                    throw std::system_error(last_error, std::system_category(), "Невозможно открыть файл " + path);
                }

                _oss << _is.rdbuf();
                _json_obj = json_t::parse(_oss.str());
            }
            catch(const std::system_error& ex) {
                if(_is.is_open()) _is.close();
                return std::unexpected(base::error_t{ ex.code(), base::location_t::current() });
            }
            catch(const json_t::exception& ex) {
                if(_is.is_open()) _is.close();
                return std::unexpected(base::error_t{ nlohmann::make_error_code(ex.id), ex.what(),  base::location_t::current() });
            }

            if(_is.is_open()) _is.close();
            return _json_obj;
        }
    private:
        string_view_t m_settings_dir;
    }; // json_parser
} // namespace helpers
} // namespace trex

#endif // TREX_INCLUDE_HELPERS__JSON_PARSER_H