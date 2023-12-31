// --------------------------------------------------------------------
// File:   GetLastError.cc
// Author: (c) 2023 Jens Kallup - paule32
// All rights reserved
//
// only for education, and non-profit usage !
//
// @brief This file contains the Microsoft Windows 10 error codes, that
//        can be use in context with the win32api member "GetLastError"
//        The error code will be map'ed into a std::map list in origin
//        language of en_US.
//        To use in your own application, you can use the po/mo locale
//        files for localization. You can find these files as attached.
//
//        Feel free, and drop a message, if you find mistakes/error's.
// --------------------------------------------------------------------
extern "C" {
# include <windows.h>   // DWORD, ...

# include <libintl.h>   // locale: gettext
# include <locale.h>    // localization
};

// --------------------------------------------------------------------
// C++ standard header stuff ...
// --------------------------------------------------------------------
#ifdef DOXYGEN
# include <string.hpp>
#else
# include <iostream>
# include <string>      // std::string
# include <map>         // std::map
# include <optional>
# include <functional>  // std::function
# include <sstream>
# include <any>
#endif                  // DOXYGEN

/**
 * @namespace windows
 * @brief The MSDN - Microsoft Developer Network documentation.
 *
 * The documentaton contains informations, that is not confirm with the developer header
 * kit stuff. So, I collect the most informations from the first developer source (the msdn).
 * I don't know in detail, if the informations there are all in right order.
 * If you find a typo or other wrong informations, let it me know, and drop a message.
 * I apologies me in forward for future errors.
 * The most, what I did there was: #undef all possible codes, and provide a modern C++ coding
 * style of "inline" members. Inline functions are the new C++ #define features.
 *
 * We use a namespace, to hope that no other conflicts with an other library or header stuff
 * occur. I simply call it: namespace windows.
 * You, as developer can invoke the namespace in your source files via:
 * "using namespace windows".
 */
# undef ERROR_SUCCESS
# undef ERROR_INVALID_FUNCTION
# undef ERROR_FILE_NOT_FOUND
# undef ERROR_PATH_NOT_FOUND
# undef ERROR_TOO_MANY_OPEN_FILES
# undef ERROR_ACCESS_DENIED
# undef ERROR_INVALID_HANDLE
# undef ERROR_ARENA_TRASHED
# undef ERROR_NOT_ENOUGH_MEMORY
# undef ERROR_INVALID_BLOCK
# undef ERROR_BAD_ENVIRONMENT
# undef ERROR_BAD_FORMAT
# undef ERROR_INVALID_ACCESS
# undef ERROR_INVALID_DATA
# undef ERROR_OUTOFMEMORY
# undef ERROR_INVALID_DRIVE
# undef ERROR_CURRENT_DIRECTORY
# undef ERROR_NOT_SAME_DEVICE
# undef ERROR_NO_MORE_FILES
# undef ERROR_WRITE_PROTECT
# undef ERROR_BAD_UNIT
# undef ERROR_NOT_READY
# undef ERROR_BAD_COMMAND
# undef ERROR_CRC
# undef ERROR_BAD_LENGTH
# undef ERROR_SEEK
# undef ERROR_NOT_DOS_DISK
# undef ERROR_SECTOR_NOT_FOUND
# undef ERROR_OUT_OF_PAPER
# undef ERROR_WRITE_FAULT
# undef ERROR_READ_FAULT
# undef ERROR_GEN_FAILURE
# undef ERROR_SHARING_VIOLATION
# undef ERROR_LOCK_VIOLATION
# undef ERROR_WRONG_DISK
# undef ERROR_SHARING_BUFFER_EXCEEDED
# undef ERROR_HANDLE_EOF
# undef ERROR_HANDLE_DISK_FULL
# undef ERROR_NOT_SUPPORTED
# undef ERROR_REM_NOT_LIST
# undef ERROR_DUP_NAME
# undef ERROR_BAD_NETPATH
# undef ERROR_NETWORK_BUSY
# undef ERROR_DEV_NOT_EXIST
# undef ERROR_TOO_MANY_CMDS
# undef ERROR_ADAP_HDW_ERR
# undef ERROR_BAD_NET_RESP
# undef ERROR_UNEXP_NET_ERR
# undef ERROR_BAD_REM_ADAP
# undef ERROR_PRINTQ_FULL
# undef ERROR_NO_SPOOL_SPACE
# undef ERROR_PRINT_CANCELLED
# undef ERROR_NETNAME_DELETED
# undef ERROR_NETWORK_ACCESS_DENIED
# undef ERROR_BAD_DEV_TYPE
# undef ERROR_BAD_NET_NAME
# undef ERROR_TOO_MANY_NAMES
# undef ERROR_TOO_MANY_SESS
# undef ERROR_SHARING_PAUSED
# undef ERROR_REQ_NOT_ACCEP
# undef ERROR_REDIR_PAUSED
# undef ERROR_FILE_EXISTS
# undef ERROR_CANNOT_MAKE
# undef ERROR_FAIL_I24
# undef ERROR_OUT_OF_STRUCTURES
# undef ERROR_ALREADY_ASSIGNED
# undef ERROR_INVALID_PASSWORD
# undef ERROR_INVALID_PARAMETER
# undef ERROR_NET_WRITE_FAULT
# undef ERROR_NO_PROC_SLOTS
# undef ERROR_TOO_MANY_SEMAPHORES
# undef ERROR_EXCL_SEM_ALREADY_OWNED
# undef ERROR_SEM_IS_SET
# undef ERROR_TOO_MANY_SEM_REQUESTS
# undef ERROR_INVALID_AT_INTERRUPT_TIME
# undef ERROR_SEM_OWNER_DIED
# undef ERROR_SEM_USER_LIMIT
# undef ERROR_DISK_CHANGE
# undef ERROR_DRIVE_LOCKED
# undef ERROR_BROKEN_PIPE
# undef ERROR_OPEN_FAILED
# undef ERROR_BUFFER_OVERFLOW
# undef ERROR_DISK_FULL
# undef ERROR_NO_MORE_SEARCH_HANDLES
# undef ERROR_INVALID_TARGET_HANDLE
# undef ERROR_INVALID_CATEGORY
# undef ERROR_INVALID_VERIFY_SWITCH
# undef ERROR_BAD_DRIVER_LEVEL
# undef ERROR_CALL_NOT_IMPLEMENTED
# undef ERROR_SEM_TIMEOUT
# undef ERROR_INSUFFICIENT_BUFFER
# undef ERROR_INVALID_NAME
# undef ERROR_INVALID_LEVEL
# undef ERROR_NO_VOLUME_LABEL
# undef ERROR_MOD_NOT_FOUND
# undef ERROR_PROC_NOT_FOUND
# undef ERROR_WAIT_NO_CHILDREN
# undef ERROR_CHILD_NOT_COMPLETE
# undef ERROR_DIRECT_ACCESS_HANDLE
# undef ERROR_NEGATIVE_SEEK
# undef ERROR_SEEK_ON_DEVICE
# undef ERROR_IS_JOIN_TARGET
# undef ERROR_IS_JOINED
# undef ERROR_IS_SUBSTED
# undef ERROR_NOT_JOINED
# undef ERROR_NOT_SUBSTED
# undef ERROR_JOIN_TO_JOIN
# undef ERROR_SUBST_TO_SUBST
# undef ERROR_JOIN_TO_SUBST
# undef ERROR_SUBST_TO_JOIN
# undef ERROR_BUSY_DRIVE
# undef ERROR_SAME_DRIVE
# undef ERROR_DIR_NOT_ROOT
# undef ERROR_DIR_NOT_EMPTY
# undef ERROR_IS_SUBST_PATH
# undef ERROR_IS_JOIN_PATH
# undef ERROR_PATH_BUSY
# undef ERROR_IS_SUBST_TARGET
# undef ERROR_SYSTEM_TRACE
# undef ERROR_INVALID_EVENT_COUNT
# undef ERROR_TOO_MANY_MUXWAITERS
# undef ERROR_INVALID_LIST_FORMAT
# undef ERROR_LABEL_TOO_LONG
# undef ERROR_TOO_MANY_TCBS
# undef ERROR_SIGNAL_REFUSED
# undef ERROR_DISCARDED
# undef ERROR_NOT_LOCKED
# undef ERROR_BAD_THREADID_ADDR
# undef ERROR_BAD_ARGUMENTS
# undef ERROR_BAD_PATHNAME
# undef ERROR_SIGNAL_PENDING
# undef ERROR_MAX_THRDS_REACHED
# undef ERROR_LOCK_FAILED
# undef ERROR_BUSY
# undef ERROR_DEVICE_SUPPORT_IN_PROGRESS
# undef ERROR_CANCEL_VIOLATION
# undef ERROR_ATOMIC_LOCKS_NOT_SUPPORTED
# undef ERROR_INVALID_SEGMENT_NUMBER
# undef ERROR_INVALID_ORDINAL
# undef ERROR_ALREADY_EXISTS
# undef ERROR_INVALID_FLAG_NUMBER
# undef ERROR_SEM_NOT_FOUND
# undef ERROR_INVALID_STARTING_CODESEG
# undef ERROR_INVALID_STACKSEG
# undef ERROR_INVALID_MODULETYPE
# undef ERROR_INVALID_EXE_SIGNATURE
# undef ERROR_EXE_MARKED_INVALID
# undef ERROR_BAD_EXE_FORMAT
# undef ERROR_ITERATED_DATA_EXCEEDS_64k
# undef ERROR_INVALID_MINALLOCSIZE
# undef ERROR_DYNLINK_FROM_INVALID_RING
# undef ERROR_IOPL_NOT_ENABLED
# undef ERROR_INVALID_SEGDPL
# undef ERROR_AUTODATASEG_EXCEEDS_64k
# undef ERROR_RING2SEG_MUST_BE_MOVABLE
# undef ERROR_RELOC_CHAIN_XEEDS_SEGLIM
# undef ERROR_INFLOOP_IN_RELOC_CHAIN
# undef ERROR_ENVVAR_NOT_FOUND
# undef ERROR_NO_SIGNAL_SENT
# undef ERROR_FILENAME_EXCED_RANGE
# undef ERROR_RING2_STACK_IN_USE
# undef ERROR_META_EXPANSION_TOO_LONG
# undef ERROR_INVALID_SIGNAL_NUMBER
# undef ERROR_THREAD_1_INACTIVE
# undef ERROR_LOCKED
# undef ERROR_TOO_MANY_MODULES
# undef ERROR_NESTING_NOT_ALLOWED
# undef ERROR_EXE_MACHINE_TYPE_MISMATCH
# undef ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY
# undef ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY
# undef ERROR_FILE_CHECKED_OUT
# undef ERROR_CHECKOUT_REQUIRED
# undef ERROR_BAD_FILE_TYPE
# undef ERROR_FILE_TOO_LARGE
# undef ERROR_FORMS_AUTH_REQUIRED
# undef ERROR_VIRUS_INFECTED
# undef ERROR_VIRUS_DELETED
# undef ERROR_PIPE_LOCAL
# undef ERROR_BAD_PIPE
# undef ERROR_PIPE_BUSY
# undef ERROR_NO_DATA
# undef ERROR_PIPE_NOT_CONNECTED
# undef ERROR_MORE_DATA
# undef ERROR_VC_DISCONNECTED
# undef ERROR_INVALID_EA_NAME
# undef ERROR_EA_LIST_INCONSISTENT
# undef WAIT_TIMEOUT
# undef ERROR_NO_MORE_ITEMS
# undef ERROR_CANNOT_COPY
# undef ERROR_DIRECTORY
# undef ERROR_EAS_DIDNT_FIT
# undef ERROR_EA_FILE_CORRUPT
# undef ERROR_EA_TABLE_FULL
# undef ERROR_INVALID_EA_HANDLE
# undef ERROR_EAS_NOT_SUPPORTED
# undef ERROR_NOT_OWNER
# undef ERROR_TOO_MANY_POSTS
# undef ERROR_PARTIAL_COPY
# undef ERROR_OPLOCK_NOT_GRANTED
# undef ERROR_INVALID_OPLOCK_PROTOCOL
# undef ERROR_DISK_TOO_FRAGMENTED
# undef ERROR_DELETE_PENDING
# undef ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING
# undef ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME
# undef ERROR_SECURITY_STREAM_IS_INCONSISTENT
# undef ERROR_INVALID_LOCK_RANGE
# undef ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT
# undef ERROR_NOTIFICATION_GUID_ALREADY_DEFINED
# undef ERROR_INVALID_EXCEPTION_HANDLER
# undef ERROR_DUPLICATE_PRIVILEGES
# undef ERROR_NO_RANGES_PROCESSED
# undef ERROR_NOT_ALLOWED_ON_SYSTEM_FILE
# undef ERROR_DISK_RESOURCES_EXHAUSTED
# undef ERROR_INVALID_TOKEN
# undef ERROR_DEVICE_FEATURE_NOT_SUPPORTED
# undef ERROR_MR_MID_NOT_FOUND
# undef ERROR_SCOPE_NOT_FOUND
# undef ERROR_UNDEFINED_SCOPE
# undef ERROR_INVALID_CAP
# undef ERROR_DEVICE_UNREACHABLE
# undef ERROR_DEVICE_NO_RESOURCES
# undef ERROR_DATA_CHECKSUM_ERROR
# undef ERROR_INTERMIXED_KERNEL_EA_OPERATION
# undef ERROR_FILE_LEVEL_TRIM_NOT_SUPPORTED
# undef ERROR_OFFSET_ALIGNMENT_VIOLATION
# undef ERROR_INVALID_FIELD_IN_PARAMETER_LIST
# undef ERROR_OPERATION_IN_PROGRESS
# undef ERROR_BAD_DEVICE_PATH
# undef ERROR_TOO_MANY_DESCRIPTORS
# undef ERROR_SCRUB_DATA_DISABLED
# undef ERROR_NOT_REDUNDANT_STORAGE
# undef ERROR_RESIDENT_FILE_NOT_SUPPORTED
# undef ERROR_COMPRESSED_FILE_NOT_SUPPORTED
# undef ERROR_DIRECTORY_NOT_SUPPORTED
# undef ERROR_NOT_READ_FROM_COPY
# undef ERROR_FAIL_NOACTION_REBOOT
# undef ERROR_FAIL_SHUTDOWN
# undef ERROR_FAIL_RESTART
# undef ERROR_MAX_SESSIONS_REACHED
# undef ERROR_THREAD_MODE_ALREADY_BACKGROUND
# undef ERROR_THREAD_MODE_NOT_BACKGROUND
# undef ERROR_PROCESS_MODE_ALREADY_BACKGROUND
# undef ERROR_PROCESS_MODE_NOT_BACKGROUND
# undef ERROR_INVALID_ADDRESS

