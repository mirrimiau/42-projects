<?php

session_start();
if ($_GET["submit"] == "OK")
{
	$_SESSION["submit"] = $_GET["submit"];
	$_SESSION["login"] = $_GET["login"];
	$_SESSION["passwd"] = $_GET["passwd"];
}
?>

<html>
<body>
	<form method="get" action="index.php">
		Username: <input type="text" name="login" value="<?=$_SESSION["login"];?>" />
		<br />
		Password: <input type="text" name="passwd" value="<?=$_SESSION["passwd"];?>" />
		<input type="submit" name="submit" value="OK" />
	</form>
</body>

</html>