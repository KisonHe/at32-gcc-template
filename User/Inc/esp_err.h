#pragma once

#include <cstdint>
#include <cassert>
#include "printf.h"

/*
 * The likely and unlikely macro pairs:
 * These macros are useful to place when application
 * knows the majority ocurrence of a decision paths,
 * placing one of these macros can hint the compiler
 * to reorder instructions producing more optimized
 * code.
 */
#if (CONFIG_COMPILER_OPTIMIZATION_PERF)
#ifndef likely
#define likely(x)      __builtin_expect(!!(x), 1)
#endif
#ifndef unlikely
#define unlikely(x)    __builtin_expect(!!(x), 0)
#endif
#else
#ifndef likely
#define likely(x)      (x)
#endif
#ifndef unlikely
#define unlikely(x)    (x)
#endif
#endif

#define ASSERT_HANDLER while(1);   /*Halt by default*/

#define ASSERT_MSG(expr, msg)                                         \
    do {                                                                 \
        if(!(expr)) {                                                    \
            log_e("Asserted at expression: %s (%s)", #expr, msg); \
            ASSERT_HANDLER                                            \
        }                                                                \
    } while(0)

#define ASSERT_NULL(p) ASSERT_MSG(p != NULL, "NULL pointer");



/*
 * Utility macros used for designated initializers, which work differently
 * in C99 and C++ standards mainly for aggregate types.
 * The member separator, comma, is already part of the macro, please omit the trailing comma.
 * Usage example:
 *   struct config_t { char* pchr; char arr[SIZE]; } config = {
 *              ESP_COMPILER_DESIGNATED_INIT_AGGREGATE_TYPE_EMPTY(pchr)
 *              ESP_COMPILER_DESIGNATED_INIT_AGGREGATE_TYPE_STR(arr, "Value")
 *          };
 */
#ifdef __cplusplus
#define ESP_COMPILER_DESIGNATED_INIT_AGGREGATE_TYPE_STR(member, value)  { .member = value },
#define ESP_COMPILER_DESIGNATED_INIT_AGGREGATE_TYPE_EMPTY(member) .member = { },
#else
#define ESP_COMPILER_DESIGNATED_INIT_AGGREGATE_TYPE_STR(member, value)  .member = value,
#define ESP_COMPILER_DESIGNATED_INIT_AGGREGATE_TYPE_EMPTY(member)
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef int esp_err_t;

/* Definitions for error constants. */
#define ESP_OK          0       /*!< esp_err_t value indicating success (no error) */
#define ESP_FAIL        (-1)      /*!< Generic esp_err_t code indicating failure */

#define ESP_ERR_NO_MEM              0x101   /*!< Out of memory */
#define ESP_ERR_INVALID_ARG         0x102   /*!< Invalid argument */
#define ESP_ERR_INVALID_STATE       0x103   /*!< Invalid state */
#define ESP_ERR_INVALID_SIZE        0x104   /*!< Invalid size */
#define ESP_ERR_NOT_FOUND           0x105   /*!< Requested resource not found */
#define ESP_ERR_NOT_SUPPORTED       0x106   /*!< Operation or feature not supported */
#define ESP_ERR_TIMEOUT             0x107   /*!< Operation timed out */
#define ESP_ERR_INVALID_RESPONSE    0x108   /*!< Received response was invalid */
#define ESP_ERR_INVALID_CRC         0x109   /*!< CRC or checksum was invalid */
#define ESP_ERR_INVALID_VERSION     0x10A   /*!< Version was invalid */
#define ESP_ERR_INVALID_MAC         0x10B   /*!< MAC address was invalid */
#define ESP_ERR_NOT_FINISHED        0x10C   /*!< There are items remained to retrieve */
#define ESP_ERR_NO_AUTH             0x10D   /*!< Not authorized */
#define ESP_ERR_FAIL_TO_ACQUIRE_LOCK             0x10E   /*!< Fail to get the lock */


#define ESP_ERR_WIFI_BASE           0x3000  /*!< Starting number of WiFi error codes */
#define ESP_ERR_MESH_BASE           0x4000  /*!< Starting number of MESH error codes */
#define ESP_ERR_FLASH_BASE          0x6000  /*!< Starting number of flash error codes */
#define ESP_ERR_HW_CRYPTO_BASE      0xc000  /*!< Starting number of HW cryptography module error codes */

/**
  * @brief Returns string for esp_err_t error codes
  *
  * This function finds the error code in a pre-generated lookup-table and
  * returns its string representation.
  *
  * The function is generated by the Python script
  * tools/gen_esp_err_to_name.py which should be run each time an esp_err_t
  * error is modified, created or removed from the IDF project.
  *
  * @param code esp_err_t error code
  * @return string error message
  */
const char *esp_err_to_name(esp_err_t code);

/**
  * @brief Returns string for esp_err_t and system error codes
  *
  * This function finds the error code in a pre-generated lookup-table of
  * esp_err_t errors and returns its string representation. If the error code
  * is not found then it is attempted to be found among system errors.
  *
  * The function is generated by the Python script
  * tools/gen_esp_err_to_name.py which should be run each time an esp_err_t
  * error is modified, created or removed from the IDF project.
  *
  * @param code esp_err_t error code
  * @param[out] buf buffer where the error message should be written
  * @param buflen Size of buffer buf. At most buflen bytes are written into the buf buffer (including the terminating null byte).
  * @return buf containing the string error message
  */
const char *esp_err_to_name_r(esp_err_t code, char *buf, size_t buflen);

/** @cond */
void _esp_error_check_failed(esp_err_t rc, const char *file, int line, const char *function, const char *expression) __attribute__((noreturn));

/** @cond */
void _esp_error_check_failed_without_abort(esp_err_t rc, const char *file, int line, const char *function, const char *expression);

#ifndef __ASSERT_FUNC
/* This won't happen on IDF, which defines __ASSERT_FUNC in assert.h, but it does happen when building on the host which
   uses /usr/include/assert.h or equivalent.
*/
#ifdef __ASSERT_FUNCTION
#define __ASSERT_FUNC __ASSERT_FUNCTION /* used in glibc assert.h */
#else
#define __ASSERT_FUNC "??"
#endif
#endif
/** @endcond */

/**
 * Macro which can be used to check the error code,
 * and terminate the program in case the code is not ESP_OK.
 * Prints the error code, error location, and the failed statement to serial output.
 *
 * Disabled if assertions are disabled.
 */
#ifdef NDEBUG
#define ESP_ERROR_CHECK(x) do {                                         \
        esp_err_t err_rc_ = (x);                                        \
        (void) sizeof(err_rc_);                                         \
    } while(0)
