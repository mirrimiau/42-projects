#!/usr/bin/php
<?php
	$i = 1;
	$b = array();
	while ($argv[$i])
	{
		$a = explode(' ', $argv[$i]);
		$b = array_merge($b, $a);
		$i++;
	}
	sort($b, SORT_REGULAR);
	$i = 0;
	while ($b[$i])
	{
		print($b[$i]."\n");
		$i++;
	}
?>