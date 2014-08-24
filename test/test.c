#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

int main( int argc, char *argv[] )
{
	uint64_t	id;
	FILE		*fd;

	id = 12345678901234;

	fd = fopen( "test.db", "w" );
	fwrite( &id, sizeof(uint64_t), 1, fd );
	fclose( fd );

	fd = fopen( "test.db", "r" );
	fread( &id, sizeof(uint64_t), 1, fd );
	printf( "%llu\n", id );
	fclose( fd );

	return 0;
}

