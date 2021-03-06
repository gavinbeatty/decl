
cmake_minimum_required(VERSION 2.6)
if(POLICY CMP0011)
    cmake_policy(PUSH)
    cmake_policy(SET CMP0011 NEW)
endif(POLICY CMP0011)

macro(macro_version_major_number _a _a_major)
    string(REGEX REPLACE "^([0-9]+)" "\\1" "${_a_major}" "${_a}")
    set("${_a_major}" "${CMAKE_MATCH_1}")
    if("${${_a_major}}" STREQUAL "")
        set("${_a_major}" "0")
    endif("${${_a_major}}" STREQUAL "")
endmacro(macro_version_major_number _a _a_major)
macro(macro_version_minor_number _a _a_minor)
    string(REGEX REPLACE "^[0-9]+\\.([0-9]+)" "\\1" "${_a_minor}" "${_a}")
    set("${_a_minor}" "${CMAKE_MATCH_1}")
    if("${${_a_minor}}" STREQUAL "")
        set("${_a_minor}" "0")
    endif("${${_a_minor}}" STREQUAL "")
endmacro(macro_version_minor_number _a _a_minor)
macro(macro_version_patch_number _a _a_patch)
    string(REGEX REPLACE "^[0-9]+\\.[0-9]+\\.([0-9]+)" "\\1" "${_a_patch}" "${_a}")
    set("${_a_patch}" "${CMAKE_MATCH_1}")
    if("${${_a_patch}}" STREQUAL "")
        set("${_a_patch}" "0")
    endif("${${_a_patch}}" STREQUAL "")
endmacro(macro_version_patch_number _a _a_patch)
macro(macro_version_other_number _a _a_other)
    string(REGEX REPLACE "^[0-9]+\\.[0-9]+\\.[0-9]+\\.([0-9]+)" "\\1" "${_a_other}" "${_a}")
    set("${_a_other}" "${CMAKE_MATCH_1}")
    if("${${_a_other}}" STREQUAL "")
        set("${_a_other}" "0")
    endif("${${_a_other}}" STREQUAL "")
endmacro(macro_version_other_number _a _a_other)
macro(macro_version_letter _a _a_letter)
    string(REGEX REPLACE "^[0-9.]*([a-zA-Z])$" "\\1" "${_a_letter}" "${_a}")
    set("${_a_letter}" "${CMAKE_MATCH_1}")
endmacro(macro_version_letter _a _a_letter)
macro(macro_normalize_version _a _norm _letter)
    macro_version_major_number("${_a}" _a_major)
    macro_version_minor_number("${_a}" _a_minor)
    macro_version_patch_number("${_a}" _a_patch)
    macro_version_other_number("${_a}" _a_other)
    macro_version_letter("${_a}" "${_letter}")
    foreach(_i "_a_major" "_a_minor" "_a_patch" "_a_other")
        if("${${_i}}" GREATER 99)
            message(SEND_ERROR "macro_normalize_version: can only handle version numbers less than 100 in each position.")
        endif("${${_i}}" GREATER 99)
    endforeach(_i "_a_major" "_a_minor" "_a_patch" "_a_other")
    math(EXPR "${_norm}" "${_a_other} + ( ${_a_patch} * 100 ) + ( ${_a_minor} * 10000 ) + ( ${_a_major} * 1000000 )")
endmacro(macro_normalize_version _a _norm _letter)

macro(macro_version_letter_cmp_ _a _b _result)
    if("${_a}" STREQUAL "${_b}")
        set("${_result}" 0)
    elseif("${_a}" STREQUAL "")
        set("${_result}" -1)
    elseif("${_b}" STREQUAL "")
        set("${_result}" 1)
    elseif("${_a}" STRLESS "${_b}")
        set("${_result}" -1)
    else("${_a}" STREQUAL "${_b}")
        set("${_result}" 1)
    endif("${_a}" STREQUAL "${_b}")
endmacro(macro_version_letter_cmp_ _a _b _result)

macro(macro_cmp_op_result_match _op _cmpresult _result)
    set("${_result}" 0)
    if("${_op}" STREQUAL "==" AND "${_cmpresult}" EQUAL 0)
        set("${_result}" 1)
    elseif("${_op}" STREQUAL "!=")
        if(NOT "${_cmpresult}" EQUAL 0)
            set("${_result}" 1)
        endif(NOT "${_cmpresult}" EQUAL 0)
    elseif("${_op}" STREQUAL "<" AND "${_cmpresult}" EQUAL -1)
        set("${_result}" 1)
    elseif("${_op}" STREQUAL ">" AND "${_cmpresult}" EQUAL 1)
        set("${_result}" 1)
    elseif("${_op}" STREQUAL "<=")
        if(NOT "${_cmpresult}" EQUAL 1)
            set("${_result}" 1)
        endif(NOT "${_cmpresult}" EQUAL 1)
    elseif("${_op}" STREQUAL ">=")
        if(NOT "${_cmpresult}" EQUAL -1)
            set("${_result}" 1)
        endif(NOT "${_cmpresult}" EQUAL -1)
    endif("${_op}" STREQUAL "==")
endmacro(macro_cmp_op_result_match _op _cmpresult _result)

macro(macro_version_cmp _a _b _result)
    if("${_a}" STREQUAL "${_b}")
        set("${_result}" 0)
    else("${_a}" STREQUAL "${_b}")
        macro_normalize_version("${_a}" _a_norm _a_letter)
        macro_normalize_version("${_b}" _b_norm _b_letter)
        if("${_a_norm}" EQUAL "${_b_norm}")
            macro_version_letter_cmp_("${_a_letter}" "${_b_letter}" "${_result}")
        elseif("${_a_norm}" LESS "${_b_norm}")
            set("${_result}" -1)
        else("${_a_norm}" EQUAL "${_b_norm}")
            set("${_result}" 1)
        endif("${_a_norm}" EQUAL "${_b_norm}")
    endif("${_a}" STREQUAL "${_b}")
endmacro(macro_version_cmp _a _b _result)

if(POLICY CMP0011)
    cmake_policy(POP)
endif(POLICY CMP0011)

