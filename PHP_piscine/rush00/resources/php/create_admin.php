<?php
	if ($_POST["submit"] == "OK" && $_POST["passwd"] !== "" && hash("whirlpool", $_POST["mkey"]) === file_get_contents("../private/masterkey"))
	{
		if (!file_exists("../private/admins"))
		{
			mkdir ("../private");
			$array = [];
			file_put_contents("../private/admins", serialize($array));
		}
		$array = unserialize(file_get_contents("../private/admins"));
		for ($i = 0; $array[$i]; $i++)
		{	
			if($array[$i]["login"] == $_POST["login"])
			{
				echo "ERROR\n";
				exit ;
			}
		}
		$new = [ "login" => $_POST["login"] , "passwd" => hash("whirlpool", $_POST["passwd"]) ];
		$array[] = $new;
		file_put_contents("../private/admins", serialize($array));
		echo ("OK\n");
	}
	else
	{
		echo ("MASTER KEY WRONG! THIS INCIDENT HAS BEEN REPORTED (not really)\n");
		exit ;
	}
?>