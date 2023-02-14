
<?php

function ft_kill(string $error)
{
	echo ($error."\n");
	exit ;
}

if ($_POST["submit"] == "OK"  && $_POST["login"] !== "" && file_exists("../private/admins"))
{
	$array = unserialize(file_get_contents("../private/admins"));
	for ($i = 0; $array[$i]; $i++)
		if($array[$i]["login"] == $_POST["login"])
			break ;
	if ($array[$i]["login"] != $_POST["login"])
		ft_kill("No such user");
	$pw_hold = $array[$i]["passwd"];
	$login_hold = $array[$i]["login"];
	$array[$i]["passwd"] = "";
	$array[$i]["login"] = "";
	file_put_contents("../private/admins", serialize($array));
	echo ($login_hold." deleted from admin ");
}
else
	ft_kill("ERROR");
if ($_POST["submit"] == "OK")
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
			$array = unserialize(file_get_contents("../private/admins"));
			$new = [ "login" => $login_hold , "passwd" => $pw_hold ];
			$array[] = $new;
			file_put_contents("../private/admins", serialize($array));
			ft_kill(" but user already exists! The progress has been undone.");
		}
	}
	$new = [ "login" => $_POST["login"] , "passwd" => $pw_hold ];
	$array[] = $new;
	file_put_contents("../private/passwd", serialize($array));
	echo ("and added to users\n");
}
else
	ft_kill("ERROR");

?>
