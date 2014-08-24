<?
if (!function_exists('pack64') || !function_exists('unpack64'))
	dl('pack64.so');

if (function_exists('pack64') && function_exists('unpack64') && unpack64(pack64('12345678901234')) == '12345678901234') {
	echo('Install success!');

	if (file_exists('test.db')) {
		$buf=@file_get_contents('test.db');
		assert(unpack64($buf) == '12345678901234');
	}
}else{
	echo('Install FAILED!!!');
}
?>

