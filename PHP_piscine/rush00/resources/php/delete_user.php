<?php

	function ft_kill()
	{
		echo ("ERROR\n");
		exit ;
	}

	if ($_POST["submit"] == "OK"  && $_POST["login"] !== "" && file_exists("../private/passwd"))
	{
		$array = unserialize(file_get_contents("../private/passwd"));
		for ($i = 0; $array[$i]; $i++)
			if($array[$i]["login"] == $_POST["login"])
				break ;
		if ($array[$i]["login"] != $_POST["login"])
			ft_kill();
		$array[$i]["passwd"] = "";
		$array[$i]["login"] = "";
		file_put_contents("../private/passwd", serialize($array));
		echo ("OK\n");
	}
	else
		ft_kill();
?>
