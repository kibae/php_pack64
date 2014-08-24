#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdint.h>
#include "php.h"
#include "php_pack64.h"

const zend_function_entry pack64_functions[] = {
	PHP_FE(pack64, NULL)
	PHP_FE(unpack64, NULL)
	{NULL, NULL, NULL}
};

zend_module_entry pack64_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	PHP_PACK64_EXTNAME,
	pack64_functions,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
#if ZEND_MODULE_API_NO >= 20010901
	PHP_PACK64_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_PACK64
ZEND_GET_MODULE(pack64)
#endif

PHP_FUNCTION(unpack64)
{
	char		*str;
	int		str_len;
	uint64_t	*uint;
	char		*result;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &str, &str_len) == FAILURE)
	{
		RETURN_NULL();
	}

	if (str_len < sizeof(uint64_t))
	{
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "argument length is too short." );
		RETURN_NULL();
	}

	uint = (uint64_t *) str;
	result = safe_emalloc( 40, 1, 1 );
	snprintf( result, 40, "%llu", (*uint) );

	RETURN_STRING( result, 0 );
}

PHP_FUNCTION(pack64)
{
	char		*str;
	int		str_len;
	uint64_t	uint;
	char		*result;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &str, &str_len) == FAILURE)
	{
		RETURN_NULL();
	}

	if (str_len <= 0)
	{
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "argument length is too short." );
		RETURN_NULL();
	}

	uint = strtoll( str, NULL, 10 );
	result = safe_emalloc( sizeof(uint64_t), 1, 0 );
	memcpy( result, &uint, sizeof(uint64_t) );

	RETVAL_STRINGL( result, sizeof(uint64_t), 0 );
}





