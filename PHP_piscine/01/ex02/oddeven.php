#!/usr/bin/php
<?php
	while (1)
	{
		echo "Enter a number: ";
		$x = fgets(STDIN);
		if(!$x)
			return ;
		$x = rtrim($x, "\r\n");
		if (!is_numeric($x))
			echo "'$x' is not a number\n";
		else if($x % 2 == 0)
			echo "The number $x is even\n";
		else if($x % 2 == 1 || $x % 2 == -1)
			echo "The number $x is odd\n";
	}
?>