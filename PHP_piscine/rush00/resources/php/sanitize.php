<?php

function sanitize(string $string)
{
	if (filter_var($string, FILTER_SANITIZE_FULL_SPECIAL_CHARS) !== $string)
    {
		exit ("you are being naughty with your fancy special characters...");
	}
}
?>