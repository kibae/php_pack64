#ifndef PHP_PACK64_H
#define PHP_PACK64_H 1

#define PHP_PACK64_VERSION "1.0"
#define PHP_PACK64_EXTNAME "pack64"

PHP_FUNCTION(unpack64);
PHP_FUNCTION(pack64);

extern zend_module_entry pack64_module_entry;

#endif