namespace windows {

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SUCCESS() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_FUNCTION() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_FILE_NOT_FOUND() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_PATH_NOT_FOUND() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_TOO_MANY_OPEN_FILES() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_ACCESS_DENIED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_HANDLE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_ARENA_TRASHED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NOT_ENOUGH_MEMORY() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_BLOCK() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_ENVIRONMENT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_FORMAT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_ACCESS() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_DATA() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_OUTOFMEMORY() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_DRIVE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_CURRENT_DIRECTORY() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NOT_SAME_DEVICE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NO_MORE_FILES() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_WRITE_PROTECT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_UNIT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NOT_READY() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_COMMAND() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_CRC() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_LENGTH() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SEEK() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NOT_DOS_DISK() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SECTOR_NOT_FOUND() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_OUT_OF_PAPER() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_WRITE_FAULT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_READ_FAULT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_GEN_FAILURE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SHARING_VIOLATION() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_LOCK_VIOLATION() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_WRONG_DISK() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SHARING_BUFFER_EXCEEDED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_HANDLE_EOF() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_HANDLE_DISK_FULL() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NOT_SUPPORTED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_REM_NOT_LIST() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DUP_NAME() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_NETPATH() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NETWORK_BUSY() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DEV_NOT_EXIST() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_TOO_MANY_CMDS() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_ADAP_HDW_ERR() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_NET_RESP() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_UNEXP_NET_ERR() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_REM_ADAP() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_PRINTQ_FULL() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NO_SPOOL_SPACE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_PRINT_CANCELLED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NETNAME_DELETED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NETWORK_ACCESS_DENIED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_DEV_TYPE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_NET_NAME() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_TOO_MANY_NAMES() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_TOO_MANY_SESS() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SHARING_PAUSED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_REQ_NOT_ACCEP() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_REDIR_PAUSED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_FILE_EXISTS() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_CANNOT_MAKE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_FAIL_I24() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_OUT_OF_STRUCTURES() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_ALREADY_ASSIGNED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_PASSWORD() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_PARAMETER() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NET_WRITE_FAULT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NO_PROC_SLOTS() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_TOO_MANY_SEMAPHORES() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_EXCL_SEM_ALREADY_OWNED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SEM_IS_SET() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_TOO_MANY_SEM_REQUESTS() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_AT_INTERRUPT_TIME() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SEM_OWNER_DIED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SEM_USER_LIMIT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DISK_CHANGE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DRIVE_LOCKED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BROKEN_PIPE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_OPEN_FAILED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BUFFER_OVERFLOW() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DISK_FULL() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NO_MORE_SEARCH_HANDLES() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_TARGET_HANDLE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_CATEGORY() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_VERIFY_SWITCH() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_DRIVER_LEVEL() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_CALL_NOT_IMPLEMENTED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SEM_TIMEOUT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INSUFFICIENT_BUFFER() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_NAME() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_LEVEL() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NO_VOLUME_LABEL() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_MOD_NOT_FOUND() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_PROC_NOT_FOUND() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_WAIT_NO_CHILDREN() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_CHILD_NOT_COMPLETE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DIRECT_ACCESS_HANDLE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NEGATIVE_SEEK() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SEEK_ON_DEVICE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_IS_JOIN_TARGET() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_IS_JOINED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_IS_SUBSTED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NOT_JOINED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NOT_SUBSTED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_JOIN_TO_JOIN() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SUBST_TO_SUBST() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_JOIN_TO_SUBST() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SUBST_TO_JOIN() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BUSY_DRIVE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SAME_DRIVE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DIR_NOT_ROOT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DIR_NOT_EMPTY() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_IS_SUBST_PATH() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_IS_JOIN_PATH() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_PATH_BUSY() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_IS_SUBST_TARGET() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SYSTEM_TRACE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_EVENT_COUNT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_TOO_MANY_MUXWAITERS() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_LIST_FORMAT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_LABEL_TOO_LONG() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_TOO_MANY_TCBS() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SIGNAL_REFUSED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DISCARDED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NOT_LOCKED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_THREADID_ADDR() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_ARGUMENTS() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_PATHNAME() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SIGNAL_PENDING() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_MAX_THRDS_REACHED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_LOCK_FAILED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BUSY() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DEVICE_SUPPORT_IN_PROGRESS() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_CANCEL_VIOLATION() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_ATOMIC_LOCKS_NOT_SUPPORTED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_SEGMENT_NUMBER() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_ORDINAL() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_ALREADY_EXISTS() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_FLAG_NUMBER() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SEM_NOT_FOUND() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_STARTING_CODESEG() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_STACKSEG() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_MODULETYPE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_EXE_SIGNATURE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_EXE_MARKED_INVALID() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_EXE_FORMAT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_ITERATED_DATA_EXCEEDS_64k() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_MINALLOCSIZE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DYNLINK_FROM_INVALID_RING() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_IOPL_NOT_ENABLED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_SEGDPL() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_AUTODATASEG_EXCEEDS_64k() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_RING2SEG_MUST_BE_MOVABLE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_RELOC_CHAIN_XEEDS_SEGLIM() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INFLOOP_IN_RELOC_CHAIN() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_ENVVAR_NOT_FOUND() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NO_SIGNAL_SENT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_FILENAME_EXCED_RANGE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_RING2_STACK_IN_USE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_META_EXPANSION_TOO_LONG() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_SIGNAL_NUMBER() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_THREAD_1_INACTIVE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_LOCKED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_TOO_MANY_MODULES() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NESTING_NOT_ALLOWED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_EXE_MACHINE_TYPE_MISMATCH() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_FILE_CHECKED_OUT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_CHECKOUT_REQUIRED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_FILE_TYPE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_FILE_TOO_LARGE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_FORMS_AUTH_REQUIRED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_VIRUS_INFECTED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_VIRUS_DELETED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_PIPE_LOCAL() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_PIPE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_PIPE_BUSY() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NO_DATA() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_PIPE_NOT_CONNECTED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_MORE_DATA() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_VC_DISCONNECTED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_EA_NAME() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_EA_LIST_INCONSISTENT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD WAIT_TIMEOUT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NO_MORE_ITEMS() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_CANNOT_COPY() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DIRECTORY() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_EAS_DIDNT_FIT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_EA_FILE_CORRUPT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_EA_TABLE_FULL() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_EA_HANDLE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_EAS_NOT_SUPPORTED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NOT_OWNER() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_TOO_MANY_POSTS() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_PARTIAL_COPY() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_OPLOCK_NOT_GRANTED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_OPLOCK_PROTOCOL() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DISK_TOO_FRAGMENTED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DELETE_PENDING() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SECURITY_STREAM_IS_INCONSISTENT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_LOCK_RANGE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NOTIFICATION_GUID_ALREADY_DEFINED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_EXCEPTION_HANDLER() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DUPLICATE_PRIVILEGES() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NO_RANGES_PROCESSED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NOT_ALLOWED_ON_SYSTEM_FILE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DISK_RESOURCES_EXHAUSTED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_TOKEN() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DEVICE_FEATURE_NOT_SUPPORTED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_MR_MID_NOT_FOUND() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SCOPE_NOT_FOUND() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_UNDEFINED_SCOPE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_CAP() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DEVICE_UNREACHABLE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DEVICE_NO_RESOURCES() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DATA_CHECKSUM_ERROR() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INTERMIXED_KERNEL_EA_OPERATION() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_FILE_LEVEL_TRIM_NOT_SUPPORTED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_OFFSET_ALIGNMENT_VIOLATION() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_FIELD_IN_PARAMETER_LIST() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_OPERATION_IN_PROGRESS() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_BAD_DEVICE_PATH() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_TOO_MANY_DESCRIPTORS() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_SCRUB_DATA_DISABLED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NOT_REDUNDANT_STORAGE() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_RESIDENT_FILE_NOT_SUPPORTED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_COMPRESSED_FILE_NOT_SUPPORTED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_DIRECTORY_NOT_SUPPORTED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_NOT_READ_FROM_COPY() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_FAIL_NOACTION_REBOOT() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_FAIL_SHUTDOWN() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_FAIL_RESTART() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_MAX_SESSIONS_REACHED() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_THREAD_MODE_ALREADY_BACKGROUND() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_THREAD_MODE_NOT_BACKGROUND() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_PROCESS_MODE_ALREADY_BACKGROUND() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_PROCESS_MODE_NOT_BACKGROUND() { return 0x0; }

/**
 * @brief This inline function contains the inline functions for the error
 *        codes ERROR_SUCCESS as return result.
 *
 * @return DWORD  -  The error code number.
 */
inline DWORD ERROR_INVALID_ADDRESS() { return 0x0; }

/**
 * @brief This is our error code \color{yellow,std::map} list. The first parameter is the inline error code with the data type \ref DWORD
 *        The seocnd parameter is the short error message.
 */
std::map< DWORD, std::string > WindowsErrorCode =
{
    { ERROR_SUCCESS(),"The operation completed successfully." },
    { ERROR_INVALID_FUNCTION(),"Incorrect function." },
    { ERROR_FILE_NOT_FOUND(),"The system cannot find the file specified." },
    { ERROR_PATH_NOT_FOUND(),"The system cannot find the path specified." },
    { ERROR_TOO_MANY_OPEN_FILES(),"The system cannot open the file." },
    { ERROR_ACCESS_DENIED(),"Access is denied." },
    { ERROR_INVALID_HANDLE(),"The handle is invalid." },
    { ERROR_ARENA_TRASHED(),"The storage control blocks were destroyed." },
    { ERROR_NOT_ENOUGH_MEMORY(),"Not enough memory resources are available to process this command." },
    { ERROR_INVALID_BLOCK(),"The storage control block address is invalid." },
    { ERROR_BAD_ENVIRONMENT(),"The environment is incorrect." },
    { ERROR_BAD_FORMAT(),"An attempt was made to load a program with an incorrect format." },
    { ERROR_INVALID_ACCESS(),"The access code is invalid." },
    { ERROR_INVALID_DATA(),"The data is invalid." },
    { ERROR_OUTOFMEMORY(),"Not enough storage is available to complete this operation." },
    { ERROR_INVALID_DRIVE(),"The system cannot find the drive specified." },
    { ERROR_CURRENT_DIRECTORY(),"The directory cannot be removed." },
    { ERROR_NOT_SAME_DEVICE(),"The system cannot move the file to a different disk drive." },
    { ERROR_NO_MORE_FILES(),"There are no more files." },
    { ERROR_WRITE_PROTECT(),"The media is write protected." },
    { ERROR_BAD_UNIT(),"The system cannot find the device specified." },
    { ERROR_NOT_READY(),"The device is not ready." },
    { ERROR_BAD_COMMAND(),"The device does not recognize the command." },
    { ERROR_CRC(),"Data error (cyclic redundancy check)." },
    { ERROR_BAD_LENGTH(),"The program issued a command but the command length is incorrect." },
    { ERROR_SEEK(),"The drive cannot locate a specific area or track on the disk." },
    { ERROR_NOT_DOS_DISK(),"The specified disk or diskette cannot be accessed." },
    { ERROR_SECTOR_NOT_FOUND(),"The drive cannot find the sector requested." },
    { ERROR_OUT_OF_PAPER(),"The printer is out of paper." },
    { ERROR_WRITE_FAULT(),"The system cannot write to the specified device." },
    { ERROR_READ_FAULT(),"The system cannot read from the specified device." },
    { ERROR_GEN_FAILURE(),"A device attached to the system is not functioning." },
    { ERROR_SHARING_VIOLATION(),"The process cannot access the file because it is being used by another process." },
    { ERROR_LOCK_VIOLATION(),"The process cannot access the file because another process has locked a portion of the file." },
    { ERROR_WRONG_DISK(),"The wrong diskette is in the drive. Insert %2 (Volume Serial Number: %3) into drive %1." },
    { ERROR_SHARING_BUFFER_EXCEEDED(),"Too many files opened for sharing." },
    { ERROR_HANDLE_EOF(),"Reached the end of the file." },
    { ERROR_HANDLE_DISK_FULL(),"The disk is full." },
    { ERROR_NOT_SUPPORTED(),"The request is not supported." },
    { ERROR_REM_NOT_LIST(),
    "Windows cannot find the network path. Verify that the network path is "
    "correct and the destination computer is not busy or turned off. If Windows "
    "still cannot find the network path, contact your network administrator." },
    { ERROR_DUP_NAME(),
    "You were not connected because a duplicate name exists on the network. "
    "If joining a domain, go to System in Control Panel to change the computer "
    "name and try again. If joining a workgroup, choose another workgroup name." },
    { ERROR_BAD_NETPATH(),"The network path was not found." },
    { ERROR_NETWORK_BUSY(),"The network is busy." },
    { ERROR_DEV_NOT_EXIST(),"The specified network resource or device is no longer available." },
    { ERROR_TOO_MANY_CMDS(),"The network BIOS command limit has been reached." },
    { ERROR_ADAP_HDW_ERR(),"A network adapter hardware error occurred." },
    { ERROR_BAD_NET_RESP(),"The specified server cannot perform the requested operation." },
    { ERROR_UNEXP_NET_ERR(),"An unexpected network error occurred." },
    { ERROR_BAD_REM_ADAP(),"The remote adapter is not compatible." },
    { ERROR_PRINTQ_FULL(),"The printer queue is full." },
    { ERROR_NO_SPOOL_SPACE(),"Space to store the file waiting to be printed is not available on the server." },
    { ERROR_PRINT_CANCELLED(),"Your file waiting to be printed was deleted." },
    { ERROR_NETNAME_DELETED(),"The specified network name is no longer available." },
    { ERROR_NETWORK_ACCESS_DENIED(),"Network access is denied." },
    { ERROR_BAD_DEV_TYPE(),"The network resource type is not correct." },
    { ERROR_BAD_NET_NAME(),"The network name cannot be found." },
    { ERROR_TOO_MANY_NAMES(),"The name limit for the local computer network adapter card was exceeded." },
    { ERROR_TOO_MANY_SESS(),"The network BIOS session limit was exceeded." },
    { ERROR_SHARING_PAUSED(),"The remote server has been paused or is in the process of being started." },
    { ERROR_REQ_NOT_ACCEP(),
    "No more connections can be made to this remote computer at this time "
    "because there are already as many connections as the computer can accept." },
    { ERROR_REDIR_PAUSED(),"The specified printer or disk device has been paused." },
    { ERROR_FILE_EXISTS(),"The file exists." },
    { ERROR_CANNOT_MAKE(),"The directory or file cannot be created." },
    { ERROR_FAIL_I24(),"Fail on INT 24." },
    { ERROR_OUT_OF_STRUCTURES(),"Storage to process this request is not available." },
    { ERROR_ALREADY_ASSIGNED(),"The local device name is already in use." },
    { ERROR_INVALID_PASSWORD(),"The specified network password is not correct." },
    { ERROR_INVALID_PARAMETER(),"The parameter is incorrect." },
    { ERROR_NET_WRITE_FAULT(),"A write fault occurred on the network." },
    { ERROR_NO_PROC_SLOTS(),"The system cannot start another process at this time." },
    { ERROR_TOO_MANY_SEMAPHORES(),"Cannot create another system semaphore." },
    { ERROR_EXCL_SEM_ALREADY_OWNED(),"The exclusive semaphore is owned by another process." },
    { ERROR_SEM_IS_SET(),"The semaphore is set and cannot be closed." },
    { ERROR_TOO_MANY_SEM_REQUESTS(),"The semaphore cannot be set again." },
    { ERROR_INVALID_AT_INTERRUPT_TIME(),"Cannot request exclusive semaphores at interrupt time." },
    { ERROR_SEM_OWNER_DIED(),"The previous ownership of this semaphore has ended." },
    { ERROR_SEM_USER_LIMIT(),"Insert the diskette for drive %1." },
    { ERROR_DISK_CHANGE(),"The program stopped because an alternate diskette was not inserted." },
    { ERROR_DRIVE_LOCKED(),"The disk is in use or locked by another process." },
    { ERROR_BROKEN_PIPE(),"The pipe has been ended." },
    { ERROR_OPEN_FAILED(),"The system cannot open the device or file specified." },
    { ERROR_BUFFER_OVERFLOW(),"The file name is too long." },
    { ERROR_DISK_FULL(),"There is not enough space on the disk." },
    { ERROR_NO_MORE_SEARCH_HANDLES(),"No more internal file identifiers available." },
    { ERROR_INVALID_TARGET_HANDLE(),"The target internal file identifier is incorrect." },
    { ERROR_INVALID_CATEGORY(),"The IOCTL call made by the application program is not correct." },
    { ERROR_INVALID_VERIFY_SWITCH(),"The verify-on-write switch parameter value is not correct." },
    { ERROR_BAD_DRIVER_LEVEL(),"The system does not support the command requested." },
    { ERROR_CALL_NOT_IMPLEMENTED(),"This function is not supported on this system." },
    { ERROR_SEM_TIMEOUT(),"The semaphore timeout period has expired." },
    { ERROR_INSUFFICIENT_BUFFER(),"The data area passed to a system call is too small." },
    { ERROR_INVALID_NAME(),"The filename, directory name, or volume label syntax is incorrect." },
    { ERROR_INVALID_LEVEL(),"The system call level is not correct." },
    { ERROR_NO_VOLUME_LABEL(),"The disk has no volume label." },
    { ERROR_MOD_NOT_FOUND(),"The specified module could not be found." },
    { ERROR_PROC_NOT_FOUND(),"The specified procedure could not be found." },
    { ERROR_WAIT_NO_CHILDREN(),"There are no child processes to wait for." },
    { ERROR_CHILD_NOT_COMPLETE(),"The %1 application cannot be run in Win32 mode." },
    { ERROR_DIRECT_ACCESS_HANDLE(),
    "Attempt to use a file handle to an open disk partition for an operation "
    "other than raw disk I/O." },
    { ERROR_NEGATIVE_SEEK(),"An attempt was made to move the file pointer before the beginning of the file." },
    { ERROR_SEEK_ON_DEVICE(),"The file pointer cannot be set on the specified device or file." },
    { ERROR_IS_JOIN_TARGET(),
    "A JOIN or SUBST command cannot be used for a drive that contains "
    "previously joined drives." },
    { ERROR_IS_JOINED(),
    "An attempt was made to use a JOIN or SUBST command on a drive that has "
    "already been joined." },
    { ERROR_IS_SUBSTED(),
    "An attempt was made to use a JOIN or SUBST command on a drive that has "
    "already been substituted." },
    { ERROR_NOT_JOINED(),"The system tried to delete the JOIN of a drive that is not joined." },
    { ERROR_NOT_SUBSTED(),
    "The system tried to delete the substitution of a drive that is not "
    "substituted." },
    { ERROR_JOIN_TO_JOIN(),"The system tried to join a drive to a directory on a joined drive." },
    { ERROR_SUBST_TO_SUBST(),
    "The system tried to substitute a drive to a directory on a substituted drive." },
    { ERROR_JOIN_TO_SUBST(),"The system tried to join a drive to a directory on a substituted drive." },
    { ERROR_SUBST_TO_JOIN(),"The system tried to SUBST a drive to a directory on a joined drive." },
    { ERROR_BUSY_DRIVE(),"The system cannot perform a JOIN or SUBST at this time." },
    { ERROR_SAME_DRIVE(),
    "The system cannot join or substitute a drive to or for a directory "
    "on the same drive." },
    { ERROR_DIR_NOT_ROOT(),"The directory is not a subdirectory of the root directory." },
    { ERROR_DIR_NOT_EMPTY(),"The directory is not empty." },
    { ERROR_IS_SUBST_PATH(),"The path specified is being used in a substitute." },
    { ERROR_IS_JOIN_PATH(),"Not enough resources are available to process this command." },
    { ERROR_PATH_BUSY(),"The path specified cannot be used at this time." },
    { ERROR_IS_SUBST_TARGET(),
    "An attempt was made to join or substitute a drive for which a "
    "directory on the drive is the target of a previous substitute." },
    { ERROR_SYSTEM_TRACE(),
    "System trace information was not specified in your CONFIG.SYS "
    "file, or tracing is disallowed." },
    { ERROR_INVALID_EVENT_COUNT(),
    "The number of specified semaphore events for DosMuxSemWait is "
    "not correct." },
    { ERROR_TOO_MANY_MUXWAITERS(),"DosMuxSemWait did not execute; too many semaphores are already set." },
    { ERROR_INVALID_LIST_FORMAT(),"The DosMuxSemWait list is not correct." },
    { ERROR_LABEL_TOO_LONG(),
    "The volume label you entered exceeds the label character limit of "
    "the target file system." },
    { ERROR_TOO_MANY_TCBS(),"Cannot create another thread." },
    { ERROR_SIGNAL_REFUSED(),"The recipient process has refused the signal." },
    { ERROR_DISCARDED(),"The segment is already discarded and cannot be locked." },
    { ERROR_NOT_LOCKED(),"The segment is already unlocked." },
    { ERROR_BAD_THREADID_ADDR(),"The address for the thread ID is not correct." },
    { ERROR_BAD_ARGUMENTS(),"One or more arguments are not correct." },
    { ERROR_BAD_PATHNAME(),"The specified path is invalid." },
    { ERROR_SIGNAL_PENDING(),"A signal is already pending." },
    { ERROR_MAX_THRDS_REACHED(),"No more threads can be created in the system." },
    { ERROR_LOCK_FAILED(),"Unable to lock a region of a file." },
    { ERROR_BUSY(),"The requested resource is in use." },
    { ERROR_DEVICE_SUPPORT_IN_PROGRESS(),"Device's command support detection is in progress." },
    { ERROR_CANCEL_VIOLATION(),"A lock request was not outstanding for the supplied cancel region." },
    { ERROR_ATOMIC_LOCKS_NOT_SUPPORTED(),"The file system does not support atomic changes to the lock type." },
    { ERROR_INVALID_SEGMENT_NUMBER(),"The system detected a segment number that was not correct." },
    { ERROR_INVALID_ORDINAL(),"The operating system cannot run %1." },
    { ERROR_ALREADY_EXISTS(),"Cannot create a file when that file already exists." },
    { ERROR_INVALID_FLAG_NUMBER(),"The flag passed is not correct." },
    { ERROR_SEM_NOT_FOUND(),"The specified system semaphore name was not found." },
    { ERROR_INVALID_STARTING_CODESEG(),"The operating system cannot run %1." },
    { ERROR_INVALID_STACKSEG(),"The operating system cannot run %1." },
    { ERROR_INVALID_MODULETYPE(),"The operating system cannot run %1." },
    { ERROR_INVALID_EXE_SIGNATURE(),"Cannot run %1 in Win32 mode." },
    { ERROR_EXE_MARKED_INVALID(),"The operating system cannot run %1." },
    { ERROR_BAD_EXE_FORMAT(),"%1 is not a valid Win32 application." },
    { ERROR_ITERATED_DATA_EXCEEDS_64k(),"The operating system cannot run %1." },
    { ERROR_INVALID_MINALLOCSIZE(),"The operating system cannot run %1." },
    { ERROR_DYNLINK_FROM_INVALID_RING(),"The operating system cannot run this application program." },
    { ERROR_IOPL_NOT_ENABLED(),"The operating system is not presently configured to run this application." },
    { ERROR_INVALID_SEGDPL(),"The operating system cannot run %1." },
    { ERROR_AUTODATASEG_EXCEEDS_64k(),"The operating system cannot run this application program." },
    { ERROR_RING2SEG_MUST_BE_MOVABLE(),"The code segment cannot be greater than or equal to 64K." },
    { ERROR_RELOC_CHAIN_XEEDS_SEGLIM(),"The operating system cannot run %1." },
    { ERROR_INFLOOP_IN_RELOC_CHAIN(),"The operating system cannot run %1." },
    { ERROR_ENVVAR_NOT_FOUND(),"The system could not find the environment option that was entered." },
    { ERROR_NO_SIGNAL_SENT(),"No process in the command subtree has a signal handler." },
    { ERROR_FILENAME_EXCED_RANGE(),"The filename or extension is too long." },
    { ERROR_RING2_STACK_IN_USE(),"The ring 2 stack is in use." },
    { ERROR_META_EXPANSION_TOO_LONG(),
    "The global filename characters, * or ?, are entered incorrectly or too many "
    "global filename characters are specified." },
    { ERROR_INVALID_SIGNAL_NUMBER(),"The signal being posted is not correct." },
    { ERROR_THREAD_1_INACTIVE(),"The signal handler cannot be set." },
    { ERROR_LOCKED(),"The segment is locked and cannot be reallocated." },
    { ERROR_TOO_MANY_MODULES(),"Too many dynamic-link modules are attached to this program or dynamic-link module." },
    { ERROR_NESTING_NOT_ALLOWED(),"Cannot nest calls to LoadModule." },
    { ERROR_EXE_MACHINE_TYPE_MISMATCH(),
    "This version of %1 is not compatible with the version of Windows you're running. "
    "Check your computer's system information and then contact the software publisher." },
    { ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY(),"The image file %1 is signed, unable to modify." },
    { ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY(),"The image file %1 is strong signed, unable to modify." },
    { ERROR_FILE_CHECKED_OUT(),"This file is checked out or locked for editing by another user." },
    { ERROR_CHECKOUT_REQUIRED(),"The file must be checked out before saving changes." },
    { ERROR_BAD_FILE_TYPE(),"The file type being saved or retrieved has been blocked." },
    { ERROR_FILE_TOO_LARGE(),"The file size exceeds the limit allowed and cannot be saved." },
    { ERROR_FORMS_AUTH_REQUIRED(),
    "Access Denied. Before opening files in this location, you must first add the web "
    "site to your trusted sites list, browse to the web site, and select the option to "
    "login automatically." },
    { ERROR_VIRUS_INFECTED(),
    "Operation did not complete successfully because the file contains a virus or "
    "potentially unwanted software." },
    { ERROR_VIRUS_DELETED(),
    "This file contains a virus or potentially unwanted software and cannot be opened. "
    "Due to the nature of this virus or potentially unwanted software, "
    "the file has been removed from this location." },
    { ERROR_PIPE_LOCAL(),"The pipe is local." },
    { ERROR_BAD_PIPE(),"The pipe state is invalid." },
    { ERROR_PIPE_BUSY(),"All pipe instances are busy." },
    { ERROR_NO_DATA(),"The pipe is being closed." },
    { ERROR_PIPE_NOT_CONNECTED(),"No process is on the other end of the pipe." },
    { ERROR_MORE_DATA(),"More data is available." },
    { ERROR_VC_DISCONNECTED(),"The session was canceled." },
    { ERROR_INVALID_EA_NAME(),"The specified extended attribute name was invalid." },
    { ERROR_EA_LIST_INCONSISTENT(),"The extended attributes are inconsistent." },
    { WAIT_TIMEOUT(),"The wait operation timed out." },
    { ERROR_NO_MORE_ITEMS(),"No more data is available." },
    { ERROR_CANNOT_COPY(),"The copy functions cannot be used." },
    { ERROR_DIRECTORY(),"The directory name is invalid." },
    { ERROR_EAS_DIDNT_FIT(),"The extended attributes did not fit in the buffer." },
    { ERROR_EA_FILE_CORRUPT(),"The extended attribute file on the mounted file system is corrupt." },
    { ERROR_EA_TABLE_FULL(),"The extended attribute table file is full." },
    { ERROR_INVALID_EA_HANDLE(),"The specified extended attribute handle is invalid." },
    { ERROR_EAS_NOT_SUPPORTED(),"The mounted file system does not support extended attributes." },
    { ERROR_NOT_OWNER(),"Attempt to release mutex not owned by caller." },
    { ERROR_TOO_MANY_POSTS(),"Too many posts were made to a semaphore." },
    { ERROR_PARTIAL_COPY(),"Only part of a ReadProcessMemory or WriteProcessMemory request was completed." },
    { ERROR_OPLOCK_NOT_GRANTED(),"The oplock request is denied." },
    { ERROR_INVALID_OPLOCK_PROTOCOL(),"An invalid oplock acknowledgment was received by the system." },
    { ERROR_DISK_TOO_FRAGMENTED(),"The volume is too fragmented to complete this operation." },
    { ERROR_DELETE_PENDING(),"The file cannot be opened because it is in the process of being deleted." },
    { ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING(),
    "Short name settings may not be changed on this volume due to the global "
    "registry setting." },
    { ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME(),"Short names are not enabled on this volume." },
    { ERROR_SECURITY_STREAM_IS_INCONSISTENT(),
    "The security stream for the given volume is in an inconsistent state. "
    "Please run CHKDSK on the volume." },
    { ERROR_INVALID_LOCK_RANGE(),"A requested file lock operation cannot be processed due to an invalid byte range." },
    { ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT(),"The subsystem needed to support the image type is not present." },
    { ERROR_NOTIFICATION_GUID_ALREADY_DEFINED(),"The specified file already has a notification GUID associated with it." },
    { ERROR_INVALID_EXCEPTION_HANDLER(),"An invalid exception handler routine has been detected." },
    { ERROR_DUPLICATE_PRIVILEGES(),"Duplicate privileges were specified for the token." },
    { ERROR_NO_RANGES_PROCESSED(),"No ranges for the specified operation were able to be processed." },
    { ERROR_NOT_ALLOWED_ON_SYSTEM_FILE(),"Operation is not allowed on a file system internal file." },
    { ERROR_DISK_RESOURCES_EXHAUSTED(),"The physical resources of this disk have been exhausted." },
    { ERROR_INVALID_TOKEN(),"The token representing the data is invalid." },
    { ERROR_DEVICE_FEATURE_NOT_SUPPORTED(),"The device does not support the command feature." },
    { ERROR_MR_MID_NOT_FOUND(),
    "The system cannot find message text for message number 0x%1 in the message "
    "file for %2." },
    { ERROR_SCOPE_NOT_FOUND(),"The scope specified was not found." },
    { ERROR_UNDEFINED_SCOPE(),"The Central Access Policy specified is not defined on the target machine." },
    { ERROR_INVALID_CAP(),"The Central Access Policy obtained from Active Directory is invalid." },
    { ERROR_DEVICE_UNREACHABLE(),"The device is unreachable." },
    { ERROR_DEVICE_NO_RESOURCES(),"The target device has insufficient resources to complete the operation." },
    { ERROR_DATA_CHECKSUM_ERROR(),"A data integrity checksum error occurred. Data in the file stream is corrupt." },
    { ERROR_INTERMIXED_KERNEL_EA_OPERATION(),
    "An attempt was made to modify both a KERNEL and normal Extended Attribute "
    "(EA) in the same operation." },
    { ERROR_FILE_LEVEL_TRIM_NOT_SUPPORTED(),"Device does not support file-level TRIM." },
    { ERROR_OFFSET_ALIGNMENT_VIOLATION(),
    "The command specified a data offset that does not align to the device's "
    "granularity/alignment." },
    { ERROR_INVALID_FIELD_IN_PARAMETER_LIST(),"The command specified an invalid field in its parameter list." },
    { ERROR_OPERATION_IN_PROGRESS(),"An operation is currently in progress with the device." },
    { ERROR_BAD_DEVICE_PATH(),
    "An attempt was made to send down the command via an invalid path to the "
    "target device." },
    { ERROR_TOO_MANY_DESCRIPTORS(),
    "The command specified a number of descriptors that exceeded the maximum "
    "supported by the device." },
    { ERROR_SCRUB_DATA_DISABLED(),"Scrub is disabled on the specified file." },
    { ERROR_NOT_REDUNDANT_STORAGE(),"The storage device does not provide redundancy." },
    { ERROR_RESIDENT_FILE_NOT_SUPPORTED(),"An operation is not supported on a resident file." },
    { ERROR_COMPRESSED_FILE_NOT_SUPPORTED(),"An operation is not supported on a compressed file." },
    { ERROR_DIRECTORY_NOT_SUPPORTED(),"An operation is not supported on a directory." },
    { ERROR_NOT_READ_FROM_COPY(),"The specified copy of the requested data could not be read." },
    { ERROR_FAIL_NOACTION_REBOOT(),"No action was taken as a system reboot is required." },
    { ERROR_FAIL_SHUTDOWN(),"The shutdown operation failed." },
    { ERROR_FAIL_RESTART(),"The restart operation failed." },
    { ERROR_MAX_SESSIONS_REACHED(),"The maximum number of sessions has been reached." },
    { ERROR_THREAD_MODE_ALREADY_BACKGROUND(),"The thread is already in background processing mode." },
    { ERROR_THREAD_MODE_NOT_BACKGROUND(),"The thread is not in background processing mode." },
    { ERROR_PROCESS_MODE_ALREADY_BACKGROUND(),"The process is already in background processing mode." },
    { ERROR_PROCESS_MODE_NOT_BACKGROUND(),"The process is not in background processing mode." },
    { ERROR_INVALID_ADDRESS(),"Attempt to access invalid address." }
};

/**
 * @brief  In real C++ productive usage, we can use the power of C++
 *         templates. We can get the error code text by "asString",
 *         which returns a std::string.
 *         Okay, this is in real make-up C++ code - but nice to see,
 *         when the code blow up.
 */
std::optional<std::string> getErrorCode(DWORD code) {
    auto it = WindowsErrorCode.find(code);
    if (it != WindowsErrorCode.end()) {
        return it->second;
    }   return std::nullopt;
}

template <typename T = DWORD>
struct asString {
    std::string operator()(T value) const {
        auto   result = getErrorCode(value);
        return result.value_or("unknown error");
    }
    std::string operator()() const {
        return "asString";
    }
};
template <typename T = DWORD>
struct asLogger {
    std::string operator()(T value) const {
        auto   result = getErrorCode(value);
        return result.value_or("unknown logger error");
    }
    std::string operator()() const {
        return "asLogger";
    }
};

/**
 * @brief This template provide access to the Windows error code: ERROR_SUCCESS.
 *        The result is a std::string for the coresponding error code number.
 *
 * @tparam T    Data type for the template. (Default: \ref DWORD).
 * @param  func The std::function that should be execute. Default is nullptr (no exec).
 * @param  args The std::any Variable that includes the arguments for func.
 *              This could be a std::vector with a list of arguments, or a single container
 *              that includes a single argument.
 *
 * @return std::string The return value for this template function is a std::string.
 * @see    inline DWORD ERROR_SUCCESS()
 *
 */
template <template <typename> class T>
std::string ERROR_SUCCESS(
    std::function<void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return T<DWORD>()(ERROR_SUCCESS());
}
template <template< typename> class T> std::string ERROR_INVALID_FUNCTION() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_FILE_NOT_FOUND() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_PATH_NOT_FOUND() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_TOO_MANY_OPEN_FILES() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_ACCESS_DENIED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_HANDLE() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_ARENA_TRASHED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NOT_ENOUGH_MEMORY() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_BLOCK() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BAD_ENVIRONMENT() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BAD_FORMAT() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_ACCESS() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_DATA() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_OUTOFMEMORY() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_DRIVE() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_CURRENT_DIRECTORY() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NOT_SAME_DEVICE() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NO_MORE_FILES() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_WRITE_PROTECT() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BAD_UNIT() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NOT_READY() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BAD_COMMAND() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_CRC() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BAD_LENGTH() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_SEEK() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NOT_DOS_DISK() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_SECTOR_NOT_FOUND() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_OUT_OF_PAPER() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_WRITE_FAULT() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_READ_FAULT() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_GEN_FAILURE() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_SHARING_VIOLATION() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_LOCK_VIOLATION() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_WRONG_DISK() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_SHARING_BUFFER_EXCEEDED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_HANDLE_EOF() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_HANDLE_DISK_FULL() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NOT_SUPPORTED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_REM_NOT_LIST() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_DUP_NAME() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BAD_NETPATH() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NETWORK_BUSY() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_DEV_NOT_EXIST() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_TOO_MANY_CMDS() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_ADAP_HDW_ERR() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BAD_NET_RESP() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_UNEXP_NET_ERR() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BAD_REM_ADAP() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_PRINTQ_FULL() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NO_SPOOL_SPACE() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_PRINT_CANCELLED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NETNAME_DELETED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NETWORK_ACCESS_DENIED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BAD_DEV_TYPE() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BAD_NET_NAME() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_TOO_MANY_NAMES() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_TOO_MANY_SESS() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_SHARING_PAUSED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_REQ_NOT_ACCEP() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_REDIR_PAUSED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_FILE_EXISTS() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_CANNOT_MAKE() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_FAIL_I24() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_OUT_OF_STRUCTURES() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_ALREADY_ASSIGNED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_PASSWORD() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_PARAMETER() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NET_WRITE_FAULT() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NO_PROC_SLOTS() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_TOO_MANY_SEMAPHORES() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_EXCL_SEM_ALREADY_OWNED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_SEM_IS_SET() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_TOO_MANY_SEM_REQUESTS() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_AT_INTERRUPT_TIME() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_SEM_OWNER_DIED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_SEM_USER_LIMIT() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_DISK_CHANGE() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_DRIVE_LOCKED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BROKEN_PIPE() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_OPEN_FAILED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BUFFER_OVERFLOW() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_DISK_FULL() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NO_MORE_SEARCH_HANDLES() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_TARGET_HANDLE() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_CATEGORY() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_VERIFY_SWITCH() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BAD_DRIVER_LEVEL() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_CALL_NOT_IMPLEMENTED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_SEM_TIMEOUT() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INSUFFICIENT_BUFFER() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_NAME() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_LEVEL() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NO_VOLUME_LABEL() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_MOD_NOT_FOUND() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_PROC_NOT_FOUND() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_WAIT_NO_CHILDREN() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_CHILD_NOT_COMPLETE() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_DIRECT_ACCESS_HANDLE() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NEGATIVE_SEEK() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_SEEK_ON_DEVICE() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_IS_JOIN_TARGET() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_IS_JOINED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_IS_SUBSTED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NOT_JOINED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NOT_SUBSTED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_JOIN_TO_JOIN() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_SUBST_TO_SUBST() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_JOIN_TO_SUBST() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_SUBST_TO_JOIN() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BUSY_DRIVE() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_SAME_DRIVE() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_DIR_NOT_ROOT() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_DIR_NOT_EMPTY() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_IS_SUBST_PATH() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_IS_JOIN_PATH() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_PATH_BUSY() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_IS_SUBST_TARGET() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_SYSTEM_TRACE() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_EVENT_COUNT() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_TOO_MANY_MUXWAITERS() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_LIST_FORMAT() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_LABEL_TOO_LONG() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_TOO_MANY_TCBS() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_SIGNAL_REFUSED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_DISCARDED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_NOT_LOCKED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BAD_THREADID_ADDR() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BAD_ARGUMENTS() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BAD_PATHNAME() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_SIGNAL_PENDING() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_MAX_THRDS_REACHED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_LOCK_FAILED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_BUSY() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_DEVICE_SUPPORT_IN_PROGRESS() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_CANCEL_VIOLATION() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_ATOMIC_LOCKS_NOT_SUPPORTED() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_SEGMENT_NUMBER() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_ORDINAL() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_ALREADY_EXISTS() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_FLAG_NUMBER() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_SEM_NOT_FOUND() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_STARTING_CODESEG() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_STACKSEG() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_MODULETYPE() { return T<DWORD>()(1); }
template <template< typename> class T> std::string ERROR_INVALID_EXE_SIGNATURE() { return T<DWORD>()(ERROR_INVALID_EXE_SIGNATURE()); }
template <template< typename> class T> std::string ERROR_EXE_MARKED_INVALID() { return T<DWORD>()(ERROR_EXE_MARKED_INVALID()); }
template <template< typename> class T> std::string ERROR_BAD_EXE_FORMAT() { return T<DWORD>()(ERROR_BAD_EXE_FORMAT()); }
template <template< typename> class T> std::string ERROR_ITERATED_DATA_EXCEEDS_64k() { return T<DWORD>()(ERROR_ITERATED_DATA_EXCEEDS_64k()); }
template <template< typename> class T> std::string ERROR_INVALID_MINALLOCSIZE() { return T<DWORD>()(ERROR_INVALID_MINALLOCSIZE()); }
template <template< typename> class T> std::string ERROR_DYNLINK_FROM_INVALID_RING() { return T<DWORD>()(ERROR_DYNLINK_FROM_INVALID_RING()); }
template <template< typename> class T> std::string ERROR_IOPL_NOT_ENABLED() { return T<DWORD>()(ERROR_IOPL_NOT_ENABLED()); }
template <template< typename> class T> std::string ERROR_INVALID_SEGDPL() { return T<DWORD>()(ERROR_INVALID_SEGDPL()); }
template <template< typename> class T> std::string ERROR_AUTODATASEG_EXCEEDS_64k() { return T<DWORD>()(ERROR_AUTODATASEG_EXCEEDS_64k()); }
template <template< typename> class T> std::string ERROR_RING2SEG_MUST_BE_MOVABLE() { return T<DWORD>()(ERROR_RING2SEG_MUST_BE_MOVABLE()); }
template <template< typename> class T> std::string ERROR_RELOC_CHAIN_XEEDS_SEGLIM() { return T<DWORD>()(ERROR_RELOC_CHAIN_XEEDS_SEGLIM()); }
template <template< typename> class T> std::string ERROR_INFLOOP_IN_RELOC_CHAIN() { return T<DWORD>()(ERROR_INFLOOP_IN_RELOC_CHAIN()); }
template <template< typename> class T> std::string ERROR_ENVVAR_NOT_FOUND() { return T<DWORD>()(ERROR_ENVVAR_NOT_FOUND()); }
template <template< typename> class T> std::string ERROR_NO_SIGNAL_SENT() { return T<DWORD>()(ERROR_NO_SIGNAL_SENT()); }
template <template< typename> class T> std::string ERROR_FILENAME_EXCED_RANGE() { return T<DWORD>()(ERROR_FILENAME_EXCED_RANGE()); }
template <template< typename> class T> std::string ERROR_RING2_STACK_IN_USE() { return T<DWORD>()(ERROR_RING2_STACK_IN_USE()); }
template <template< typename> class T> std::string ERROR_META_EXPANSION_TOO_LONG() { return T<DWORD>()(ERROR_META_EXPANSION_TOO_LONG()); }
template <template< typename> class T> std::string ERROR_INVALID_SIGNAL_NUMBER() { return T<DWORD>()(ERROR_INVALID_SIGNAL_NUMBER()); }
template <template< typename> class T> std::string ERROR_THREAD_1_INACTIVE() { return T<DWORD>()(ERROR_THREAD_1_INACTIVE()); }
template <template< typename> class T> std::string ERROR_LOCKED() { return T<DWORD>()(ERROR_LOCKED()); }
template <template< typename> class T> std::string ERROR_TOO_MANY_MODULES() { return T<DWORD>()(ERROR_TOO_MANY_MODULES()); }
template <template< typename> class T> std::string ERROR_NESTING_NOT_ALLOWED() { return T<DWORD>()(ERROR_NESTING_NOT_ALLOWED()); }
template <template< typename> class T> std::string ERROR_EXE_MACHINE_TYPE_MISMATCH() { return T<DWORD>()(ERROR_EXE_MACHINE_TYPE_MISMATCH()); }
template <template< typename> class T> std::string ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY() { return T<DWORD>()(ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY()); }
template <template< typename> class T> std::string ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY() { return T<DWORD>()(ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY()); }
template <template< typename> class T> std::string ERROR_FILE_CHECKED_OUT() { return T<DWORD>()(ERROR_FILE_CHECKED_OUT()); }
template <template< typename> class T> std::string ERROR_CHECKOUT_REQUIRED() { return T<DWORD>()(ERROR_CHECKOUT_REQUIRED()); }
template <template< typename> class T> std::string ERROR_BAD_FILE_TYPE() { return T<DWORD>()(ERROR_BAD_FILE_TYPE()); }
template <template< typename> class T> std::string ERROR_FILE_TOO_LARGE() { return T<DWORD>()(ERROR_FILE_TOO_LARGE()); }
template <template< typename> class T> std::string ERROR_FORMS_AUTH_REQUIRED() { return T<DWORD>()(ERROR_FORMS_AUTH_REQUIRED()); }
template <template< typename> class T> std::string ERROR_VIRUS_INFECTED() { return T<DWORD>()(ERROR_VIRUS_INFECTED()); }
template <template< typename> class T> std::string ERROR_VIRUS_DELETED() { return T<DWORD>()(ERROR_VIRUS_DELETED()); }
template <template< typename> class T> std::string ERROR_PIPE_LOCAL() { return T<DWORD>()(ERROR_PIPE_LOCAL()); }
template <template< typename> class T> std::string ERROR_BAD_PIPE() { return T<DWORD>()(ERROR_BAD_PIPE()); }
template <template< typename> class T> std::string ERROR_PIPE_BUSY() { return T<DWORD>()(ERROR_PIPE_BUSY()); }
template <template< typename> class T> std::string ERROR_NO_DATA() { return T<DWORD>()(ERROR_NO_DATA()); }
template <template< typename> class T> std::string ERROR_PIPE_NOT_CONNECTED() { return T<DWORD>()(ERROR_PIPE_NOT_CONNECTED()); }
template <template< typename> class T> std::string ERROR_MORE_DATA() { return T<DWORD>()(ERROR_MORE_DATA()); }
template <template< typename> class T> std::string ERROR_VC_DISCONNECTED() { return T<DWORD>()(ERROR_VC_DISCONNECTED()); }
template <template< typename> class T> std::string ERROR_INVALID_EA_NAME() { return T<DWORD>()(ERROR_INVALID_EA_NAME()); }
template <template< typename> class T> std::string ERROR_EA_LIST_INCONSISTENT() { return T<DWORD>()(ERROR_EA_LIST_INCONSISTENT()); }
template <template< typename> class T> std::string WAIT_TIMEOUT() { return T<DWORD>()(WAIT_TIMEOUT()); }
template <template< typename> class T> std::string ERROR_NO_MORE_ITEMS() { return T<DWORD>()(ERROR_NO_MORE_ITEMS()); }
template <template< typename> class T> std::string ERROR_CANNOT_COPY() { return T<DWORD>()(ERROR_CANNOT_COPY()); }
template <template< typename> class T> std::string ERROR_DIRECTORY() { return T<DWORD>()(ERROR_DIRECTORY()); }
template <template< typename> class T> std::string ERROR_EAS_DIDNT_FIT() { return T<DWORD>()(ERROR_EAS_DIDNT_FIT()); }
template <template< typename> class T> std::string ERROR_EA_FILE_CORRUPT() { return T<DWORD>()(ERROR_EA_FILE_CORRUPT()); }
template <template< typename> class T> std::string ERROR_EA_TABLE_FULL() { return T<DWORD>()(ERROR_EA_TABLE_FULL()); }
template <template< typename> class T> std::string ERROR_INVALID_EA_HANDLE() { return T<DWORD>()(ERROR_INVALID_EA_HANDLE()); }
template <template< typename> class T> std::string ERROR_EAS_NOT_SUPPORTED() { return T<DWORD>()(ERROR_EAS_NOT_SUPPORTED()); }
template <template< typename> class T> std::string ERROR_NOT_OWNER() { return T<DWORD>()(ERROR_NOT_OWNER()); }
template <template< typename> class T> std::string ERROR_TOO_MANY_POSTS() { return T<DWORD>()(ERROR_TOO_MANY_POSTS()); }
template <template< typename> class T> std::string ERROR_PARTIAL_COPY() { return T<DWORD>()(ERROR_PARTIAL_COPY()); }
template <template< typename> class T> std::string ERROR_OPLOCK_NOT_GRANTED() { return T<DWORD>()(ERROR_OPLOCK_NOT_GRANTED()); }
template <template< typename> class T> std::string ERROR_INVALID_OPLOCK_PROTOCOL() { return T<DWORD>()(ERROR_INVALID_OPLOCK_PROTOCOL()); }
template <template< typename> class T> std::string ERROR_DISK_TOO_FRAGMENTED() { return T<DWORD>()(ERROR_DISK_TOO_FRAGMENTED()); }
template <template< typename> class T> std::string ERROR_DELETE_PENDING() { return T<DWORD>()(ERROR_DELETE_PENDING()); }
template <template< typename> class T> std::string ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING() { return T<DWORD>()(ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING()); }
template <template< typename> class T> std::string ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME() { return T<DWORD>()(ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME()); }
template <template< typename> class T> std::string ERROR_SECURITY_STREAM_IS_INCONSISTENT() { return T<DWORD>()(ERROR_SECURITY_STREAM_IS_INCONSISTENT()); }
template <template< typename> class T> std::string ERROR_INVALID_LOCK_RANGE() { return T<DWORD>()(ERROR_INVALID_LOCK_RANGE()); }
template <template< typename> class T> std::string ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT() { return T<DWORD>()(ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT()); }
template <template< typename> class T> std::string ERROR_NOTIFICATION_GUID_ALREADY_DEFINED() { return T<DWORD>()(ERROR_NOTIFICATION_GUID_ALREADY_DEFINED()); }
template <template< typename> class T> std::string ERROR_INVALID_EXCEPTION_HANDLER() { return T<DWORD>()(ERROR_INVALID_EXCEPTION_HANDLER()); }
template <template< typename> class T> std::string ERROR_DUPLICATE_PRIVILEGES() { return T<DWORD>()(ERROR_DUPLICATE_PRIVILEGES()); }
template <template< typename> class T> std::string ERROR_NO_RANGES_PROCESSED() { return T<DWORD>()(ERROR_NO_RANGES_PROCESSED()); }
template <template< typename> class T> std::string ERROR_NOT_ALLOWED_ON_SYSTEM_FILE() { return T<DWORD>()(ERROR_NOT_ALLOWED_ON_SYSTEM_FILE()); }
template <template< typename> class T> std::string ERROR_DISK_RESOURCES_EXHAUSTED() { return T<DWORD>()(ERROR_DISK_RESOURCES_EXHAUSTED()); }
template <template< typename> class T> std::string ERROR_INVALID_TOKEN() { return T<DWORD>()(ERROR_INVALID_TOKEN()); }
template <template< typename> class T> std::string ERROR_DEVICE_FEATURE_NOT_SUPPORTED() { return T<DWORD>()(ERROR_DEVICE_FEATURE_NOT_SUPPORTED()); }
template <template< typename> class T> std::string ERROR_MR_MID_NOT_FOUND() { return T<DWORD>()(ERROR_MR_MID_NOT_FOUND()); }
template <template< typename> class T> std::string ERROR_SCOPE_NOT_FOUND() { return T<DWORD>()(ERROR_SCOPE_NOT_FOUND()); }
template <template< typename> class T> std::string ERROR_UNDEFINED_SCOPE() { return T<DWORD>()(ERROR_UNDEFINED_SCOPE()); }
template <template< typename> class T> std::string ERROR_INVALID_CAP() { return T<DWORD>()(ERROR_INVALID_CAP()); }

template <template <typename> class T>
std::string
ERROR_DEVICE_UNREACHABLE(
std::function<void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_DEVICE_UNREACHABLE());
}