#elif defined(CONFIG_COMPILER_OPTIMIZATION_ASSERTIONS_SILENT)
#define ESP_ERROR_CHECK(x) do {                                         \
        esp_err_t err_rc_ = (x);                                        \
        if (unlikely(err_rc_ != ESP_OK)) {                              \
            abort();                                                    \
        }                                                               \
    } while(0)
#else
#define ESP_ERROR_CHECK(x) do {                                         \
        esp_err_t err_rc_ = (x);                                        \
        if (unlikely(err_rc_ != ESP_OK)) {                              \
            _esp_error_check_failed(err_rc_, __FILE__, __LINE__,        \
                                    __ASSERT_FUNC, #x);                 \
        }                                                               \
    } while(0)
#endif

/**
 * Macro which can be used to check the error code. Prints the error code, error location, and the failed statement to
 * serial output.
 * In comparison with ESP_ERROR_CHECK(), this prints the same error message but isn't terminating the program.
 */
#if defined NDEBUG || defined CONFIG_COMPILER_OPTIMIZATION_ASSERTIONS_SILENT
#define ESP_ERROR_CHECK_WITHOUT_ABORT(x) ({                                         \
        esp_err_t err_rc_ = (x);                                                    \
        err_rc_;                                                                    \
    })
#else
#define ESP_ERROR_CHECK_WITHOUT_ABORT(x) ({                                         \
        esp_err_t err_rc_ = (x);                                                    \
        if (unlikely(err_rc_ != ESP_OK)) {                                          \
            _esp_error_check_failed_without_abort(err_rc_, __FILE__, __LINE__,      \
                                                  __ASSERT_FUNC, #x);               \
        }                                                                           \
        err_rc_;                                                                    \
    })
#endif //NDEBUG

#ifdef __cplusplus
}
#endif

