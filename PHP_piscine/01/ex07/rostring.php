#!/usr/bin/php
<?php

	if ($argv[1])
	{
		$argv[1] = preg_replace('/\s+/', ' ', $argv[1]);
		$a = explode(" ", trim($argv[1]));
		$i = 1;
		while ($a[$i])
		{
			print($a[$i]." ");
			$i++;
		}
		print($a[0]);
	}

?>