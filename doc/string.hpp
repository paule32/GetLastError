// --------------------------------------------------------------------
// File:   string.hpp
// Author: (c) 2023 Jens Kallup - paule32
// All rights reserved
//
// only for education, and non-profit usage !
//
// @brief This file contains some signatures for the std:: container.
//        This file is a helper for the Doxygen documentation. It is
//        not the orginal file.
//        So, it could not use directly for productive development
//        purposes.
// --------------------------------------------------------------------
# pragma once

#ifdef DOXYGEN
/**
 * @brief This is the standard container, that contains re-written
 *        std:: container. It is not the original file, so you should
 *        not be used in productive applications. Because I can not
 *        give any gurantees for working or other purposes.
 */
namespace std {

/**
 * @brief This container structure can be used to use, and manupulate
 *        strings.
 */
struct string {
    /**
     * @brief This is only a simple constructor. It returns an empty
     *        std::string .
     */
    std::string operator()(void) const {
    }
    /**
     * @brief This constructs a std::string, and initialize the std::string
     *        with a given "const char* ".
     *
     * @param  const char*  A constant char*
     * @return std::string  Return the constructed "const char*" as std::string .
     */         
    std::string operator()(const char* value) const {
        auto   result = getErrorCode(value);
        return result.value_or("unknown error");
    }
};

}       // namespace: std
#endif  // DOXYGEN