template <template <typename> class T>
std::string
ERROR_DEVICE_NO_RESOURCES(
std::function<void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_DEVICE_NO_RESOURCES());
}

template <template <typename> class T>
std::string
ERROR_DATA_CHECKSUM_ERROR(
std::function<void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_DATA_CHECKSUM_ERROR());
}

template <template <typename> class T>
std::string ERROR_INTERMIXED_KERNEL_EA_OPERATION(
std::function<void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_INTERMIXED_KERNEL_EA_OPERATION());
}

template <template <typename> class T>
std::string
ERROR_FILE_LEVEL_TRIM_NOT_SUPPORTED(
std::function<void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_FILE_LEVEL_TRIM_NOT_SUPPORTED());
}

template <template <typename> class T>
std::string
ERROR_OFFSET_ALIGNMENT_VIOLATION(
std::function<void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_OFFSET_ALIGNMENT_VIOLATION());
}

template <template <typename> class T>
std::string
ERROR_INVALID_FIELD_IN_PARAMETER_LIST(
std::function<void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_INVALID_FIELD_IN_PARAMETER_LIST());
}

template <template <typename> class T>
std::string
ERROR_OPERATION_IN_PROGRESS(
std::function<void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_OPERATION_IN_PROGRESS());
}

template <template <typename> class T>
std::string
ERROR_BAD_DEVICE_PATH(
std::function<void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_BAD_DEVICE_PATH());
}

