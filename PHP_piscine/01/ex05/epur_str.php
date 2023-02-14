#!/usr/bin/php
<?php

	if ($argc == 2)
	{
		$argv[1] = trim($argv[1]);
		$i = 0;
		while ($argv[1][$i])
		{
			print ($argv[1][$i]);
			if ($argv[1][$i] == ' ')
			{
				while ($argv[1][$i] == ' ')
				{
					$i++;
				}
				continue ;
			}
			$i++;
		}
	}
	
?>