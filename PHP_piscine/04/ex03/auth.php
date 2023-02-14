<?php

function auth($login, $passwd)
{
	if ($login !== "" && $passwd !== "" && file_exists("../private/passwd"))
	{
		$array = unserialize(file_get_contents("../private/passwd"));
		for ($i = 0; $array[$i]; $i++)
			if($array[$i]["login"] == $login)
				break ;
		if (hash("whirlpool", $passwd) != $array[$i]["passwd"])
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

?>