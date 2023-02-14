#!/usr/bin/php
<?php

function ft_split($str)
{
	$array = (explode(" ",$str));
	sort($array, SORT_REGULAR);
	return ($array);
}

?>