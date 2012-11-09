#ifdef PHP_WIN32
#include "php_Gorilla.h"
#include <tchar.h>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <share.h>

static int SerialPort_getLineStatus(GORILLA_METHOD_PARAMETERS) {
    return 0;
}


static void SerialPort_setLineStatus(zend_bool stat, int line, GORILLA_METHOD_PARAMETERS) {
    return;
}

void SerialPort_open_impl(const char *device, GORILLA_METHOD_PARAMETERS) {
    php_stream *stream;
    zval *zval_stream;
    zval *zval_win32Handle;
    HANDLE win32Handle = NULL;
    int serial_port_fd;
    int res = 0;
    int flags = 0;
    
    
#define mode "ab+"
    
    if (php_stream_parse_fopen_modes(mode, &flags) == FAILURE) {
        zend_throw_exception(NULL, "failed to get flags", 344 TSRMLS_CC);
        return;
    }
    
    res = _sopen_s(&serial_port_fd, device, flags, _SH_DENYNO, _S_IREAD|_S_IWRITE);
    if (res != 0) {
        zend_throw_exception(NULL, "failed to open device", 345 TSRMLS_CC);
        return;
    }
    zend_update_property_long(_this_ce, _this_zval, "_streamFd", strlen("_streamFd"), serial_port_fd TSRMLS_CC);
    
    win32Handle = _get_osfhandle(serial_port_fd);
    if (win32Handle == INVALID_HANDLE_VALUE) {
        zend_throw_exception(NULL, "failed to open Win32Handle", 346 TSRMLS_CC);
        return;
    }
    zval_win32Handle = zend_read_property(_this_ce, _this_zval, "_win32Handle", strlen("_win32Handle"), 1 TSRMLS_CC);
    ZEND_REGISTER_RESOURCE(zval_win32Handle, win32Handle, le_Win32Handle);
    
    stream = php_stream_fopen_from_fd(serial_port_fd, mode, NULL);
    if (stream == NULL) {
        zend_throw_exception(NULL, "failed to open stream from file descriptor", 347 TSRMLS_CC);
        return;
    }
    zval_stream = zend_read_property(_this_ce, _this_zval, "_stream", strlen("_stream"), 1 TSRMLS_CC);
    php_stream_to_zval(stream, zval_stream);
    
    return;
}

void SerialPort_setCanonical_impl(zend_bool canonical, GORILLA_METHOD_PARAMETERS) {
    return;
}

int SerialPort_isCanonical_impl(GORILLA_METHOD_PARAMETERS) {
    return 0;
}

int SerialPort_getFlowControl_impl(GORILLA_METHOD_PARAMETERS) {
    
    return FLOW_CONTROL_DEFAULT;
}

void SerialPort_setFlowControl_impl(int flow_control, GORILLA_METHOD_PARAMETERS) {
    return;
}

int SerialPort_getCTS_impl(GORILLA_METHOD_PARAMETERS) {
    return 0;
}

int SerialPort_getRTS_impl(GORILLA_METHOD_PARAMETERS) {
    return 0;
}

void SerialPort_setRTS_impl(zend_bool rts, GORILLA_METHOD_PARAMETERS) {
    return;
}

int SerialPort_getDSR_impl(GORILLA_METHOD_PARAMETERS) {
    return 0;
}

int SerialPort_getDTR_impl(GORILLA_METHOD_PARAMETERS) {
    return 0;
}

void SerialPort_setDTR_impl(zend_bool dtr, GORILLA_METHOD_PARAMETERS) {
    return;
}

int SerialPort_getDCD_impl(GORILLA_METHOD_PARAMETERS) {
    return 0;
}

int SerialPort_getRNG_impl(GORILLA_METHOD_PARAMETERS) {
    return 0;
}

int SerialPort_getNumOfStopBits_impl(GORILLA_METHOD_PARAMETERS) {
    return 1;
}

void SerialPort_setNumOfStopBits_impl(long stop_bits, GORILLA_METHOD_PARAMETERS) {
    return;
}

int SerialPort_getParity_impl(GORILLA_METHOD_PARAMETERS) {
    return PARITY_INVALID;
}

void SerialPort_setParity_impl(int parity, GORILLA_METHOD_PARAMETERS) {
    return;
}

long SerialPort_getVMin_impl(GORILLA_METHOD_PARAMETERS) {
    return 0;
}

void SerialPort_setVMin_impl(long vmin, GORILLA_METHOD_PARAMETERS) {
    return;
}

int SerialPort_getVTime_impl(GORILLA_METHOD_PARAMETERS) {
    return 0;
}

void SerialPort_setVTime_impl(long vtime, GORILLA_METHOD_PARAMETERS) {
    return;
}

void SerialPort_setCharSize_impl(long char_size, GORILLA_METHOD_PARAMETERS) {
    return;
}

long SerialPort_getCharSize_impl(GORILLA_METHOD_PARAMETERS) {
    return CHAR_SIZE_DEFAULT;
}

long SerialPort_getBaudRate_impl(GORILLA_METHOD_PARAMETERS) {
    return BAUD_RATE_9600;
}

void SerialPort_setBaudRate_impl(long baud_rate, GORILLA_METHOD_PARAMETERS) {
    return;
}

#endif