template <template <typename> class T>
std::string
ERROR_TOO_MANY_DESCRIPTORS(
std::function<void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_TOO_MANY_DESCRIPTORS());
}

template <template <typename> class T>
std::string
ERROR_SCRUB_DATA_DISABLED(
std::function<void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_SCRUB_DATA_DISABLED());
}

template <template <typename> class T>
std::string
ERROR_NOT_REDUNDANT_STORAGE(
std::function<void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_NOT_REDUNDANT_STORAGE());
}

template <template <typename> class T>
std::string
ERROR_RESIDENT_FILE_NOT_SUPPORTED(
std::function<void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_RESIDENT_FILE_NOT_SUPPORTED());
}

template <template <typename> class T>
std::string
ERROR_COMPRESSED_FILE_NOT_SUPPORTED(
std::function<void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_COMPRESSED_FILE_NOT_SUPPORTED());
}

template <template <typename> class T>
std::string
ERROR_DIRECTORY_NOT_SUPPORTED(
std::function<void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_DIRECTORY_NOT_SUPPORTED());
}

template <template <typename> class T>
std::string
ERROR_NOT_READ_FROM_COPY(
std::function<void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_NOT_READ_FROM_COPY());
}

template <template <typename> class T>
std::string
ERROR_FAIL_NOACTION_REBOOT(
std::function<
    void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_FAIL_NOACTION_REBOOT());
}

