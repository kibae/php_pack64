PHP_ARG_ENABLE(pack64, whether to enable pack uint64_t support, [ --enable-pack64   Enable uint64_t pack support])

if test "$PHP_PACK64" != "no"; then
	PHP_NEW_EXTENSION(pack64, pack64.c, $ext_shared)
fi

