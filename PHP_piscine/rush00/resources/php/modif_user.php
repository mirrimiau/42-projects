<?php

	include("sanitize.php");

	sanitize($_POST["submit"]);
	sanitize($_POST["login"]);
	sanitize($_POST["newpw"]);
	sanitize($_POST["oldpw"]);

	function ft_kill()
	{
		echo ("ERROR\n");
		exit ;
	}

	if ($_POST["submit"] == "OK" && $_POST["newpw"] !== "" && $_POST["oldpw"] !== "" && $_POST["login"] !== "" && file_exists("../private/passwd"))
	{
		$array = unserialize(file_get_contents("../private/passwd"));
		for ($i = 0; $array[$i]; $i++)
			if($array[$i]["login"] == $_POST["login"])
				break ;
		if (hash("whirlpool", $_POST["oldpw"]) != $array[$i]["passwd"])
			ft_kill();
		$array[$i]["passwd"] = hash("whirlpool", $_POST["newpw"]);
		file_put_contents("../private/passwd", serialize($array));
		echo ("OK\n");
	}
	else
		ft_kill();
?>