<?php

session_start();
if ($_POST["submit"] === "Log out")
{
	$_SESSION["login"] = "";
	$_SESSION["admin"] = "";
	header("location: login_page.php");
}

?>