template <template <typename> class T>
std::string
ERROR_FAIL_SHUTDOWN(
std::function<
    void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_FAIL_SHUTDOWN());
}

template <template <typename> class T>
std::string
ERROR_FAIL_RESTART(
std::function<
    void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_FAIL_RESTART());
}

template <template <typename> class T>
std::string
ERROR_MAX_SESSIONS_REACHED(
std::function<
    void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_MAX_SESSIONS_REACHED());
}

template <template <typename> class T>
std::string
ERROR_THREAD_MODE_ALREADY_BACKGROUND(
std::function<
    void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_THREAD_MODE_ALREADY_BACKGROUND());
}

template <template <typename> class T>
std::string
ERROR_THREAD_MODE_NOT_BACKGROUND(
std::function<
    void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_THREAD_MODE_NOT_BACKGROUND());
}

template <template <typename> class T>
std::string
ERROR_PROCESS_MODE_ALREADY_BACKGROUND(
std::function<
    void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_PROCESS_MODE_ALREADY_BACKGROUND());
}

template <template <typename> class T>
std::string
ERROR_PROCESS_MODE_NOT_BACKGROUND(
std::function<
    void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_PROCESS_MODE_NOT_BACKGROUND());
}

template <template <typename> class T>
std::string
ERROR_INVALID_ADDRESS(
std::function<
    void(std::any)> func = nullptr, std::any args = nullptr) {
    if (func != nullptr)
        func(args);
    return asString<DWORD>()(ERROR_INVALID_ADDRESS());
}

// -------------------------------------------------------------------
// @brief Dummy function, to place the template(s) code into the .obj
//        and .dll file.
// -------------------------------------------------------------------
static std::string dummy()
{
    std::vector< std::string > dumm =
    {
        ERROR_THREAD_MODE_NOT_BACKGROUND      <asString> (),
        ERROR_PROCESS_MODE_ALREADY_BACKGROUND <asString> (),
        ERROR_PROCESS_MODE_NOT_BACKGROUND     <asString> (),
        ERROR_INVALID_ADDRESS                 <asString> ()
    };
    return "";
}

}   // namespace: windows

// -------------------------------------------------------------------
// .dll entry point ...
// -------------------------------------------------------------------
BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,     // handle to DLL module
    DWORD     fdwReason,    // reason for calling function
    LPVOID    lpvReserved)  // reserved
{
    windows::dummy();
    return true;
}
