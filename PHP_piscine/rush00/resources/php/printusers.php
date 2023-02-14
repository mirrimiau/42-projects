<?php
	session_start();
	if ($_SESSION["admin"] != TRUE)
		{
			echo ("admin only");
			exit ;
		}
	$array = unserialize(file_get_contents("../private/passwd"));
	for ($i = 0; $array[$i]; $i++)
	{
		print ($array[$i]["login"]." ");
	}

?>