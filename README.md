php_pack64
==============

64bit large number en/decoder

## Function
```php
string pack64( string $big_number )
string unpack64( string $data )
```

## Install
* tar zxf php_pack64.tgz
* cd php_pack64
* phpize
* ./configure
* make
* make install
* echo "extension = pack64.so" >> /etc/php.ini (your php.ini file)

## Examples
```php
<?php
$big_number = '12345678901234567';
assert( $big_number == unpack64( pack64( $big_number ) ) );
?>
```

