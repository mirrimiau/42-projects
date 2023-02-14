<?php
	foreach ($_GET as $key => $value)
	{
		if ($key == "action" && $_GET["$key"] == "set")
		{
			setcookie($_GET["name"], $_GET["value"], time() + 300);
		}
		if ($key == "action" && $value == "get")
		{
			foreach ($_GET as $key => $value)
			{
				if ($key != "action")
				{
					if ($_COOKIE["$value"])
						echo ($_COOKIE["$value"]."\n");
				}
			}
		}
		if ($key == "action" && $value == "del")
		{
			setcookie($_GET["name"], $_GET["value"], time() - 300);
		}	
	}
?>