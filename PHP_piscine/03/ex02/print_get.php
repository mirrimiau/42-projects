<?php
	foreach ($_GET as $key => $value)
	{
		echo "$key";
		if ($value != FALSE)
		echo ": $value";
		echo "\n";
	}
?>