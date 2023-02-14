<?php
	
	include("sanitize.php");

	sanitize($_POST["submit"]);
	sanitize($_POST["login"]);
	sanitize($_POST["passwd"]);

	if ($_POST["submit"] == "OK" && $_POST["passwd"] !== "")
	{
		if (!file_exists("../private/passwd"))
		{
			mkdir ("../private");
			$array = [];
			file_put_contents("../private/passwd", serialize($array));
		}
		$array = unserialize(file_get_contents("../private/passwd"));
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
		file_put_contents("../private/passwd", serialize($array));
		echo ("OK\n");
	}
	else
	{
		echo ("ERROR\n");
		exit ;
	}

?>