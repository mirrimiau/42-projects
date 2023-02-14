<?php

function ft_kill()
{
	echo ("ERROR\n");
	exit ;
}

include("auth.php");
include("sanitize.php");
sanitize($_POST["login"]);
sanitize($_POST["passwd"]);
sanitize($_POST["submit"]);

if ($_POST["submit"] == "OK"  && $_POST["login"] !== "" && $_POST["passwd"] !== ""
&& file_exists("../private/passwd") && auth($_POST["login"], $_POST["passwd"]) && $_POST["tick"] === "TRUE")
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
